#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//stdin
void test01()
{
	int num = 0;
	printf("�����¸�num��ֵ\n");

	fclose(stdin); //�ر��豸�ļ�  ����

	scanf("%d", &num);
	printf("num = %d\n", num);
}

//stdout
void test02()
{
	printf("hello world1\n");
	printf("hello world2\n");
	printf("hello world3\n");

	//fclose(stdout); //�ر��豸�ļ�  ��Ļ

	

	FILE * fp = fopen("aa.txt", "r");
	if (fp == NULL)
	{
		perror("�ļ���ʧ��");
		//return;
	}


	fclose(stderr);

	perror("�ļ���ʧ��");
	
	printf("hello world4\n");
	printf("hello world5\n");
}

int main(){
	test02();


	system("pause");
	return EXIT_SUCCESS;
}