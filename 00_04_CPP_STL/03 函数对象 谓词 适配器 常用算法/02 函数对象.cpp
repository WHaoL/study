//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>

//1���º���������()�������ʹ����ʹ�ý׶���������
class MyPrint
{
public:
	void operator()(string test)
	{
		cout << test << endl;
		m_Count++;
	}
	int m_Count = 0;
};
void test01()
{
	MyPrint mp;
	mp("test01------hello world"); //���������ĺ���������һ������
}

//2���º�����������ͨ�����ĸ�������Լ�ӵ���ڲ���״̬
void myPrint(string test)
{
	cout << test << endl;
}

void test02()
{
	MyPrint mp;
	mp("test02------hello world");
	mp("test02------hello world");
	mp("test02------hello world");
	mp("test02------hello world");
	mp("test02------hello world");

	cout << "mpʹ�ô���Ϊ�� " << mp.m_Count << endl;
}

//3���������� ������Ϊ �����Ĳ���
void doWork(MyPrint mp, string str)
{
	mp(str);
}

void test03()
{
	MyPrint mp;
	doWork(mp, "hello");
}

int main()
{

	test01();

	test02();
	test03();
	//system("pause");
	return 0;
}