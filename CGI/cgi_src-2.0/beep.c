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

char beepbuf[N];

void get_beep()
{
	cgiFormStringNoNewlines("beep",beepbuf,N);
}

int cgiMain()
{
	key_t key;
	int msgid;
	char sto_no[2];	
	get_beep();
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

	if (strncmp(beepbuf,"beep_on", 7) == 0)
	{
		msg_buf.text[0] =1;
	}
	else if(strncmp(beepbuf,"beep_off", 8) == 0)
	{
		msg_buf.text[0] =0;
	}

	msg_buf.type = 1L;
	msg_buf.msgtype = 2L;
	msgsnd(msgid, &msg_buf,sizeof(msg_buf)-sizeof(long),0);

	cgiHeaderContentType("text/html");
	fprintf(cgiOut, "<HTML>\n");
	fprintf(cgiOut, "<BODY bgcolor=\"#fffffffff\">\n");
	//fprintf(cgiOut, "<meta http-equiv=\"refresh\" content=\"0;url=../main1.html\">");
	fprintf(cgiOut, "<meta http-equiv=\"refresh\" content=\"1;url=../main%d.html\">",sto_no[0]-48);
	fprintf(cgiOut, "</BODY></HTML>\n");
	return 0;
}
