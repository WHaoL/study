#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son :public Base
{
public:
	//���������еĳ�Ա���Զ�������̳���һ�ݣ�˽������ֻ�Ǳ��������������ˣ���˷��ʲ���
	int m_D;
};


// C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\Shortcuts
// ��ת�̷� F:
// cd ��ת.cpp�ļ�Ŀ¼��
// cl /d1 reportSingleClassLayoutSon 06.....cpp
void test01()
{
	cout << "sizeof Son =" << sizeof(Son) << endl; //16
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}