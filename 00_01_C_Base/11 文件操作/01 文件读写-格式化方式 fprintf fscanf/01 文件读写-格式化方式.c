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

//fprintf  格式化方式 写文件
void test01()
{
	struct Hero heros[5] = 
	{
		{"刘备",100,100},
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

	for (int i = 0; i < sizeof(heros) / sizeof(struct Hero) ;i++)
	{
		int len = fprintf(fp, "[姓名]%s [攻击力]%d [防御力]%d\n", heros[i].name, heros[i].atk, heros[i].def);
		printf("len = %d\n", len);
	}


	//关闭文件指针
	fclose(fp);
}

//读文件 fscanf
void test02()
{
	struct Hero heros[5];

	FILE * fp = fopen("test1.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		return;
	}

	int i = 0;
	while (!feof(fp)) //如果没有读到文件尾，开始读取
	{
		fscanf(fp, "[姓名]%s [攻击力]%d [防御力]%d\n", heros[i].name, &heros[i].atk, &heros[i].def);
		i++;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("姓名:%s 攻击力:%d 防御力:%d\n", heros[i].name, heros[i].atk, heros[i].def);
	}

	//关闭文件指针
	fclose(fp);

}

int main(){

	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}