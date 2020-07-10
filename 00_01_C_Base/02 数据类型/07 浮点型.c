#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//浮点型

//浮点型 常量
void test01()
{
	//float （单精度）占用4字节 
	//double （双精度）占用8字节

	printf("sizeof = %d\n",sizeof(3.14));//默认认为小数是double数据类型

	printf("sizeof = %d\n", sizeof(3.14f));//加入f变为float数据类型
}

//浮点型 变量
void test02()
{
	//float a = 1.111f; //默认小数点后 显示6位
	//printf("%f\n", a);
	//printf("%.2f\n", a); //就显示两位小数

	//double b = 2.222;
	//printf("%lf\n", b);
	//printf("%.3lf\n", b); //显示3位小数

	//float 精确 7有效数字
	//double 精确 15~16有效数字
	float PI1 = 3.141592653589793f;
	printf("PI1 = %.10f\n", PI1);
	
	double PI2 = 3.141592653589793;
	printf("PI1 = %.10lf\n", PI2);
}

//浮点型 表示方式 之  科学计数法
void test03()
{
	float f1 = 3e2; // 3 * 10 ^ 2
	printf("%f\n", f1);
	float f2 = 3e-2;  //  3 * 0.1 ^ 2
	printf("%f\n", f2);

}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}