#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

//ģ���� Ҳ������Ĭ�ϲ���
template<class NAMETYPE ,class AGETYPE = int >
class Person
{
public:
	Person(NAMETYPE name, AGETYPE age = 18)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "������ " << this->m_Name << " ���䣺 " << this->m_Age << endl;
	}

	NAMETYPE m_Name;
	AGETYPE m_Age;
};

void test01()
{
	//��ģ��ʹ�õ�ʱ�򣬲��������Զ������Ƶ� ��ֻ��ʹ����ʾָ������
	//Person p1("Tom", 18);

	Person <string> p1("Tom", 18);
	p1.showPerson();
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}