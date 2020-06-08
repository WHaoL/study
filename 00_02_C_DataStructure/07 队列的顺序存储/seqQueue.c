#include "seqQueue.h"

//初始化队列
seqQueue init_seqQueue()
{
	struct dynamicArray * arr = init_dynamicArray(MAX);

	return arr;
}
//入队
void push_seqQueue(seqQueue queue, void * data)
{
	//本质 -- 尾插
	if (queue == NULL)
	{
		return;
	}
	if (data==NULL)
	{
		return;
	}
	struct dynamicArray * myQueue = queue;

	if (myQueue->m_Size == MAX)
	{
		return;
	}

	insert_dynamicArray(myQueue, myQueue->m_Size, data);

}
//出队
void pop_seqQueue(seqQueue queue)
{
	//本质  头删
	if (queue == NULL)
	{
		return;
	}
	struct dynamicArray * myQueue = queue;

	if (myQueue->m_Size == 0)
	{
		return;
	}

	removeByPos_dynamicArray(myQueue, 0);
}
//返回队头
void * front_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct dynamicArray * myQueue = queue;

	return myQueue->addr[0];

}
//返回队尾
void * back_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct dynamicArray * myQueue = queue;

	return myQueue->addr[myQueue->m_Size-1];
}
//队列大小
int size_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct dynamicArray * myQueue = queue;
	return myQueue->m_Size;
}

//判断是否为空
int isEmpty_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct dynamicArray * myQueue = queue;
	if (myQueue->m_Size == 0)
	{
		return 1;
	}
	return 0;
}

//销毁队列
void destroy_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return;
	}

	struct dynamicArray * myQueue = queue;

	destroy_dynamicArray(myQueue);
}