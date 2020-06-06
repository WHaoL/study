#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��̬����

//���ṹ�����
struct LinkNode
{
	//������
	int num;
	//ָ����
	struct LinkNode * next;
};

void test01()
{
	//�������
	struct LinkNode node1 = { 10, NULL };
	struct LinkNode node2 = { 20, NULL };
	struct LinkNode node3 = { 30, NULL };
	struct LinkNode node4 = { 40, NULL };
	struct LinkNode node5 = { 50, NULL };

	//�������֮��Ĺ�ϵ
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	//��α����������
	//ͨ��һ����ʱ��ָ�� �ӵ�һ����㿪ʼ�������ݣ���ƫ��
	struct LinkNode * pCurrent = &node1;

	while (pCurrent != NULL)
	{
		printf("%d\n", pCurrent->num);

		pCurrent = pCurrent->next;
	}
}



//��̬����
void test02()
{
	//�������
	struct LinkNode *  node1 = malloc(sizeof(struct LinkNode));
	node1->num = 100;
	struct LinkNode *  node2 = malloc(sizeof(struct LinkNode));
	node2->num = 200;
	struct LinkNode *  node3 = malloc(sizeof(struct LinkNode));
	node3->num = 300;
	struct LinkNode *  node4 = malloc(sizeof(struct LinkNode));
	node4->num = 400;
	struct LinkNode *  node5 = malloc(sizeof(struct LinkNode));
	node5->num = 500;

	//�������֮��Ĺ�ϵ
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;

	//��������
	struct LinkNode * pCurrent = node1;
	while (pCurrent != NULL)
	{
		printf("%d\n", pCurrent->num);
		pCurrent = pCurrent->next;
	}

	//�ͷ�
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}