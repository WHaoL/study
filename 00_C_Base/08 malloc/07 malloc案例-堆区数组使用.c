#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "07 myArray.h"

void test01()
{
	int num = 0;
	int * arr = NULL;
	printf("请输入数组元素个数\n");
	scanf("%d", &num);

	//创建数组
	allocateSpace(&arr,num);

	//设置数组中元素
	setArray(arr, num);

	//打印数组元素
	printArray(arr, num);

	//排序数组
	sortArray(arr, num);
	printf("数组排序后的结果为\n");
	printArray(arr, num);

	//剩余测试
	printf("数组的最大值为:%d 最小值为:%d 总和为:%d 平均数为:%d\n",
		getMax(arr, num), getMin(arr, num), getSum(arr, num), getAvgArray(arr, num));

	//释放数组
	freeArray(&arr);

}


int main(){

	test01();


	system("pause");
	return EXIT_SUCCESS;
}