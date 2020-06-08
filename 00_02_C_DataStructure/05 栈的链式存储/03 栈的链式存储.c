#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//���ṹ��
struct LinkNode
{
	struct LinkNode * next;
};

//ջ�Ľṹ��
struct LStack
{
	struct LinkNode pHeader;
	int m_Size;
};

typedef void * LinkStack;

//��ʼ��ջ
LinkStack init_LinkStack()
{
   struct LStack  * myStack	= malloc(sizeof(struct LStack));

   if (myStack == NULL)
   {
	   return NULL;
   }

   myStack->m_Size = 0;
   myStack->pHeader.next = NULL;

   return myStack;
}

//��ջ
void push_LinkStack(LinkStack stack, void * data)
{
	//���� -- ͷ��
	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	//ȡ���û��������ݵ�ǰ4���ֽڣ�����ʹ��
	struct LinkNode * myNode = data;

	//��ԭ��ʵ�ṹ��
	struct LStack * myStack = stack;

	//����ָ��ָ��
	myNode->next = myStack->pHeader.next;
	myStack->pHeader.next = myNode;

	//����ջ��С
	myStack->m_Size++;

}

//��ջ
void pop_LinkStack(LinkStack stack)
{
	//��ջ����   ͷɾ

	if (stack == NULL)
	{
		return;
	}

	struct LStack * myStack = stack;

	if (myStack->m_Size == 0)
	{
		return;
	}

	//��¼��һ�����λ��
	struct LinkNode * pFirst = myStack->pHeader.next;

	//����ָ���ָ��
	myStack->pHeader.next = pFirst->next;

	//����ջ��С
	myStack->m_Size--;

}

//����ջ��
void * top_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return NULL;
	}

	struct LStack * myStack = stack;

	if (myStack->m_Size == 0)
	{
		return NULL;
	}

	return myStack->pHeader.next;
}

//����ջ��С
int size_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	struct LStack * myStack = stack;

	return myStack->m_Size;

}

//�ж��Ƿ�Ϊ��
int isEmpty_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1; //-1������  ��ջ
	}

	struct LStack * myStack = stack;

	if (myStack->m_Size == 0)
	{
		return 1;//0��Ԫ�� Ҳ�ǿ�ջ ������
	}

	return 0;//ջ�ǿ� ���ؼ�
}

//����
void destroy_LinkStack(LinkStack stack)
{
	if (stack != NULL)
	{
		free(stack);
		stack = NULL;
	}
}



//����
struct Person
{
	void * node;
	char name[64];
	int age;
};


int main(){

	//��ʼ��ջ
	LinkStack stack = init_LinkStack();

	//׼������
	struct Person p1 = { NULL, "aaa", 10 };
	struct Person p2 = { NULL, "bbb", 20 };
	struct Person p3 = { NULL, "ccc", 30 };
	struct Person p4 = { NULL, "ddd", 40 };
	struct Person p5 = { NULL, "eee", 50 };

	//��ջ
	push_LinkStack(stack, &p1);
	push_LinkStack(stack, &p2);
	push_LinkStack(stack, &p3);
	push_LinkStack(stack, &p4);
	push_LinkStack(stack, &p5);

	//ջ�Ĵ�С
	printf("ջ�Ĵ�СΪ%d\n", size_LinkStack(stack));

	//�鿴ջ��Ԫ�� ����ִ�г�ջ
	while (isEmpty_LinkStack(stack) == 0) //ջ�ǿ� ��ȥִ����������
	{
		struct Person * pTop = top_LinkStack(stack);
		printf("��ʽ�洢 --- ջ��Ԫ�� ����:%s ���䣺%d\n", pTop->name, pTop->age);

		pop_LinkStack(stack);
	}

	printf("ջ�Ĵ�СΪ%d\n", size_LinkStack(stack));

	//����ջ
	destroy_LinkStack(stack);

	system("pause");
	return EXIT_SUCCESS;
}