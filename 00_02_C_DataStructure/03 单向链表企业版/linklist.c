#include "linklist.h"
//结点结构体
struct LinkNode
{
	//只维护指针域
	struct LinkNode * next;
};

//链表结构体
struct LList
{
	//链表头结点
	struct LinkNode pHeader;
	//链表长度
	int m_Size;
};

typedef void * LinkList;


//初始化链表
LinkList init_LinkList()
{
	struct LList * mylist = malloc(sizeof(struct LList));
	if (mylist == NULL)
	{
		return NULL;
	}

	mylist->pHeader.next = NULL;
	mylist->m_Size = 0;

	return mylist;
}


//插入链表
void insert_LinkList(LinkList list, int pos, void * data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	//还原真实结构体
	struct LList * mylist = list;
	//无效位置尾插
	if (pos < 0 || pos >mylist->m_Size)
	{
		pos = mylist->m_Size;
	}

	//将用户数据 强转为 struct LinkNode * 
	struct LinkNode * myNode = data;


	//找到插入位置的前驱结点
	struct LinkNode * pCurrent = &mylist->pHeader;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//此时 pCurrent就是待插入位置的前驱结点

	//更新结点关系
	myNode->next = pCurrent->next;
	pCurrent->next = myNode;
	//更新链表长度
	mylist->m_Size++;
}

//遍历链表
void foreach_LinkList(LinkList list, void(*myPrint)(void *))
{
	if (list == NULL)
	{
		return;
	}

	struct LList * mylist = list;

	struct LinkNode * pCurrent = mylist->pHeader.next; //指向第一个有真实数据的结点
	for (int i = 0; i < mylist->m_Size; i++)
	{
		myPrint(pCurrent);
		pCurrent = pCurrent->next;
	}
}

//删除链表
void removeByPos_LinkList(LinkList list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	struct LList * mylist = list;
	if (pos < 0 || pos >  mylist->m_Size - 1)
	{
		return;
	}

	//创建辅助指针变量
	struct LinkNode * pCurrent = &mylist->pHeader;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//pCurrent就是待删除结点的前驱结点


	//记录待删除结点位置
	struct LinkNode * pDel = pCurrent->next;

	//更新结点关系
	pCurrent->next = pDel->next;

	//free(pDel); //error  数据是用户开辟的，我们不用管理释放

	//更新链表长度
	mylist->m_Size--;
}

//销毁链表
void destroy_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}
	free(list);
	list = NULL;
}
