#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

//编译器会默认个一个类添加4个函数  默认构造(空实现)  拷贝构造（值拷贝） 析构函数（空实现）  operator=（值拷贝）
class Person
{
public:
    Person(char *name, int age)
    {
        this->m_Name = new char[strlen(name) + 1];
        strcpy(this->m_Name, name);

        this->m_Age = age;
    }

    //重载=运算符
    Person &operator=(const Person &p)
    {
        //先判断原来释放有堆区的数据  如果有 释放
        if (this->m_Name != NULL)
        {
            delete[] this->m_Name;
            this->m_Name = NULL;
        }

        this->m_Name = new char[strlen(p.m_Name) + 1];
        strcpy(this->m_Name, p.m_Name);

        this->m_Age = p.m_Age;

        return *this;
    }

    //拷贝构造
    Person(const Person &p)
    {
        this->m_Name = new char[strlen(p.m_Name) + 1];
        strcpy(this->m_Name, p.m_Name);

        this->m_Age = p.m_Age;
    }

    ~Person()
    {
        if (this->m_Name != NULL)
        {
            delete[] this->m_Name;
            this->m_Name = NULL;
        }
    }

    char *m_Name;
    int m_Age;
};

void test01()
{
    Person p1("Tom", 18);
    cout << "p1的姓名： " << p1.m_Name << " 年龄： " << p1.m_Age << endl;

    Person p2("Jerry", 20);
    cout << "p2的姓名： " << p2.m_Name << " 年龄： " << p2.m_Age << endl;

    //p1 = p2; //赋值

    Person p3(" ", 10);
    cout << "p3的姓名： " << p3.m_Name << " 年龄： " << p3.m_Age << endl;

    p3 = p1 = p2;

    cout << "p1的姓名： " << p1.m_Name << " 年龄： " << p1.m_Age << endl;
    cout << "p2的姓名： " << p2.m_Name << " 年龄： " << p2.m_Age << endl;
    cout << "p3的姓名： " << p3.m_Name << " 年龄： " << p3.m_Age << endl;
}

int main()
{

    test01();

    /*int a = 10;
	int b = 20;
	int c = 30;

	c = a = b;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;*/

    system("pause");
    return EXIT_SUCCESS;
}