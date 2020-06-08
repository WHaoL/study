#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template <class T>
void mySwap(T&a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}


//利用选择排序实现从小到大
//template<typename T> // typename 等价  class
template<class T>
void mySort( T arr[] , int len)
{
	for (int i = 0; i < len;i++)
	{
		int min = i;
		for (int j = i + 1; j < len;j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (i != min)
		{
			mySwap(arr[i], arr[min]);
		}
	}
}

template<class T>
void printArray(T arr[], int len)
{
	for (int i = 0; i < len;i++)
	{
		cout << arr[i] << endl;
	}
}

void test01()
{
	char charArray[] = "hello world";
	int len = strlen(charArray);//sizeof(charArray) / sizeof(char);
	mySort(charArray, len);

	printArray(charArray, len);
}

void test02()
{
	int intArray[] = { 5, 4, 3, 2, 1 };

	int len = sizeof(intArray) / sizeof(int);
	mySort(intArray, len);
	printArray(intArray, len);
}


int main(){
	test02();


	system("pause");
	return EXIT_SUCCESS;
}