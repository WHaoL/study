#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//#pragma pack(1)

class Person
{
public:
    int m_A; //�Ǿ�̬��Ա����  ������Ķ�����

    double m_C;

    static int m_B; //��̬��Ա����  ��������Ķ�����

    void func(){}; //�Ǿ�̬��Ա���� ��������Ķ�����

    static void func2(){}; //��̬��Ա���� ��������Ķ�����
};
int Person::m_B = 0;

//ֻ�зǾ�̬��Ա����������������ϣ����඼����
void test01()
{
    //����Ҳ����ʵ��������,ÿ���������ڴ��ж�Ӧ���ж�һ�޶��ĵ�ַ�ռ䣬Ϊ�����ֵ�ַ����1���ֽ�
    //������ÿ��Ԫ��ҲӦ���ж�һ�޶����ڴ�ռ� Person arr[10];  arr[0]  arr[1]

    //�����sizeof���Ϊ1
    Person p1;
    cout << "sizeof person = " << sizeof(p1) << endl; // 16
}

void test02()
{
    Person p1;
    p1.func(); //thisָ��  ָ�� �����õĳ�Ա����  �����Ķ���

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