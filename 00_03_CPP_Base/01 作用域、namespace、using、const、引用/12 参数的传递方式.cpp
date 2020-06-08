#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//ֵ����
void mySwap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	mySwap(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}

//��ַ����
void mySwap2(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void test02()
{
	int a = 10;
	int b = 20;
	mySwap2(&a, &b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

//���ô���
void mySwap3(int &a,int &b) // int &a = a , int &b = b;
{
	int temp = a;
	a = b;
	b = temp;
}
void test03()
{
	int a = 10;
	int b = 20;
	mySwap3(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}


//����ע������
int& func()
{
	int a = 1000;
	return a;
}

void test04()
{
	//1�����ñ�����һ��Ϸ����ڴ�ռ�
	int a = 10;
	//int &b = 10; error 10�ڳ������У��������������޸��ڴ�
	

	//2����Ҫ���ؾֲ�����������
	int& ret = func();
	cout << "ret = " << ret << endl;
	cout << "ret = " << ret << endl;
	cout << "ret = " << ret << endl;
}



int& func2()
{
	static int a = 1000;
	return a;
}

void test05()
{

	int& ret = func2();

	cout << "ret = " << ret << endl;
	
	//�����ķ���ֵ��������ã���ô�����ĵ��ÿ�����Ϊ��ֵ
	func2() = 10000;

	cout << "ret  = " << ret << endl;
}



int main(){

	test05();

	system("pause");
	return EXIT_SUCCESS;
}