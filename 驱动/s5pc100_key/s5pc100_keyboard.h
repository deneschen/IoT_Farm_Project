#define KEY_BUFFER_SIZE 32 
typedef struct
{
    unsigned int key_values[KEY_BUFFER_SIZE];	//按键时间，如果读按键时间小于5秒种的作废
    unsigned long jiffies[KEY_BUFFER_SIZE];		//按键缓冲区
    int head;									//按键缓冲区的头
    int tail;									//按键缓冲区的尾
}KEY_BUFFER;
