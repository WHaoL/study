#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1����̬��Ա����
//2����̬��Ա����
class Person
{
public:

	Person()
	{
		//m_A = 10;  
		/*
			����ͨ����������ʱ��Ĭ�Ϲ��캯����ʼ����̬���ݳ�Ա��

			ͨ��������������ʱ��û�ж������ɣ�Ҳ�Ͳ�����Ĭ�Ϲ��캯�������ã�
			�Ͳ����߳�ʼ���Ĵ��룬��ô��̬���ݳ�Ա���޷�����ʼ��
		*/
	}

	//��̬��Ա����
	//ֻ��һ�ݺ���
	//��̬��Ա���� Ҳ���з���Ȩ��
	static void func()
	{
		cout << "��̬��Ա����func����" << endl;
		m_A = 100; //��̬��Ա������ ���Է��ʾ�̬��Ա����
		//m_C = 100; //��̬��Ա������ �����Է��ʷǾ�̬��Ա�������޷����ֵ������ĸ������޸�m_C��̬��Ա����
	}

	//�Ǿ�̬��Ա���� ,���Է��ʾ�̬��Ա�����ͷǾ�̬��Ա����
	void func2()
	{
		m_A = 100;
		m_C = 100;
	}

	//��̬��Ա
	//�ڱ���׶ξͷ����ڴ�
	//���ж��󶼹���ͬһ����̬��Ա����
	//���������������������ʼ��
	static int m_A;

	int m_C; //�Ǿ�̬��Ա����

private:
	static int m_B;

	static void func3()
	{
		cout << "��̬��Ա����func3����" << endl;
	}
};

//��̬��Ա���������ڶ��壬�����ʼ��
int Person::m_A = 10;
int Person::m_B = 10;

void test01()
{
	Person p1;
	cout << "p1.m_A =  " << p1.m_A << endl;

	Person p2;
	p2.m_A = 20;

	cout << "p1.m_A =  " << p1.m_A << endl;
}

//���ʷ�ʽ
void test02()
{
	//���ʷ�ʽ1  ͨ���������
	Person p1;
	cout << "p1.m_A =  " << p1.m_A << endl;

	//���ʷ�ʽ2  ͨ����������
	cout << Person::m_A << endl;
}

//��̬��Ա���� Ҳ���з���Ȩ��
void test03()
{
	//m_B����˽��Ȩ�����ԣ�������ⲻ���Է���
	//cout << "m_B = " << Person::m_B << endl;
}

void test04()
{
	//��̬��Ա�������ʷ�ʽ ������
	//ͨ������
	Person p1;
	p1.func();

	//ͨ������
	Person::func();

	//Person::func3(); func3˽�г�Ա�����������ʲ���
}


int main(){

	test04();

	system("pause");
	return EXIT_SUCCESS;
}


