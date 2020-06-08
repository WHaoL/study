#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "linklist.h"

void test01()
{
	//��ʼ������
	struct LinkNode * pHeader = init_LinkList();

	//��������
	printf("��������Ľ��Ϊ��\n");

	foreach_LinkList(pHeader);

	//��������
	insert_LinkList(pHeader, 20, 100);
	insert_LinkList(pHeader, 1000, 200);

	printf("���������Ľ��Ϊ��\n");
	//  10  100 20 30 200
	foreach_LinkList(pHeader);


	//ɾ�� 30
	//10 100 20 200

	delete_LinkList(pHeader, 30);
	delete_LinkList(pHeader, 300);
	printf("ɾ��30���ݺ�ı������Ϊ��\n");
	foreach_LinkList(pHeader);


	//�������  ��պ������ǿ��Ը��õ�
	clear_LinkList(pHeader);

	printf("��������ı������Ϊ��\n");
	clear_LinkList(pHeader);

	insert_LinkList(pHeader, 111, 111);
	insert_LinkList(pHeader, 222, 222);
	insert_LinkList(pHeader, 333, 333);

	foreach_LinkList(pHeader);


	//��������  ��������
	destroy_LinkList(pHeader);
	//printf("���������ı������Ϊ��\n");
	//foreach_LinkList(pHeader); error ��Ϊ�����Ѿ������٣�������ʹ��
}


void test02()
{
	struct LinkNode * pHeader = init_LinkList();

	printf("����תǰ������\n");
	foreach_LinkList(pHeader);


	printf("����ת�������\n");
	//��ת
	reverse_LinkList(pHeader);
	foreach_LinkList(pHeader);

	//ͳ�������� 
	int num = size_LinkList(pHeader);
	printf("����ĳ���Ϊ��%d\n", num);

	//����
	destroy_LinkList(pHeader);

}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}