#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1 3 5 2 4 
//逆置后
//4 2 5 3 1 

void test01()
{
	int arr[6] = { 1,3,5,2,4,6 };

	printf("逆置前的遍历结果为:\n");
	for (int i = 0; i <sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	//逆置
	int start = 0; //起始交换下标
	int end = sizeof(arr) / sizeof(int)-1; //最后一个元素的下标

	while (start<end)
	{
		//创建临时遍历
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;

		//下标更新
		start++;
		end--;
	}
	printf("逆置后的遍历结果为:\n");
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

}



int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}