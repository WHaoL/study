#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class myException
{
public:

	myException()
	{
		cout << "myException��Ĭ�Ϲ��캯������" << endl;
	}

	myException(const myException &)
	{
		cout << "myException�Ŀ������캯������" << endl;
	}

	~myException()
	{
		cout << "myException��������������" << endl;
	}

};

void func()
{
	throw new myException();
}

void test01()
{
	try
	{
		func();
	}
	// ��catch (myException e)   throw myException(); ����ÿ������캯���������µĶ���
	// ��catch (myException &e)  throw myException(); ֻ��һ���쳣����    �Ƽ�
	// ��catch (myException *e)  throw &myException(); �쳣�������ǰ���ͷţ���˲�����ʹ��
	// ��catch (myException *e)  throw new myException(); �߼�������һ���ģ�����Ҫ�Լ���delete
	catch (myException * e)
	{
		cout << "���Լ����쳣����" << endl;

		delete e;
	}

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}