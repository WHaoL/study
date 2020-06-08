#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//对任意数组进行排序，算法选择排序，规则用户制定

void selectSort(void * arr, int eleSize, int len, int(*myCompare)( void * ,void * ))
{
	char * temp = malloc(eleSize);

	for (int i = 0; i < len;i++)
	{
		int minOrMax = i; //认定i为最小值 或 最大值 下标
		for (int j = i + 1; j < len;j++) // 通过循环，找到真实最小值 或 最大值的下标
		{
			//如果是从小到大排序 
			//获取j元素首地址
			char * pJ = (char *)arr + j * eleSize;
			//获取minOrMax元素的首地址
			char * pMinOrMax = (char*)arr + minOrMax * eleSize;

			//if ( arr[j] < arr[minOrMax])
			//if ( pJ < pMinOrMax )
			// if ( *num1 < *num2)

			if (myCompare (pJ,pMinOrMax))
			{
				minOrMax = j;
			}
		}

		if (minOrMax != i)
		{
			//i首地址
			char * pI = (char *)arr + i*eleSize;
			//minOrMax首地址
			char * pMinOrMax = (char*)arr + minOrMax * eleSize;

			memcpy(temp, pI, eleSize);
			memcpy(pI, pMinOrMax, eleSize);
			memcpy(pMinOrMax, temp, eleSize);
		}

	}

	free(temp);

}










int compareInt(void * data1,void * data2)
{
	int * num1 = data1;
	int * num2 = data2;

	//if ( *num1 < *num2)
	//{
	//	return 1;
	//}
	//else
	//{
	//	return 0;
	//}

	return *num1 < *num2;
	
}

void test01()
{
	int arr[] = { 20, 40, 10, 30, 50 };

	int len = sizeof(arr) / sizeof(int);
	selectSort(arr, sizeof(int), len, compareInt);

	for (int i = 0; i < len;i++)
	{
		printf("%d\n", arr[i]);
	}
}


struct Person
{
	char name[64];
	int age;
};

int comparePerson(void * data1,void * data2)
{
	struct Person * p1 = data1;
	struct Person * p2 = data2;

	//按年龄做降序排序

	//if (p1->age > p2->age)
	//{
	//	return 1;
	//}

	//return 0;

	return p1->age > p2->age;
}

void test02()
{
	struct Person personArray[] = 
	{
		{ "aaa", 40 },
		{ "bbb", 30 },
		{ "ccc", 60 },
		{ "ddd", 50 },
		{ "eee", 20 },
	};

	int len = sizeof(personArray) / sizeof(struct Person);
	for (int i = 0; i < len;i++)
	{
		printf("姓名：%s 年龄：%d\n", personArray[i].name, personArray[i].age);
	}

	//按年龄做降序排序
	
	selectSort(personArray, sizeof(struct Person), len, comparePerson);

	printf("--------------------------\n");

	printf("年龄降序后遍历结果为：\n");
	for (int i = 0; i < len; i++)
	{
		printf("姓名：%s 年龄：%d\n", personArray[i].name, personArray[i].age);
	}
}

int main(){
	test02();


	system("pause");
	return EXIT_SUCCESS;
}