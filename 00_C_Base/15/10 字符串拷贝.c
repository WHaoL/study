#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//第一种实现 利用下标方式  []
void copyString1(char* dest,char * src )
{
	int len = strlen(src);
	for (int i = 0; i < len;i++)
	{
		dest[i] = src[i];
	}
	dest[len] = '\0';
}


//第二种实现  利用字符串指针
void copyString2(char* dest, char * src)
{
	while (*src != '\0')
	{
		*dest = *src;

		dest++;
		src++;
	}

	*dest = '\0';
}

//第三种 
void copyString3(char* dest, char * src)
{
	while (*dest++ = *src++){}

	//int a = 0;
	//while (a = 0)
	//{
	//	printf("a");
	//}

}

void test01()
{
	char * str = "hello world";

	char buf[1024];

	//需求 将str中的内容，拷贝到 buf中
	//copyString1(buf,str);
	//copyString2(buf, str);
	copyString3(buf, str);
	printf("buf = %s\n", buf);
}

int main(){

	test01();



	system("pause");
	return EXIT_SUCCESS;
}