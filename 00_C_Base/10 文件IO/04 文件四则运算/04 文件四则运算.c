#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

//�ļ���ÿһ�е�������һ����������ı��ʽ
//������   1 + 1 = 
//����1 �� дһ���������Զ���50����Ŀ���������� 1 ~ 100֮�䣬�����Ϊ  + - * / ���  15 ~ 20 minʵ��

//����2 �� ��дһ�������������е���Ŀ���������50��Ĵ𰸣� ������  1 + 1 = 2

//���⺯��
void setQuestion()
{
	//1��׼������  ��� ������ 
	int num1 = 0;
	int num2 = 0;
	char ch = 0;

	char oper[] = { '+', '-', '*', '/' };

	//2�����ļ�  д�ķ�ʽ��
	FILE * fp = fopen("test.txt", "w");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	//3��׼��д����ַ���  
	// 3.1 �����  1 ~ 100 
	// 3.2 �ַ�  ���+ - * /
	// 3.3 ��׼�����ַ��� ƴ�ӵ�һ��    1 + 1 =

	for (int i = 0; i < 50;i++)
	{
		num1 = rand() % 100 + 1;  // 1 ~ 100
		num2 = rand() % 100 + 1;  // 1 ~ 100
		ch = oper[rand() % 4];    // 0 ~ 3

		char buf[128] = { 0 };

		sprintf(buf, "%d %c %d =\n",num1,ch,num2);

		//printf("%s\n", buf);
		//4�� fputs д�뵽�ļ���
		fputs(buf, fp);

	}

	//5���ر��ļ� 
	fclose(fp);

	printf("50����Ŀ�������\n");
}

//��������
void answerQuestion()
{
	FILE * fp1 = fopen("test.txt", "r");
	FILE * fp2 = fopen("test2.txt", "w");

	if ( fp1 == NULL || fp2 == NULL )
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	char buf[1024] = { 0 };

	while (fgets(buf, sizeof(buf), fp1))
	{
		int num1 = 0;
		int num2 = 0;
		char ch = 0;
		//printf("%s", buf);  // 50 + 7 = 

		//���ݲ��
		sscanf(buf, "%d %c %d =", &num1, &ch, &num2);
		//printf("num1 = %d\n", num1);
		//printf("num2 = %d\n", num2);
		//printf("ch = %c\n", ch);
		int ret = 0;

		switch (ch)
		{
		case '+':
			ret = num1 + num2;
			break;
		case '-':
			ret = num1 - num2;
			break;
		case '*':
			ret = num1 * num2;
			break;
		case '/':
			ret = num1 / num2;
			break;
		default:
			break;
		}

		//�������װ��һ���ַ��� ��д�뵽�ļ���
		char str[128] = { 0 };
		sprintf(str, "%d %c %d = %d\n", num1, ch, num2, ret);

		fputs(str, fp2);
	}

	fclose(fp1);
	fclose(fp2);

	printf("50����Ŀ������\n");

}


int main(){
	//���������
	srand((unsigned int)time(NULL));

	//setQuestion();

	answerQuestion();

	system("pause");
	return EXIT_SUCCESS;
}