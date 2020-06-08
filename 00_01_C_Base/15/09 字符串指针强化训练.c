#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	//注意字符串结束标志 \0
	char str1[] = { 'h', 'e', 'l', 'l', 'o','\0' };
	printf("%s\n", str1);


	char str2[100] = { 'h', 'e', 'l', 'l', 'o' };
	printf("%s\n", str2);

	char str3[] = "hello";
	printf("%s\n", str3);
	printf("sizeof str:%d\n", sizeof(str3)); //6
	printf("strlen str:%d\n", strlen(str3)); //5
}

void test02()
{
	char str4[100] = "hello";
	printf("sizeof str:%d\n", sizeof(str4)); //100
	printf("strlen str:%d\n", strlen(str4)); //5
}

void test03()
{
	char str5[] = "hello\0world";
	printf("%s\n", str5);
	printf("sizeof str5:%d\n", sizeof(str5)); // 12 
	printf("strlen str5:%d\n", strlen(str5)); // 5 
}

void test04()
{
	char str6[] = "hello\012world";
	printf("%s\n", str6);  // \012 是八进制是数字  转为十进制是10，而10的ASCII码是换行
	printf("sizeof str6:%d\n", sizeof(str6)); //12
	printf("strlen str6:%d\n", strlen(str6)); //11 
}

int main(){

	test04();

	system("pause");
	return EXIT_SUCCESS;
}