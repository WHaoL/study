#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、 memset 内存赋值
void test01()
{
	char buf[32] = "hello world";
	printf("buf = %s\n", buf);

	//参数1  目标内存首地址   参数2  赋的具体值   参数3  赋值大小 
	memset(buf, 'a', 32);
	printf("buf = %s\n", buf);

	//用途：清空内存
	memset(buf, 0, 32);
	printf("buf = %s\n", buf);

}

//2 memcpy 内存拷贝
void printArray(char * arr , int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%c", arr[i]);
	}
	printf("###\n");
}

void test02()
{
	//拷贝字符串
	char dst[64] = { 0 };
	char src[64] = "hello\0world";

	strcpy(dst, src); //遇到\0结束拷贝
	printArray(dst, sizeof(dst)); 

	//内存拷贝
	memset(dst, 0, sizeof(dst));
	memcpy(dst, src, sizeof(src)); //不会遇到\0就结束

	printArray(dst, sizeof(dst));

	//用途：给数组赋值
	int arr1[5] = { 0 };
	int arr2[5] = { 1, 2, 3, 4, 5 };

	memcpy(arr1, arr2, sizeof(arr2));
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", arr1[i]);
	}
}

//3、memmove 内存移动
void test03()
{
	int arr[5] = { 10, 20, 30, 40, 50 };

	//memcpy(arr + 2, arr + 1, 3 * sizeof(int));

	memmove(arr + 2, arr + 1, 3 * sizeof(int)); //效率比memcpy稍微低，安全

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", arr[i]);
	}
}

//4、memcmp  内存比较   
void test04()
{
	char str1[32] = "hello\0world";
	char str2[32] = "hello\0c";

	if (strcmp(str1,str2) == 0)
	{
		printf("相等\n");
	}
	else if (strcmp(str1, str2) > 0)
	{
		printf("str1 > str2 \n");
	}
	else
	{
		printf("str1 < str2 \n");
	}

	//不会遇到\0结束比较
	if (memcmp(str1, str2, sizeof(str1)) == 0)
	{
		printf("相等\n");
	}
	else if (memcmp(str1, str2, sizeof(str1)) > 0)
	{
		printf("str1 > str2 \n");
	}
	else
	{
		printf("str1 < str2 \n");
	}

	//对比两个数组
	int arr1[] = { 10, 20, 30, 30, 50 };
	int arr2[] = { 10, 20, 30, 30, 50 };

	if (memcmp(arr1, arr2, sizeof(arr1)) == 0)
	{
		printf("相等\n");
	}
	else if (memcmp(arr1, arr2, sizeof(arr1)) > 0)
	{
		printf("arr1 > arr2 \n");
	}
	else
	{
		printf("arr1 < arr2 \n");
	}
    
}


int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}