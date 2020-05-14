#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <sys/timeb.h>
#include "sort.h"
using namespace std;

int main()
{
	int array[] = {12, 2, 5, 22, 67, 32, 66, 45, 54, 89, 7, 6};
    int len = sizeof(array)/sizeof(int);
	insertionSort(array, len);
	//遍历
	printf("插入排序之后的序列: ");
	for (int i = 0; i < len; ++i)
	{
		cout << array[i] << "  ";
	}
	cout << endl;

	int array1[] = { 12, 5, 33, 6, 10 };
    len = sizeof(array1)/sizeof(int);
	//排序
	selectionSort(array1, len);
	//遍历
	cout << "选择排序之后的序列: ";
	for (int i = 0; i < len; ++i)
	{
		printf("%d  ", array1[i]);
	}
	cout << endl;
    return 0;
}
