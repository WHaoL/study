#include "linkQueue.h"

//初始化队列
LinkQueue init_LinkQueue()
{
	struct LQueue * myQueue = malloc(sizeof(struct LQueue));

	if (myQueue == NULL)
	{
		return NULL;
	}

	myQueue->m_Size = 0;
	myQueue->pHeader.next = NULL;
	myQueue->pTail = &myQueue->pHeader;

	return myQueue;
}

//入队
void push_LinkQueue(LinkQueue queue, void * data)
{
	//本质 尾插
	if (queue == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	//将用户数据的前4个字节取出
	struct LinkNode * myNode = data;

	//还原真实结构体
	struct LQueue * myQueue = queue;

	//更新指针的指向
	myQueue->pTail->next = myNode;

	myNode->next = NULL;

	myQueue->pTail = myNode;

	//更新队列大小
	myQueue->m_Size++;

}
//出队
void pop_LinkQueue(LinkQueue queue)
{
	//本质  头删
	if (queue == NULL)
	{
		return;
	}
	struct LQueue * myQueue = queue;
	if (myQueue->m_Size == 0)
	{
		return;
	}

	if (myQueue->m_Size==1)
	{
		myQueue->pHeader.next = NULL;
		myQueue->pTail = &myQueue->pHeader;
		myQueue->m_Size = 0;
		return;
	}

	//记录第一个结点
	struct LinkNode * pFirst = myQueue->pHeader.next;

	//更新指针的指向
	myQueue->pHeader.next = pFirst->next;

	//队列大小更新
	myQueue->m_Size--;
}
//返回队头
void * front_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct LQueue * myQueue = queue;
	return myQueue->pHeader.next;
}
//返回队尾
void * back_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct LQueue * myQueue = queue;
	return myQueue->pTail;
}
//返回队列大小
int size_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct LQueue * myQueue = queue;
	return myQueue->m_Size;
}
//判断是否为空
int isEmpty_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct LQueue * myQueue = queue;
	if ( myQueue->m_Size == 0)
	{
		return 1;
	}

	return 0;
}
//销毁队列
void destroy_LinkQueue(LinkQueue queue)
{
	if (queue!=NULL)
	{
		free(queue);
		queue = NULL;
	}
}