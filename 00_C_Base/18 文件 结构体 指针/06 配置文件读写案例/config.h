#pragma  once 
#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//配置信息的结构体
struct ConfigInfo
{
	char key[64];  //索引的key
	char value[64];  //根据key索引的value值
};

//获取文件行数
int getFileLines(char * fileName);

//判断字符串是否是有效行
int isValidLine(char * buf);

//解析文件
void parseFile(char * fileName, int lines, struct ConfigInfo ** configInfo);

//根据key获取value
char * getValueByKey(char * key, struct ConfigInfo * configInfo, int len);

//释放堆区
void freeSpace(struct ConfigInfo * configInfo);