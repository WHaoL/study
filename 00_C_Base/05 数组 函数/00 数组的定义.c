#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//数组的定义
//数组：就是一个集合，里面存放是相同类型的数据元素
//数据元素之间的地址位置是连续的

void test01()
{
	//定义方式1
	//数据类型  数组名 [元素个数];
	//初始的数据是随机
	int score[10]; // 数组名 score ， 数组中存放最多10个数据，每个数据的数据类型  int

	//给数组元素赋值
	//从0开始索引位置
	score[0] = 100;
	score[1] = 99;
	score[2] = 98;
	score[9] = 60;
	//score[10] = 100; //下标越界

	//利用下标法输出
	//printf("%d\n", score[0]);
	//printf("%d\n", score[1]);
	//printf("%d\n", score[2]);
	//printf("%d\n", score[9]);


	//定义方式2
	//数据类型  数组名 [元素个数] = {值1，值2 ，值3 ...}

	int score2[10] = { 0,1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int score2[10] = { 0, 1, 2, 3, 4, 5}; //不足的10个数据，剩余的位置用0填充
	//int score2[10] = { [1] = 10 , [5] = 50 , [7] = 70};  //部分初始化

	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d\n", score2[i]);
	//}
	//
	//定义方式3
	//数据类型  数组名[] = {值1，值2 ，值3 ...}
	int score3[] = { 1, 2, 3, 4, 5 ,6,7,8};

	for (int i = 0; i < 8; i++)
	{
		printf("%d\n", score3[i]);
	}
}



//一维数组名称
void test02()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//1、统计整个数组占用内存空间大小
	printf("sizeof arr =  %d\n", sizeof(arr));
	printf("每个数据占用空间大小 = %d\n", sizeof(arr[0]));
	printf("数组中元素的个数 = %d\n", sizeof (arr) / sizeof(int));

	//2、通过数组的名称，获取到数组的首地址
	printf("数组的首地址为:%x\n", arr);  //%p可以用十六进制显示  %d用十进制显示地址
	//printf("数组的首地址为:%p\n", arr);


	printf("数组中第一个元素的地址：%d\n", &arr[0]);
	printf("数组中第二个元素的地址：%d\n", &arr[1]);
	printf("数组中第三个元素的地址：%d\n", &arr[2]);

	//数组名常量，不可以赋值
	//arr = 100; error不可以给数组名赋值


}

//五只小猪称体重
void test03()
{
	int arr[5] = { 300, 350, 1500, 400, 1000 };

	//手动输入五只猪体重
	//for (int i = 0; i < 5; i++)
	//{
	//	scanf("%d", &arr[i]);
	//}

	//在数组中找到最大值
	int max = 0; //认定第一个数就是最大值 ，记录下标
	int num = sizeof(arr) / sizeof(int); //数组元素个数
	for (int i = 1; i < num;i++)
	{
		if (arr[i]> arr[max]) //说明遍历的下标的元素更大
		{
			max = i;
		}
	}

	printf("最重的猪是%d 号 最重的体重为：%d\n",max + 1,arr[max]);

}

int main(){
	test02();


	system("pause");
	return EXIT_SUCCESS;
}