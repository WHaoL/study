#pragma  once  //防止头文件重复包含
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//函数声明，全局变量声明


//创建数组
void allocateSpace(int ** arr, int num);

//设置数组元素
void setArray(int * arr , int num);

//打印数组 
void printArray(int * arr, int num);

//对于数组进行排序
void sortArray(int * arr, int num);

//获取数组平均值
int getAvgArray(int * arr, int num);

//获取数组最大值
int getMax(int * arr, int num);

//获取数组最小值
int getMin(int * arr, int num);

//获取数组总和
int getSum(int * arr, int num);

//释放数组
void freeArray(int ** arr);