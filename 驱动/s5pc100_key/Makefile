$(warning KERNELRELEASE=$(KERNELRELEASE))
ifeq ($(KERNELRELEASE),)


KERNELDIR ?= /home/linux/linux-2.6.35

KERNELDIR ?= /lib/modules/$(shell uname -r)/build M=$(PWD) modules
PWD := $(shell pwd)

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	arm-none-linux-gnueabi-gcc keyboard_test.c -o keyboard_test
	

modules_install:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install

clean:
	rm -rf *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions Module*

test:keyboard_test.c

.PHONY: modules modules_install clean

else
	obj-m := s5pc100_keyboard.o 
endif
