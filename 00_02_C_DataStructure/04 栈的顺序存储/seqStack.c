#include "seqStack.h"


//��ʼ��
SeqStack init_SeqStack()
{
	struct SStack * myStack = malloc(sizeof(struct SStack));

	if (myStack == NULL)
	{
		return NULL;
	}

	myStack->m_Size = 0;
	//for (int i = 0; i < 1024;i++)
	//{
	//	myStack->data[i] = NULL;
	//}
	memset(myStack->data, 0, sizeof(void*)* MAX);

	return myStack;
}


//��ջ
void push_SeqStack(SeqStack stack, void * data)
{
	//���� --- β��
	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct SStack * myStack = stack;

	if (myStack->m_Size == MAX)
	{
		return;
	}

	//β��
	myStack->data[myStack->m_Size] = data;
	//����ջ��С
	myStack->m_Size++;
}

//��ջ
void pop_SeqStack(SeqStack stack)
{
	//����  --- βɾ
	if (stack == NULL)
	{
		return;
	}
	struct SStack * myStack = stack;

	if (myStack->m_Size == 0)
	{
		return;
	}

	myStack->data[myStack->m_Size - 1] = NULL;

	//����ջ��С
	myStack->m_Size--;

}

//����ջ��
void * top_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	struct SStack * myStack = stack;

	if (myStack->m_Size == 0)
	{
		return NULL;
	}
	return myStack->data[myStack->m_Size - 1];
}

//���ش�С
int size_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct SStack * myStack = stack;

	return myStack->m_Size;
}

//�ж��Ƿ�Ϊ��
int isEmpty_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return -1; //��
	}
	struct SStack * myStack = stack;

	if (myStack->m_Size == 0) //ջΪ��
	{
		return 1;
	}

	return 0; //ջ�ǿ�
}

//����
void destroy_SeqStack(SeqStack stack)
{
	if (stack != NULL)
	{
		free(stack);
		stack = NULL;
	}
}



