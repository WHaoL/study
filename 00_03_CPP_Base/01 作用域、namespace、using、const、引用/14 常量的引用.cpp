#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void test01()
{
	//int &ref = 10;//���ñ������Ϸ��ڴ�ռ�

	const int &ref = 10; //�������Ż����룺 int temp = 10;  const int &ref = temp;

	//ref = 1000;

	int * p = (int *)&ref;
	*p = 1000;
	cout << ref << endl;

}

//constʹ�ó���  �������κ����βΣ���ֹ�����е������
void showNum(const int & a) // const int & a = a;
{
	//a = 10000;
	cout << a << endl;
}

void test02()
{
	int a = 10;
	showNum(a);
}

int main(){
	test02();


	system("pause");
	return EXIT_SUCCESS;
}