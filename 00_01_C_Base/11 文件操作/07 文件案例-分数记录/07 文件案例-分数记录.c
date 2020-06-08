#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int fileIsEmpty; //ȫ�ֱ�������־�ļ��Ƿ�Ϊ�� ���Ϊ�� 1   ��Ϊ�� 0

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

//1������¼�¼
void setScore()
{
	printf("�������¼�¼\n");

	double score = 0;
	scanf("%lf", &score);

	FILE * fp = fopen("score.txt", "a+");

	fprintf(fp, "%lf\n", score);

	fclose(fp);
	printf("��¼�Ѿ�����\n");
	fileIsEmpty = 0; //�ļ���Ϊ��

	system("pause");
	system("cls");
}

//2����ʾ�����¼����
void showScore()
{
	if (fileIsEmpty)
	{
		printf("�ļ���¼Ϊ��\n");
		system("pause");
		system("cls");
		return;
	}


	FILE * fp = fopen("score.txt", "r");

	int i = 1;
	while (!feof(fp))
	{
		double score;
		int ret = fscanf(fp, "%lf\n", &score); //����ֵ����ɹ�ת���ĸ����������-1����ת��ʧ��
		if (ret == -1)
		{
			break;
		}
		printf("%d��ķ���Ϊ:%lf\n",i,score);
		i++;
	}


	fclose(fp);
	system("pause");
	system("cls");
}

//3 ����ļ�
void clearFile()
{
	if (fileIsEmpty)
	{
		printf("�ļ���¼Ϊ��\n");
		system("pause");
		system("cls");
		return;
	}

	printf("�Ƿ�ȷ�����?\n");
	printf("1��ȷ��\n");
	printf("2��ȡ��\n");

	int select = 0;
	scanf("%d", &select);

	if (select == 1)
	{
		//ȷ�����
		FILE * fp = fopen("score.txt", "w");
		fclose(fp);
		fileIsEmpty = 1;
		printf("������\n");
	}

	system("pause");
	system("cls");
}

void showMenu()
{
	printf("******************************************\n");
	printf("************** ��ӭʹ�ó��� **************\n");
	printf("************** 1������µļ�¼ ***********\n");
	printf("************** 2���鿴�����¼ ***********\n");
	printf("************** 3����������¼ ***********\n");
	printf("************** 4���˳���ǰ���� ***********\n");
	printf("******************************************\n");
}

int main(){

	//��ʼ�� ��¼�Ƿ�Ϊ��  �ı�־
	initFlag();

	int choice = 0;  //��¼�û���ѡ��

	while (1)
	{
		showMenu();
		printf("����������ѡ��:\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1: // 1������µļ�¼
			setScore();
			break;
		case 2:  //2���鿴�����¼
			showScore();
			break;
		case 3:  //3����������¼
			clearFile();
			break;
		case 4:  //4���˳���ǰ����
			printf("��ӭ�´�ʹ��\n");
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