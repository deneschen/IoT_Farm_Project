#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>

#include "s5pc100_led.h"

int main()
{
	int dev_fd;
	dev_fd = open("/dev/dota_led",O_RDWR | O_NONBLOCK);
	if (dev_fd < 0) 
	{
		perror("open");
		exit(1);
	}
	while(1)
	{
		ioctl(dev_fd,LED_ON,0);
		usleep(100000);
 
		ioctl(dev_fd,LED_OFF,0);
		usleep(100000);       


		ioctl(dev_fd,LED_ON,1);
		usleep(100000);

		ioctl(dev_fd,LED_OFF,1);
		usleep(100000);


		ioctl(dev_fd,LED_ON,2);
		usleep(100000);

		ioctl(dev_fd,LED_OFF,2);
		usleep(100000);


		ioctl(dev_fd,LED_ON,3);
		usleep(100000);

		ioctl(dev_fd,LED_OFF,3);
		usleep(100000);

	}
	return 0;
}
