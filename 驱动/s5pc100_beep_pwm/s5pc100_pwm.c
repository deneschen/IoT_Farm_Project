#include <linux/module.h> 
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>

#include <asm/io.h>

#include <plat/regs-timer.h>

#include <mach/regs-gpio.h>

#include "s5pc100_pwm.h"


MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("farsight");

static int pwm_major = 500;
static int pwm_minor = 0;
static struct cdev pwm_cdev;
static int cnt_def = 300;

static void beep_init(void)
{
	writel((readl(S5PC100_GPD_BASE) & (~0xF << 4)) | (0x2 << 4), S5PC100_GPD_BASE);
	writel(readl(S3C2410_TCFG0) & ~0xff, S3C2410_TCFG0);
	writel((readl(S3C2410_TCFG1) & ~(0xf << 4)) | (0x1 << 4), S3C2410_TCFG1);
	writel(cnt_def, S3C2410_TCNTB(1));
	writel(cnt_def/2, S3C2410_TCMPB(1));
	writel((readl(S3C2410_TCON) & ~(0xf << 8)) | (0xa << 8), S3C2410_TCON);
}

static void beep_on(void)
{
	writel((readl(S3C2410_TCON) & ~(0xf << 8)) | (0x9 << 8), S3C2410_TCON);
}

static void beep_off(void)
{
	writel((readl(S3C2410_TCON) & ~(0xf << 8)), S3C2410_TCON);
}

static void set_cnt(unsigned long arg)
{
	beep_off();
	writel(arg, S3C2410_TCNTB(1));
	writel(arg/2, S3C2410_TCMPB(1));
	beep_on();
}

static void set_pre(unsigned long arg)
{
	beep_off();
	writel((readl(S3C2410_TCFG0) & ~0xff) | (arg & 0xff), S3C2410_TCFG0);
	beep_on();
}

static int s5pc100_pwm_open(struct inode *inode, struct file *file)
{
	printk("pwm: device open\n");
	beep_init();
	return 0;
}

static int s5pc100_pwm_close(struct inode *inode, struct file *file)
{
	printk("pwm: device close\n");
	beep_off();
	return 0;
}

static int s5pc100_pwm_ioctl(struct inode *inode, struct file *file, unsigned int cmd, unsigned long arg)
{
	printk("pwm: device ioctl\n");
	switch(cmd)
	{
	case BEEP_ON:
		printk("pwm: BEEP ON\n");
		beep_on();
		break;
	case BEEP_OFF:
		printk("pwm: BEEP OFF\n");
		beep_off();
		break;
	case SET_CNT:
		printk("pwm: SET CNT\n");
		set_cnt(arg);
		break;
	case SET_PRE:
		printk("pwm: SET PRE\n");
		set_pre(arg);
		break;
	default:
		printk("pwm: available command\n");
		break;
	}
	return 0;
}

static struct file_operations s5pc100_pwm_ops = {
	.owner 		= THIS_MODULE,
	.open 		= s5pc100_pwm_open,
	.release 	= s5pc100_pwm_close,
	.ioctl		= s5pc100_pwm_ioctl
};

static int pwm_setup_cdev(struct cdev *cdev, 
		struct file_operations *fops)
{
	int result;
	dev_t devno = MKDEV(pwm_major, pwm_minor);
	cdev_init(cdev, fops);
	cdev->owner = THIS_MODULE;
	result = cdev_add(cdev, devno, 1);
	if(result)
	{
		printk("pwm: cdev add faipwm\n");
		return result;
	}
	return 0;
}

static int __init s5pc100_pwm_init(void)
{
	int result;
	dev_t devno = MKDEV(pwm_major, pwm_minor);
	result = register_chrdev_region(devno, 1, "s5pc100_pwm");
	if(result)
	{
		printk("pwm: unable to get major %d\n", pwm_major);
		return result;
	}

	result = pwm_setup_cdev(&pwm_cdev, &s5pc100_pwm_ops);
	if(result)
		return result;

	printk("pwm: driver instalpwm, with major %d!\n", pwm_major);
	return 0;
}

static void __exit s5pc100_pwm_exit(void)
{
	dev_t devno = MKDEV(pwm_major, pwm_minor);
	cdev_del(&pwm_cdev);
	unregister_chrdev_region(devno, 1);
	printk("pwm: driver uninstalpwm!\n");
}

module_init(s5pc100_pwm_init);
module_exit(s5pc100_pwm_exit);
