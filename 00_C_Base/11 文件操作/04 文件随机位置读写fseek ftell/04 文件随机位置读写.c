#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//fseek 
void test01()
{
	FILE * fp = fopen("test.txt", "w+");

	fputs("hello world", fp);

#if 0
	fclose(fp);

	fp =fopen("test.txt", "r");
#else 

	char buf[64] = { 0 };

	//fseek(fp, 0, SEEK_SET); //从文件起始位置 偏移0个字节
	//fseek(fp, -11 , SEEK_END);
	//rewind(fp); //将文件光标设置到文件开始位置

	fseek(fp, -5, SEEK_CUR);  //word

	fgets(buf, sizeof(buf), fp);

	printf("buf = %s\n", buf);

	fclose(fp);

#endif
	

}

//获取文件光标读写位置 ftell
void test02()
{
	FILE * fp = fopen("test.txt", "r");

	//将文件光标设置到文件尾
	fseek(fp, 0, SEEK_END);
	if (fp == NULL)
	{
		printf("打开失败\n");
		return;
	}

	int len = ftell(fp);
	printf("len = %d\n",len); //11

	//将hello world读取出来，并且放入到堆区
	char * p = malloc(len + 1); //多开辟1个 放\0
	memset(p, 0, len + 1);

	rewind(fp); //将文件光标 置首
	fread(p, len, 1, fp); //按块读取
	//打印字符串
	printf("%s\n", p);

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	fclose(fp);

}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}