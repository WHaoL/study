#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	//����Ӱ����
	//10 ~ 9  ����
	//8 ~ 7  �ǳ���
	//6 ~ 5  һ��
	//5����   ��Ƭ

	int score = 0;
	printf("�����Ӱ��֣�\n");

	scanf("%d", &score);
	printf("�����ķ����ǣ�%d\n", score);

	switch (score) //switch�еı��ʽ���ͣ�ֻ�������ͻ����ַ���
	{
	case 10:
		//printf("����\n");
		//break;  //����break������֧
	case  9:
		printf("����\n");
		break;
	case  8:
		//printf("�ǳ���\n");
		//break;
	case  7:
		printf("�ǳ���\n");
		break;
	case  6:
		//printf("һ��\n");
		//break;
	case  5:
		printf("һ��\n");
		break;
	default: //Ĭ�ϵķ�֧
		printf("��Ƭ\n");
		break;
	}
	//�ܽ᣺��if���Ƚϣ����ڶ������ж�ʱ��switch�ṹ�Ƚ�������ִ��Ч�ʸߣ� ȱ���ж����䲻����
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}