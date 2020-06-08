#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person
{
public:
    Person() {}
    Person(int a, int b) : m_A(a), m_B(b)
    {
    }

    //利用成员函数重载+
    //Person operator+(Person & p)
    //{
    //	Person temp;
    //	temp.m_A = this->m_A + p.m_A;
    //	temp.m_B = this->m_B + p.m_B;
    //	return temp;
    //}

    int m_A;
    int m_B;
};

//利用全局函数重载 +
Person operator+(Person &p1, Person &p2)
{
    cout << " Person operator+(Person &p1, Person &p2) " << endl;
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}

Person operator+(Person &p1, int num)
{
    cout << " Person operator+(Person &p1, int num) " << endl;
    Person temp;
    temp.m_A = p1.m_A + num;
    temp.m_B = p1.m_B + num;
    return temp;
}

void test01()
{
    Person p1(10, 10);
    Person p2(20, 20);
    Person p3 = p1 + p2;

    //成员函数 本质调用
    //Person p3 = p1.operator+(p2);

    //全局函数 本质调用
    //Person p3 = operator+(p1, p2);

    cout << "p3.m_A = " << p3.m_A << " m_B = " << p3.m_B << endl;

    //运算符重载  可不可以实现 函数重载？ 可以
    Person p4 = p1 + 100;
    cout << "p4.m_A = " << p4.m_A << " m_B = " << p4.m_B << endl;
}

int main()
{

    test01();

    int a = 2, b = 3, c = 4;
    cout << (((a + b) > c) && (b = c)) << endl;
    cout << "b = " << b << endl;

    system("pause");
    return EXIT_SUCCESS;
}