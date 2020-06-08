#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//枚举中的每个值 从0开始 依次递增
enum POKER
{
	HONGTAO , HEITAO = 3, MEIHUA = 7,  FANGPIAN = 7
};

void test01()
{
	enum POKER poker;
	poker = MEIHUA;
	printf("%d\n", poker);

	printf("hongtao = %d\n", HONGTAO); // 0
	printf("heitao = %d\n", HEITAO);   //3
	printf("meihua = %d\n", MEIHUA);   //7
	printf("fangpian = %d\n", FANGPIAN); // 7

	//HONGTAO = 1; // error 枚举元素的值 是不可以修改的 类似于 #define  HONGTAO 0
}

//BOOL 布尔数据类型 ，代表真和假的一种类型，在C下没有，如果想模仿出来，可以用enum
// 真 ---  TRUE     假  --- FALSE  
enum  BOOL
{
	FALSE, //假
	TRUE   //真
};

void test02()
{
	enum BOOL flag;
	//flag = FALSE;
	flag = TRUE;
	if (flag == TRUE)
	{
		printf("标志flag为真\n");
	}
	else
	{
		printf("标志flag为假\n");
	}
}

enum 
{
	WIDTH = 1000,
	HEIGHT =1000
};
void test03()
{
	printf("墙的宽度为：%d\n", WIDTH);
	printf("墙的高度为：%d\n", HEIGHT);
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}