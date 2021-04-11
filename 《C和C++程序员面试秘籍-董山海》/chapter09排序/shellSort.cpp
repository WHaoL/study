#include <iostream>
#include <string>
using namespace std;
/*--------------- shell 排序 --------------------- 
	最佳情况时间是 O(N × 1) = O(N), 
	最坏情况时间是 O(N × N) = O(N²). 

	希尔排序是把记录按下标的一定增量分组，对每组使用直接插入排序算法排序；
	随着增量逐渐减少，每组包含的关键词越来越多，当增量减至 1 时，整个文件恰
	被分成一组，算法便终止。

	稳定性: 希尔排序是非稳定排序算法。

-------------------------------------------------*/
void shellSort1(int array[], int len)
{
	int gap = len; // 初始步长
	do
	{
		gap = gap / 3 + 1;			  // 步长递减公式--O(n*1.3)
		for (int i = 0; i < gap; ++i) // 分组,对每一组,进行插入排序
		{
			for (int j = i + gap; j < len; j += gap) // 插入排序
			{
				int tmp = array[j]; // 临时变量
				int index = j - gap;
				while ((index >= 0) && (tmp < array[index])) // 从后往前遍历
				{
					array[index + gap] = array[index]; // 后移
					index -= gap;
				}
				array[index + gap] = tmp; // 回填
			}
		}
	} while (gap > 1);
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
	shellSort1(a1, len);
	print_arr(a1, len);

	int a2[] = {8, 4, 6, 9, 10, 2, 3, 5, 7};
	len = sizeof(a2) / sizeof(a2[0]);
	print_arr(a2, len);
	shellSort1(a2, len);
	print_arr(a2, len);

	getchar();
	return 0;
}