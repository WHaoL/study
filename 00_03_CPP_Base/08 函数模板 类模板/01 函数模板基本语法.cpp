#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//int���ͽ���
void swapInt(int&a ,int&b)
{
	int temp = a;
	a = b;
	b = temp;
}

//double����
void swapDouble(double&a, double&b)
{
	double temp = a;
	a = b;
	b = temp;
}

//����ģ��ʵ�ֽ���
template<typename T> //T����ͨ�õ��������ͣ����߱�������������ŵĺ����������г�����T����Ҫ����
void mySwap(T&a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void mySwap2()
{
}

void test01()
{
	int a = 10;
	int b = 20;
	//swapInt(a, b);
	char c = 'c';
	//1���Զ������Ƶ��������Ƶ���һ�µ�T���ͣ������޷�����
	//mySwap(a, c); error �޷��Ƶ���һ�µ�T

	//2����ʾָ������
	mySwap<int>(a, b);

	//ע�����ģ�岻���Զ���ʹ�ã�����ȷ��T����
	mySwap2<double>();

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	double d1 = 1.1;
	double d2 = 2.2;
	//swapDouble(d1, d2);
	mySwap(d1, d2);
	cout << "d1 = " << d1 << endl;
	cout << "d2 = " << d2 << endl;
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}