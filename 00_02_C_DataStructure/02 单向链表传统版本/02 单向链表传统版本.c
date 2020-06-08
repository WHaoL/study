#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/***********************************************************************************/
/*
	���Ա����ʽ�洢-��- -��ƺ�ʵ��
*/
//���ṹ��
struct LinkNode
{
	//������
	void * data;

	//ָ����
	struct LinkNode * next;
};

//����Ľṹ��
struct LList
{
	struct LinkNode pHeader; //ͷ���

	int m_Size; //������
};

//���û�ʹ�õ���void * 
typedef void * LinkList;


//��ʼ������
LinkList init_LinkList()
{
	//�����ڴ�
	struct LList * mylist = malloc(sizeof(struct LList));
	if (mylist == NULL)
	{
		return NULL;
	}

	mylist->pHeader.data = NULL;
	mylist->pHeader.next = NULL;
	mylist->m_Size = 0;

	return mylist;
}

//��������
void insert_LinkList(LinkList list,int pos , void * data )
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	//��Чλ�� ǿ��β��
	struct LList * mylist = list;
	if (pos < 0 || pos > mylist->m_Size)
	{
		pos = mylist->m_Size;
	}

	//��������
	struct LinkNode * pCurrent = &mylist->pHeader;
	//�ҵ�������λ�õ�ǰ������λ��
	for (int i = 0; i < pos;i++)
	{
		pCurrent = pCurrent->next;
	}

	//�����½��
	struct LinkNode * newNode = malloc(sizeof(struct LinkNode));
	newNode->data = data;
	newNode->next = NULL;

	//����ָ���ָ��
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	//����������
	mylist->m_Size++;
}

//��������
void foreach_LinkList(LinkList list , void(*myPrint)(void*))
{
	if (list == NULL)
	{
		return;
	}
	//��ԭ������ʵ�ṹ��
	struct LList * mylist = list;

	//pCurrentָ���һ������ʵ���ݵĽ��
	struct LinkNode * pCurrent = mylist->pHeader.next;

	for (int i = 0; i < mylist->m_Size;i++)
	{
		myPrint(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}


//ɾ��  ��λ��ɾ��
void removeByPos_LinkList(LinkList list ,int pos)
{
	if (list == NULL)
	{
		return;
	}

	struct LList * mylist = list;

	if (pos < 0 || pos >  mylist->m_Size- 1)
	{
		return;
	}

	//�ҵ���ɾ������ǰ�����
	struct LinkNode * pCurrent = &mylist->pHeader;

	for (int i = 0; i < pos;i++)
	{
		pCurrent = pCurrent->next;
	}

	//�ȼ�¼��ɾ������λ��
	struct LinkNode * pDel = pCurrent->next;

	//���½�������ϵ
	pCurrent->next = pDel->next;
	//�ͷŴ�ɾ�����
	free(pDel);
	pDel = NULL;

	//����������
	mylist->m_Size--;
}


//ɾ��  ��ֵɾ
void removeByValue_LinkList(LinkList list , void * data , int (*myCompare)(void * ,void* ))
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	//��ԭ��ʵ����ṹ��
	struct LList * mylist = list;

	//������������ָ��
	struct LinkNode * pPrev = &mylist->pHeader;
	struct LinkNode * pCurrent = mylist->pHeader.next;

	for (int i = 0; i < mylist->m_Size;i++)
	{
		//�ж��û�ɾ���Ľ���Ƿ��ǵ�ǰ�����Ľ��
		//if (data == pCurrent->data)
		if (myCompare(data,pCurrent->data))
		{
			//pCurrent����Ҫɾ���Ľ��
			//���½���ϵ
			pPrev->next = pCurrent->next;
			//�Ƿ��ɾ�����
			free(pCurrent);
			pCurrent = NULL;
			//����������
			mylist->m_Size--;
			break;
		}

		//����ָ������ƶ�
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
}

//�������
void clear_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	struct LList * mylist = list;

	struct LinkNode * pCurrent = mylist->pHeader.next;
	for (int i = 0; i < mylist->m_Size;i++)
	{
		//�ȼ�¼��һ������λ��
		struct LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}

	mylist->pHeader.next = NULL;
	mylist->m_Size = 0;
}

//����������
int size_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return -1;
	}

	struct LList * mylist = list;

	return mylist->m_Size;
}
//��������
void destroy_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	//�����
	clear_LinkList(list);

	free(list);
	list = NULL;

}




struct Person
{
	char name[64];
	int age;
};

void printPerson(void * data)
{
	struct Person * p = data;
	printf("����:%s  ���䣺%d\n", p->name, p->age);
}

int comparePerson(void * data1, void * data2)
{
	struct Person * p1 = data1;
	struct Person * p2 = data2;

	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

//��������
void test01()
{
	//��ʼ������
	LinkList list = init_LinkList();

	//��������
	struct Person p1 = { "����", 19 };
	struct Person p2 = { "槼�", 20 };
	struct Person p3 = { "³��", 18 };
	struct Person p4 = { "�ŷ�", 22 };
	struct Person p5 = { "�ݼ�", 21 };
	struct Person p6 = { "�缧", 23 };

	insert_LinkList(list, 0, &p1);
	insert_LinkList(list, 0, &p2);
	insert_LinkList(list, 1, &p3);
	insert_LinkList(list, 1, &p4);
	insert_LinkList(list, -1, &p5);
	insert_LinkList(list, 2, &p6);

	//��������
	//槼� �ŷ�  �缧 ³�� ���� �ݼ�
	foreach_LinkList(list, printPerson);
	printf("����ĳ���Ϊ��%d\n", size_LinkList(list));

	//ɾ�� ��λ��ɾ�� ����
	removeByPos_LinkList(list, 4);
	printf("----------------------------\n");
	printf("ɾ������������Ľ��Ϊ\n");
	foreach_LinkList(list, printPerson);
	printf("����ĳ���Ϊ��%d\n", size_LinkList(list));

	//ɾ�� ��ֵɾ��
	struct Person p = { "�ŷ�", 22 };
	removeByValue_LinkList(list, &p, comparePerson);
	printf("----------------------------\n");
	printf("ɾ���ŷɺ�����Ľ��Ϊ\n");
	foreach_LinkList(list, printPerson);
	printf("����ĳ���Ϊ��%d\n", size_LinkList(list));

	//�������
	clear_LinkList(list);
	printf("----------------------------\n");
	printf("������������Ľ��Ϊ\n");
	foreach_LinkList(list, printPerson);
	printf("����ĳ���Ϊ��%d\n", size_LinkList(list));

	//��������
	destroy_LinkList(list);
}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}