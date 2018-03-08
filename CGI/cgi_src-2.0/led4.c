#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <errno.h>
#include "cgic.h"

#define N 32

struct msg
{
	long type;
	long msgtype;
	unsigned char text[N];
};

char ledbuf[N];

void get_led4()
{
	cgiFormStringNoNewlines("led4",ledbuf,N);
}

int cgiMain()
{
	key_t key;
	int msgid;
	char sto_no[2];	
	get_led4();
	struct msg msg_buf;
	memset(&msg_buf,0,sizeof(msg_buf));
	
	cgiFormString("store", sto_no, 2);

	if((key = ftok("/app", 'g')) < 0)
	{
		perror("ftok");
		exit(1);
	}

	if((msgid = msgget(key, 0666)) < 0)
	{
		perror("msgget");
		exit(1);
	}
	bzero (msg_buf.text, sizeof (msg_buf.text));
	if (strncmp(ledbuf,"led4_on", 7) == 0)
	{
		msg_buf.text[0] =  (1<<7) | (1<<3);
	}
	else if(strncmp(ledbuf,"led4_off", 8) == 0)
	{
		msg_buf.text[0] = (1<<7);
	}

	msg_buf.type = 1L;
	msg_buf.msgtype = 1L;
	msgsnd(msgid, &msg_buf,sizeof(msg_buf)-sizeof(long),0);

	cgiHeaderContentType("text/html");
	fprintf(cgiOut, "<HTML>\n");
	fprintf(cgiOut, "<BODY bgcolor=\"#fffffffff\">\n");
	//fprintf(cgiOut, "<meta http-equiv=\"refresh\" content=\"0;url=../main1.html\">");
	fprintf(cgiOut, "<meta http-equiv=\"refresh\" content=\"1;url=../main%d.html\">",sto_no[0]-48);
	fprintf(cgiOut, "</BODY></HTML>\n");

	return 0;
}
