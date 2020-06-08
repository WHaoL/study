#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//二叉树结点结构体
struct BinaryNode
{
	char ch; //显示数据 字母
	struct BinaryNode * lChild; //左子树
	struct BinaryNode * rChild; //右子树
};

//统计叶子数量
void calculateLeafNum(struct BinaryNode * root , int * p)
{
	if (root == NULL)
	{
		return;
	}

	//结点左子树与右子树同时为空 称为叶子
	if (root->lChild == NULL && root->rChild == NULL)
	{
		(*p)++; //统计的叶子数量++
	}

	calculateLeafNum(root->lChild, p);

	calculateLeafNum(root->rChild, p);
}

//获取树高度
int getTreeHeight(struct BinaryNode * root)
{
	if (root == NULL)
	{
		return 0;
	}

	//求左子树高度
	int lHeight = getTreeHeight(root->lChild);
	//求右子树高度
	int rHeight = getTreeHeight(root->rChild);
	//取大的值 +1 
	int height = lHeight > rHeight ? lHeight + 1 : rHeight + 1;

	return height;
}

//拷贝二叉树
struct BinaryNode * copyTree(struct BinaryNode * root)
{
	if (root == NULL)
	{
		return NULL;
	}

	//1、先拷贝左子树
	struct BinaryNode * lChild = copyTree(root->lChild);

	//2、再拷贝右子树
	struct BinaryNode * rChild = copyTree(root->rChild);

	//3、创建根结点，将左右子树挂载  
	struct BinaryNode * newNode  = malloc(sizeof(struct BinaryNode));
	newNode->lChild = lChild;
	newNode->rChild = rChild;
	newNode->ch = root->ch;

	return newNode;
}

void recursion(struct BinaryNode * root)
{
	if (root == NULL)
	{
		return;
	}

	

	recursion(root->lChild);

	printf("%c ", root->ch);

	recursion(root->rChild);
}

//释放树
void freeTree(struct BinaryNode * root)
{
	if (root == NULL)
	{
		return;
	}

	//先释放左子树  
	freeTree(root->lChild);
	//再释放右子树
	freeTree(root->rChild);

	printf("%c被释放了\n", root->ch);
	//再释放根
	free(root);

}

void test01()
{
	//创建二叉树结点
	struct BinaryNode nodeA = { 'A', NULL, NULL };
	struct BinaryNode nodeB = { 'B', NULL, NULL };
	struct BinaryNode nodeC = { 'C', NULL, NULL };
	struct BinaryNode nodeD = { 'D', NULL, NULL };
	struct BinaryNode nodeE = { 'E', NULL, NULL };
	struct BinaryNode nodeF = { 'F', NULL, NULL };
	struct BinaryNode nodeG = { 'G', NULL, NULL };
	struct BinaryNode nodeH = { 'H', NULL, NULL };

	//建立结点之间的关系
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;

	//1、统计叶子数量
	int num = 0;
	calculateLeafNum(&nodeA, &num);

	printf("数的叶子数量为: %d\n", num);


	//2、求数的深度/高度
	int height = getTreeHeight(&nodeA);

	printf("数的高度为: %d\n", height);

	//3、拷贝二叉树
	struct BinaryNode * newTree = copyTree(&nodeA);
	//利用新树遍历
	recursion(newTree);

	printf("\n--------------------\n");
	//4、释放二叉树
	freeTree(newTree);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}