#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

//模板中 也可以有默认参数
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
		cout << "姓名： " << this->m_Name << " 年龄： " << this->m_Age << endl;
	}

	NAMETYPE m_Name;
	AGETYPE m_Age;
};

void test01()
{
	//类模板使用的时候，不可以用自动类型推导 ，只能使用显示指定类型
	//Person p1("Tom", 18);

	Person <string> p1("Tom", 18);
	p1.showPerson();
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}