/*
	create by liangwenhao 
	void createPerson(vector<Person>v)  ����ѡ�� ���� ��������
*/
//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
using namespace std;

/*
��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�
//1. ��������ѡ�֣��ŵ�vector��
//2. ����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
//3. sort�㷨��deque�����з�������pop_back pop_frontȥ����ߺ���ͷ�
//4. deque��������һ�飬�ۼӷ������ۼӷ���/d.size()
//5. person.score = ƽ����
*/

class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name; //����
	int m_Score;   //ƽ����
};

//����ѡ��
void createPerson(vector<Person> &v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		int score = 0;

		Person p(name, score);

		v.push_back(p);
	}
}

void setScore(vector<Person> &v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//׼��deque���� ��� ��ί����
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60; // 60 ~ 100
			d.push_back(score);
		}

		//�鿴10����ί����
		//cout << "ѡ�� " << it->m_Name << "��֣� " << endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;

		//����
		sort(d.begin(), d.end());
		//ȥ����߷�  ��ͷ�
		d.pop_back();  //���
		d.pop_front(); //���

		//�ܷ�
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		//ƽ����
		int avg = sum / d.size();

		//��ƽ���� ��ֵ��Person
		it->m_Score = avg;
	}
}

void showScore(vector<Person> &v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������ " << (*it).m_Name << " ƽ���֣� " << it->m_Score << endl;
	}
}

int main()
{

	//���������
	srand((unsigned int)time(NULL));

	//1�����ѡ����

	//2���������ѡ������
	vector<Person> v;
	//3������5��ѡ��
	createPerson(v);

	//4��ѡ�ִ��
	setScore(v);

	//5����ӡƽ����
	showScore(v);

	//system("pause");
	return EXIT_SUCCESS;
}