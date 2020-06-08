#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//#pragma pack(1)

class Person
{
public:
    int m_A; //非静态成员变量  属于类的对象上

    double m_C;

    static int m_B; //静态成员变量  不属于类的对象上

    void func(){}; //非静态成员函数 不属于类的对象上

    static void func2(){}; //静态成员函数 不属于类的对象上
};
int Person::m_B = 0;

//只有非静态成员变量，属于类对象上，其余都不算
void test01()
{
    //空类也可以实例化对象,每个对象在内存中都应该有独一无二的地址空间，为了区分地址，给1个字节
    //数组中每个元素也应该有独一无二的内存空间 Person arr[10];  arr[0]  arr[1]

    //空类的sizeof结果为1
    Person p1;
    cout << "sizeof person = " << sizeof(p1) << endl; // 16
}

void test02()
{
    Person p1;
    p1.func(); //this指针  指向 被调用的成员函数  所属的对象

    Person p2;
    p2.func();
}

int main()
{

    test01();
    test02();


    system("pause");
    return EXIT_SUCCESS;
}