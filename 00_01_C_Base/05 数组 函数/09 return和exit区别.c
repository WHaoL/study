#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	printf("01\n");
	printf("02\n");
	printf("03\n");
	return;  //�˳���ǰ����
	//system("pause");
	//exit(0); //�˳�����
	printf("04\n");
	printf("05\n");
	printf("06\n");

}
//return �Ľ��Ϊ�� 1 2 3  01 02 03 4 5 6 
//exit �Ľ��Ϊ�� 1 2 3 01 02 03 
int main(){

	printf("1\n");
	printf("2\n");
	printf("3\n");
	test01();
	printf("4\n");
	printf("5\n");
	printf("6\n");

	system("pause");
	return EXIT_SUCCESS;
}