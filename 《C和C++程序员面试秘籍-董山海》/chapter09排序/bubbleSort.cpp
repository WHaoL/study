#include <iostream>
#include <string>
using namespace std;
/********************* 冒泡排序 *********************
	冒泡排序算法的运作如下：（从后往前）
	1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
	2. 每次外层循环：对每一对相邻元素作同样的工作
	3. 针对所有的元素重复以上的步骤，除了最后一个。
	4. 持续每次对越来越少的元素重复上面的步骤，
	   直到没有任何一对数字需要比较。
	O(n²) 
	稳定性:冒泡排序是一种稳定排序算法
***************************************************/
//冒泡排序(升序)
void bubbleSort1(int *array, int len) //array[len]
{
	for (int i = 0; i < len - 1; ++i) //进行len-1趟扫描
	{
		for (int j = 0; j < len - 1 - i; ++j) //第一趟从([0]与[0+1])...比较到([len-2-i]与[len-2-i+1]);然后是第二趟
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}

// 冒泡排序的优化
// 添加标志位flag：false-表示没有排好, true-表示已经排好
void bubbleSort2(int *array, int len)
{
	int flag = false;
	for (int i = 0; (i < len - 1) && (flag == false); ++i)
	{
		flag = true; // 设置标志
		for (int j = 0; j < len - 1 - i; ++j)
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				flag = false; //没有排好
			}
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
	bubbleSort1(a1, len);
	print_arr(a1, len);

	int a2[] = {8, 4, 6, 9, 10, 2, 3, 5, 7};
	len = sizeof(a2) / sizeof(a2[0]);
	print_arr(a2, len);
	bubbleSort1(a2, len);
	print_arr(a2, len);

	getchar();
	return 0;
}