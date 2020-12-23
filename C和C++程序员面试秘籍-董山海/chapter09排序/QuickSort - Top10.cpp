#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//************************快速排序**************************//
/****
 *	参数
 *		a 数组
 *		start 数组的第一个有效下标
 *		end   数组的最后一个有效下标的 下一位
 */
void quick_sort(int *a, int start, int end)
{
	if (end - start <= 1)
	{
		return;
	}
	int head = start;
	int tail = end - 1;
	int pivot = (head + tail) / 2;

	while (tail > head)
	{
		while (head < pivot && a[head] <= a[pivot])
			head++;

		int tmp = a[head];
		a[head] = a[pivot];
		a[pivot] = tmp;
		pivot = head;

		while (tail > pivot && a[tail] >= a[pivot])
			tail--;
		tmp = a[tail];
		a[tail] = a[pivot];
		a[pivot] = tmp;
		pivot = tail;
	}

	quick_sort(a, start, pivot);
	quick_sort(a, pivot + 1, end);
}
//************************快速排序解决Top10问题**************************//
void top10(int *a, int start, int end)
{
	if (end - start <= 1 || start > 9)
	{
		return;
	}

	int head = start;
	int tail = end - 1;
	int pivot = (head + tail) / 2; //基准值下标
	while (tail > head)
	{
		while (head < pivot && a[head] <= a[pivot])
			head++;

		int tmp = a[head];
		a[head] = a[pivot];
		a[pivot] = tmp;
		pivot = head;

		while (tail > pivot && a[tail] >= a[pivot])
			tail--;
		tmp = a[tail];
		a[tail] = a[pivot];
		a[pivot] = tmp;
		pivot = tail;
	}

	if (start + pivot == 9) //找到
	{
		return;
	}
	if (start + pivot > 9) //对左侧继续
	{
		top10(a, start, pivot);
	}
	if (start + pivot < 9) //对右侧继续
	{
		top10(a, pivot + 1, end);
	}
}

int main()
{
	//-----------------------快速排序测试--------------------------//
	puts("------------------------快速排序测试-------------------------");
	int a[10] = {5, 6, 9, 3, 2, 1, 4, 7, 7, 1};
	quick_sort(a, 0, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d\t", a[i]);
	}
	puts("\n\n");

	//------------------------Top10测试-------------------------//
	puts("------------------------快速排序的Top10测试-------------------------");
	srand(time(NULL));
	int a2[100];
	for (int i = 0; i < 100; i++)
	{
		a2[i] = rand() % 200;
		printf("%d  ", a2[i]);
	}
	puts("\n--------------");
	top10(a2, 0, 100);
	for (int i = 0; i < 10; i++)
	{
		printf("%d\t", a2[i]);
	}
	puts("\n\n");
}