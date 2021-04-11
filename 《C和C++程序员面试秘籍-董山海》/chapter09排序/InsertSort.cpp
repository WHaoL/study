#include <iostream>
#include <string>
using namespace std;
/*-------------------- 插入排序 ---------------------- 
	直接插入排序的两个性质：
		- 在最好的情况(序列本身已是有序的)下时间代价为 O(n)
		- 对于短序列，直接插入排序比较有效
	shell 排序有效地利用了直接排序的这两个性质
-----------------------------------------------------*/
//插入排序算法(升序排列)
template <class T>
void ImprovedInsertSort(T Array[], int n)
{
	T TempRecord;				//临时变量
	for (int i = 1; i < n; ++i) //依次插入第 i 个记录
	{
		TempRecord = Array[i];
		int j = i - 1;								//从 i 开始往前寻找记录 i 的正确位置
		while ((j >= 0) && (TempRecord < Array[j])) //将那些大于等于记录 i 的记录后移
		{
			Array[j + 1] = Array[j];
			j = j - 1;
		}
		Array[j + 1] = TempRecord; //此时 j 后面就是记录 i 的正确位置，回填
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
	ImprovedInsertSort(a1, len);
	print_arr(a1, len);

	int a2[] = {8, 4, 6, 9, 10, 2, 3, 5, 7};
	len = sizeof(a2) / sizeof(a2[0]);
	print_arr(a2, len);
	ImprovedInsertSort(a2, len);
	print_arr(a2, len);

	getchar();
	return 0;
}