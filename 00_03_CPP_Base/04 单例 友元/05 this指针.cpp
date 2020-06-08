#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        //加this之后可以区分是指向对象的指针
        this->age = age;
    }

    Person &personAddAge(Person &p)
    {

        this->age += p.age;
        //this指针指向被调用成员函数所属对象
        //*this 就是Person本体
        return *this;
    }

    int age;
};
void test01()
{
    //this指针指向被调用的成员函数所属对象
    Person p1(10);
    cout << "p1.age = " << p1.age << endl;

    Person p2(10);
    //链式编程思想
    p2.personAddAge(p1);
    cout << "p2.age = " << p2.age << endl; //20

    p2.age = 10;
    p2.personAddAge(p1).personAddAge(p1);
    cout << "p2.age = " << p2.age << endl; //30

    p2.age = 10;
    p2.personAddAge(p1).personAddAge(p1).personAddAge(p1);
    cout << "p2.age = " << p2.age << endl; //40
}

int main()
{

    test01();

    system("pause");
    return EXIT_SUCCESS;
}