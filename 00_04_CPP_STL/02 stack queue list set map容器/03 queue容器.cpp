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

	//入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	q.push(p5);

	cout << "队列大小为： " << q.size() << endl;

	//查看队头 队尾 执行出队
	while ( !q.empty())  // 等价于  q.size() > 0
	{
		Person pFront = q.front();
		cout << "队头姓名为：  " << pFront.m_Name << " 年龄： " << pFront.m_Age << endl;

		Person pBack =  q.back();
		cout << "队尾姓名为：  " << pBack.m_Name << " 年龄： " << pBack.m_Age << endl;

		//出队
		q.pop();
	}

	cout << "队列大小为： " << q.size() << endl;
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}