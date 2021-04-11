		typedef int ElementType; //数据部分的数据类型
		
/* P39 START：figure 3-6 */ // list.h
		#ifndef __LIST_H__
		#define __LIST_H__

		struct Node;
		typedef struct Node *PtrNode; //结点类型的指针
		typedef PtrNode List;         //头结点
		typedef PtrNode Position;     //中间某一节点

		List MakeEmpty(List L);                         //把链表全部结点置空
		int IsEmpty(List L);                            //判断链表是否是空表
		int IsLast(Position P, List L);                 //判断P是否是最后一个结点
		Position Find(ElementType X, List L);           //返回关键字首次出现的位置
		void Delete(ElementType X, List L);             //从链表中删除某一元素
		Position FindPrevious(ElementType X, List L);   //返回关键字的上一个位置
		void Insert(ElementType X, List L, Position P); //在某个位置，插入某个关键字
		void DeleteList(List L);
		Position Header(List L); //返回头结点
		Position First(List L);  //
		Position Advance(Position P);
		ElementType Retrieve(Position P);

		#endif
/* END */