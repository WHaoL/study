#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "dynamicArray.h"

////动态数组结构体
//struct dynamicArray
//{
//	void ** addr; //维护在堆区开辟数组指针
//
//	int m_Capacity; //容量
//
//	int m_Size; //大小
//};
//
////初始化数组   参数 初始容量
//struct dynamicArray * init_dynamicArray(int capacity)
//{
//	if (capacity <= 0)
//	{
//		return NULL;
//	}
//
//	//分配内存空间
//	struct dynamicArray * arr = malloc(sizeof(struct dynamicArray));
//
//	if (arr== NULL)
//	{
//		return NULL;
//	}
//	
//	//初始化属性
//	arr->addr = malloc(sizeof(void *)* capacity);
//	memset(arr->addr, 0, sizeof(void *)* capacity);
//	arr->m_Capacity = capacity;
//
//	arr->m_Size = 0;
//
//	return arr;
//}
//
//
////插入元素  参数1  数组指针   参数2  插入位置   参数3 插入具体数据
//void insert_dynamicArray(struct dynamicArray * arr, int pos, void * data)
//{
//	if (arr == NULL)
//	{
//		return;
//	}
//	if (data == NULL)
//	{
//		return;
//	}
//	if (pos < 0 || pos > arr->m_Size )
//	{
//		//无效位置 强制尾插
//		pos = arr->m_Size;
//	}
//
//	//判断容器是否已经满了
//	if (arr->m_Size == arr->m_Capacity)
//	{
//		//1、计算申请更大大小
//		int newCapacity = arr->m_Capacity * 2;
//
//		//2、创建新空间
//		void ** newSpace  = malloc(sizeof(void *)* newCapacity);
//
//		//3、将原有空间下的数据拷贝到新空间下
//		memcpy(newSpace, arr->addr, sizeof(void *)* arr->m_Capacity);
//
//		//4、释放原有空间
//		free(arr->addr);
//
//		//5、更新指针的指向
//		arr->addr = newSpace;
//
//		//6、更新容量
//		arr->m_Capacity = newCapacity;
//	}
//
//
//	//插入数据
//	for (int i = arr->m_Size - 1; i >= pos; i--)
//	{
//		//向后移动数据
//		arr->addr[i + 1] = arr->addr[i];
//	}
//	//将新元素插入到指定位置上
//	arr->addr[pos] = data;
//
//	//更新大小
//	arr->m_Size++;
//}
//
////遍历数组
//void foreach_dynamicArray(struct dynamicArray *arr , void(*myPrint)(void*))
//{
//	for (int i = 0; i < arr->m_Size;i++)
//	{
//		//arr->addr[i]每个数据的首地址
//		myPrint(arr->addr[i]);
//	}
//}
//
////删除元素  --- 按位置删除元素
//void removeByPos_dynamicArray(struct dynamicArray *arr, int pos)
//{
//	if (arr == NULL)
//	{
//		return;
//	}
//
//	//无效的位置 直接return
//	if (pos < 0 || pos > arr->m_Size - 1)
//	{
//		return;
//	}
//
//	for (int i = pos; i < arr->m_Size-1;i++)
//	{
//		arr->addr[i] = arr->addr[i + 1];
//	}
//
//	//更新数组大小
//	arr->m_Size--;
//}
//
////删除元素  按值方式删除
//void removeByValue_dynamicArray(struct dynamicArray *arr, void * data  , int(*myCompare)(void*,void* ) )
//{
//	if (arr == NULL)
//	{
//		return;
//	}
//	if (data == NULL)
//	{
//		return;
//	}
//	if (myCompare == NULL)
//	{
//		return;
//	}
//
//	for (int i = 0; i < arr->m_Size;i++)
//	{
//		//if (arr->addr[i] == data )
//		if (myCompare(arr->addr[i],data))
//		{
//			removeByPos_dynamicArray(arr, i);
//			break;
//		}
//	}
//
//}
////销毁数组
//void destroy_dynamicArray(struct dynamicArray *arr)
//{
//	if (arr== NULL)
//	{
//		return;
//	}
//
//	if (arr->addr != NULL)
//	{
//		free(arr->addr);
//		arr->addr = NULL;
//	}
//
//	free(arr);
//	arr = NULL;
//}






//测试动态数组
struct Person
{
	char name[64];
	int age;
};

void printPerson(void * data)
{
	struct Person * p = data;
	printf("姓名：%s  年龄：%d\n", p->name, p->age);
}

int comparePerson(void * data1,void * data2)
{
	struct Person * p1 = data1;
	struct Person * p2 = data2;

	//if ( strcmp( p1->name ,  p2->name) == 0 && p1->age == p2->age)
	//{
	//	return 1;
	//}
	//return 0;

	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

int main(){

	//初始化数组
	struct dynamicArray * arr = init_dynamicArray(5);

	struct Person p1 = { "刘备", 19 };
	struct Person p2 = { "妲己", 20 };
	struct Person p3 = { "鲁班", 18 };
	struct Person p4 = { "张飞", 22 };
	struct Person p5 = { "虞姬", 21 };
	struct Person p6 = { "甄姬", 23 };

	printf("插入数据前 -- 数组的容量:%d\n", arr->m_Capacity);
	//插入数据
	insert_dynamicArray(arr, 0, &p1);
	insert_dynamicArray(arr, 0, &p2);
	insert_dynamicArray(arr, 0, &p3);
	insert_dynamicArray(arr, 1, &p4);
	insert_dynamicArray(arr, -1, &p5);
	insert_dynamicArray(arr, 100, &p6);

	//arr->m_Capacity = 0;
	//arr->m_Size = -1;
	//arr->addr = NULL;

	printf("插入数据后 -- 数组的容量:%d\n", arr->m_Capacity);
	// 鲁班 张飞 妲己 刘备 虞姬  甄姬

	//遍历数组
	foreach_dynamicArray(arr, printPerson);

	//删除元素  删刘备
	removeByPos_dynamicArray(arr, 3);
	printf("-----------------------------\n");
	printf("删除刘备后遍历结果为\n");
	foreach_dynamicArray(arr, printPerson);

	//删除元素  删张飞
	struct Person p = { "张飞", 22 };
	removeByValue_dynamicArray(arr, &p, comparePerson);

	printf("-----------------------------\n");
	printf("删除张飞后遍历结果为\n");
	foreach_dynamicArray(arr, printPerson);


	//销毁数组
	destroy_dynamicArray(arr);

	system("pause");
	return EXIT_SUCCESS;
}