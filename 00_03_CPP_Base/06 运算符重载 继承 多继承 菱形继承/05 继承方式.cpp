#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// --------------------- �����̳�  -------------------------
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
        m_A = 100; //�����еĹ������� �������б�Ϊ ��������
        m_B = 100; //�����еı������� �������б�Ϊ ��������
                   //m_C = 100; //������˽�г�Ա��������ʲ���
    }
};

void test01()
{
    Son1 s1;
    s1.m_A = 200; //��Son1��m_A�ǹ������ԣ�������Է���
                  //s1.m_B = 200; //��Son1��m_B�Ǳ������ԣ����ⲻ���Է���
                  //s1.m_C = 200; //Son1�����ʲ���������Ҳ�����Է���
}

// --------------------- �����̳�  -------------------------
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
        m_A = 100; //�����еĹ������� �������б�Ϊ ��������
        m_B = 100; //�����еı������� �������б�Ϊ ��������
                   //m_C = 100; //������˽�г�Ա��������ʲ���
    }
};

void test02()
{
    Son2 s;
    //s.m_A = 100; //��Son2�� m_A��Ϊ�������ԣ�������ʲ���
    //s.m_B = 100; //��Son2�� m_B��Ϊ�������ԣ�������ʲ���
    //s.m_C = 100; //Son2�ж����ʲ���������Ҳ�����Է���
}

// --------------------- ˽�м̳�  -------------------------
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
        m_A = 100; //�����еĹ������� �������б�Ϊ ˽������
        m_B = 100; //�����еı������� �������б�Ϊ ˽������
                   //m_C = 100; //������˽�г�Ա��������ʲ���
    }
};
class GrandSon3 : public Son3
{
public:
    void func()
    {
        //m_A = 100; //��Son3��m_A��Ϊ˽�����ԣ���˷��ʲ���
        //m_B = 100; //��Son3��m_B��Ϊ˽�����ԣ���˷��ʲ���
        //m_C = 100; //Son3�ж����ʲ���m_C
    }
};
void test03()
{
    Son3 s;
    //s.m_A = 100; //��Son3�� m_A��Ϊ˽�����ԣ�������ʲ���
    //s.m_B = 100; //��Son3�� m_B��Ϊ˽�����ԣ�������ʲ���
    //s.m_C = 100; //Son3�ж����ʲ���m_C,���ⲻ���Է���
}

int main()
{

    system("pause");
    return EXIT_SUCCESS;
}