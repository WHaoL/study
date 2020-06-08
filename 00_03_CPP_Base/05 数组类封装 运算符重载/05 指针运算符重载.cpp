#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        cout << "Person 构造函数调用" << endl;
        this->m_Age = age;
    }

    void showAge()
    {
        cout << "age = " << this->m_Age << endl;
    }

    ~Person()
    {
        cout << "Person 析构函数调用" << endl;
    }

private:
    int m_Age;
};

//智能指针
class smartPoint
{
public:
    smartPoint(Person *person)
    {
        cout << "smartPoint 智能指针构造函数" << endl;
        this->m_Person = person;
    }

    //重载 ->
    Person *operator->()
    {
        return this->m_Person;
    }

    Person &operator*()
    {
        return *this->m_Person;
    }

    ~smartPoint()
    {
        if (this->m_Person != NULL)
        {
            cout << "smartPoint析构函数调用" << endl;
            delete this->m_Person;
            this->m_Person = NULL;
        }
    }

private:
    Person *m_Person;
};

void test01()
{
    //Person p1(18); //栈
    //p1.showAge();

    //Person * p1 = new Person(18); //堆区
    //p1->showAge();
    //(*p1).showAge();
    //delete p1;//靠程序员自觉，使用完毕后释放

    //智能地方在于 new出来的对象 不用管理释放
    smartPoint sp(new Person(18));
    sp->showAge(); // sp->->showAge();  简化为 sp->showAge();

    (*sp).showAge();
}

int main()
{

    test01();

    system("pause");
    return EXIT_SUCCESS;
}