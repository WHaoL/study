#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�����ӡ
void reversePrint(char * str)
{
	//�ݹ��������
	if (*str == '\0')
	{
		return;
	}

	reversePrint(str + 1);
	printf("%c", *str);
}

void test01()
{
	char * str = "abc";

	reversePrint(str);

}


//쳲���������  
// 1 1 2 3 5 8 13 21 34  55

int fibonacci(int pos)
{
	if (pos==1 || pos == 2)
	{
		return 1;
	}

	return fibonacci(pos - 1) + fibonacci(pos - 2);
}

void test02()
{
	int ret = fibonacci(10);

	printf("%d\n", ret);

}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}