#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

const double PI = 3.14;

//��ؼ���  class + ����
class Circle
{
public: //����Ȩ��

	//��ȡԲ�ܳ��ĺ���
	double calculateZC()
	{
		return 2 * PI * m_R;
	}

	//����Բ�İ뾶
	void setR(int r)
	{
		m_R = r;
	}

	//��ȡԲ�İ뾶
	int getR()
	{
		return m_R;
	}

	//�뾶
	int m_R;
};

void test01()
{
	Circle c1; //ͨ��Բ�� ����Բ����

	//��Բ����İ뾶��ֵ
	//c1.m_R = 10;
	c1.setR(10);

	cout << "Բ���ܳ�Ϊ�� " << c1.calculateZC() << endl;
	cout << "Բ�İ뾶Ϊ�� " << c1.getR() << endl;
}


//���ѧ����  ���� ������ѧ�ţ��������úͻ�ȡ����ʾ��Ϣ
class Student
{
public:
	
	//�����������ݶ��г�Ա
	//������������  ��Ա����  ��Ա����
	//�������к���  ��Ա����  ��Ա����

	//��������
	void setName(string name)
	{
		m_Name = name;
	}
	//����ѧ��
	void setId(int id)
	{
		m_Id = id;
	}

	//��ȡ����
	string getName()
	{
		return m_Name;
	}
	//��ȡѧ��
	int getId()
	{
		return m_Id;
	}

	//��ʾ��Ϣ
	void showInfo()
	{
		cout << "������ " << m_Name << " ѧ�ţ� " << m_Id << endl;
	}

	//����
	string m_Name;
	//ѧ��
	int m_Id;
};

void test02()
{
	//ͨ���� ��������  ���� ʵ��������
	Student s1;
	s1.setName("����");
	s1.setId(1);
	cout << "������ " << s1.getName() << " ѧ�ţ� " << s1.getId() << endl;

	Student s2;
	s2.setName("����");
	s2.setId(2);
	s2.showInfo();
}


int main(){
	test02();


	system("pause");
	return EXIT_SUCCESS;
}