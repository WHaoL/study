#pragma  once 
#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//������Ϣ�Ľṹ��
struct ConfigInfo
{
	char key[64];  //������key
	char value[64];  //����key������valueֵ
};

//��ȡ�ļ�����
int getFileLines(char * fileName);

//�ж��ַ����Ƿ�����Ч��
int isValidLine(char * buf);

//�����ļ�
void parseFile(char * fileName, int lines, struct ConfigInfo ** configInfo);

//����key��ȡvalue
char * getValueByKey(char * key, struct ConfigInfo * configInfo, int len);

//�ͷŶ���
void freeSpace(struct ConfigInfo * configInfo);