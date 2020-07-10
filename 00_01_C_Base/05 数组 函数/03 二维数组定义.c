#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//二维数组定义
void test01()
{
	//方式1
	//元素数据类型  数组名 【行数】【列数】
	int arr[2][3];

	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;
	arr[1][0] = 4;
	arr[1][1] = 5;
	arr[1][2] = 6;

	//printf("%d\n", arr[0][0]);
	//printf("%d\n", arr[0][1]);
	//printf("%d\n", arr[0][2]);

	//外层循环
	//for (int i = 0; i < 2; i++)
	//{
	//	//内层循环
	//	for (int j = 0; j < 3; j++)
	//	{
	//		printf("%d ", arr[i][j]);
	//	}
	//	printf("\n");
	//}

	//方式2  推荐
	int arr2[2][3] = { 
		{ 1, 2, 3 }, 
		{ 4, 5, 6 },  //最后一行结尾,可选添加
	};
	//for (int i = 0; i < 2; i++)
	//{
	//	//内层循环
	//	for (int j = 0; j < 3; j++)
	//	{
	//		printf("%d ", arr2[i][j]);
	//	}
	//	printf("\n");
	//}

	//方式3 
	int arr3[2][3] = { 1, 2, 3, 4, 5, 6 }; //本质也是一个一维数组，地址也是连续


	//方式4
	int arr4[][3] = { 1, 2, 3, 4, 5, 6 ,7};  //行数可以省略
	for (int i = 0; i < 3; i++)
	{
		//内层循环
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr4[i][j]);
		}
		printf("\n");
	}
}

//二维数组数组名
void test02()
{
	int arr[2][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },  
	};

	//可以查看整个数组占用内存空间大小
	printf("二维数组占用空间为%d\n", sizeof(arr)); //24
	printf("二维数组每行占用空间为%d\n", sizeof(arr[0])); //12
	printf("二维数组每个元素占用空间为%d\n", sizeof(arr[0][0])); // 4

	//二维数组 行数  列数
	printf("二维数组行数:%d\n", sizeof(arr) / sizeof(arr[0]));
	printf("二维数组列数:%d\n", sizeof(arr[0])/sizeof(arr[0][0]));

	//可以查看二维数组首地址
	printf("二维数组首地址 %d\n", arr);
	printf("二维数组第一行地址 %d\n", arr[0]);
	printf("二维数组第二行地址 %d\n", arr[1]);

	printf("第一个元素的地址:%d\n", &arr[0][0]);
	printf("第二个元素的地址:%d\n", &arr[0][1]);
}

//二维数组应用案例 求总和成绩
void test03()
{
	int scores[3][3] =
	{
		{ 100, 100, 100 },  //第一个人考试成绩  
		{ 90, 50, 80 },  //第二个人考试成绩 
		{ 70, 80, 90 },  //第三个人考试成绩 
	};

	//利用代码显示每个人的成绩的总和

	char* names[3] = {"张三", "李四", "王五"};

	int row = sizeof(scores) / sizeof(scores[0]);
	int col = sizeof(scores[0]) / sizeof(scores[0][0]);
	for (int i = 0; i <row; i++)
	{
		int sum = 0;
		for (int j = 0; j < col; j++)
		{
			sum += scores[i][j];
			printf("%d ", scores[i][j]);

		}
		printf("\n");
		printf("第%d个同学%s的总分为 %d\n", i + 1, names[i], sum);
		printf("第%d个同学%s的平均分为 %d\n", i + 1,names[i], sum / col);
	}


}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}