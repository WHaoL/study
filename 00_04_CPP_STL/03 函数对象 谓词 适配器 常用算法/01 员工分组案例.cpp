//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

enum
{
	CAIWU,
	RENLI,
	YANFA
};

/*
//��˾������Ƹ��5��Ա����5��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
//��Ա��Ϣ��: ���� ���ʵ����
//ͨ��Multimap������Ϣ�Ĳ��� ���� ��ʾ
//�ֲ�����ʾԱ����Ϣ ��ʾȫ��Ա����Ϣ
*/

class Worker
{
public:
	string m_Name; //����
	int m_Money;   //����
};

//����Ա��
void createWorker(vector<Worker> &v)
{
	string nameSeed = "ABCDE";

	for (int i = 0; i < 5; i++)
	{
		Worker worker;
		worker.m_Name = "Ա��";
		worker.m_Name += nameSeed[i];

		worker.m_Money = rand() % 10000 + 10000; // 10000 ~19999
		v.push_back(worker);
	}
}

void setGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int dId = rand() % 3;		   // 0 ~ 2
		m.insert(make_pair(dId, *it)); //�����ű�� �� ��Ա ���뵽map������
									   //multimap�ᰴ��key�Զ�����
	}
}

void showGroup(multimap<int, Worker> &m)
{
	// 0 A   0 B   1 C  2  D  2 E

	multimap<int, Worker>::iterator pos = m.find(CAIWU); //��ѯ��CAIWU�����Ƿ���Ա��
	int num = m.count(CAIWU);							 //���㣺CAIWU����Ա������
	int index = 0;										 //���������α���num��Ա��
	cout << "CAIWU��������Ա��Ϣ����------��Ա����Ϊ num = " << num << endl;
	for (; pos != m.end() && index < num; pos++, index++)
	{
		cout << "������ " << pos->second.m_Name << " ���ʣ� " << pos->second.m_Money << endl;
	}

	pos = m.find(RENLI);
	num = m.count(RENLI);
	index = 0;
	cout << "RENLI����������Ա��Ϣ����------��Ա����Ϊ num = " << num << endl;
	for (; pos != m.end() && index < num; pos++, index++)
	{
		cout << "������ " << pos->second.m_Name << " ���ʣ� " << pos->second.m_Money << endl;
	}

	pos = m.find(YANFA);
	num = m.count(YANFA);
	index = 0;
	cout << "YNAFA�з�������Ա��Ϣ����------��Ա����Ϊ num = " << num << endl;
	for (; pos != m.end() && index < num; pos++, index++)
	{
		cout << "������ " << pos->second.m_Name << " ���ʣ� " << pos->second.m_Money << endl;
	}
}

void test01()
{

	srand((unsigned int)time(NULL)); //���������
	vector<Worker> v;				 //���Ա��������
	createWorker(v);				 //����5��Ա��

	//for (vector<Worker>::iterator it = v.begin(); it != v.end();it++)
	//{
	//	cout << "������ " << it->m_Name << " ���ʣ� " << it->m_Money << endl;
	//}

	multimap<int, Worker> m; // ���Ա�����ź�Ա����Ϣ
	setGroup(v, m);			 //Ա���ַ�����������
	showGroup(m);			 //�ֲ�����ʾ��Ա
}

int main()
{
	test01();
	//system("pause");
	return 0;
}