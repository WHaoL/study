#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "config.h"


int main(){

	//�ļ���������ȡ

	int len = getFileLines("config.txt");
	printf("�ļ�������Ϊ��%d\n", len);

	struct ConfigInfo * arr = NULL;// malloc(sizeof(struct ConfigInfo) * 5);
	
	//�����ļ�
	parseFile("config.txt", len, &arr);

	//��֤  ����key��ȡvalue
	printf("Ӣ�۵�idΪ:%s\n", getValueByKey("heroId", arr , len));
	printf("Ӣ�۵�����Ϊ:%s\n", getValueByKey("heroName", arr, len));
	printf("Ӣ�۵Ĺ�����Ϊ:%s\n", getValueByKey("heroAtk", arr, len));
	printf("Ӣ�۵ķ�����Ϊ:%s\n", getValueByKey("heroDef", arr, len));
	printf("Ӣ�۵ļ��Ϊ:%s\n", getValueByKey("heroInfo", arr, len));


	//�ͷŶ�������
	freeSpace(arr);
	arr = NULL;



	system("pause");
	return EXIT_SUCCESS;
}