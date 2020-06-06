#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//������������������㷨ѡ�����򣬹����û��ƶ�

void selectSort(void * arr, int eleSize, int len, int(*myCompare)( void * ,void * ))
{
	char * temp = malloc(eleSize);

	for (int i = 0; i < len;i++)
	{
		int minOrMax = i; //�϶�iΪ��Сֵ �� ���ֵ �±�
		for (int j = i + 1; j < len;j++) // ͨ��ѭ�����ҵ���ʵ��Сֵ �� ���ֵ���±�
		{
			//����Ǵ�С�������� 
			//��ȡjԪ���׵�ַ
			char * pJ = (char *)arr + j * eleSize;
			//��ȡminOrMaxԪ�ص��׵�ַ
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
			//i�׵�ַ
			char * pI = (char *)arr + i*eleSize;
			//minOrMax�׵�ַ
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

	//����������������

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
		printf("������%s ���䣺%d\n", personArray[i].name, personArray[i].age);
	}

	//����������������
	
	selectSort(personArray, sizeof(struct Person), len, comparePerson);

	printf("--------------------------\n");

	printf("���併���������Ϊ��\n");
	for (int i = 0; i < len; i++)
	{
		printf("������%s ���䣺%d\n", personArray[i].name, personArray[i].age);
	}
}

int main(){
	test02();


	system("pause");
	return EXIT_SUCCESS;
}