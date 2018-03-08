CC=arm-none-linux-gnueabi-gcc
AFLAGS=-Wall -g
OBJS=beep.cgi led1.cgi led2.cgi led3.cgi led4.cgi capture.cgi picture1.cgi picture2.cgi m0_beep.cgi m0_fan.cgi m0_led.cgi \
m0_seg.cgi env1.cgi env2.cgi setEnv.cgi login.cgi set_sms.cgi wifi.cgi

run:$(OBJS)

$(OBJS):%.cgi:%.c
	$(CC) $(AFLAGS) $< cgic.c -o $@

.PHONY:clean
clean:
	rm *.cgi

