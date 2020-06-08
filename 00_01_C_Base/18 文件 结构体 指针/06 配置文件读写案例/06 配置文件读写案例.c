#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "config.h"


int main(){

	//文件的行数获取

	int len = getFileLines("config.txt");
	printf("文件的行数为：%d\n", len);

	struct ConfigInfo * arr = NULL;// malloc(sizeof(struct ConfigInfo) * 5);
	
	//解析文件
	parseFile("config.txt", len, &arr);

	//验证  根据key获取value
	printf("英雄的id为:%s\n", getValueByKey("heroId", arr , len));
	printf("英雄的姓名为:%s\n", getValueByKey("heroName", arr, len));
	printf("英雄的攻击力为:%s\n", getValueByKey("heroAtk", arr, len));
	printf("英雄的防御力为:%s\n", getValueByKey("heroDef", arr, len));
	printf("英雄的简介为:%s\n", getValueByKey("heroInfo", arr, len));


	//释放堆区数据
	freeSpace(arr);
	arr = NULL;



	system("pause");
	return EXIT_SUCCESS;
}