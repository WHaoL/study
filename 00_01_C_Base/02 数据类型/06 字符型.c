#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	//语法： char a = 'a';

	char ch = 'a';//字符变量 用单引号引起来
	
	//打印字符变量
	printf("ch = %c\n", ch);
	
	//查看字符型 占用内存空间是多少？？
	printf("sizeof char  = %d\n", sizeof(char)); //1个字节

	//字符变量 可以重新赋值
	ch = 'a';
	printf("ch = %c\n", ch);

	//ch = "abcde"; //不可以用双引号
	//ch = 'abcde'; //单引号内部 只能有一个字符


	//计算机中存放的所有数据都是 0或者1  ，那么字符该如何存储？？？
	//为了存储这些字符，给每个字符都对应一个数字，然后在进行存储
	//建立一个字符与数字关系的对照表 ASCII码表  美国信息交换标准代码
	//char 本质  小整型 
	printf("ch = %d\n", ch);


	char ch2 = 65;
	printf("ch2 = %c\n", ch2); // A 

	//A  ---  65    a --- 97    a-A = 32;

}

//大小写转换案例
void test02()
{
	//a  -> A
	char ch = 'a';
	printf("转换前： %c\n", ch);

	ch = ch - 32;
	printf("转换后： %c\n", ch);


	// Z  ->  z
	char ch2 = 'Z';
	printf("转换前： %c\n", ch2);
	ch2 = ch2 + 32;
	printf("转换后： %c\n", ch2);
}

int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}