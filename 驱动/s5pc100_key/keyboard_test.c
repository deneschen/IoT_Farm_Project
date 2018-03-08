#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "s5pc100_keyboard.h"

#define DEBUG 
//#undef  DEBUG

int main (void)
{
    int fd;
	int i;
    //int data;
    int result;
    int g_keyBuffer;
	char key = 0;

    fd = open ("/dev/key", O_RDWR);
    if (fd < 0) {
        printf("fd open failed.\n");
        exit (0);
    }


    while(1)
    {
        result = read (fd, (char *)&g_keyBuffer, sizeof (g_keyBuffer));
    	printf ("key_value_test = %d\n", g_keyBuffer);
    }

    close (fd);
    return 0;
}
