#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "linklist.h"


////���ṹ��
//struct LinkNode
//{
//	//ֻά��ָ����
//	struct LinkNode * next;
//};
//
////����ṹ��
//struct LList
//{
//	//����ͷ���
//	struct LinkNode pHeader;
//	//������
//	int m_Size; 
//};
//
//typedef void * LinkList;
//
//
////��ʼ������
//LinkList init_LinkList()
//{
//	struct LList * mylist = malloc(sizeof(struct LList));
//	if (mylist == NULL)
//	{
//		return NULL;
//	}
//
//	mylist->pHeader.next = NULL;
//	mylist->m_Size = 0;
//
//	return mylist;
//}
//
//
////��������
//void insert_LinkList(LinkList list,int pos , void * data)
//{
//	if (list == NULL)
//	{
//		return;
//	}
//	if (data == NULL)
//	{
//		return;
//	}
//	//��ԭ��ʵ�ṹ��
//	struct LList * mylist = list;
//	//��Чλ��β��
//	if (pos < 0 || pos >mylist->m_Size)
//	{
//		pos = mylist->m_Size;
//	}
//
//	//���û����� ǿתΪ struct LinkNode * 
//	struct LinkNode * myNode = data;
//
//
//	//�ҵ�����λ�õ�ǰ�����
//	struct LinkNode * pCurrent = &mylist->pHeader;
//
//	for (int i = 0; i < pos;i++)
//	{
//		pCurrent = pCurrent->next;
//	}
//	//��ʱ pCurrent���Ǵ�����λ�õ�ǰ�����
//
//	//���½���ϵ
//	myNode->next = pCurrent->next;
//	pCurrent->next = myNode;
//	//����������
//	mylist->m_Size++;
//}
//
////��������
//void foreach_LinkList(LinkList list ,void (*myPrint)(void *))
//{
//	if (list == NULL)
//	{
//		return;
//	}
//
//	struct LList * mylist = list;
//
//	struct LinkNode * pCurrent = mylist->pHeader.next; //ָ���һ������ʵ���ݵĽ��
//	for (int i = 0; i < mylist->m_Size;i++)
//	{
//		myPrint(pCurrent);
//		pCurrent = pCurrent->next;
//	}
//}
//
////ɾ������
//void removeByPos_LinkList(LinkList list, int pos)
//{
//	if (list == NULL)
//	{
//		return;
//	}
//	struct LList * mylist = list;
//	if (pos < 0 || pos >  mylist->m_Size - 1)
//	{
//		return;
//	}
//
//	//��������ָ�����
//	struct LinkNode * pCurrent = &mylist->pHeader;
//
//	for (int i = 0; i < pos;i++)
//	{
//		pCurrent = pCurrent->next;
//	}
//
//	//pCurrent���Ǵ�ɾ������ǰ�����
//
//
//	//��¼��ɾ�����λ��
//	struct LinkNode * pDel = pCurrent->next;
//
//	//���½���ϵ
//	pCurrent->next = pDel->next;
//
//	//free(pDel); //error  �������û����ٵģ����ǲ��ù����ͷ�
//
//	//����������
//	mylist->m_Size--;
//}
//
////��������
//void destroy_LinkList(LinkList list)
//{
//	if (list == NULL)
//	{
//		return;
//	}
//	free(list);
//	list = NULL;
//}





//��������
struct Person
{
	//struct LinkNode node;
	void * node; 
	char name[64];
	int age;
};

void printPerson(void * data)
{
	struct Person * p = data;
	printf("������%s ����:%d\n", p->name, p->age);
}

void test01()
{
	//��ʼ������
	LinkList list = init_LinkList();

	//׼������
	struct Person p1 = { NULL,"aaa", 10 };  //alt + shift
	struct Person p2 = { NULL,"bbb", 20 };
	struct Person p3 = { NULL,"ccc", 30 };
	struct Person p4 = { NULL,"ddd", 40 };
	struct Person p5 = { NULL,"eee", 50 };

	//��������
	insert_LinkList(list, 0, &p1);
	insert_LinkList(list, 0, &p2);
	insert_LinkList(list, 1, &p3);
	insert_LinkList(list, -1, &p4);
	insert_LinkList(list, 1, &p5);

	//��������
	//bbb eee ccc aaa ddd
	foreach_LinkList(list, printPerson);

	//����ɾ��  aaa
	removeByPos_LinkList(list, 3);
	printf("ɾ��aaa��ı������Ϊ\n");
	foreach_LinkList(list, printPerson);

	//��������
	destroy_LinkList(list);

	//�ṩ��ֵɾ�������������ȡ��������
}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}