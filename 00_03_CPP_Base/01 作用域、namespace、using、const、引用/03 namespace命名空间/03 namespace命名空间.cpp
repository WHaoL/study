#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "game1.h"
#include "game2.h"


//1�������ռ���;��������Ƴ�ͻ
void test01()
{
	LOL::goAtk();

	KingGlory::goAtk();
}

//2�������ռ��¿��Դ�ű������������ṹ�塢��...
namespace A
{
	int a = 0;
	void func(){};
	struct Person {};
	class Animal{};
}

//3�������ռ����������ȫ����������
void test02()
{
	//namespace B  //error ����д��ȫ����
	//{
	//}
}

//4�������ռ����Ƕ�������ռ�
namespace B
{
	int m_A = 10;
	namespace C
	{
		int m_A = 20;
	}
}

void test03()
{
	cout << "B�����ռ��µ�m_A =  " << B::m_A << endl;
	cout << "C�����ռ��µ�m_A =  " << B::C::m_A << endl;
}

//5�������ռ��ǿ��ŵģ�������ʱ�������ռ������������
namespace B
{
	int m_B = 1000;
}

void test04()
{
	cout << "B�����ռ��µ�m_A =  " << B::m_A << endl;
	cout << "B�����ռ��µ�m_B =  " << B::m_B << endl;
}

//6�������ռ������������

int m_C = 100;
namespace 
{
	int m_C = 100; //���Ե���ȫ�ֱ���  
	int m_D = 200; //�������ռ�����������£��������ǰ����ʽ��static�ؼ���
}
void test05()
{
	cout << "m_C = " << ::m_C << endl;
	cout << "m_D = " << m_D << endl;
}

//7�������ռ���������
namespace veryLongName
{
	int m_E = 10000;
}
void test06()
{
	namespace vertShortName = veryLongName;
	cout << "m_E = " << veryLongName::m_E << endl;
	cout << "m_E = " << vertShortName::m_E << endl;
}

int main(){

	test06();


	system("pause");
	return EXIT_SUCCESS;
}