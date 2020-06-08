#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//结点结构体
struct LinkNode
{
	struct LinkNode * next;
};

//栈的结构体
struct LStack
{
	struct LinkNode pHeader;
	int m_Size;
};

typedef void * LinkStack;

//初始化栈
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

//入栈
void push_LinkStack(LinkStack stack, void * data)
{
	//本质 -- 头插
	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	//取出用户插入数据的前4个字节，我们使用
	struct LinkNode * myNode = data;

	//还原真实结构体
	struct LStack * myStack = stack;

	//更新指针指向
	myNode->next = myStack->pHeader.next;
	myStack->pHeader.next = myNode;

	//更新栈大小
	myStack->m_Size++;

}

//出栈
void pop_LinkStack(LinkStack stack)
{
	//出栈本质   头删

	if (stack == NULL)
	{
		return;
	}

	struct LStack * myStack = stack;

	if (myStack->m_Size == 0)
	{
		return;
	}

	//记录第一个结点位置
	struct LinkNode * pFirst = myStack->pHeader.next;

	//更新指针的指向
	myStack->pHeader.next = pFirst->next;

	//更新栈大小
	myStack->m_Size--;

}

//返回栈顶
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

//返回栈大小
int size_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	struct LStack * myStack = stack;

	return myStack->m_Size;

}

//判断是否为空
int isEmpty_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1; //-1代表真  空栈
	}

	struct LStack * myStack = stack;

	if (myStack->m_Size == 0)
	{
		return 1;//0个元素 也是空栈 返回真
	}

	return 0;//栈非空 返回假
}

//销毁
void destroy_LinkStack(LinkStack stack)
{
	if (stack != NULL)
	{
		free(stack);
		stack = NULL;
	}
}



//测试
struct Person
{
	void * node;
	char name[64];
	int age;
};


int main(){

	//初始化栈
	LinkStack stack = init_LinkStack();

	//准备数据
	struct Person p1 = { NULL, "aaa", 10 };
	struct Person p2 = { NULL, "bbb", 20 };
	struct Person p3 = { NULL, "ccc", 30 };
	struct Person p4 = { NULL, "ddd", 40 };
	struct Person p5 = { NULL, "eee", 50 };

	//入栈
	push_LinkStack(stack, &p1);
	push_LinkStack(stack, &p2);
	push_LinkStack(stack, &p3);
	push_LinkStack(stack, &p4);
	push_LinkStack(stack, &p5);

	//栈的大小
	printf("栈的大小为%d\n", size_LinkStack(stack));

	//查看栈顶元素 并且执行出栈
	while (isEmpty_LinkStack(stack) == 0) //栈非空 才去执行上述操作
	{
		struct Person * pTop = top_LinkStack(stack);
		printf("链式存储 --- 栈顶元素 姓名:%s 年龄：%d\n", pTop->name, pTop->age);

		pop_LinkStack(stack);
	}

	printf("栈的大小为%d\n", size_LinkStack(stack));

	//销毁栈
	destroy_LinkStack(stack);

	system("pause");
	return EXIT_SUCCESS;
}