#include <linux/module.h> 
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>

#include <asm/io.h>

#include <mach/regs-gpio.h>
//#include <asm/atomic.h>
//#include <asm/system.h>
#include <linux/device.h>

#include "s5pc100_led.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("farsight");

static int led_major = 250;
static int led_minor = 0;
static struct cdev led_cdev;
struct class *my_class;

static void led_init(void)
{
	writel((readl(S5PC100_GPG3_BASE) & ~0xF) | 0x1, S5PC100_GPG3_BASE);
	writel((readl(S5PC100_GPG3_BASE) & ~(0xF << 4)) | (0x1 << 4), S5PC100_GPG3_BASE);
	writel((readl(S5PC100_GPG3_BASE) & ~(0xF << 8)) | (0x1 << 8), S5PC100_GPG3_BASE);
	writel((readl(S5PC100_GPG3_BASE) & ~(0xF << 12)) | (0x1 << 12), S5PC100_GPG3_BASE);
}

/*
static void led_on(void)
{
	//writel((readl(S5PC100_GPG3_BASE + 4) | 0x1), S5PC100_GPG3_BASE + 4);
	//writel((readl(S5PC100_GPG3_BASE + 4) | (0x2)), S5PC100_GPG3_BASE + 4);
	//writel((readl(S5PC100_GPG3_BASE + 4) | (0x4)), S5PC100_GPG3_BASE + 4);
	//writel((readl(S5PC100_GPG3_BASE + 4) | (0x8)), S5PC100_GPG3_BASE + 4);

}

static void led_off(void)
{
	writel((readl(S5PC100_GPG3_BASE + 4) & ~0x1), S5PC100_GPG3_BASE + 4);
}

*/
static int s5pc100_led_open(struct inode *inode, struct file *file)
{
	printk("led: device open\n");
	led_init();
	return 0;
}

static int s5pc100_led_close(struct inode *inode, struct file *file)
{
	printk("led: device close\n");
	return 0;
}

static int s5pc100_led_ioctl(struct inode *inode, struct file *file, unsigned int cmd, unsigned long arg)
{
	printk("led: device ioctl\n");
	switch(cmd)
	{
	case LED_ON:
        if(arg == 0)
        {
	        writel((readl(S5PC100_GPG3_BASE + 4) | 0x1), S5PC100_GPG3_BASE + 4);
		    printk("led 1 ON\n");
        }
		//led_on();
        if(arg == 1)
        {
	        writel((readl(S5PC100_GPG3_BASE + 4) | (0x2)), S5PC100_GPG3_BASE + 4);
            printk("led 2 ON\n");
        }
        if(arg == 2)
        {
	        writel((readl(S5PC100_GPG3_BASE + 4) | (0x4)), S5PC100_GPG3_BASE + 4);
            printk("led 3 ON\n");
        }
        if(arg == 3)
        {
            writel((readl(S5PC100_GPG3_BASE + 4) | (0x8)), S5PC100_GPG3_BASE + 4);
            printk("led 4 ON\n");
        }
        break;

    case LED_OFF:
        if(arg == 0)
        {
            writel((readl(S5PC100_GPG3_BASE + 4) & ~0x1), S5PC100_GPG3_BASE + 4);
            printk("led 1 OFF\n");
        }
        //led_on();
        if(arg == 1)
        {
            writel((readl(S5PC100_GPG3_BASE + 4) & ~(0x1 << 1)), S5PC100_GPG3_BASE + 4);
            printk("led 2 OFF\n");
        }
        if(arg == 2)
        {
            writel((readl(S5PC100_GPG3_BASE + 4) & ~(0x1 << 2)), S5PC100_GPG3_BASE + 4);
            printk("led 3 OFF\n");
        }
        if(arg == 3)
        {
            writel((readl(S5PC100_GPG3_BASE + 4) & ~(0x1 << 3)), S5PC100_GPG3_BASE + 4);
            printk("led 4 OFF\n");
        }
        printk("led: OFF\n");
        //led_off();
        break;
    default:
		printk("led: available command\n");
		break;
	}
	return 0;
}

static struct file_operations s5pc100_led_ops = {
	.owner 		= THIS_MODULE,
	.open 		= s5pc100_led_open,
	.release 	= s5pc100_led_close,
	.ioctl		= s5pc100_led_ioctl
};

static int led_setup_cdev(struct cdev *cdev, 
		struct file_operations *fops)
{
	int result;
	dev_t devno = MKDEV(led_major, led_minor);
	cdev_init(cdev, fops);
	cdev->owner = THIS_MODULE;
	result = cdev_add(cdev, devno, 1);
	if(result)
	{
		printk("led: cdev add failed\n");
		return result;
	}
	return 0;
}

static int __init s5pc100_led_init(void)
{
	int result;
	dev_t devno = MKDEV(led_major, led_minor);
	result = register_chrdev_region(devno, 1, "s5pc100_led");
	if(result)
	{
		printk("led: unable to get major %d\n", led_major);
		return result;
	}

	result = led_setup_cdev(&led_cdev, &s5pc100_led_ops);
	if(result)
		return result;

	printk("led: driver installed, with major %d!\n", led_major);

    my_class = class_create(THIS_MODULE, "led_class");
    if (IS_ERR(my_class))
        printk(KERN_WARNING "Error:failed to create led_class\n");

    device_create(my_class, NULL, devno, NULL, "dota_led");
	return 0;
}

static void __exit s5pc100_led_exit(void)
{
	dev_t devno = MKDEV(led_major, led_minor);
	cdev_del(&led_cdev);
	printk("led: driver uninstalled!\n");

    device_destroy(my_class, devno);
    class_destroy(my_class);

	unregister_chrdev_region(devno, 1);
}

module_init(s5pc100_led_init);
module_exit(s5pc100_led_exit);
