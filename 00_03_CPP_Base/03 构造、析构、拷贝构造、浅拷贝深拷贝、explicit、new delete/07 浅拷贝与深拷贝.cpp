#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}

	Person(char * name ,int age)
	{
		cout << "Person的有参构造函数调用" << endl;

		//将name分配到堆区
		m_Name = (char *)malloc(strlen(name) + 1);
		strcpy(m_Name, name);
		m_Age = age;
	}

	//拷贝构造函数
	Person(const Person & p)
	{
		cout << "Person的拷贝构造函数调用" << endl;
		m_Age = p.m_Age;

		//m_Name = p.m_Name; //编译器提供的浅拷贝代码

		m_Name =(char *)malloc(strlen(p.m_Name) + 1);
		strcpy(m_Name, p.m_Name);
	}

	~Person()
	{
		//析构函数清理数据
		cout << "Person的析构函数调用" << endl;

		if (m_Name != NULL)
		{
			free(m_Name);
			m_Name = NULL;
		}
	}

	char * m_Name;
	int m_Age;
};

void test01()
{
	Person p1("Tom", 18);
	cout << "p1 姓名： " << p1.m_Name << " 年龄： " << p1.m_Age << endl;

	Person p2(p1);
	cout << "p2 姓名： " << p2.m_Name << " 年龄： " << p2.m_Age << endl;
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}