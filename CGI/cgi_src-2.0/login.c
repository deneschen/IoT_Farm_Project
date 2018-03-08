#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cgic.h"

int cgiMain()
{
	cgiHeaderContentType("text/html");
	fprintf(cgiOut, "<HTML>\n");
	fprintf(cgiOut, "<HTML><HEAD>\n");
	fprintf(cgiOut, "<TITLE>登录提示</TITLE></HEAD>\n");
	fprintf(cgiOut, "<BODY>");
	fprintf(cgiOut, "<H1>%s<Hi>","登录成功，正在为你跳转");		
	fprintf(cgiOut, "<meta http-equiv=\"refresh\" content=\"0;url=../choose.html\">");
	return 0;
}