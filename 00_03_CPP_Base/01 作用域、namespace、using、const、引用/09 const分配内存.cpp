#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

//1����const�ı���ȡ��ַ���������ʱ�ڴ�
void test01()
{
	const int m_a = 100;
	int * p = (int *)&m_a; // ������ʱtemp�������ڴ�
}

//2��ʹ�ñ��� ����ʼ��const���εı���
void test02()
{
	int a = 100;
	const int m_a = a;

	int * p = (int *)&m_a;
	*p = 1000;
	cout << m_a << endl;
}

//3�������Զ����������ͣ������ڴ�
struct Person
{
	string name;
	int age;
};
void test03()
{
	const Person p; //����ջ��

	//p.age = 10;
	Person * pp = (Person *)&p;

	pp->name = "����";
	pp->age = 18;

	cout << "������ " << p.name << " ���䣺 " << p.age << endl;
}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}