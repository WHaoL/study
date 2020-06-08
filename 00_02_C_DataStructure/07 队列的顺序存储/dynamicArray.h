#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//动态数组结构体
struct dynamicArray
{
	void ** addr; //维护在堆区开辟数组指针

	int m_Capacity; //容量

	int m_Size; //大小
};

//初始化数组   参数 初始容量
struct dynamicArray * init_dynamicArray(int capacity);


//插入元素  参数1  数组指针   参数2  插入位置   参数3 插入具体数据
void insert_dynamicArray(struct dynamicArray * arr, int pos, void * data);


//遍历数组
void foreach_dynamicArray(struct dynamicArray *arr, void(*myPrint)(void*));


//删除元素  --- 按位置删除元素
void removeByPos_dynamicArray(struct dynamicArray *arr, int pos);

//删除元素  按值方式删除
void removeByValue_dynamicArray(struct dynamicArray *arr, void * data, int(*myCompare)(void*, void*));

//销毁数组
void destroy_dynamicArray(struct dynamicArray *arr);


