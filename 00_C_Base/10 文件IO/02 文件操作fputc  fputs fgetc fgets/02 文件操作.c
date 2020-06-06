#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//fopen
void test01()
{
	//����ֻ���ķ�ʽ �� test.txt�ļ�
	FILE * fp = fopen("test.txt", "r");

	if (fp == NULL)
	{
		printf("�ļ���ȡʧ��\n");
		return;
	}

	printf("�ļ��򿪳ɹ�\n");

	//�ļ��ر�
	fclose(fp);
}

//2�����ַ��ӷ�ʽ ���ļ���д
//fputc ���ַ���ʽд
void test02()
{
	//1�����ļ�
	FILE * fp = fopen("test2.txt", "w"); //wֻд   13
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n"); 
		return;
	}

	//2��д�ļ�
	char buf[] = "hello world\n";

	int  i = 0;
	while (buf[i]!= '\0')
	{
		//���ַ�д
		fputc(buf[i], fp);
		i++;
	}

	//3���ر��ļ�
	fclose(fp);
}


void test03()
{
	//1�����ļ�
	FILE * fp = fopen("test3.txt", "wb"); //wbֻд  ������д    12
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	//2��д�ļ�
	char buf[] = "hello world\n";

	int  i = 0;
	while (buf[i] != '\0')
	{
		//���ַ�д
		fputc(buf[i], fp);
		i++;
	}

	//3���ر��ļ�
	fclose(fp);
}

//���ļ�  fgetc ���ַ��ķ�ʽ���ļ�
void test04()
{
	//1�����ļ�
	FILE * fp = fopen("test2.txt", "r");

	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	//2�����ļ�
	char ch;

	//ch = fgetc(fp);
	//printf("%c\n", ch);  //��ȡһ���ַ�

	while (  (ch= fgetc(fp) ) != EOF  )   // EOF ��־  �ļ�������־   end of file
	{
		printf("%c", ch);
	}

	//3���ر��ļ�
	fclose(fp);

}

//�Ӽ��̻�ȡ�û��������ݣ����ұ��浽�ļ���
//���û����� :quit �����������
void test05()
{
	FILE * fp = fopen("test5.txt", "w");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	while (1)
	{
		char buf[1024] = { 0 };
		fgets(buf, sizeof(buf), stdin);

		//����û�����������ǲ��� :quit
		if (strncmp(buf,":quit",5) == 0)
		{
			break;
		}

		//���û���������ݣ�д�뵽�ļ���
		int  i = 0; 
		while (buf[i] != '\0')
		{
			fputc(buf[i++], fp);
		}
	}

	fclose(fp);
}


int main(){
	test05();


	system("pause");
	return EXIT_SUCCESS;
}