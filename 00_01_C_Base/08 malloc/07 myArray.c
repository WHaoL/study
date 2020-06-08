#include "myArray.h"

//��������
void allocateSpace(int ** arr, int num)
{
  int * p = malloc(sizeof(int)* num);

  if (p == NULL)
  {
	  printf("�����ڴ�ʧ��\n");
	  return;
  }
  memset(p, 0, sizeof(int)*num);

  *arr = p; //������ϵ
}

//��������Ԫ��
void setArray(int * arr, int num)
{
	printf("������%d��Ԫ��\n", num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}
}

//��ӡ���� 
void printArray(int * arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//���������������
void sortArray(int * arr, int num )
{
	for (int i = 0; i < num - 1;i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			//����  ���j > j+1 ��������
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

}
//��ȡ����ƽ��ֵ
int getAvgArray(int * arr, int num)
{
	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum += arr[i];
	}
	return sum / num;
}

//��ȡ�������ֵ
int getMax(int * arr, int num)
{
	int max = 0; //�϶�0�±�������ֵ
	for (int i = 1; i < num;i++)
	{
		if (arr[i] > arr[max])
		{
			max = i; //�������ֵ�±�
		}
	}

	return arr[max];
}

//��ȡ������Сֵ
int getMin(int * arr, int num)
{
	int min = 0; //�϶�0�±������Сֵ
	for (int i = 1; i < num; i++)
	{
		if (arr[i] < arr[min])
		{
			min = i; //������Сֵ�±�
		}
	}

	return arr[min];
}
//��ȡ�����ܺ�
int getSum(int * arr, int num)
{
	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum += arr[i];
	}
	return sum;

}
//�ͷ�����
void freeArray(int ** arr)
{
	if (*arr != NULL)
	{
		free(*arr);
		*arr = NULL;
	}
}