#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//设置数组
void setCharArray(char * arr ,int num)
{
	printf("请输入一个字符串\n");

	fgets(arr, num, stdin); //stdin标准输入设备 键盘
}

//统计字符个数 自己实现
int myStrlen(char * arr)
{
	//hello world\0\0\0\0
	int count = 0; //记录字符个数 

	while (arr[count] != '\0')
	{
		count++;
	}

	return count;

	//简化版本 
	//while (arr[count++]){}
	//return count - 1;
}


//改变字符数组，大写转小写，小写转大写
void changeArray(char *arr)
{
	int index = 0;
	while ( arr[index] != '\0')
	{
		//printf("%c", arr[index]);
		if (arr[index] >= 'a' && arr[index] <= 'z')
		{
			arr[index] = arr[index] - ('a' - 'A');
		}
		else if (arr[index] >= 'A' && arr[index] <= 'Z')
		{
			arr[index] = arr[index] + ('a' - 'A');
		}
		index++;
	}
}

void test01()
{
	char buf[1024] = { 0 };

	//设置数据
	setCharArray(buf,sizeof(buf));

	//hello world\n\0\0\0
	buf[strlen(buf) - 1] = '\0'; //将\n的字符改为\0

	//打印输出
	printf("%s\n", buf);

	//统计字符串个数  strlen
	int count = myStrlen(buf);
	printf("count = %d\n", count);
	printf("count = %d\n", strlen(buf));

	//字符串大小写转换  
	//小写 转 大写     大写 转 小写
	changeArray(buf);
	printf("转换后的结果为\n");
	printf("%s\n", buf);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}