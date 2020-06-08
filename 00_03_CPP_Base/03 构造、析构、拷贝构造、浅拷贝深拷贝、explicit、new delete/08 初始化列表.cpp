#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:

	// 构造函数形参列表后面 + :  属性（值）,属性（值）...
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c)
	{
		cout << "Person构造调用" << endl;
	}

	/*Person(int a ,int b,int c)
	{
	m_A = a;
	m_B = b;
	m_C = c;
	}*/

	int m_A;
	int m_B;
	int m_C;
};

void test01()
{
	Person p1(10, 20, 30);

	cout << "m_A = " << p1.m_A << endl;
	cout << "m_B = " << p1.m_B << endl;
	cout << "m_C = " << p1.m_C << endl;
}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}