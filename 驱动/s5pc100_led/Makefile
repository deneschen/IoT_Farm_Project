ifeq ($(KERNELRELEASE),)

KERNELDIR ?= /home/linux/linux-2.6.35/
CC = /home/linux/armtool/arm-none-linux-gnueabi-gcc

PWD := $(shell pwd)

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

modules_install:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install

test:test.c


clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions Module* module* test

.PHONY: modules modules_install clean

else
    obj-m := s5pc100_led.o
endif

