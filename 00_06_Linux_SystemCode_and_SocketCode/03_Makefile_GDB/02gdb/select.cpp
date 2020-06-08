#include <iostream>
using namespace std;

//选择排序(升序排列)
void selectionSort(int *array, int len)
{
	// 指向最小的元素的位置
	int min = 0;	
	// 外层循环 - 取无序序列的第一个元素
	for (int i = 0; i < len - 1; ++i)
	{
		min = i;
		// 内层循环
		for (int j = i + 1; j < len; ++j)
		{
			// 判断
			if (array[min] > array[j])
			{
				// 保存最小的元素的位置
				min = j;
			}
		}
		// 判断是否需要交换
		if (min != i)
		{
			// 找到了新的最小值
			// 交换
			int tmp = array[min];
			array[min] = array[i];
			array[i] = tmp;
		}
	}
}
