#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//���ַ���ʽ�� test.txt
void test01()
{
	FILE * fp= fopen("test.txt", "r");

	if (fp == NULL)
	{
		return;
	}

	char ch;

	while (!feof(fp))
	{
		//feof�����ͺ���
		ch = fgetc(fp);

		if (feof(fp))
		{
			break;
		}

		printf("%c", ch);
	}

	//while (  (ch = fgetc(fp))  != EOF )
	//{
	//	printf("%c",ch);
	//}


	fclose(fp);
}


//ע������2 
struct Person
{
	char * name; //���������ָ���������ôЩ�ļ�ʱ��Ҫ��ָ��ָ�������д�룬������ָ��
	int age;
};

int main(){

	test01();

	//printf(" aaaa\n");
	//printf("%caaaa\n",EOF);

	system("pause");
	return EXIT_SUCCESS;
}