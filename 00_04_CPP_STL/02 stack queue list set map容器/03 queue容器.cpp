#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <queue>
#include <string>

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void test01()
{
	queue<Person>q;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	//���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	q.push(p5);

	cout << "���д�СΪ�� " << q.size() << endl;

	//�鿴��ͷ ��β ִ�г���
	while ( !q.empty())  // �ȼ���  q.size() > 0
	{
		Person pFront = q.front();
		cout << "��ͷ����Ϊ��  " << pFront.m_Name << " ���䣺 " << pFront.m_Age << endl;

		Person pBack =  q.back();
		cout << "��β����Ϊ��  " << pBack.m_Name << " ���䣺 " << pBack.m_Age << endl;

		//����
		q.pop();
	}

	cout << "���д�СΪ�� " << q.size() << endl;
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}