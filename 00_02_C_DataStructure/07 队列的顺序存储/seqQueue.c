#include "seqQueue.h"

//��ʼ������
seqQueue init_seqQueue()
{
	struct dynamicArray * arr = init_dynamicArray(MAX);

	return arr;
}
//���
void push_seqQueue(seqQueue queue, void * data)
{
	//���� -- β��
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
//����
void pop_seqQueue(seqQueue queue)
{
	//����  ͷɾ
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
//���ض�ͷ
void * front_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct dynamicArray * myQueue = queue;

	return myQueue->addr[0];

}
//���ض�β
void * back_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct dynamicArray * myQueue = queue;

	return myQueue->addr[myQueue->m_Size-1];
}
//���д�С
int size_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct dynamicArray * myQueue = queue;
	return myQueue->m_Size;
}

//�ж��Ƿ�Ϊ��
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

//���ٶ���
void destroy_seqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return;
	}

	struct dynamicArray * myQueue = queue;

	destroy_dynamicArray(myQueue);
}