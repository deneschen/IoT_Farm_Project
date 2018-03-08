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
	char text[N];
};

struct From_to_send{
	char gateway[12];
	char ip[12];
}phone_NUM;

void get_set_sms()
{
	cgiFormStringNoNewlines("gateway",phone_NUM.gateway,15);
	cgiFormStringNoNewlines("ip",phone_NUM.ip,15);
}

int cgiMain()
{
	key_t key;
	int msgid;
	char sto_no[2];	
	get_set_sms();
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
	strcat(phone_NUM.ip,"f");
	strcat(phone_NUM.ip,phone_NUM.gateway);
	strcpy(msg_buf.text,phone_NUM.ip);
	
	msg_buf.type = 1L;
	msg_buf.msgtype = 11L;
	msgsnd(msgid, &msg_buf,sizeof(msg_buf)-sizeof(long),0);

	cgiHeaderContentType("text/html");
	fprintf(cgiOut, "<HTML><HEAD>\n"); 
	fprintf(cgiOut, "<TITLE>My CGI</TITLE></HEAD>\n"); 
	fprintf(cgiOut, "<BODY bgcolor=\"#fffffffff\">\n");
	
	fprintf(cgiOut, "<H2>WiFi¿ªÆô³É¹¦</H2>");
	fprintf(cgiOut, "<meta http-equiv=\"refresh\" content=\"0;url=../main%d.html\">",sto_no[0]-48);
	fprintf(cgiOut, "</BODY></HTML>\n");
	return 0;
}
