#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// --------------------- 公共继承  -------------------------
class Base1
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son1 : public Base1
{
public:
    void func()
    {
        m_A = 100; //父类中的公共属性 到子类中变为 公共属性
        m_B = 100; //父类中的保护属性 到子类中变为 保护属性
                   //m_C = 100; //父类中私有成员，子类访问不到
    }
};

void test01()
{
    Son1 s1;
    s1.m_A = 200; //在Son1中m_A是公共属性，类外可以访问
                  //s1.m_B = 200; //在Son1中m_B是保护属性，类外不可以访问
                  //s1.m_C = 200; //Son1都访问不到，类外也不可以访问
}

// --------------------- 保护继承  -------------------------
class Base2
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son2 : protected Base2
{
public:
    void func()
    {
        m_A = 100; //父类中的公共属性 到子类中变为 保护属性
        m_B = 100; //父类中的保护属性 到子类中变为 保护属性
                   //m_C = 100; //父类中私有成员，子类访问不到
    }
};

void test02()
{
    Son2 s;
    //s.m_A = 100; //在Son2中 m_A变为保护属性，类外访问不到
    //s.m_B = 100; //在Son2中 m_B变为保护属性，类外访问不到
    //s.m_C = 100; //Son2中都访问不到，类外也不可以访问
}

// --------------------- 私有继承  -------------------------
class Base3
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};

class Son3 : private Base3
{
public:
    void func()
    {
        m_A = 100; //父类中的公共属性 到子类中变为 私有属性
        m_B = 100; //父类中的保护属性 到子类中变为 私有属性
                   //m_C = 100; //父类中私有成员，子类访问不到
    }
};
class GrandSon3 : public Son3
{
public:
    void func()
    {
        //m_A = 100; //在Son3中m_A变为私有属性，因此访问不到
        //m_B = 100; //在Son3中m_B变为私有属性，因此访问不到
        //m_C = 100; //Son3中都访问不到m_C
    }
};
void test03()
{
    Son3 s;
    //s.m_A = 100; //在Son3中 m_A变为私有属性，类外访问不到
    //s.m_B = 100; //在Son3中 m_B变为私有属性，类外访问不到
    //s.m_C = 100; //Son3中都访问不到m_C,类外不可以访问
}

int main()
{

    system("pause");
    return EXIT_SUCCESS;
}