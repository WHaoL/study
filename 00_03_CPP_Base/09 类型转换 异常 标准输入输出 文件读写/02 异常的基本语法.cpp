#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�쳣�������Զ������������
class myException
{
public:
	void printError()
	{
		cout << "���Լ����쳣" << endl;
	}
};

class Person
{
public:
	Person()
	{
		cout << "PersonĬ�Ϲ���" << endl;
	}
	~Person()
	{
		cout << "Person��������" << endl;
	}

};

int myDivision(int a ,int b)
{
	if ( b == 0)
	{
		//return -1; //��C������ ����-1�����쳣��ֵ.����-1�Ľ���޷��������쳣���Ƿ���ֵ

		//throw 1; //�׳�һ��int�����쳣
		//throw 'a'; //�׳�һ��char�����쳣
		//throw 3.14; //�׳�double�����쳣

		Person p1;
		Person p2;

		//��try��ʼ����throw�׳��쳣ǰ������ջ�ϵĶ��󶼱��ͷţ�������˳���빹����෴�ģ�������̳�Ϊջ����

		throw myException(); //�׳�һ��myException �쳣�Ķ���
	}
	return a / b;
}

void test01()
{
	int a = 10;
	int b = 0;

	try
	{
		myDivision(a, b);
	}
	catch (int)
	{
		cout << "int���͵��쳣����" << endl;
	}
	catch (char)
	{
		cout << "char���͵��쳣����" << endl;
	}
	catch (double d)
	{
		//���������쳣���봦������������׳������� throw�ؼ���
		throw;
		cout << "double���͵��쳣����" << endl;
	}
	catch (myException e)
	{
		e.printError();
	}
	catch (...)
	{
		cout << "�������͵��쳣����" << endl;
	}

	
	//if ( myDivision(a,b) == -1)
	//{
	//	cout << "�����쳣" << endl;
	//}
	//else
	//{
	//	cout << myDivision(a, b) << endl;
	//}
}

int main(){

	try
	{
		test01();
	}
	catch (int)
	{
		cout << "main������ int���͵��쳣����" << endl;
	}
	catch (...)
	{
		cout << "main������ �����쳣����" << endl;
	}

	//C++�е��쳣�����д��������������������Զ����� terminate �������ó�����ֹ
	

	system("pause");
	return EXIT_SUCCESS;
}