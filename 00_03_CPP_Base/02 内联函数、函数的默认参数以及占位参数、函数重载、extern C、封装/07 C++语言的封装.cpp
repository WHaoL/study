#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//��
struct Person
{
public:
	char m_Name[64];

	int m_Age;

	//�Է�
	void personEat()
	{
		printf("%s�ڳ��˷�\n", m_Name);
	}

};

//��
class Dog
{
public:
	char m_Name[64];
	int m_Age;

	//�Է�
	void dogEat()
	{
		printf("%s�ڳԹ���\n", m_Name);
	}
};

//C++�з�װ˼��1�������Ժ���Ϊ��Ϊһ�����壬�����������е�����
//C++�з�װ˼��2�����������Ժ���Ϊ������Ȩ�޿���
//����Ȩ�� һ��������
//public     ����Ȩ��   ��Ա  ���ڿ��Է���  ����Ҳ���Է���
//protected  ����Ȩ��   ��Ա  ���ڿ��Է���  ���ⲻ���Է���
//private    ˽��Ȩ��   ��Ա  ���ڿ��Է���  ���ⲻ���Է���
//C++��struct ��class ������
// struct Ĭ�Ϸ���Ȩ���� public
// class  Ĭ�Ϸ���Ȩ���� private
void test01()
{
	Person p;
	strcpy(p.m_Name, "����");
	p.personEat();

	Dog d;
	strcpy(d.m_Name, "����");
	d.dogEat();

	//p.dogEat();  person������û��dogEat����
}


class Person1
{
public:
	string m_Name; //����
protected:
	string m_Car; //����
private:
	int m_pwd; //���п�����

public:
	void func()
	{
		m_Name = "����";	//public  ���ڿ��Է���
		m_Car = "��˹��˹";	//protected  ���ڿ��Է���
		m_pwd = 12345;		//privates  ���ڿ��Է���
	}
};

void test02()
{
	Person1 p1;
	p1.m_Name = "����";    //public    ������Է���
	//p1.m_Car = "������"; //protected ���ⲻ���Է���
	//p1.m_pwd = 54321;    //private   ���ⲻ���Է���

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}