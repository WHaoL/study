#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

class myPrint
{
public:

	//���� ()
	void operator()(string text)
	{
		cout << text << endl;
	}

};

void MyPrint(string text)
{
	cout << text << endl;
}

void test01()
{
	myPrint mp;
	mp("hello world"); // �º���  ʹ�÷���������ĵ��ã���˳�Ϊ�º���
	//������һ������������ǳ������Ķ���Ϊ ��������

	MyPrint("hello world");
}

//�º����ǳ���û�й̶���д��
class MyAdd
{
public:
	int operator()(int a ,int b)
	{
		return a + b;
	}
};

void test02()
{
	/*MyAdd add;
	cout << add(10, 10) << endl;*/

	cout << MyAdd()(10, 10) << endl;//������������  �ص㣺��ǰ��ִ���꣬�����ͷ�
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}