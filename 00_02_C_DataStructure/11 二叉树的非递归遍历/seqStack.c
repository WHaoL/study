#include "seqStack.h"


//初始化
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


//入栈
void push_SeqStack(SeqStack stack, void * data)
{
	//本质 --- 尾插
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

	//尾插
	myStack->data[myStack->m_Size] = data;
	//更新栈大小
	myStack->m_Size++;
}

//出栈
void pop_SeqStack(SeqStack stack)
{
	//本质  --- 尾删
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

	//更新栈大小
	myStack->m_Size--;

}

//返回栈顶
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

//返回大小
int size_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct SStack * myStack = stack;

	return myStack->m_Size;
}

//判断是否为空
int isEmpty_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return -1; //真
	}
	struct SStack * myStack = stack;

	if (myStack->m_Size == 0) //栈为空
	{
		return 1;
	}

	return 0; //栈非空
}

//销毁
void destroy_SeqStack(SeqStack stack)
{
	if (stack != NULL)
	{
		free(stack);
		stack = NULL;
	}
}



