#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//sprintf使用
void test01()
{
	char buf[1024] = { 0 };

	int a = 0;
	scanf("%d", &a);
	sprintf(buf, "今天是%d年 %d月 %d日", a, 6, 6);

	printf("buf = %s\n", buf);


	//字符串拼接
	memset(buf, 0, 1024);
	char str1[] = "hello";
	char str2[] = "world";
	int len = sprintf(buf, "%s %s", str1, str2);  //sprintf返回值是字符串的长度
	printf("buf:%s len:%d\n", buf, len);

	//数字转字符串
	memset(buf, 0, 1024);
	int num = 100;
	sprintf(buf, "%d", num);
	printf("buf:%s\n", buf);

}

void test02()
{
	char buf[1024] = { 0 };
	int num = 100;
	//设置宽度 右对齐
	memset(buf, 0, 1024);
	sprintf(buf, "%8d", num); //设置宽度为8  ，数字右对齐
	printf("buf:%s\n", buf);
	printf("buf:1111111111111\n");

	//设置宽度 左对齐
	memset(buf, 0, 1024);
	sprintf(buf, "%-8d", num); //设置宽度为8  ，数字左对齐
	printf("buf:%s111\n", buf);
	printf("buf:1111111111111\n");

	////转成16进制字符串 小写
	memset(buf, 0, 1024);
	sprintf(buf, "0x%x", num);
	printf("buf:%s\n", buf); //0x64

	//转成8进制字符串
	memset(buf, 0, 1024);
	sprintf(buf, "0%o", num); //0144
	printf("buf:%s\n", buf);

}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}