#include <linux/fs.h>
#include <linux/io.h>
#include <linux/cdev.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/interrupt.h>
#include <asm/delay.h>
#include <asm/uaccess.h>
//#include "s5pc100_key.h"
#include <linux/workqueue.h>
#include <linux/sched.h>
#include <asm/irq.h>

#define DEBUG 
//#undef  DEBUG
#define DRIVER_AUTHOR "XU HAO"
#define DRIVER_VERSION "V1.0"
#define DRIVER_DESC "A key driver"
#define S5PC100_GPH0_CON (0XE0300C00)
#define KEY_BUFFER_SIZE 32

MODULE_LICENSE ("GPL");
MODULE_AUTHOR (DRIVER_AUTHOR);
MODULE_VERSION (DRIVER_VERSION);
MODULE_DESCRIPTION (DRIVER_DESC);
MODULE_SUPPORTED_DEVICE ("S5PC100");

int major = 400;
int minor = 0;
int number_of_devices = 1;
    
volatile unsigned int *GPH0CON;

typedef struct 
{
	unsigned int key_values[KEY_BUFFER_SIZE];    //按键时间，如果读按键时间小于5秒钟的作废
	unsigned int jiffies[KEY_BUFFER_SIZE];       //按键混冲区
	int head;                                    //按键缓冲区的头
	int tail;                                    //按键缓冲区的尾
}KEY_BUFFER;

struct class *my_class;
struct cdev *cdev;
dev_t dev = 0;
int key_value = 0;

static spinlock_t buffer_lock;                     //定义自旋锁
static KEY_BUFFER g_keyBuffer;                     //键盘缓冲区

struct work_struct key_wq;                         //定义工作队列
static DECLARE_WAIT_QUEUE_HEAD(wq);                 //生成一个等待队列头
static int flag = 0;
char buf[1] = {'1'};

unsigned long irqno;
/*
 *功能：获取当前的毫秒数(从系统启动开始)
 *入口：
 * */
static unsigned long GetTickCount (void)
{
    struct timeval currTick;             //timeval结构用于指定时间值
    unsigned long ulRet;

    do_gettimeofday (&currTick);           //获取当前时间 保存在timeval结构体中
    ulRet = currTick.tv_sec;                     //tv_sec 秒 long int
    ulRet *= 1000;
    ulRet += (currTick.tv_usec + 500) / 1000;
    return ulRet;
}

/*
 *功能：初始化按键缓冲区
 *入口：
 * */
static void init_keyBuffer (void) 
{
    int i;
 
    spin_lock_irq (&buffer_lock);               //获得一个自旋锁具有不会受到中断影响	
 
    g_keyBuffer.head = 0;
    g_keyBuffer.tail = 0;

    for (i=0; i < KEY_BUFFER_SIZE; i++)
    {
        g_keyBuffer.key_values[i] = 0;
        g_keyBuffer.jiffies[i] = 0;
    }
    spin_unlock_irq (&buffer_lock);

}

/*
 * 功能：删除过时（5秒前入键值）
 * 入口：
 * */
static void remove_timeoutKey (void)
{
    unsigned long ulTick;

    spin_lock_irq (&buffer_lock);

    while (g_keyBuffer.head != g_keyBuffer.tail)
    {
        ulTick = GetTickCount() - g_keyBuffer.jiffies[g_keyBuffer.head];
        if (ulTick < 3000)
            break;
        g_keyBuffer.key_values[g_keyBuffer.head] = 0;
        g_keyBuffer.jiffies[g_keyBuffer.head] = 0;
        g_keyBuffer.head ++;
        g_keyBuffer.head &= (KEY_BUFFER_SIZE -1);
    }

    spin_unlock_irq (&buffer_lock);

}

static void key_do_work(unsigned long arg)
{	
//	unsigned long irqno = arg;
    __udelay(50000);                //微妙级忙等待函数

    if (((g_keyBuffer.head + 1) & (KEY_BUFFER_SIZE - 1)) != g_keyBuffer.tail)
    {
        spin_lock_irq (&buffer_lock);
        //临界资源
        g_keyBuffer.key_values[g_keyBuffer.tail] = key_value;
        g_keyBuffer.jiffies[g_keyBuffer.tail] = GetTickCount ();
        g_keyBuffer.tail ++;
        g_keyBuffer.tail &= (KEY_BUFFER_SIZE -1);

        spin_unlock_irq (&buffer_lock);
    }
}

static int open (struct inode *inode, struct file *file)
{
    /*
    enable_irq (IRQ_EINT(1));
    enable_irq (IRQ_EINT(2));
    enable_irq (IRQ_EINT(3));
    enable_irq (IRQ_EINT(4));
    enable_irq (IRQ_EINT(6));
    enable_irq (IRQ_EINT(7));
    */ 
	int ret = nonseekable_open (inode, file);
 
	if (ret>=0)
    	init_keyBuffer ();

    return ret;
}

static int release (struct inode *inode, struct file *file)
{
    /*
    disable_irq (IRQ_EINT(1));
    disable_irq (IRQ_EINT(2));
    disable_irq (IRQ_EINT(3));
    disable_irq (IRQ_EINT(4));
    disable_irq (IRQ_EINT(6));
    disable_irq (IRQ_EINT(7));
    */
    return 0;
}

ssize_t read_key (struct file *file, char __user *buf, size_t count, loff_t *f_pos)
{
    ssize_t ret = 0;

#if 0
    if( copy_to_user (buf, (char *)&key_value, count)) {
#ifdef DEBUG
        printk (KERN_INFO "DEBUG: copy to user failed.\n");
#endif
        ret = -EFAULT;
    }
#endif
	
	wait_event_interruptible(wq, flag != 0);
	flag = 0;
    remove_timeoutKey ();
    spin_lock_irq (&buffer_lock);

    while (g_keyBuffer.head != g_keyBuffer.tail && (((size_t)ret) < count))
    {
        buf[ret] = (char)(g_keyBuffer.key_values[g_keyBuffer.head]);
        g_keyBuffer.key_values[g_keyBuffer.head] = 0;
        g_keyBuffer.jiffies[g_keyBuffer.head] = 0;
        g_keyBuffer.head ++;
        g_keyBuffer.head &= (KEY_BUFFER_SIZE -1);
        ret ++;
    }
#ifdef DEBUG
	if( copy_to_user (buf, (char *)&key_value, count)) {
#ifdef DEBUG
        printk (KERN_INFO "DEBUG: copy to user failed.\n");
#endif
        ret = -EFAULT;
    }
#endif

#ifdef DEBUG
    printk (KERN_INFO "read : keyvalue = %d\n", key_value);
#endif
    spin_unlock_irq (&buffer_lock);

    return count;
}

struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = open,
    .release = release,
    .read = read_key
};

/*
 *作用：处理按键中断
 * */
irqreturn_t irq_handler (int irqno, void *dev_id)
{
//	int key_value = 0;
    switch (irqno) {
       
    case IRQ_EINT(1) :
        key_value = 1;
		flag = 1;
#ifdef DEBUG
        printk (KERN_INFO "SOMEONE IN!\n");
		wake_up_interruptible(&wq);
#endif
        break;
    case IRQ_EINT(2) :
        key_value = 2;
#ifdef DEBUG
        printk (KERN_INFO "SOMEONE OUT!\n");
		flag = 2;
		wake_up_interruptible(&wq);
#endif
        break;
    case IRQ_EINT(3) :
        key_value = 3;
#ifdef DEBUG
        printk (KERN_INFO "calling\n");
	flag = 3;
	wake_up_interruptible(&wq);
#endif
        break;
    case IRQ_EINT(4) :
        key_value = 4;
#ifdef DEBUG
        printk (KERN_INFO "INTERRUPT 4\n");
#endif
        break;
    case IRQ_EINT(6) :
        key_value = 5;
#ifdef DEBUG
        printk (KERN_INFO "INTERRUPT 6\n");
#endif
        break;
    case IRQ_EINT(7) :
        key_value = 6;
#ifdef DEBUG
        printk (KERN_INFO "INTERRUPT 7\n");
#endif
        break;
    
    default :
        printk (KERN_WARNING "VALIDE INTERRUPT\n");
        break;
    }

	schedule_work(&key_wq);

	return IRQ_HANDLED;
}

static int init_device (void) 
{
    if ((GPH0CON = (volatile unsigned int *)ioremap (S5PC100_GPH0_CON, 4)) == NULL)
        return -1;

    writel ((readl (GPH0CON) & ~(0xffff)) | (0x0010<<4) | (0x0010<<8) | (0x0010<<12) | (0x0010<<16) | (0x0010<<24) | (0x0010<<28), GPH0CON);
 

    return 0;

}

/*
 *作用：申请按键中断
 * */
static int init_irq (void)
{
    int result = 0;

    result = request_irq (IRQ_EINT(1), irq_handler, IRQF_DISABLED | IRQF_TRIGGER_FALLING, "key", NULL);
    result = request_irq (IRQ_EINT(2), irq_handler, IRQF_DISABLED | IRQF_TRIGGER_FALLING, "key", NULL);
    result = request_irq (IRQ_EINT(3), irq_handler, IRQF_DISABLED | IRQF_TRIGGER_FALLING, "key", NULL);
    result = request_irq (IRQ_EINT(4), irq_handler, IRQF_DISABLED | IRQF_TRIGGER_FALLING, "key", NULL);
    result = request_irq (IRQ_EINT(6), irq_handler, IRQF_DISABLED | IRQF_TRIGGER_FALLING, "key", NULL);
    result = request_irq (IRQ_EINT(7), irq_handler, IRQF_DISABLED | IRQF_TRIGGER_FALLING, "key", NULL);


    return result;
}

static int __init init_driver (void)
{
    int result;

    if (major) {
        dev = MKDEV (major, minor);
        result = register_chrdev_region (dev, number_of_devices, "key");
    }
    else {
        result = alloc_chrdev_region (&dev, 0, 1, "key");
        major = MAJOR (dev);
    }

    if (result<0) {
        printk (KERN_WARNING "DRIVER: can't get major number %d\n", major);
        return result;
    }
 
    /* char_reg_setup_cdev */
    cdev = cdev_alloc();
    cdev_init (cdev, &fops);
    cdev->owner = THIS_MODULE;

    result = cdev_add (cdev, dev, 1);
    if (result<0) 
        printk (KERN_WARNING "Error %d: adding char_device.\n", result);

    my_class = class_create(THIS_MODULE, "arthur_class");
    if (IS_ERR(my_class)) 
        printk (KERN_WARNING "Error : failed in creating class.\n");

    device_create(my_class, NULL, dev, NULL, "keyboard");

    result = init_device();
    if (result < 0) {
        printk (KERN_WARNING "DRIVER: can't map the address.\n");
        return result;
    }

    init_irq(); 
    if (result<0) {
        printk (KERN_WARNING "DRIVER: can't request irq.\n");
        return result;
    }

	spin_lock_init (&buffer_lock);
	INIT_WORK(&key_wq, key_do_work);
#ifdef DEBUG
    printk (KERN_INFO "DEBUG: key init success.\n");
#endif
    return 0;
}

static void __exit exit_driver (void)
{
    device_destroy(my_class, dev);
    class_destroy(my_class);
    
    iounmap (GPH0CON);

    free_irq(IRQ_EINT(1), NULL);
    free_irq(IRQ_EINT(2), NULL);
    free_irq(IRQ_EINT(3), NULL);
    free_irq(IRQ_EINT(4), NULL);
    free_irq(IRQ_EINT(6), NULL);
    free_irq(IRQ_EINT(7), NULL);

    if (cdev) 
        cdev_del (cdev);

    unregister_chrdev_region (dev, number_of_devices);
#ifdef DEBUG
    printk (KERN_INFO "DEBUG: key exit success.\n");
#endif
}

module_init (init_driver);
module_exit (exit_driver);
