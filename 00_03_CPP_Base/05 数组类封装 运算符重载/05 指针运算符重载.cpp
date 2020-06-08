#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        cout << "Person ���캯������" << endl;
        this->m_Age = age;
    }

    void showAge()
    {
        cout << "age = " << this->m_Age << endl;
    }

    ~Person()
    {
        cout << "Person ������������" << endl;
    }

private:
    int m_Age;
};

//����ָ��
class smartPoint
{
public:
    smartPoint(Person *person)
    {
        cout << "smartPoint ����ָ�빹�캯��" << endl;
        this->m_Person = person;
    }

    //���� ->
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
            cout << "smartPoint������������" << endl;
            delete this->m_Person;
            this->m_Person = NULL;
        }
    }

private:
    Person *m_Person;
};

void test01()
{
    //Person p1(18); //ջ
    //p1.showAge();

    //Person * p1 = new Person(18); //����
    //p1->showAge();
    //(*p1).showAge();
    //delete p1;//������Ա�Ծ���ʹ����Ϻ��ͷ�

    //���ܵط����� new�����Ķ��� ���ù����ͷ�
    smartPoint sp(new Person(18));
    sp->showAge(); // sp->->showAge();  ��Ϊ sp->showAge();

    (*sp).showAge();
}

int main()
{

    test01();

    system("pause");
    return EXIT_SUCCESS;
}