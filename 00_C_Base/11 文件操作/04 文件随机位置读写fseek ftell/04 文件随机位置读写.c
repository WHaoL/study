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

	//fseek(fp, 0, SEEK_SET); //���ļ���ʼλ�� ƫ��0���ֽ�
	//fseek(fp, -11 , SEEK_END);
	//rewind(fp); //���ļ�������õ��ļ���ʼλ��

	fseek(fp, -5, SEEK_CUR);  //word

	fgets(buf, sizeof(buf), fp);

	printf("buf = %s\n", buf);

	fclose(fp);

#endif
	

}

//��ȡ�ļ�����дλ�� ftell
void test02()
{
	FILE * fp = fopen("test.txt", "r");

	//���ļ�������õ��ļ�β
	fseek(fp, 0, SEEK_END);
	if (fp == NULL)
	{
		printf("��ʧ��\n");
		return;
	}

	int len = ftell(fp);
	printf("len = %d\n",len); //11

	//��hello world��ȡ���������ҷ��뵽����
	char * p = malloc(len + 1); //�࿪��1�� ��\0
	memset(p, 0, len + 1);

	rewind(fp); //���ļ���� ����
	fread(p, len, 1, fp); //�����ȡ
	//��ӡ�ַ���
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