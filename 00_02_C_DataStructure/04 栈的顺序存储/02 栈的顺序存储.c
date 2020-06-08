#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "seqStack.h"

////ջ�Ľṹ��
//struct SStack
//{
//	void * data[MAX]; //ջ�ڲ���ʵ�Ľṹ
//	int m_Size; //ջ�Ĵ�С
//};
//
//typedef void * SeqStack;
//
////��ʼ��
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
////��ջ
//void push_SeqStack(SeqStack stack, void * data)
//{
//	//���� --- β��
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
//	//β��
//	myStack->data[myStack->m_Size] = data;
//	//����ջ��С
//	myStack->m_Size++;
//}
//
////��ջ
//void pop_SeqStack(SeqStack stack)
//{
//	//����  --- βɾ
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
//	//����ջ��С
//	myStack->m_Size--;
//
//}
//
////����ջ��
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
////���ش�С
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
////�ж��Ƿ�Ϊ��
//int isEmpty_SeqStack(SeqStack stack)
//{
//	if (stack == NULL)
//	{
//		return -1; //��
//	}
//	struct SStack * myStack = stack;
//
//	if ( myStack->m_Size == 0) //ջΪ��
//	{
//		return 1; 
//	}
//
//	return 0; //ջ�ǿ�
//}
//
////����
//void destroy_SeqStack(SeqStack stack)
//{
//	if (stack != NULL)
//	{
//		free(stack);
//		stack = NULL;
//	}
//}
//




//����ջ
struct Person
{
	char name[64];
	int age;
};


int main(){

	//��ʼ��ջ
	SeqStack stack = init_SeqStack();

	//׼������
	struct Person p1 = {  "aaa", 10 }; 
	struct Person p2 = {  "bbb", 20 };
	struct Person p3 = {  "ccc", 30 };
	struct Person p4 = {  "ddd", 40 };
	struct Person p5 = {  "eee", 50 };

	//��ջ
	push_SeqStack(stack, &p1);
	push_SeqStack(stack, &p2);
	push_SeqStack(stack, &p3);
	push_SeqStack(stack, &p4);
	push_SeqStack(stack, &p5);

	//ջ�Ĵ�С
	printf("ջ�Ĵ�СΪ%d\n", size_SeqStack(stack));

	//�鿴ջ��Ԫ�� ����ִ�г�ջ
	while ( isEmpty_SeqStack(stack ) == 0) //ջ�ǿ� ��ȥִ����������
	{
		struct Person * pTop = top_SeqStack(stack);
		printf("ջ��Ԫ�� ����:%s ���䣺%d\n", pTop->name, pTop->age);

		pop_SeqStack(stack);
	}

	printf("ջ�Ĵ�СΪ%d\n", size_SeqStack(stack));

	//����ջ
	destroy_SeqStack(stack);

	system("pause");
	return EXIT_SUCCESS;
}