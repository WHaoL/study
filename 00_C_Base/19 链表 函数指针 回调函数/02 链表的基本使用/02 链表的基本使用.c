#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "linklist.h"

void test01()
{
	//初始化链表
	struct LinkNode * pHeader = init_LinkList();

	//遍历链表
	printf("链表遍历的结果为：\n");

	foreach_LinkList(pHeader);

	//插入链表
	insert_LinkList(pHeader, 20, 100);
	insert_LinkList(pHeader, 1000, 200);

	printf("插入链表后的结果为：\n");
	//  10  100 20 30 200
	foreach_LinkList(pHeader);


	//删除 30
	//10 100 20 200

	delete_LinkList(pHeader, 30);
	delete_LinkList(pHeader, 300);
	printf("删除30数据后的遍历结果为：\n");
	foreach_LinkList(pHeader);


	//清空链表  清空后链表是可以复用的
	clear_LinkList(pHeader);

	printf("清空链表后的遍历结果为：\n");
	clear_LinkList(pHeader);

	insert_LinkList(pHeader, 111, 111);
	insert_LinkList(pHeader, 222, 222);
	insert_LinkList(pHeader, 333, 333);

	foreach_LinkList(pHeader);


	//销毁链表  不可以用
	destroy_LinkList(pHeader);
	//printf("销毁链表后的遍历结果为：\n");
	//foreach_LinkList(pHeader); error 因为链表已经被销毁，不可以使用
}


void test02()
{
	struct LinkNode * pHeader = init_LinkList();

	printf("链表反转前遍历：\n");
	foreach_LinkList(pHeader);


	printf("链表反转后遍历：\n");
	//反转
	reverse_LinkList(pHeader);
	foreach_LinkList(pHeader);

	//统计链表长度 
	int num = size_LinkList(pHeader);
	printf("链表的长度为：%d\n", num);

	//销毁
	destroy_LinkList(pHeader);

}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}