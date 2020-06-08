#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int myStrstr(char * str , char * subStr)
{
	int num = 0;
	while (*str != '\0')
	{
		//如果指针指向的内容不是d，str偏移，执行下一次循环
		if (*str != *subStr)
		{
			str++;
			num++;
			continue;
		}

		//下面的代码 就是str指向d之后的逻辑
		//创建小的临时指针
		//memcmp(src,dst,3) == 0;

		char * tmpStr = str;
		char * tmpSubStr = subStr;

		while (*tmpSubStr != '\0')
		{
			if (*tmpStr != *tmpSubStr) //临时指针指向的内容不等
			{
				//匹配失败 跳过
				str++;
				num++;
				break;
			}
			tmpStr++;
			tmpSubStr++;
		}

		//匹配成功条件
		if (*tmpSubStr == '\0')
		{
			return num;
		}
	}

	return -1;

}

void test01()
{
	char * str = "abcdefgdnfaaaa";

	int ret = myStrstr(str, "dnf");

	if (ret != -1)
	{
		printf("找到了子串，位置是：%d\n", ret);
	}
	else
	{
		printf("未找到子串\n");
	}
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}