#include "linklist.h"

//初始化链表  返回头结点，可以让用户使用我的链表
struct LinkNode* init_LinkList()
{
	//创建头结点 在堆区
	struct LinkNode *  pHeader = malloc(sizeof(struct LinkNode));
	if (pHeader == NULL)
	{
		return NULL;
	}

	//pHeader->num;  头结点 不维护数据域
	pHeader->next = NULL; //指针域开始置空

	//让用户向链表中插入一些结点，如果输入的是-1，代表插入结束

	struct LinkNode * pTail = pHeader; //创建一个尾结点的指针，方便链表的尾插操作

	int val = -1;
	while (1)
	{

		printf("请输入数据，-1代表输入结束\n");
		scanf("%d", &val);
		if (val == -1)
		{
			break;
		}

		//创建新结点
		struct LinkNode * newNode = malloc(sizeof(struct LinkNode));
		newNode->num = val; //数据域是用户指定
		newNode->next = NULL;

		//更改指针的指向
		pTail->next = newNode;
		pTail = newNode;

	}

	return pHeader;
}

//遍历链表
void foreach_LinkList(struct LinkNode * pHeader)
{
	if (pHeader == NULL)
	{
		return;
	}

	//pCurrent指向第一个有真实数据的结点
	struct LinkNode * pCurrent = pHeader->next;

	while (pCurrent != NULL)
	{
		printf("%d\n", pCurrent->num);
		pCurrent = pCurrent->next;
	}

}


//插入链表
void insert_LinkList(struct LinkNode * pHeader, int oldVal, int newVal)
{
	if (pHeader == NULL)
	{
		return;
	}

	//创建两个辅助指针
	struct LinkNode * pPrev = pHeader;
	struct LinkNode * pCurrent = pHeader->next;

	while (pCurrent != NULL)
	{
		//如果pCurrent指针指向的数据 和 用户传入的oldVal一样，不需要移动辅助指针
		if (pCurrent->num == oldVal)
		{
			break;
		}

		//辅助指针移动
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}

	//创建新结点
	struct LinkNode * newNode = malloc(sizeof(struct LinkNode));
	newNode->num = newVal;
	newNode->next = NULL;

	//更改指针指向
	newNode->next = pCurrent;
	pPrev->next = newNode;

}


//删除链表
void delete_LinkList(struct LinkNode * pHeader, int delVal)
{
	if (pHeader == NULL)
	{
		return;
	}
	
	//创建两个辅助指针变量
	struct LinkNode * pPrev =  pHeader;
	struct LinkNode * pCurrent = pHeader->next;

	while ( pCurrent != NULL)
	{
		if (pCurrent->num == delVal) //找到了要删除数据
		{
			break;
		}
		//辅助指针向后移动
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}

	if (pCurrent == NULL) //未找到用户要删的数据
	{
		return;
	}

	//更新指针的指向
	pPrev->next = pCurrent->next;

	//释放掉待删除的结点
	free(pCurrent);
	pCurrent = NULL;


}


//清空链表
void clear_LinkList(struct LinkNode * pHeader)
{
	if (pHeader == NULL)
	{
		return;
	}

	//创建临时指针
	struct LinkNode * pCurrent = pHeader->next;

	while (pCurrent != NULL)
	{
		//先记录 下一个结点位置
		struct LinkNode * nextNode = pCurrent->next;

		//释放当前结点
		free(pCurrent);
		pCurrent = nextNode;
	}

	pHeader->next = NULL;

}


//销毁链表
void destroy_LinkList(struct LinkNode * pHeader)
{
	if (pHeader ==NULL)
	{
		return;
	}

	//先清空链表
	clear_LinkList(pHeader);

	//再释放头结点
	free(pHeader);
	pHeader = NULL;

}


//反转链表
void reverse_LinkList(struct LinkNode * pHeader)
{
	if (pHeader == NULL)
	{
		return;
	}

	//创建3个辅助指针
	struct LinkNode * pPrev = NULL;
	struct LinkNode * pCurrent = pHeader->next;
	struct LinkNode * pNext = NULL;

	while (pCurrent != NULL)
	{
		pNext = pCurrent->next;

		pCurrent->next = pPrev;

		pPrev = pCurrent;
		pCurrent = pNext;
	}

	pHeader->next = pPrev;

}


//统计链表长度
int size_LinkList(struct LinkNode * pHeader)
{
	if (pHeader == NULL)
	{
		return -1;
	}

	struct LinkNode * pCurrent = pHeader->next;

	int num = 0;

	while (pCurrent != NULL)
	{
		num++;
		pCurrent = pCurrent->next;
	}
	return num;
}