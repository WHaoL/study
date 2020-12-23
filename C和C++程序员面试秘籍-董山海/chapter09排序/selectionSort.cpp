#include <iostream>
#include <string>
using namespace std;
/*-------------------- 选择排序 -------------------- 

	每一次外层循环，从待排序的序列中选出最小的
	一个元素，存放在本次待排序序列的起始位置
	..... 
	
	找到第 0 小，放在第 0 个位置上
	找到第 1 小，放在第 1 个位置上
	..... 

	稳定性:选择排序是不稳定的排序方法 如:[5,5,3]
-------------------------------------------------*/
//选择排序(升序排列：从小到大)
void selectionSort(int *array, int len)
{
	int min = 0;					  //指向最小的元素的位置
	for (int i = 0; i < len - 1; ++i) //外层循环
	{
		min = i;
		for (int j = i + 1; j < len; ++j) //内层循环
		{
			if (array[min] > array[j]) //判断
			{
				min = j; // 保存最小的元素的位置
			}
		}
		if (min != i) // 判断是否需要交换
		{			  // 找到了新的最小值--交换
			int tmp = array[min];
			array[min] = array[i];
			array[i] = tmp;
		}
	}
}
void print_arr(int arr[], int len)
{
	for (int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
}
int main()
{
	int a1[] = {7, 3, 5, 8, 9, 1, 2, 4, 6};
	int len = sizeof(a1) / sizeof(a1[0]);
	print_arr(a1, len);
	selectionSort(a1, len);
	print_arr(a1, len);

	int a2[] = {8, 4, 6, 9, 10, 2, 3, 5, 7};
	len = sizeof(a2) / sizeof(a2[0]);
	print_arr(a2, len);
	selectionSort(a2, len);
	print_arr(a2, len);

	getchar();
	return 0;
}