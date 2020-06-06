#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��ȡ�ļ�����
int getFileLines(FILE * fp)
{
	if (fp == NULL)
	{
		return -1;
	}

	char buf[1024] = { 0 };
	int lines = 0;

	while (fgets(buf,1024,fp) != NULL)
	{
		//printf("%s\n", buf);
		lines++;
	}

	//���ļ��������
	fseek(fp,0 , SEEK_SET);

	return lines;
}

//���ļ�������������
void readFileData(FILE * fp, int len , char ** pArray)
{
	if (fp == NULL)
	{
		return;
	}
	if (pArray == NULL)
	{
		return;
	}
	if (len <= 0)
	{
		return;
	}

	char buf[1024] = { 0 };
	int lines = 0;
	int index = 0;
	while (fgets(buf, 1024, fp) != NULL)
	{
		//buf���ж�ȡ������
		//aaaaaaaaaa\n
		int currentLen = strlen(buf) + 1;

		//��buf�����һ��Ԫ��ǿ�Ƹ�Ϊ\0
		buf[strlen(buf) - 1] = '\0';

		char * currentP = malloc(sizeof(char)*currentLen);
		//��buf�е����ݷ��뵽currentPָ��Ķ�����
		strcpy(currentP, buf);

		pArray[index++] = currentP;

		//��ջ�����
		memset(buf, 0, 1024);
	}


}

//��ӡ����
void showFileData(char ** pArray , int len)
{
	for (int i = 0; i < len;i++)
	{
		printf("%d�е�����Ϊ:%s\n", i + 1, pArray[i]);
	}

}

void freeSpace(char ** pArray, int len)
{

	//���ͷ��Ӷ������ݣ����ͷ�����
	for (int i = 0; i < len; i++)
	{
		if (pArray[i] != NULL)
		{
			printf("%s���ͷ���\n", pArray[i]);
			free(pArray[i]);
			pArray[i] = NULL;
		}
	}

	if (pArray != NULL)
	{
		free(pArray);
		pArray = NULL;
	}
}

void test01()
{

	FILE * fp = fopen("test.txt", "r");

	//ͳ���ļ�������
	int len = getFileLines(fp);

	//printf("�ļ�������Ϊ%d\n", len);

	//ά��һ�����飬�����ļ��е�����
	char ** pArray = malloc(sizeof(char *)*len);

	//��ȡ�ļ��е����ݣ����뵽������
	readFileData(fp, len, pArray);

	//��ʾ�����е�����
	showFileData(pArray, len);

	//�ͷŶ���
	freeSpace(pArray , len);
	
	pArray = NULL;

	//�ر��ļ�ָ��
	fclose(fp);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}