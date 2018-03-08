#include "sqlite_cgi.h"	

#define TEMPERATURE_MAX   1
#define TEMPERATURE_MIN   2
#define HUMIDITY_MAX      3
#define HUMIDITY_MIN      4
#define ILLUMINATION_MAX  5
#define ILLUMINATION_MIN  6
#define TELEPHONE_NUM     7
#define MODE              8
#define IFNOCICE          9
#define INTERVAL          10 
#define UPDATE_PERIOD     11
#define USER_NAME         12
#define PASSWORD          13



float callback_val[15];
char callback_str[20];
int flag_goods = 0;

/*
**回到函数，查询之后的信息都通过
*/
static int callback_getenv (void * para, int n_column, char ** column_value, char ** column_name )
{
	int i;
#if DEBUG_SQLITE
	printf ("n_column = %d\n", n_column);
#endif
	for (i=0; i<n_column; i++)
	{
		if (n_column-1 == i)
		{
			strcpy (callback_str, column_value[i]);
#if DEBUG_SQLITE
			printf ("%s = %s\n", column_name[i], callback_str);
#endif
		}
		else
		{
			callback_val[i] = (float)atof(column_value[i]);
#if DEBUG_SQLITE
			printf ("%s = %f\n", column_name[i], callback_val[i]);
#endif
		}
	}
#if DEBUG_SQLITE
	printf ("**********************\n");
#endif

#if 1
	if (1 == flag_goods)
	{
		info_CGI.storage_no[STORAGE_NO].goods_info[(int)atof(column_value[1])].goods_type = (int)atof(column_value[1]);
		info_CGI.storage_no[STORAGE_NO].goods_info[(int)atof(column_value[1])].goods_count = (int)atof(column_value[2]);
	}
#endif
#if 0
		info_CGI.storage_no[storageNum_t].goods_info[goodsKinds_t].goods_type = (int)callback_val[1];
		info_CGI.storage_no[storageNum_t].goods_info[goodsKinds_t].goods_count = (int)callback_val[2];
#endif
	return 0;
}

static int callback_getenv_s (void * para, int n_column, char ** column_value, char ** column_name )
{
	strcpy (callback_str, column_value[0]);
#if DEBUG_SQLITE
	printf ("%s = %s\n", column_name[0], callback_str);
#endif
	return 0;
}

/*
**更新env参数的SQLite指令选择函数
**这个函数中只能插入int类型的值
*/
int setEnv (float val, int dev_no_t, int no)
{
	char sql[1024];
	switch (no)
	{
	case 1:
		sprintf (sql, "update env set temperatureMax = '%f' where dev_no = '%d';", val, dev_no_t);
		break;
	case 2:
		sprintf (sql, "update env set temperatureMin = '%f' where dev_no = '%d';", val, dev_no_t);
		break;
	case 3:
		sprintf (sql, "update env set humidityMax = '%f' where dev_no = '%d';", val, dev_no_t);
		break;
	case 4:
		sprintf (sql, "update env set humidityMin = '%f' where dev_no = '%d';", val, dev_no_t);
		break;
	case 5:
		sprintf (sql, "update env set illuminationMax = '%f' where dev_no = '%d';", val, dev_no_t);
		break;
	case 6:
		sprintf (sql, "update env set illuminationMin = '%f' where dev_no = '%d';", val, dev_no_t);
		break;
#if 0
	case 7:
		sprintf (sql, "update env set telephoneNum = '%f';", val);
		break;
	case 8:
		sprintf (sql, "update env set mode = '%d';", (int)val);
		break;
	case 9:
		sprintf (sql, "update env set ifnocice = '%d';", (int)val);
		break;
	case 10:
		sprintf (sql, "update env set interval = '%d';", (int)val);
		break;
	case 11:
		sprintf (sql, "update env set updatePeriod = '%d';", (int)val);
		break;
//	case 12:
//		sprintf (sql, "update env set username = '%f';", val);
		break;
	case 13:
		sprintf (sql, "update env set password = '%d';", (int)val);
		break;
#endif
	}

	sqlite3 *db;
	char *err_msg = 0;
	int recode;
	recode = sqlite3_open (SQLITE_OPEN, &db);
	if (recode != SQLITE_OK)
	{
		printf ("Can't Open Database:%s!\n", sqlite3_errmsg(db));
		sqlite3_close (db);
		return 1;
	}
	else
	{
#if DEBUG_SQLITE
		printf ("open OK!\n");
#endif
		recode=sqlite3_exec (db, sql, 0, 0, &err_msg);
		if (recode != SQLITE_OK)
		{
			printf ("Error:%s", err_msg);
			sqlite3_close (db);
			return 1;
		}
		else
		{
#if DEBUG_SQLITE
			printf ("Insert OK!\n");
#endif
			sqlite3_close (db);
			return 0;
		}
	}
}

/*
**更新env参数的SQLite指令选择函数
**这个函数中只能插入字符串类型的值
*/
int setEnv_s (char *val, int no)
{
	char sql[1024];
	switch(no)
	{
	case 7:
		sprintf (sql, "update env set telephoneNum = '%s';", val);
	case 12:
		sprintf (sql, "update env set username = '%s';", val);
	}

	sqlite3 *db;
	char *err_msg = 0;
	int recode;
	recode = sqlite3_open (SQLITE_OPEN, &db);
	if (recode != SQLITE_OK)
	{
		printf ("Can't Open Database:%s!\n",sqlite3_errmsg(db));
		sqlite3_close (db);
		return 1;
	}
	else
	{
#if DEBUG_SQLITE
		printf ("open OK!\n");
#endif
		recode = sqlite3_exec (db, sql, 0, 0, &err_msg);
		if (recode != SQLITE_OK)
		{
			printf ("Error:%s", err_msg);
			sqlite3_close (db);
			return 1;
		}
		else
		{
#if DEBUG_SQLITE
			printf ("Insert OK!\n");
#endif
			sqlite3_close (db);
			return 0;
		}
	}
}

/*
**获得env参数的SQLite指令选择函数
*/

int getEnv_select (int storageNum_t, int no)
{
	char sql[1024];
	sqlite3 *db;
	char *err_msg = 0;
	int recode;

	switch (no)
	{
	case 1:
		sprintf (sql, "select temperatureMax from env where dev_no = '%d';", storageNum_t);
		break;
	case 2:
		sprintf (sql, "select temperatureMin from env where dev_no = '%d';", storageNum_t);
		break;
	case 3:
		sprintf (sql, "select humidityMax from env where dev_no = '%d';", storageNum_t);
		break;
	case 4:
		sprintf (sql, "select humidityMin from env where dev_no = '%d';", storageNum_t);
		break;
	case 5:
		sprintf (sql, "select illuminationMax from env where dev_no = '%d';", storageNum_t);
		break;
	case 6:
		sprintf (sql, "select illuminationMin from env where dev_no = '%d';", storageNum_t);
		break;
#if 0
	case 7:
		sprintf (sql, "select telephoneNum from env;");
		break;
	case 8:
		sprintf (sql, "select mode from env;");
		break;
	case 9:
		sprintf (sql, "select ifnocice from env;");
		break;
	case 10:
		sprintf (sql, "select interval from env;");
		break;
	case 11:
		sprintf (sql, "select updatePeriod from env;");
		break;
	case 12:
		sprintf (sql, "select username from env;");
		break;
	case 13:
		sprintf (sql, "select password from env;");
		break;
#endif
	}
	recode = sqlite3_open (SQLITE_OPEN, &db);
	if (recode != SQLITE_OK)
	{
		printf ("Can't Open Database:%s!\n", sqlite3_errmsg(db));
		sqlite3_close (db);
		return 1;
	}
	else
	{
#if DEBUG_SQLITE
		printf ("open OK!\n");
#endif
		if ((7 == no) || (12 == no))
		{
			recode = sqlite3_exec (db, sql, callback_getenv_s, 0, &err_msg);
		}
		else
		{
			recode = sqlite3_exec (db, sql, callback_getenv, 0, &err_msg);
		}
		if (recode != SQLITE_OK)
		{
			printf ("Error:%s", err_msg);
			sqlite3_close (db);
			return 1;
		}
		else
		{
#if DEBUG_SQLITE
			printf ("get env OK!\n");
#endif
			sqlite3_close (db);
			return 0;
		}
	}
}

/*
**获得env参数
*/
int getEnv (struct env_info_clien_addr *env_info_clien_addr_t, int storageNum_t)
{
	getEnv_select (storageNum_t, TEMPERATURE_MAX);
	env_info_clien_addr_t->storage_no[storageNum_t].temperatureMAX = callback_val[0];
	all_info_RT.storage_no[storageNum_t].temperatureMAX = callback_val[0];	
	getEnv_select (storageNum_t, TEMPERATURE_MIN);
	env_info_clien_addr_t->storage_no[storageNum_t].temperatureMIN = callback_val[0];
	all_info_RT.storage_no[storageNum_t].temperatureMIN = callback_val[0];
	getEnv_select (storageNum_t, HUMIDITY_MAX);
	env_info_clien_addr_t->storage_no[storageNum_t].humidityMAX = callback_val[0];
	all_info_RT.storage_no[storageNum_t].humidityMAX = callback_val[0];
	getEnv_select (storageNum_t, HUMIDITY_MIN);
	env_info_clien_addr_t->storage_no[storageNum_t].humidityMIN = callback_val[0];
	all_info_RT.storage_no[storageNum_t].humidityMIN = callback_val[0];
	getEnv_select (storageNum_t, ILLUMINATION_MAX);
	env_info_clien_addr_t->storage_no[storageNum_t].illuminationMAX = callback_val[0];
	all_info_RT.storage_no[storageNum_t].illuminationMAX = callback_val[0];
	getEnv_select (storageNum_t, ILLUMINATION_MIN);
	env_info_clien_addr_t->storage_no[storageNum_t].illuminationMIN = callback_val[0];
	all_info_RT.storage_no[storageNum_t].illuminationMIN = callback_val[0];
#if 0
	getEnv_select (TELEPHONE_NUM);
	strcpy(storage_info_t->telephoneNum, callback_str);
	getEnv_select (MODE);
	storage_info_t->mode = (int)callback_val[0];
	getEnv_select (IFNOCICE);
	storage_info_t->ifnocice = (int)callback_val[0];
	getEnv_select (INTERVAL);
	storage_info_t->interval = (int)callback_val[0];
	getEnv_select (UPDATE_PERIOD);
	storage_info_t->updatePeriod = (int)callback_val[0];
	getEnv_select (USER_NAME);
	strcpy(storage_info_t->username, callback_str);
	getEnv_select (PASSWORD);
	storage_info_t->password = (int)callback_val[0];
#endif
	return 0;
}

int getCollect_Current_env (int storage_num_t)
{
#if DEBUG_SQLITE
	printf ("getCollect_env ok\n");
#endif
	sqlite3 *db;
	char *err_msg = 0;
	int recode;
	recode = sqlite3_open (SQLITE_OPEN, &db);
	char sql[1024];

	sprintf (sql, "select * from collect_env where dev_no = %d order by envtime desc limit 1", storage_num_t);

	if (recode != SQLITE_OK)
	{
		printf ("Can't Open Database:%s!\n", sqlite3_errmsg(db));
		sqlite3_close (db);
		return 1;
	}
	else
	{
#if DEBUG_SQLITE
		printf ("open OK!\n");
#endif
		recode = sqlite3_exec (db, sql, callback_getenv, 0, &err_msg);
		if (recode != SQLITE_OK)
		{
			printf ("Error:%s", err_msg);
			sqlite3_close (db);
			return 1;
		}
		else
		{
#if DEBUG_SQLITE
			printf ("select collect_env OK!\n");
#endif
			sqlite3_close (db);
		}
		info_CGI.storage_no[storage_num_t].temperature = callback_val[1];
		info_CGI.storage_no[storage_num_t].humidity = callback_val[2];
		info_CGI.storage_no[storage_num_t].illumination = callback_val[3];
		strcpy(info_CGI.storage_no[storage_num_t].samplingTime, callback_str);
		
#if 1
		printf ("dev_no:%d  temperature = %0.1f\n", storage_num_t, info_CGI.storage_no[storage_num_t].temperature);
		printf ("dev_no:%d  humidity = %0.1f\n", storage_num_t, info_CGI.storage_no[storage_num_t].humidity);
		printf ("dev_no:%d  illumination = %0.1f\n", storage_num_t, info_CGI.storage_no[storage_num_t].illumination);
		printf ("dev_no:%d  time = %s\n", storage_num_t, info_CGI.storage_no[storage_num_t].samplingTime);
		printf ("-----------------------------\n");
#endif
	}

	return 0;
}

int getGoods (int storageNum_t, int goodsKinds_t)
{
#if DEBUG_SQLITE
	printf ("getGoods ok\n");
#endif
	sqlite3 *db;
	char *err_msg = 0;
	int recode;
	recode = sqlite3_open (SQLITE_OPEN, &db);
	char sql[1024];

	sprintf (sql, "select * from goods where dev_no = '%d' and goodsId = '%d';", storageNum_t, goodsKinds_t);

	if (recode != SQLITE_OK)
	{
		printf ("Can't Open Database:%s!\n", sqlite3_errmsg(db));
		sqlite3_close (db);
		return 1;
	}
	else
	{
#if DEBUG_SQLITE
		printf ("open OK!\n");
#endif
		recode = sqlite3_exec (db, sql, callback_getenv, 0, &err_msg);
		if (recode != SQLITE_OK)
		{
			printf ("Error:%s", err_msg);
			sqlite3_close (db);
			return 1;
		}
		else
		{
#if DEBUG_SQLITE
			printf ("select goods OK!\n");
#endif
			sqlite3_close (db);
		}
		info_CGI.storage_no[storageNum_t].goods_info[goodsKinds_t].goods_type = (int)callback_val[1];
		info_CGI.storage_no[storageNum_t].goods_info[goodsKinds_t].goods_count = (int)callback_val[2];

#if DEBUG_SQLITE 
		printf ("goods_s.goods_type = %d\n", info_CGI.storage_no[storageNum_t].goods_info[goodsKinds_t].goods_type);
		printf ("goods_s.goods_count = %d\n", info_CGI.storage_no[storageNum_t].goods_info[goodsKinds_t].goods_count);
		printf ("---------------------------------\n");
#endif
	}

	return 0;
}

int getCurrentGoods (int storageNum_t)  //获得指定编号货物信息
{
	flag_goods = 1;
#if DEBUG_SQLITE
	printf ("getGoods ok\n");
#endif
	sqlite3 *db;
	char *err_msg = 0;
	int recode;
	recode = sqlite3_open (SQLITE_OPEN, &db);
	char sql[1024];

	sprintf (sql, "select * from goods where dev_no = '%d'", storageNum_t);

	if (recode != SQLITE_OK)
	{
		printf ("Can't Open Database:%s!\n", sqlite3_errmsg(db));
		sqlite3_close (db);
		flag_goods = 0;
		return 1;
	}
	else
	{
#if DEBUG_SQLITE
		printf ("open OK!\n");
#endif
		recode = sqlite3_exec (db, sql, callback_getenv, 0, &err_msg);
		if (recode != SQLITE_OK)
		{
			printf ("Error:%s", err_msg);
			sqlite3_close (db);
			flag_goods = 0;
			return 1;
		}
		else
		{
#if DEBUG_SQLITE
			printf ("select goods OK!\n");
#endif
			sqlite3_close (db);
		}
	}
	flag_goods = 0;

	return 0;
}

int getAllGoods (void)
{
#if DEBUG_SQLITE
	printf ("getAllGoods ok\n");
#endif
	return 0;
}

int viewGoods (int storageNum_t, int goodsKinds_t)
{
#if DEBUG_SQLITE
	printf ("viewGoods ok\n");
#endif
	sqlite3 *db;
	char *err_msg = 0;
	int recode;
	recode = sqlite3_open (SQLITE_OPEN, &db);
	char sql[1024];

	sprintf (sql, "select * from goods where dev_no = '%d' and goodsId = '%d';", storageNum_t, goodsKinds_t);

	if (recode != SQLITE_OK)
	{
		printf ("Can't Open Database:%s!\n", sqlite3_errmsg(db));
		sqlite3_close (db);
		return 1;
	}
	else
	{
#if DEBUG_SQLITE
		printf ("open OK!\n");
#endif
		recode = sqlite3_exec (db, sql, callback_getenv, 0, &err_msg);
		if (recode != SQLITE_OK)
		{
			printf ("Error:%s", err_msg);
			sqlite3_close (db);
			return 1;
		}
		else
		{
#if DEBUG_SQLITE
			printf ("view goods OK!\n");
#endif
			sqlite3_close (db);
		}
	}

	return (int)callback_val[2];
}





