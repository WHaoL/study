#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�쳣 ���� �쳣�Ļ���
class BaseException
{
public:
	virtual void printError() = 0;
};

//��ָ����쳣��
class NULLPointer :public BaseException
{
public:
	void printError()
	{
		cout << "��ָ���쳣" << endl;
	}
};

//�������Խ��
class OutOfRange :public BaseException
{
public:
	void printError()
	{
		cout << "Խ���쳣" << endl;
	}
};

void func()
{
	//throw NULLPointer();
	throw OutOfRange();
}

void test01()
{
	try
	{
		func();
	}
	catch (BaseException & e)
	{
		e.printError();
	}
}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}