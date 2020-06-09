// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <stdexcept>

//�ҵ�Խ���쳣��
class MyOutOfRange : public exception
{
public:
	MyOutOfRange(const string &errInfo)
	{
		this->m_ErrorInfo = errInfo;
	}

	MyOutOfRange(const char *errInfo)
	{
		//const char * תΪ string
		this->m_ErrorInfo = string(errInfo);
	}

	// noexcept ˵���� (C++11 ��)   ָ�������Ƿ��׳��쳣��
	// �﷨��
	//		noexcept 			(1)
	// 		noexcept(���ʽ) 	(2)
	// ˵����
	// 1) �� noexcept ( true ) ��ͬ
	// 2) �� ���ʽ ��ֵΪ true������������Ϊ���׳��κ��쳣��
	virtual const char *what() const noexcept(true)
	{
		//string תΪ  const char *
		return this->m_ErrorInfo.c_str();
	}

	// noexcept �����(C++11) 	ȷ�����ʽ�Ƿ���׳��κ��쳣
	// throw ���ʽ 			�������󲢽�����ת�Ƶ��������
	// move_if_noexcept(C++11)	���ƶ����캯�����׳�������ֵ���� (����ģ��)

	string m_ErrorInfo; //ά��������Ϣ
};

class Person
{
public:
	Person(int age)
	{
		if (age < 0 || age > 150)
		{
			//throw out_of_range("����Ӧ����0~150֮��");
			throw MyOutOfRange("���Լ����쳣 --- ����Ӧ����0~150֮�� ");
		}

		this->m_Age = age;
	}

	int m_Age;
};

void test01()
{
	try
	{
		Person p1(151);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}

int main()
{

	test01();

	// system("pause");
	return EXIT_SUCCESS;
}