#ifndef __DATA_GLOBAL__
#define __DATA_GLOBAL__

#define STORAGE_NO		2
#define GOODSKINDS_1	2
#define GOODSKINDS_2	3
#define GOODSKINDS_3	4
#define GOODSKINDS_4	5
#define GOODSKINDS_5	6
#define GOODSKINDS_6	7
#define GOODSKINDS_7	9

#define STORAGE_NUM		4
#define GOODS_NUM		7


#define SQLITE_OPEN		"../warehouse.db"


char *no_to_name (char **name, int no);

struct storage_goods_info
{
	unsigned char goods_type;
	unsigned int goods_count;
};

struct storage_info
{
	unsigned char storage_status;  // 0:open 1:close
	unsigned char led_status;
	unsigned char buzzer_status;
	unsigned char fan_status;
	unsigned char seg_status;
	signed char x;
	signed char y;
	signed char z;
	char samplingTime[20];
	float temperature;
	float temperatureMIN;
	float temperatureMAX;
	float humidity;
	float humidityMIN;
	float humidityMAX;
	float illumination;
	float illuminationMIN;
	float illuminationMAX;
	float battery;
	float adc;
	float adcMIN;
	struct storage_goods_info goods_info[GOODS_NUM];
};

struct env_info_clien_addr
{
	struct storage_info storage_no[STORAGE_NUM];	
};

struct sqlite_operation
{
	int table_select_mask;
	int env_operation_mask;
	int table_operation_mask;
	int goods_operation_mask;
};


struct env_info_clien_addr info_CGI;
struct env_info_clien_addr all_info_RT;;


#endif
