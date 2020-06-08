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

//fprintf  ��ʽ����ʽ д�ļ�
void test01()
{
	struct Hero heros[5] = 
	{
		{"����",100,100},
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

	for (int i = 0; i < sizeof(heros) / sizeof(struct Hero) ;i++)
	{
		int len = fprintf(fp, "[����]%s [������]%d [������]%d\n", heros[i].name, heros[i].atk, heros[i].def);
		printf("len = %d\n", len);
	}


	//�ر��ļ�ָ��
	fclose(fp);
}

//���ļ� fscanf
void test02()
{
	struct Hero heros[5];

	FILE * fp = fopen("test1.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	int i = 0;
	while (!feof(fp)) //���û�ж����ļ�β����ʼ��ȡ
	{
		fscanf(fp, "[����]%s [������]%d [������]%d\n", heros[i].name, &heros[i].atk, &heros[i].def);
		i++;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("����:%s ������:%d ������:%d\n", heros[i].name, heros[i].atk, heros[i].def);
	}

	//�ر��ļ�ָ��
	fclose(fp);

}

int main(){

	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}