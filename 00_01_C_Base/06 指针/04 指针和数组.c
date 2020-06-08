#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	int arr[5] = { 1, 2, 3, 4, 5 };

	//1、数组名可以获取整个数组占用内存大小
	printf("%d\n", sizeof(arr));

	//2、获取数组首元素地址
	printf("首元素地址：%d\n", arr);
	printf("第二个元素的地址：%d\n", arr+1);
	printf("第一个元素为:%d\n", arr[0]);
	printf("第一个元素为:%d\n", *(arr + 0) );

	printf("第二个元素为:%d\n", arr[1]);
	printf("第二个元素为:%d\n", *(arr + 1));

	for (int i = 0; i < 5; i++)
	{
		//printf("%d ", arr[i]);
		//printf("%d ", *(arr + i) );
		printf("%d ", i[arr]);

	}
	printf("\n");

	//[] 本质  * ()简写
	printf("第二个元素为: %d\n", *(1 + arr));
	printf("第二个元素为: %d\n",1[arr] );


	//arr为什么是第一个元素的地址
	// &arr[0]  ==  &*(arr+0) ==   (arr + 0)  ==  arr 
}

//利用指针操作数组
void test02()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	//定义一个指针变量，接受数组名
	int * p = arr;

	for (int i = 0; i < 5; i++)
	{
		//printf("%d ", *(p + i));
		printf("%d ", p[i]);
	}
	printf("\n");

	//p 和arr区别
	printf("sizeof arr = %d\n", sizeof (arr)); //20
	printf("sizeof p = %d\n", sizeof (p)); //4


	int *p2 = &arr[2];
	printf("%d\n", p2[1]); // 4
	printf("%d\n", p2[-1]);// 2
}


void test03()
{
	int arr[5] = { 1, 4, 7, 11, 14 };
	int * p = arr;

	printf("%d\n", *p++);   //1-先取出arr[0]==1；2-然后p++ p指向了arr[1]==4
	printf("%d\n", *p);//此时p指向了arr[1]==4
	printf("\n");

	printf("%d\n", (*p)++); //1-此时p依旧指向arr[1]==4,所以取出（*p）打印的结果为4；2-然后(*p)++,把arr[1]的值由4变为5
	printf("%d\n", *p);//此时p指向arr[1]==5
	printf("\n");

	printf("%d\n", *(p++)); //后置++，在计算单元结束后才执行，所以：1-先取出*p==5；2-然后p++，使得p指向了arr[3]==7
	printf("%d\n", *p);//此时p指向了arr[3]==7
	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		printf("%d ",arr[i]);
	}

	printf("\n");
}

void test04()
{
	int arr[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

	printf("%d\n", arr[*(arr + *(arr + arr[3]))]); // 7 

}

int main(){

	test03();

	
	system("pause");
	return EXIT_SUCCESS;
}