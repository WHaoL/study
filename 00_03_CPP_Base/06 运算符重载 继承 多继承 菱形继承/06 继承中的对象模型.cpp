#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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

class Son : public Base
{
public:
    //父类中所有的成员属性都被子类继承了一份，
    //私有属性只是被编译器给隐藏了，因此访问不到
    int m_D;
};

void test01()
{
    cout << "sizeof Son =" << sizeof(Base) << endl; //sizeof Son =12

    cout << "sizeof Son =" << sizeof(Son) << endl; //sizeof Son =16
}

int main()
{

    test01();

    system("pause");
    return EXIT_SUCCESS;
}