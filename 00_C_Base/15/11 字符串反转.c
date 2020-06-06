#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void reverseString(char * str)
{
	int len = strlen(str);

	int start = 0; //���±�
	int end = len - 1; //β�±�

	while (start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		start++;
		end--;
	}
}

void reverseString2(char * str)
{
	int len = strlen(str);

	char * start = str; //��ָ�� ָ���һ��Ԫ��
	char * end = str + len - 1; //βָ��  ָ�����������һ��Ԫ��

	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}

}

void test01()
{
	char str[] = "abcdefg";

	//reverseString(str);

	reverseString2(str);

	// g f e d c b a 
	printf("str = %s\n", str);
}


int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}