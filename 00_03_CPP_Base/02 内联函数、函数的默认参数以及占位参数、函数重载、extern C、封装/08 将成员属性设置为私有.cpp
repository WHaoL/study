#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

class Person
{
public:

	//��������
	void setName(string name)
	{
		m_Name = name;
	}
	//��ȡ����
	string getName()
	{
		return m_Name;
	}

	//��ȡ����
	int getAge()
	{
		return m_Age;
	}

	//��������
	void setAge(int age)
	{
		if (age <0 || age > 150)
		{
			cout << "�������������" << endl;
			return;
		}
		m_Age = age;
	}

	//��������
	void setLover(string lover)
	{
		m_Lover = lover;
	}
	

private:
	string m_Name; //����  �ɶ���д

	int m_Age = 18; //����  ֻ��       ��д  0 ~ 150

	string m_Lover; //����  ֻд
};

//����Ա��������˽�кô��� �Լ����ƶ�дȨ��
//����дȨ�ޣ�������֤���ݵ���Ч��
void test01()
{
	Person p1;
	p1.setName("����");
	cout << "������ " << p1.getName() << endl;

	//p1.m_Age = 19;  //˽�г�Ա ������ʲ���
	//p1.setAge(19);  //û���ṩ���ýӿ�

	//p1.setAge(1000);
	p1.setAge(100);
	cout << "���䣺 " << p1.getAge() << endl;

	p1.setLover("�־�"); //ֻд
	//cout << "���ˣ� " << p1.getLover() << endl;  ���ʲ���˽�г�Ա��û�ṩ���Ľӿ�

}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}