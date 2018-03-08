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

struct setEnv
{
	int temMAX;
	int temMIN;
	int humMAX;
	int humMIN;
	int illMAX;
	int illMIN;
};

int cgiMain()
{
	key_t  key;
	char sto_no[2];
	char buf[20];
	struct setEnv new;
	int msgid;
	struct msg msg_buf;
	
	memset(&msg_buf,0,sizeof(msg_buf));
	cgiFormString("store", sto_no, 2);

	cgiFormString("temMAX", buf, 20);
	new.temMAX = atoi (buf);
	cgiFormString("temMIN", buf, 20);
	new.temMIN = atoi (buf);
	cgiFormString("humMAX", buf, 20);
	new.humMAX = atoi (buf);
	cgiFormString("humMIN", buf, 20);
	new.humMIN = atoi (buf);
	cgiFormString("illMAX", buf, 20);
	new.illMAX = atoi (buf);
	cgiFormString("illMIN", buf, 20);
	new.illMIN = atoi (buf);



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
	
	memcpy (msg_buf.text+1, &new, 24);
	
	msg_buf.type = 1L;
	msg_buf.msgtype = 5L;
	msg_buf.text[0] = sto_no[0];
	
	msgsnd(msgid, &msg_buf,sizeof(msg_buf)-sizeof(long),0);

	sto_no[0] -= 48;
	
	cgiHeaderContentType("text/html\n\n"); 
	fprintf(cgiOut, "<HTML><HEAD>\n"); 
	fprintf(cgiOut, "<TITLE>My CGI</TITLE></HEAD>\n"); 
	fprintf(cgiOut, "<BODY>"); 

	fprintf(cgiOut, "<H2>send sucess</H2>");

	//fprintf(cgiOut, "<a href='.html'>返回</a>"); 
	fprintf(cgiOut, "<meta http-equiv=\"refresh\" content=\"1;url=../main%d.html\">", sto_no[0]);
	fprintf(cgiOut, "</BODY>\n"); 
	fprintf(cgiOut, "</HTML>\n"); 


	return 0; 

}
