#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1��show����" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2��show����" << endl;
	}
};


template<class T>
class MyClass
{
public:

	//��ģ���еĳ�Ա������һ��ʼ�ǲ��ᴴ�������ģ�ֻ������ʱȷ��T���Ŵ����������
	void func1()
	{
		obj.showPerson1();
	}

	void func2()
	{
		obj.showPerson2();
	}

	T obj;
};

void test01()
{
	MyClass <Person1>mc;
	//mc.func1();
	//mc.func2();
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}