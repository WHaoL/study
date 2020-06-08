#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyInter
{
    friend ostream &operator<<(ostream &cout, const MyInter &myint);

public:
    MyInter()
    {
        this->m_Num = 0;
    }

    //重载前置++
    MyInter &operator++()
    {
        this->m_Num++;

        return *this;
    }

    //重载后置++  利用占位参数 区分前置后置 加int属于后置
    MyInter operator++(int)
    {
        //先记住原来值
        MyInter temp = *this;
        //底层数字++
        this->m_Num++;
        //返回记住的值
        return temp;
    }

private:
    int m_Num;
};

ostream &operator<<(ostream &cout, const MyInter &myint)
{
    cout << myint.m_Num;
    return cout;
}

void test01()
{
    cout << "------test01()本次调用开始------" << endl;
    MyInter myInt;
    cout << myInt << endl; //0

    //前置++
    cout << ++(++myInt) << endl; //2
    cout << myInt << endl;       //2
    cout << "------test01()本次调用结束------" << endl;
}

void test02()
{
    cout << "------test02()本次调用开始------" << endl;
    MyInter myInt;
    cout << myInt << endl; //0

    cout << myInt++ << endl; //0
    cout << myInt << endl;   //1
    cout << "------test02()本次调用结束------" << endl;
}

int main()
{
    cout << "------main()本次调用开始------" << endl;
    test01();
    test02();

    //int a = 0;
    //cout << ++(++(++a)) << endl;
    //cout << a << endl;

    //int a = 0;
    //cout << (a++)++ << endl;

    system("pause");
    return 0;
    cout << "------main()本次调用结束------" << endl;
}