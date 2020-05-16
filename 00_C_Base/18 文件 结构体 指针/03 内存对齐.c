#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//#pragma pack (show)  //打印的就是对齐模数 默认是  8

//#pragma pack (1) //修改对齐模数  可以改成2的n次方

//内存对齐原则
//第一个属性计算，从0开始偏移
//第二个属性计算，要放在  数据类型大小  与 对齐模数比 取小的值 的整数倍
//都计算完毕后，整体做二次偏移，这个结构体的大小要扩充到 整个结构体中最大的类型 与对齐模数比 取小的值的整数倍

typedef struct _STUDENT{
	int a;    // 0 ~ 3      // 0 ~ 3
	char b;   // 4 ~ 7      // 4 ~ 4
	double c; // 8 ~ 15     // 5 ~ 12 
	float d;  // 16~ 19     // 13 ~ 16
}Student;

void test01()
{
	printf("sizeof = %d\n", sizeof(Student)); // 24
}


//当结构体嵌套结构体 如果计算偏移
typedef struct _STUDENT2{
	char a;     // 0 ~ 7
	Student b;  // 8 ~ 31 
	double c;   //32 ~ 39
}Student2;

void test02()
{
	
	printf("sizeof = %d\n", sizeof(Student2));
}


int main(){

	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}