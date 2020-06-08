#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "seqStack.h"

////栈的结构体
//struct SStack
//{
//	void * data[MAX]; //栈内部真实的结构
//	int m_Size; //栈的大小
//};
//
//typedef void * SeqStack;
//
////初始化
//SeqStack init_SeqStack()
//{
//	struct SStack * myStack = malloc(sizeof(struct SStack));
//
//	if (myStack == NULL)
//	{
//		return NULL;
//	}
//
//	myStack->m_Size = 0;
//	//for (int i = 0; i < 1024;i++)
//	//{
//	//	myStack->data[i] = NULL;
//	//}
//	memset(myStack->data, 0, sizeof(void*)* MAX);
//
//	return myStack;
//}
//
//
////入栈
//void push_SeqStack(SeqStack stack, void * data)
//{
//	//本质 --- 尾插
//	if ( stack == NULL)
//	{
//		return;
//	}
//	if (data == NULL)
//	{
//		return;
//	}
//
//	struct SStack * myStack = stack;
//
//	if (myStack->m_Size == MAX)
//	{
//		return;
//	}
//
//	//尾插
//	myStack->data[myStack->m_Size] = data;
//	//更新栈大小
//	myStack->m_Size++;
//}
//
////出栈
//void pop_SeqStack(SeqStack stack)
//{
//	//本质  --- 尾删
//	if (stack == NULL)
//	{
//		return;
//	}
//	struct SStack * myStack = stack;
//
//	if (myStack->m_Size == 0)
//	{
//		return;
//	}
//
//	myStack->data[myStack->m_Size - 1] = NULL;
//
//	//更新栈大小
//	myStack->m_Size--;
//
//}
//
////返回栈顶
//void * top_SeqStack(SeqStack stack)
//{
//	if (stack == NULL)
//	{
//		return NULL;
//	}
//	struct SStack * myStack = stack;
//
//	if (myStack->m_Size == 0)
//	{
//		return NULL;
//	}
//	return myStack->data[myStack->m_Size - 1];
//}
//
////返回大小
//int size_SeqStack(SeqStack stack)
//{
//	if (stack == NULL)
//	{
//		return -1;
//	}
//	struct SStack * myStack = stack;
//
//	return myStack->m_Size;
//}
//
////判断是否为空
//int isEmpty_SeqStack(SeqStack stack)
//{
//	if (stack == NULL)
//	{
//		return -1; //真
//	}
//	struct SStack * myStack = stack;
//
//	if ( myStack->m_Size == 0) //栈为空
//	{
//		return 1; 
//	}
//
//	return 0; //栈非空
//}
//
////销毁
//void destroy_SeqStack(SeqStack stack)
//{
//	if (stack != NULL)
//	{
//		free(stack);
//		stack = NULL;
//	}
//}
//




//测试栈
struct Person
{
	char name[64];
	int age;
};


int main(){

	//初始化栈
	SeqStack stack = init_SeqStack();

	//准备数据
	struct Person p1 = {  "aaa", 10 }; 
	struct Person p2 = {  "bbb", 20 };
	struct Person p3 = {  "ccc", 30 };
	struct Person p4 = {  "ddd", 40 };
	struct Person p5 = {  "eee", 50 };

	//入栈
	push_SeqStack(stack, &p1);
	push_SeqStack(stack, &p2);
	push_SeqStack(stack, &p3);
	push_SeqStack(stack, &p4);
	push_SeqStack(stack, &p5);

	//栈的大小
	printf("栈的大小为%d\n", size_SeqStack(stack));

	//查看栈顶元素 并且执行出栈
	while ( isEmpty_SeqStack(stack ) == 0) //栈非空 才去执行上述操作
	{
		struct Person * pTop = top_SeqStack(stack);
		printf("栈顶元素 姓名:%s 年龄：%d\n", pTop->name, pTop->age);

		pop_SeqStack(stack);
	}

	printf("栈的大小为%d\n", size_SeqStack(stack));

	//销毁栈
	destroy_SeqStack(stack);

	system("pause");
	return EXIT_SUCCESS;
}