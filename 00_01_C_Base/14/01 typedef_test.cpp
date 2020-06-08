#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main1()
{

	//char * p1, p2;
	typedef char * PCHAR;
	PCHAR p1, p2;

	printf("p1的数据类型为:%s\n", typeid(p1).name());
	printf("p2的数据类型为:%s\n", typeid(p2).name());


	system("pause");
	return EXIT_SUCCESS;
}