#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "seqStack.h"
//二叉树结点结构体
struct BinaryNode
{
	char ch; //显示数据 字母
	struct BinaryNode * lChild; //左子树
	struct BinaryNode * rChild; //右子树
	int flag; //标志 默认为假
};
/*
1、将根结点入栈 
2、只要size>0 执行循环
	获取栈顶元素  top
	出栈   pop
	判断标志 如果为真  输出执行下一次循环
	如果为假  将标志改为真 
	将右子树、左子树、根入栈
*/
void nonRecursion(struct BinaryNode * root)
{
	SeqStack stack = init_SeqStack();

	push_SeqStack(stack, root);

	while (size_SeqStack(stack) > 0)
	{
		//获取栈顶
		struct BinaryNode * topNode =  top_SeqStack(stack);

		//出栈
		pop_SeqStack(stack);

		//如果为真 打印
		if (topNode->flag)
		{
			printf("%c ", topNode->ch);
			continue;
		}

		//如果为假  将标志改为真
		topNode->flag = 1;

		//右子树、左子树、根入栈
		if (topNode->rChild != NULL)
		{
			push_SeqStack(stack, topNode->rChild);
		}

		if (topNode->lChild != NULL)
		{
			push_SeqStack(stack, topNode->lChild);
		}

		push_SeqStack(stack,topNode);
	}

	//销毁栈
	destroy_SeqStack(stack);
}

void test01()
{
	//创建二叉树结点
	struct BinaryNode nodeA = { 'A', NULL, NULL ,0};
	struct BinaryNode nodeB = { 'B', NULL, NULL ,0};
	struct BinaryNode nodeC = { 'C', NULL, NULL ,0};
	struct BinaryNode nodeD = { 'D', NULL, NULL ,0};
	struct BinaryNode nodeE = { 'E', NULL, NULL ,0};
	struct BinaryNode nodeF = { 'F', NULL, NULL ,0};
	struct BinaryNode nodeG = { 'G', NULL, NULL ,0};
	struct BinaryNode nodeH = { 'H', NULL, NULL ,0};

	//建立结点之间的关系
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;

	//非递归遍历
	nonRecursion(&nodeA);
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}