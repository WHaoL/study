#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Hero
{
	char name[64];  //姓名
	int atk;  //攻击力
	int def;  //防御力
};

//写文件  fwrite
void test01()
{
	struct Hero heros[5] =
	{
		{ "刘备", 100, 100 },
		{ "关羽", 99, 80 },
		{ "张飞", 98, 95 },
		{ "赵云", 99, 120 },
		{ "吕布", 120, 120 },
	};

	FILE * fp = fopen("test1.txt", "w");
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		return;
	}

	//按块写文件
	//for (int i = 0; i < 5;i++)
	//{
	//	fwrite(&heros[i], sizeof(struct Hero), 1, fp);
	//}

	//参数1  写入数据的首地址 参数2  块大小  参数3  块个数    参数4 文件指针
	fwrite(heros, sizeof(struct Hero), 5, fp);

	fclose(fp);
}

//读文件 fread
void test02()
{
	struct Hero heros[5];
	memset(heros, 0, sizeof(heros));


	FILE * fp = fopen("test1.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		return;
	}

	//参数1  读取数据的首地址 参数2  块大小  参数3  块个数    参数4 文件指针
	fread(heros, sizeof(struct Hero), 5, fp);

	for (int  i = 0; i < 5; i++)
	{
		printf("姓名: %s 攻击力: %d  防御力 :%d\n", heros[i].name, heros[i].atk, heros[i].def);
	}

	fclose(fp);
}

int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}