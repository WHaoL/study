#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


void func(double d)
{
	cout << "func double ����" << endl;
}

void func(float d)
{
	cout << "func float ����" << endl;
}

void test01()
{
	//�곣��������������
	#define  PI 3.14

	const float Pi = 3.14;

	//�곣�� û��������������
	func(Pi);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}