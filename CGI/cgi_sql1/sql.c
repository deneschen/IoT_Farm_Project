#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "cgic.h"
#include "data_global.h"
#include "sqlite_cgi.h"

int i;
int GOODSKINDS[7] = {2, 3, 4, 5, 6, 7, 9};
char goods_Name[8][20] = {"", "apple", "banana", "pear", "kiwi", "mango", "pitaya", "orange"};

int cgiMain()
{
	getCollect_Current_env (STORAGE_NO);
#if 0
	for (i=1; i<8; i++)
	{
		getGoods (STORAGE_NO, GOODSKINDS[i]);
	}
#endif
#if 1
	getCurrentGoods (STORAGE_NO);
#endif

	cgiHeaderContentType("text/html");
//	fprintf (cgiOut, "<head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" /><style type = \"text/css\"><!--body{line-height:50%}--></style></head>");
//	fprintf (cgiOut, "<head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" /><style><!--body{line-height:10%}--></style></head>");
	fprintf (cgiOut, "<head><meta http-equiv=\"refresh\" content=\"2\"><style><!--body{line-height:50%}--></style></head>");
	fprintf (cgiOut, "<HTML>\n");
	fprintf (cgiOut, "<BODY bgcolor=\"#3C85B2\">\n");

//	fprintf (cgiOut, "<h4><font face=\"Broadway\"><font color=\"#FFFAF0\">实时环境信息</font></font></H4>\n ");	
//	fprintf (cgiOut, "<h5>温度:\t%0.2f</H5>\n ", info_CGI.storage_no[STORAGE_NO].temperature);
//	fprintf (cgiOut, "<h5>湿度:\t%0.2f</H5>\n ", info_CGI.storage_no[STORAGE_NO].humidity);
//	fprintf (cgiOut, "<h5>光照强度:\t%0.2f</H5>\n ", info_CGI.storage_no[STORAGE_NO].illumination);
//	fprintf (cgiOut, "<hr />");
	fprintf (cgiOut, "<h4><font face=\"Broadway\"><font color=\"#FFFAF0\">仓库一物品信息 </font></font></H4>\n ");	
	//fprintf (cgiOut, "<h5>物品名称:%s</H5>\n ", goods_Name[1]);
//	fprintf (cgiOut, "<h5>物品数量:\t%d</H5>\n ", info_CGI.storage_no[STORAGE_NO].goods_info[GOODSKINDS_1].goods_count);
//	fprintf (cgiOut, "<h5>物品名称:%s</H5>\n ", goods_Name[2]);
//	fprintf (cgiOut, "<h5>物品数量:\t%d</H5>\n ", info_CGI.storage_no[STORAGE_NO].goods_info[GOODSKINDS_2].goods_count);
	fprintf (cgiOut, "<h5>物品名称:%s</H5>\n ", goods_Name[3]);
	fprintf (cgiOut, "<h5>物品数量:\t%d</H5>\n ", info_CGI.storage_no[STORAGE_NO].goods_info[GOODSKINDS_3].goods_count);
//	fprintf (cgiOut, "<h5>物品名称:%s</H5>\n ", goods_Name[4]);
	//fprintf (cgiOut, "<h5>物品数量:\t%d</H5>\n ", info_CGI.storage_no[STORAGE_NO].goods_info[GOODSKINDS_4].goods_count);
//fprintf (cgiOut, "<h5>物品名称:%s</H5>\n ", goods_Name[5]);
//	fprintf (cgiOut, "<h5>物品数量:\t%d</H5>\n ", info_CGI.storage_no[STORAGE_NO].goods_info[GOODSKINDS_5].goods_count);
//	fprintf (cgiOut, "<h5>物品名称:%s</H5>\n ", goods_Name[6]);
//	fprintf (cgiOut, "<h5>物品数量:\t%d</H5>\n ", info_CGI.storage_no[STORAGE_NO].goods_info[GOODSKINDS_6].goods_count);
////	fprintf (cgiOut, "<h5>物品名称:%s</H5>\n ", goods_Name[7]);
//	fprintf (cgiOut, "<h5>物品数量:\t%d</H5>\n ", info_CGI.storage_no[STORAGE_NO].goods_info[GOODSKINDS_7].goods_count);
	//	fprintf(cgiOut, "<h3>:</H3>\n ");	
	fprintf(cgiOut, "</BODY></HTML>\n");	

	return 0;
}


