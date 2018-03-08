#CC=gcc
CC=arm-none-linux-gnueabi-gcc
AFLAGS=-Wall -c -g
LDFLAGS= -L ./lib -lsqlite3
#LDFLAGS= -lpthread
OBJS=cgic.o data_global.o sql.o sqlite_cgi.o
#camera_function.o

sql1.cgi:$(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)
$(OBJS):%.o:%.c
	$(CC) $(AFLAGS) $< -o $@

.PHONY:clean
clean:
	rm *.o *.cgi 

