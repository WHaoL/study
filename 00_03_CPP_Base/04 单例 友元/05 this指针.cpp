#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        //��this֮�����������ָ������ָ��
        this->age = age;
    }

    Person &personAddAge(Person &p)
    {

        this->age += p.age;
        //thisָ��ָ�򱻵��ó�Ա������������
        //*this ����Person����
        return *this;
    }

    int age;
};
void test01()
{
    //thisָ��ָ�򱻵��õĳ�Ա������������
    Person p1(10);
    cout << "p1.age = " << p1.age << endl;

    Person p2(10);
    //��ʽ���˼��
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