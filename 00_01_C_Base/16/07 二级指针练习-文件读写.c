#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//获取文件行数
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

	//将文件光标置首
	fseek(fp,0 , SEEK_SET);

	return lines;
}

//读文件，放入数组中
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
		//buf中有读取的数据
		//aaaaaaaaaa\n
		int currentLen = strlen(buf) + 1;

		//将buf中最后一个元素强制改为\0
		buf[strlen(buf) - 1] = '\0';

		char * currentP = malloc(sizeof(char)*currentLen);
		//将buf中的数据放入到currentP指向的堆区中
		strcpy(currentP, buf);

		pArray[index++] = currentP;

		//清空缓冲区
		memset(buf, 0, 1024);
	}


}

//打印数组
void showFileData(char ** pArray , int len)
{
	for (int i = 0; i < len;i++)
	{
		printf("%d行的数据为:%s\n", i + 1, pArray[i]);
	}

}

void freeSpace(char ** pArray, int len)
{

	//先释放子堆区数据，在释放数组
	for (int i = 0; i < len; i++)
	{
		if (pArray[i] != NULL)
		{
			printf("%s被释放了\n", pArray[i]);
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

	//统计文件的行数
	int len = getFileLines(fp);

	//printf("文件的行数为%d\n", len);

	//维护一个数组，保存文件中的数据
	char ** pArray = malloc(sizeof(char *)*len);

	//读取文件中的数据，放入到数组中
	readFileData(fp, len, pArray);

	//显示数组中的数据
	showFileData(pArray, len);

	//释放堆区
	freeSpace(pArray , len);
	
	pArray = NULL;

	//关闭文件指针
	fclose(fp);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}