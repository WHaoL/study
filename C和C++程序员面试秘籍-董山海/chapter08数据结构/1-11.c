#include <stdio.h>
#include <stdlib.h>

/*---------------------- 1、单链表的 创建 ----------------------------*/
//链表节点的定义
typedef struct node
{
	int data;
	struct node *next;
} node;
typedef node *ptrNode;

//创建单链表（输入每个节点的数据，输入0表示停止创建）
node *createSingleList()
{
	int i = 0; //记录当前是不是第一个节点
	int x = 0; //接受输入的数据域的数据

	ptrNode head = (ptrNode)malloc(sizeof(node)); //创建头结点head
	ptrNode tmp = head;							  //tmp是本次要挂上去的节点，
	ptrNode tail = head;						  //tail充当链表尾节点指针

	while (1)
	{
		printf("Please input the data part of the current node : ");
		scanf("%d", &x);

		if (x != 0)
		{
			//z否则：创建新的节点
			tmp = (ptrNode)malloc(sizeof(node));
			tmp->data = x;

			tail->next = tmp; //节点，链接到链表尾部

			tail = tmp; //更新尾指针
		}
		else
		{
			break; //输入的数据==0时，停止链表的创建
		}
	}
	tail->next = NULL; //list的最后一个节点的next指针置为NULL
	return head;
}

/*---------------------- 2、单链表的 测长 ----------------------------*/
//返回单链表长度
int lengthOfList(ptrNode head)
{
	int len = 0;
	ptrNode p = head->next;
	while (p != NULL) //尾节点的指针域为NULL，作为终止条件
	{
		len++;
		p = p->next;
	}
	return len;
}

/*---------------------- 3、单链表的 打印 ----------------------------*/
//打印单链表
void printList(ptrNode head)
{
	ptrNode p = head->next;
	int index = 0;
	if (p == NULL)
	{
		printf("The List is empty!\n");
		return;
	}
	while (p != NULL)
	{
		printf("The %dth node's data =  %d\n", ++index, p->data);
		p = p->next;
	}
}

/*---------------------- 4、单链表节点的查找 ----------------------------*/
//查找单链表pos位置的节点，返回节点指针
//pos从0开始，0返回head
ptrNode search_node(ptrNode head, int pos)
{
	//首先检查pos的位置
	if (pos < 0)
	{
		printf("incorrect position: pos < 0 !\n");
		return NULL;
	}
	if (pos == 0)
	{
		return head;
	}

	//取得第一个有效节点的指针
	ptrNode p = head->next;
	if (p == NULL)
	{
		printf("List is empty!\n");
		return NULL;
	}

	while (--pos)
	{
		if ((p = p->next) == NULL)
		{
			printf("incorrect position: pos is too large\n");
			return NULL;
		}
	}
	return p;
}

/*---------------------- 5、单链表节点的 插入 ----------------------------*/
//在单链表pos位置插入节点，返回链表头指针
// 即插在第pos个节点之后
//pos从0开始计算，0表示插入到head节点后面
ptrNode insert_node(ptrNode head, int pos, int data)
{
	if (pos < 0)
	{
		printf("incorrect position: pos < 0 !\n");
		return NULL;
	}

	ptrNode tmp = (ptrNode)malloc(sizeof(struct node));
	tmp->data = data;

	ptrNode p = NULL;
	if (pos == 0)
	{
		head->next = tmp;
		return head;
	}
	else if ((p = search_node(head, pos)) != NULL)
	{
		tmp->next = p->next;
		p->next = tmp;
	}
	return head;
}

/*---------------------- 6、单链表节点的 删除 ----------------------------*/
// 删除单链表的pos位置的节点，返回链表头指针
// pos从1开始计算，1表示删除head后的第一个节点（即：第一个有效节点）
ptrNode delete_node(ptrNode head, int pos) // pos >= 1
{
	// if (pos < 0)
	// {
	// 	printf("incorrect position: pos < 0 !\n");
	// 	return NULL;
	// }
	// else
	{
		ptrNode p = head->next;
		if (p == NULL)
		{
			printf("The List is empty!\n");
			return NULL;
		}

		p = search_node(head, pos - 1);
		if (p != NULL && p->next != NULL)
		{
			ptrNode tmp = p->next;
			p->next = tmp->next;
			free(tmp);
		}
		return head;
	}
}

/*---------------------- 7、单链表的逆置 ----------------------------*/
ptrNode reverseList(ptrNode head)
{
	if (head->next == NULL)
	{
		printf("The List is empty!\n");
		return head;
	}
	else
	{
		ptrNode newLi = head->next;	 //新链表的第一个有效节点
		ptrNode oldLi = newLi->next; //旧链表的第一个有效节点
		newLi->next = NULL;			 //记得把新链表的尾节点.next置为NULL

		ptrNode tmp = NULL;

		while (oldLi != NULL)
		{
			tmp = oldLi->next;
			oldLi->next = newLi;
			newLi = oldLi;
			oldLi = tmp;
		}
		head->next = newLi;
		return head;
	}
}
/*---------------------- 8、寻找单链表的中间元素 ----------------------------*/
ptrNode search_Middle_node(ptrNode head)
{
	ptrNode current = head->next;
	ptrNode middle = head->next;

	int i = 0, j = 0; //j维持为i的1/2
	/**
	 * 链表为奇数个节点时
	 * 	如果i j 起始时都为0，那么 链表为1 2 3时 打印中间链表为3
	 * 	如果i j 起始时都为1，那么 链表为1 2 3时 打印中间链表为2 3
	 * 链表节点为偶数时，起始为i=j=0或者i=j=1效果是一样的
	*/
	while (current != NULL)
	{
		if (i / 2 > j)
		{
			j++;
			middle = middle->next;
		}
		else
		{
			i++;
			current = current->next;
		}
	}
	return middle;
}
/*---------------------- 9、单链表的正向排序(创建链表时) ----------------------------*/
ptrNode InsertSort(void)
{
	int data = 0;
	ptrNode head = (ptrNode)malloc(sizeof(struct node)); //头结点
	head->next = NULL;
	head->data = 0;

	ptrNode tmp = NULL;	   // 新添加的节点
	ptrNode prePtr = NULL; //待添加位置的上一个节点
	ptrNode curPtr = NULL; //指针在链表的某个节点上

	while (1)
	{
		printf("Please input the data part of the current node : ");
		scanf("%d", &data);
		if (data != 0)
		{
			tmp = (ptrNode)malloc(sizeof(struct node));
			tmp->data = data;
			tmp->next = NULL;
			if (head->next == NULL)
			{
				head->next = tmp;
				continue;
			}
			else
			{
				if (tmp->data <= head->next->data)
				{
					tmp->next = head->next;
					head->next = tmp;
					continue;
				}
				else
				{
					curPtr = head->next;
					while (tmp->data > curPtr->data &&
						   curPtr->next != NULL)
					{
						prePtr = curPtr;
						curPtr = curPtr->next;
					}
					if (curPtr->data >= tmp->data)
					{
						prePtr->next = tmp;
						tmp->next = curPtr;
					}
					else
					{
						curPtr->next = tmp;
					}
				}
			}
		}
		else
		{
			break;
		}
	}
	return head;
}
/*---------------------- 10、判断链表是否存在环形链表问题 ----------------------------*/
// 可参考： https://www.cnblogs.com/yorkyang/p/10876604.html
// 判断是否存在回环
// 如果存储在，start存放回环开始的节点
// 由于C没有bool，此处设定：返回1代表true 0代表false
int IsLoop(ptrNode head, ptrNode *start)
{
	if (head == NULL || head->next == NULL)
		return 0;

	ptrNode fastPtr = head, slowPrt = head;
	do
	{
		slowPrt = slowPrt->next;
		fastPtr = fastPtr->next->next;
	} while (fastPtr && fastPtr->next && slowPrt != fastPtr);

	if (slowPrt == fastPtr)
	{
		*start = slowPrt;
		return 1;
	}
	else
	{
		return 0;
	}
}

/*---------------------- 11、合并两个有序的单链表 ----------------------------*/
//默认从小到大
ptrNode mergeList(ptrNode head1, ptrNode head2)
{
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;

	ptrNode p1 = head1->next, p2 = head2->next;

	ptrNode headMerge = (ptrNode)malloc(sizeof(struct node));
	headMerge->next = NULL;
	ptrNode curPtr = headMerge;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data < p2->data)
		{
			curPtr->next = p1;
			p1 = p1->next;
			curPtr = curPtr->next;
		}
		else if (p1->data == p2->data)
		{
			curPtr->next = p1;
			curPtr = curPtr->next;
			p1 = p1->next;

			curPtr->next = p2;
			curPtr = curPtr->next;
			p2 = p2->next;
		}
		else
		{
			curPtr->next = p2;
			curPtr = curPtr->next;
			p2 = p2->next;
		}
	}
	if (p1 != NULL)
		curPtr->next = p1;
	if (p2 != NULL)
		curPtr->next = p2;

	return headMerge;
}

/*---------------------- 单链表的创建 ----------------------------*/

/*---------------------- 单链表的创建 ----------------------------*/
/*---------------------- 单链表的创建 ----------------------------*/
/*---------------------- 单链表的创建 ----------------------------*/
/*---------------------- 单链表的创建 ----------------------------*/
int main()
{
	//1
	//ptrNode head = createSingleList();
	// 2
	// printf("length of this list = %d\n", lengthOfList(head));
	// 3
	// printList(head);
	// 4
	// int index = 0;
	// printf("查找第几个节点，请输入：");
	// scanf("%d", &index);
	// printf("第%d个节点的数据域是%d\n", index, search_node(head, index)->data);
	// 5
	// insert_node(head,3,12345);
	// printList(head);
	// 6
	// delete_node(head, 3);
	// printList(head);
	// 7
	// head = reverseList(head);
	// printList(head);
	// 8
	// printList(search_Middle_node(head));
	// 9
	// printList(InsertSort());
	// 10
	// int flag = 0;
	// ptrNode head  = createSingleList();
	// ptrNode start = head->next->next->next->next;//使第4个节点为回环开始的位置
	// start->next = head->next;//回环到第1个节点
	// ptrNode loopStart = NULL;
	// flag = IsLoop(head,&loopStart);
	// printf("flag = %d\n",flag);
	// printf("start == loopStart ? %d\n",(start == loopStart));
	// 11
	// ptrNode head1 = createSingleList();
	// ptrNode head2 = createSingleList();
	// printList(mergeList(head1, head2));
    // 12

	getchar();
	return 0;
}

// gcc 1-11.c -o out -std=c99
// ./out