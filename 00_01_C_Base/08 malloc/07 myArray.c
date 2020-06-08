#include "myArray.h"

//创建数组
void allocateSpace(int ** arr, int num)
{
  int * p = malloc(sizeof(int)* num);

  if (p == NULL)
  {
	  printf("分配内存失败\n");
	  return;
  }
  memset(p, 0, sizeof(int)*num);

  *arr = p; //建立关系
}

//设置数组元素
void setArray(int * arr, int num)
{
	printf("请输入%d个元素\n", num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}
}

//打印数组 
void printArray(int * arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//对于数组进行排序
void sortArray(int * arr, int num )
{
	for (int i = 0; i < num - 1;i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			//升序  如果j > j+1 交换数据
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

}
//获取数组平均值
int getAvgArray(int * arr, int num)
{
	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum += arr[i];
	}
	return sum / num;
}

//获取数组最大值
int getMax(int * arr, int num)
{
	int max = 0; //认定0下标就是最大值
	for (int i = 1; i < num;i++)
	{
		if (arr[i] > arr[max])
		{
			max = i; //更新最大值下标
		}
	}

	return arr[max];
}

//获取数组最小值
int getMin(int * arr, int num)
{
	int min = 0; //认定0下标就是最小值
	for (int i = 1; i < num; i++)
	{
		if (arr[i] < arr[min])
		{
			min = i; //更新最小值下标
		}
	}

	return arr[min];
}
//获取数组总和
int getSum(int * arr, int num)
{
	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum += arr[i];
	}
	return sum;

}
//释放数组
void freeArray(int ** arr)
{
	if (*arr != NULL)
	{
		free(*arr);
		*arr = NULL;
	}
}