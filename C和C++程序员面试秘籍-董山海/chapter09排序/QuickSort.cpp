#include <iostream>
#include <string>
using namespace std;
/*--------------- 快速排序 --------------------- 
	数组排序任务可以如下完成：
	1）设 k=a[0], 将 k 挪到适当位置，使得比 k 小的元素都
	在 k 左边,比 k 大的元素都在 k 右边，和 k 相等的，不关心
	在 k 左右出现均可（O（n)时间完成）
	2) 把 k 左边的部分快速排序
	3) 把 k 右边的部分快速排序

	核心：挖坑填数
-------------------------------------------------*/
void swap(int &a, int &b) //交换变量 a,b 值
{
	int tmp = a;
	a = b;
	b = tmp;
}
/****
 *	参数
 *		a 数组
 *		start 数组的第一个有效下标
 *		end   数组的最后一个有效下标
 */		
void QuickSort(int a[], int start, int end)
{
	if (start >= end)
		return;
	int k = a[start];//每次的基准数：可以随意设置，我习惯使用数组首元素
	int i = start, j = end;
	while (i != j)
	{
		while (i < j && a[j] >= k) //从右往左找比 k 小的
			--j;
		swap(a[i], a[j]);
		while (i < j && a[i] <= k) //从左往右找比 k 大的
			++i;
		swap(a[i], a[j]);
	}//此时k放在了合适的位置(i==j,a[i] == k，并且左边元素都比k小，右边的元素都比k大)
	QuickSort(a, start, i - 1); //把 k 左边的部分快速排序
	QuickSort(a, i + 1, end);	//把 k 右边的部分快速排序
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
	QuickSort(a1, 0, len - 1);
	print_arr(a1, len);

	int a2[] = {8, 4, 6, 9, 10, 2, 3, 5, 7};
	len = sizeof(a2) / sizeof(a2[0]);
	print_arr(a2, len);
	QuickSort(a2, 0, len - 1);
	print_arr(a2, len);

	getchar();
	return 0;
}