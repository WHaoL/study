#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/***********************************************************************************/
/*
	线性表的链式存储-用- -设计和实现
*/
//结点结构体
struct LinkNode
{
	//数据域
	void * data;

	//指针域
	struct LinkNode * next;
};

//链表的结构体
struct LList
{
	struct LinkNode pHeader; //头结点

	int m_Size; //链表长度
};

//给用户使用的是void * 
typedef void * LinkList;


//初始化链表
LinkList init_LinkList()
{
	//开辟内存
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

//插入链表
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
	//无效位置 强制尾插
	struct LList * mylist = list;
	if (pos < 0 || pos > mylist->m_Size)
	{
		pos = mylist->m_Size;
	}

	//插入数据
	struct LinkNode * pCurrent = &mylist->pHeader;
	//找到待插入位置的前驱结点的位置
	for (int i = 0; i < pos;i++)
	{
		pCurrent = pCurrent->next;
	}

	//创建新结点
	struct LinkNode * newNode = malloc(sizeof(struct LinkNode));
	newNode->data = data;
	newNode->next = NULL;

	//更改指针的指向
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	//更新链表长度
	mylist->m_Size++;
}

//遍历链表
void foreach_LinkList(LinkList list , void(*myPrint)(void*))
{
	if (list == NULL)
	{
		return;
	}
	//还原链表真实结构体
	struct LList * mylist = list;

	//pCurrent指向第一个有真实数据的结点
	struct LinkNode * pCurrent = mylist->pHeader.next;

	for (int i = 0; i < mylist->m_Size;i++)
	{
		myPrint(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}


//删除  按位置删除
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

	//找到待删除结点的前驱结点
	struct LinkNode * pCurrent = &mylist->pHeader;

	for (int i = 0; i < pos;i++)
	{
		pCurrent = pCurrent->next;
	}

	//先记录待删除结点的位置
	struct LinkNode * pDel = pCurrent->next;

	//重新建立结点关系
	pCurrent->next = pDel->next;
	//释放待删除结点
	free(pDel);
	pDel = NULL;

	//更新链表长度
	mylist->m_Size--;
}


//删除  按值删
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

	//还原真实链表结构体
	struct LList * mylist = list;

	//创建两个辅助指针
	struct LinkNode * pPrev = &mylist->pHeader;
	struct LinkNode * pCurrent = mylist->pHeader.next;

	for (int i = 0; i < mylist->m_Size;i++)
	{
		//判断用户删除的结点是否是当前遍历的结点
		//if (data == pCurrent->data)
		if (myCompare(data,pCurrent->data))
		{
			//pCurrent就是要删除的结点
			//更新结点关系
			pPrev->next = pCurrent->next;
			//是否待删除结点
			free(pCurrent);
			pCurrent = NULL;
			//更新链表长度
			mylist->m_Size--;
			break;
		}

		//辅助指针向后移动
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
}

//清空链表
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
		//先记录下一个结点的位置
		struct LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}

	mylist->pHeader.next = NULL;
	mylist->m_Size = 0;
}

//返回链表长度
int size_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return -1;
	}

	struct LList * mylist = list;

	return mylist->m_Size;
}
//销毁链表
void destroy_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	//先清空
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
	printf("姓名:%s  年龄：%d\n", p->name, p->age);
}

int comparePerson(void * data1, void * data2)
{
	struct Person * p1 = data1;
	struct Person * p2 = data2;

	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

//测试链表
void test01()
{
	//初始化链表
	LinkList list = init_LinkList();

	//插入数据
	struct Person p1 = { "刘备", 19 };
	struct Person p2 = { "妲己", 20 };
	struct Person p3 = { "鲁班", 18 };
	struct Person p4 = { "张飞", 22 };
	struct Person p5 = { "虞姬", 21 };
	struct Person p6 = { "甄姬", 23 };

	insert_LinkList(list, 0, &p1);
	insert_LinkList(list, 0, &p2);
	insert_LinkList(list, 1, &p3);
	insert_LinkList(list, 1, &p4);
	insert_LinkList(list, -1, &p5);
	insert_LinkList(list, 2, &p6);

	//遍历链表
	//妲己 张飞  甄姬 鲁班 刘备 虞姬
	foreach_LinkList(list, printPerson);
	printf("链表的长度为：%d\n", size_LinkList(list));

	//删除 按位置删除 刘备
	removeByPos_LinkList(list, 4);
	printf("----------------------------\n");
	printf("删除刘备后遍历的结果为\n");
	foreach_LinkList(list, printPerson);
	printf("链表的长度为：%d\n", size_LinkList(list));

	//删除 按值删除
	struct Person p = { "张飞", 22 };
	removeByValue_LinkList(list, &p, comparePerson);
	printf("----------------------------\n");
	printf("删除张飞后遍历的结果为\n");
	foreach_LinkList(list, printPerson);
	printf("链表的长度为：%d\n", size_LinkList(list));

	//清空链表
	clear_LinkList(list);
	printf("----------------------------\n");
	printf("清空链表后遍历的结果为\n");
	foreach_LinkList(list, printPerson);
	printf("链表的长度为：%d\n", size_LinkList(list));

	//销毁链表
	destroy_LinkList(list);
}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}