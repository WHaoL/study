#include "linklist.h"

//��ʼ������  ����ͷ��㣬�������û�ʹ���ҵ�����
struct LinkNode* init_LinkList()
{
	//����ͷ��� �ڶ���
	struct LinkNode *  pHeader = malloc(sizeof(struct LinkNode));
	if (pHeader == NULL)
	{
		return NULL;
	}

	//pHeader->num;  ͷ��� ��ά��������
	pHeader->next = NULL; //ָ����ʼ�ÿ�

	//���û��������в���һЩ��㣬����������-1������������

	struct LinkNode * pTail = pHeader; //����һ��β����ָ�룬���������β�����

	int val = -1;
	while (1)
	{

		printf("���������ݣ�-1�����������\n");
		scanf("%d", &val);
		if (val == -1)
		{
			break;
		}

		//�����½��
		struct LinkNode * newNode = malloc(sizeof(struct LinkNode));
		newNode->num = val; //���������û�ָ��
		newNode->next = NULL;

		//����ָ���ָ��
		pTail->next = newNode;
		pTail = newNode;

	}

	return pHeader;
}

//��������
void foreach_LinkList(struct LinkNode * pHeader)
{
	if (pHeader == NULL)
	{
		return;
	}

	//pCurrentָ���һ������ʵ���ݵĽ��
	struct LinkNode * pCurrent = pHeader->next;

	while (pCurrent != NULL)
	{
		printf("%d\n", pCurrent->num);
		pCurrent = pCurrent->next;
	}

}


//��������
void insert_LinkList(struct LinkNode * pHeader, int oldVal, int newVal)
{
	if (pHeader == NULL)
	{
		return;
	}

	//������������ָ��
	struct LinkNode * pPrev = pHeader;
	struct LinkNode * pCurrent = pHeader->next;

	while (pCurrent != NULL)
	{
		//���pCurrentָ��ָ������� �� �û������oldValһ��������Ҫ�ƶ�����ָ��
		if (pCurrent->num == oldVal)
		{
			break;
		}

		//����ָ���ƶ�
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}

	//�����½��
	struct LinkNode * newNode = malloc(sizeof(struct LinkNode));
	newNode->num = newVal;
	newNode->next = NULL;

	//����ָ��ָ��
	newNode->next = pCurrent;
	pPrev->next = newNode;

}


//ɾ������
void delete_LinkList(struct LinkNode * pHeader, int delVal)
{
	if (pHeader == NULL)
	{
		return;
	}
	
	//������������ָ�����
	struct LinkNode * pPrev =  pHeader;
	struct LinkNode * pCurrent = pHeader->next;

	while ( pCurrent != NULL)
	{
		if (pCurrent->num == delVal) //�ҵ���Ҫɾ������
		{
			break;
		}
		//����ָ������ƶ�
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}

	if (pCurrent == NULL) //δ�ҵ��û�Ҫɾ������
	{
		return;
	}

	//����ָ���ָ��
	pPrev->next = pCurrent->next;

	//�ͷŵ���ɾ���Ľ��
	free(pCurrent);
	pCurrent = NULL;


}


//�������
void clear_LinkList(struct LinkNode * pHeader)
{
	if (pHeader == NULL)
	{
		return;
	}

	//������ʱָ��
	struct LinkNode * pCurrent = pHeader->next;

	while (pCurrent != NULL)
	{
		//�ȼ�¼ ��һ�����λ��
		struct LinkNode * nextNode = pCurrent->next;

		//�ͷŵ�ǰ���
		free(pCurrent);
		pCurrent = nextNode;
	}

	pHeader->next = NULL;

}


//��������
void destroy_LinkList(struct LinkNode * pHeader)
{
	if (pHeader ==NULL)
	{
		return;
	}

	//���������
	clear_LinkList(pHeader);

	//���ͷ�ͷ���
	free(pHeader);
	pHeader = NULL;

}


//��ת����
void reverse_LinkList(struct LinkNode * pHeader)
{
	if (pHeader == NULL)
	{
		return;
	}

	//����3������ָ��
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


//ͳ��������
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