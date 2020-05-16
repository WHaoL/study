#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int fileIsEmpty; //全局变量，标志文件是否为空 如果为空 1   不为空 0

void initFlag()
{
	FILE * fp = fopen("score.txt", "r");

	if (fp == NULL)
	{
		fileIsEmpty = 1;
		return;
	}
	char ch;
	ch = fgetc(fp);
	if (ch == EOF)
	{
		fileIsEmpty = 1;
	}
	else
	{
		fileIsEmpty = 0;
	}
	fclose(fp);
}

//1、添加新记录
void setScore()
{
	printf("请输入新记录\n");

	double score = 0;
	scanf("%lf", &score);

	FILE * fp = fopen("score.txt", "a+");

	fprintf(fp, "%lf\n", score);

	fclose(fp);
	printf("记录已经生成\n");
	fileIsEmpty = 0; //文件不为空

	system("pause");
	system("cls");
}

//2、显示往届记录分数
void showScore()
{
	if (fileIsEmpty)
	{
		printf("文件记录为空\n");
		system("pause");
		system("cls");
		return;
	}


	FILE * fp = fopen("score.txt", "r");

	int i = 1;
	while (!feof(fp))
	{
		double score;
		int ret = fscanf(fp, "%lf\n", &score); //返回值代表成功转换的个数，如果是-1代表转换失败
		if (ret == -1)
		{
			break;
		}
		printf("%d届的分数为:%lf\n",i,score);
		i++;
	}


	fclose(fp);
	system("pause");
	system("cls");
}

//3 清空文件
void clearFile()
{
	if (fileIsEmpty)
	{
		printf("文件记录为空\n");
		system("pause");
		system("cls");
		return;
	}

	printf("是否确定清空?\n");
	printf("1、确定\n");
	printf("2、取消\n");

	int select = 0;
	scanf("%d", &select);

	if (select == 1)
	{
		//确定清空
		FILE * fp = fopen("score.txt", "w");
		fclose(fp);
		fileIsEmpty = 1;
		printf("清空完毕\n");
	}

	system("pause");
	system("cls");
}

void showMenu()
{
	printf("******************************************\n");
	printf("************** 欢迎使用程序 **************\n");
	printf("************** 1、添加新的记录 ***********\n");
	printf("************** 2、查看往届记录 ***********\n");
	printf("************** 3、清空往届记录 ***********\n");
	printf("************** 4、退出当前程序 ***********\n");
	printf("******************************************\n");
}

int main(){

	//初始化 记录是否为空  的标志
	initFlag();

	int choice = 0;  //记录用户的选择

	while (1)
	{
		showMenu();
		printf("请输入您的选择:\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1: // 1、添加新的记录
			setScore();
			break;
		case 2:  //2、查看往届记录
			showScore();
			break;
		case 3:  //3、清空往届记录
			clearFile();
			break;
		case 4:  //4、退出当前程序
			printf("欢迎下次使用\n");
			system("pause");
			exit(0);
			break;
		default:
			system("cls");
			break;
		}
	}

	


	system("pause");
	return EXIT_SUCCESS;
}