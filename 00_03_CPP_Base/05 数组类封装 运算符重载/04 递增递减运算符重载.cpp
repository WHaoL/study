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

    //����ǰ��++
    MyInter &operator++()
    {
        this->m_Num++;

        return *this;
    }

    //���غ���++  ����ռλ���� ����ǰ�ú��� ��int���ں���
    MyInter operator++(int)
    {
        //�ȼ�סԭ��ֵ
        MyInter temp = *this;
        //�ײ�����++
        this->m_Num++;
        //���ؼ�ס��ֵ
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
    cout << "------test01()���ε��ÿ�ʼ------" << endl;
    MyInter myInt;
    cout << myInt << endl; //0

    //ǰ��++
    cout << ++(++myInt) << endl; //2
    cout << myInt << endl;       //2
    cout << "------test01()���ε��ý���------" << endl;
}

void test02()
{
    cout << "------test02()���ε��ÿ�ʼ------" << endl;
    MyInter myInt;
    cout << myInt << endl; //0

    cout << myInt++ << endl; //0
    cout << myInt << endl;   //1
    cout << "------test02()���ε��ý���------" << endl;
}

int main()
{
    cout << "------main()���ε��ÿ�ʼ------" << endl;
    test01();
    test02();

    //int a = 0;
    //cout << ++(++(++a)) << endl;
    //cout << a << endl;

    //int a = 0;
    //cout << (a++)++ << endl;

    system("pause");
    return 0;
    cout << "------main()���ε��ý���------" << endl;
}