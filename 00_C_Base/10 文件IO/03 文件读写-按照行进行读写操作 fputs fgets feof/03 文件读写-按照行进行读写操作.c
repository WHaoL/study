#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//写文件  fputs
void test01()
{
	FILE * fp = fopen("test1.txt", "w");
	if (fp == NULL)
	{
		printf("打开失败\n");
		return;
	}

	char *buf[] = { "床前明月光\n", "疑是地上霜\n", "举头望明月\n", "低头思故乡\n" };

	for (int i = 0; i < sizeof(buf)/sizeof(char*); i++)
	{
		//按行写文件
		fputs(buf[i], fp);
	}

	fclose(fp);
}

void test02()
{
	FILE * fp = fopen("test1.txt", "r");
	if (fp == NULL)
	{
		printf("打开失败\n");
		return;
	}

#if 0
	printf("第一个版本\n");
	char buf[1024] = {0};

	//feof() 返回值是int，如果为真，代表读取到文件尾，假没有到文件尾
	while (!feof(fp)) //如果没有读取到文件尾，执行循环
	{
		char * ret = fgets(buf, sizeof(buf), fp);

		if (ret != NULL)
		{
			//将读取到的信息中的\n 改为 \0
			buf[strlen(buf) - 1] = '\0';
			printf("%s\n", buf);
		}
		else
		{
			break;
		}

	}
#else
	printf("第二个版本\n");
	char buf[1024] = {0};

	while (fgets(buf, sizeof(buf), fp)) //如果返回的是NULL，代表读取完毕
	{
		buf[strlen(buf) - 1] = '\0';
		printf("%s\n", buf);
	}

#endif

	fclose(fp);
}

int main(){
	test02();


	system("pause");
	return EXIT_SUCCESS;
}