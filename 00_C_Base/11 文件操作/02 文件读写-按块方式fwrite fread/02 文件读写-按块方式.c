#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Hero
{
	char name[64];  //����
	int atk;  //������
	int def;  //������
};

//д�ļ�  fwrite
void test01()
{
	struct Hero heros[5] =
	{
		{ "����", 100, 100 },
		{ "����", 99, 80 },
		{ "�ŷ�", 98, 95 },
		{ "����", 99, 120 },
		{ "����", 120, 120 },
	};

	FILE * fp = fopen("test1.txt", "w");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	//����д�ļ�
	//for (int i = 0; i < 5;i++)
	//{
	//	fwrite(&heros[i], sizeof(struct Hero), 1, fp);
	//}

	//����1  д�����ݵ��׵�ַ ����2  ���С  ����3  �����    ����4 �ļ�ָ��
	fwrite(heros, sizeof(struct Hero), 5, fp);

	fclose(fp);
}

//���ļ� fread
void test02()
{
	struct Hero heros[5];
	memset(heros, 0, sizeof(heros));


	FILE * fp = fopen("test1.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	//����1  ��ȡ���ݵ��׵�ַ ����2  ���С  ����3  �����    ����4 �ļ�ָ��
	fread(heros, sizeof(struct Hero), 5, fp);

	for (int  i = 0; i < 5; i++)
	{
		printf("����: %s ������: %d  ������ :%d\n", heros[i].name, heros[i].atk, heros[i].def);
	}

	fclose(fp);
}

int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}