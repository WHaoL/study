#include "linkQueue.h"

//��ʼ������
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

//���
void push_LinkQueue(LinkQueue queue, void * data)
{
	//���� β��
	if (queue == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	//���û����ݵ�ǰ4���ֽ�ȡ��
	struct LinkNode * myNode = data;

	//��ԭ��ʵ�ṹ��
	struct LQueue * myQueue = queue;

	//����ָ���ָ��
	myQueue->pTail->next = myNode;

	myNode->next = NULL;

	myQueue->pTail = myNode;

	//���¶��д�С
	myQueue->m_Size++;

}
//����
void pop_LinkQueue(LinkQueue queue)
{
	//����  ͷɾ
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

	//��¼��һ�����
	struct LinkNode * pFirst = myQueue->pHeader.next;

	//����ָ���ָ��
	myQueue->pHeader.next = pFirst->next;

	//���д�С����
	myQueue->m_Size--;
}
//���ض�ͷ
void * front_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct LQueue * myQueue = queue;
	return myQueue->pHeader.next;
}
//���ض�β
void * back_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct LQueue * myQueue = queue;
	return myQueue->pTail;
}
//���ض��д�С
int size_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct LQueue * myQueue = queue;
	return myQueue->m_Size;
}
//�ж��Ƿ�Ϊ��
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
//���ٶ���
void destroy_LinkQueue(LinkQueue queue)
{
	if (queue!=NULL)
	{
		free(queue);
		queue = NULL;
	}
}