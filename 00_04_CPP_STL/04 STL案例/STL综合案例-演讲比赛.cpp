#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <deque>
#include <numeric>
#include <functional>
#include <ctime>

/*
1) ����ѡ�� �� ABCDEFGHIJKLMNOPQRSTUVWX �� �������÷֣�ѡ�ֱ��
2) ��1��	ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
3) ��2��	ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
4) ��3��	ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
*/

//ѡ����
class Speaker
{
public:
	string m_Name;//����
	int m_Score[3];//��¼����������
};


//����ѡ��
void createSpeaker(vector<int>&v,map<int,Speaker>&m)
{
	string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWX";
	for (int i = 0; i < 24;i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;

		//��շ�������
		for (int j = 0; j < 3;j++)
		{
			sp.m_Score[j] = 0;
		}

		//�������   100 ~ 123  
		v.push_back(i + 100);

		//������� �� ��Ӧ����Ա ���뵽m������
		m.insert(make_pair(i + 100, sp));

	}


}

//��ǩ
void speechDraw(vector<int>&v)
{
	random_shuffle(v.begin(), v.end());
}

//����  ����1 ��������   ����2  ����ѡ�ֱ������   ����3  �����źͶ�Ӧѡ������   ����4  ��Ž�����Ա�������
void speechContest(int index, vector<int>&v, map<int,Speaker>&m, vector<int>&v2)
{
	//key  ����    value  ��Ӧѡ�ֱ��   greater<int>�������
	multimap<int, int, greater<int>>mGroup; //���С��������ÿ6���˵���Ϣ���������뵽��������У�ȡǰ������

	int num = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		num++;

		//�����ί�������
		deque<int>d;

		for (int i = 0; i < 10;i++)
		{
			int score = rand() % 41 + 60;  // 60 ~ 100
			d.push_back(score);
		}
		//����
		sort(d.begin(), d.end());
		//ȥ����߷� ��ͷ�
		d.pop_back(); //���
		d.pop_front(); //���

		//�ܷ�
		int sum = accumulate(d.begin(), d.end(), 0);

		//ƽ����
		int avg = sum / d.size();

		//��ƽ���� ��ֵ�� �������Ա
		m[*it].m_Score[index - 1] = avg;

		//ÿ6����Ϊһ�飬����ǰ����
		mGroup.insert(make_pair(avg, *it));
		if (num % 6== 0)
		{
			//cout << "С������ɼ����£�" << endl;
			//for (multimap<int, int, greater<int>>::iterator mit = mGroup.begin(); mit != mGroup.end(); mit++)
			//{
			//	cout << "��ţ� " << mit->second << " ������ " << m[mit->second].m_Name << " �ɼ��� " << m[mit->second].m_Score[index - 1] << endl;
			//}

			//ȡ��ǰ����
			int count = 0;

			for (multimap<int, int, greater<int>>::iterator mit = mGroup.begin(); mit != mGroup.end() && count < 3 ;mit++ , count++)
			{
				//��ǰ�����ı�� ���뵽 v2������
				v2.push_back((*mit).second);
			}

			mGroup.clear(); //��ʱ���� ���
		}

	}


}

//��ʾ��������
void showScore(int index , vector<int>&v , map<int,Speaker>&m)
{
	cout << "��" << index << "�ֵı����ɼ����£�" << endl;

	for (map<int, Speaker>::iterator it = m.begin(); it != m.end();it++)
	{
		cout << "��ţ� " << it->first << " ������ " << it->second.m_Name << " ������ " << it->second.m_Score[index-1] << endl;
	}

	cout << "������Ա���Ϊ�� " << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << *it << endl;
	}
}

void test01()
{
	//���������
	srand( (unsigned int)time(NULL));

	//1��������ѡ�ֵı�ŷ��뵽 vector������
	vector<int>vSpeaker;

	//2������ ά��ѡ�ֱ�� �Ͷ�Ӧ��ѡ�ֵ�����
	map<int, Speaker>mSpeaker;

	//3������ѡ��
	createSpeaker(vSpeaker, mSpeaker);

	//4����ǩ
	speechDraw(vSpeaker);

	//5������
	vector<int>v2; //��һ�ֽ���ѡ�ֵı��
	speechContest(1,vSpeaker, mSpeaker, v2);

	//6���鿴�������
	showScore(1,v2 , mSpeaker);

	//�ڶ��ֱ���
	//��ǩ  ����   ��ʾ
	speechDraw(v2);
	vector<int>v3; //�ڶ��ֽ���ѡ�ֵı��
	speechContest(2, v2, mSpeaker, v3);
	showScore(2, v3, mSpeaker);

	//�����ֱ���
	speechDraw(v3);
	vector<int>v4; //�ڶ��ֽ���ѡ�ֵı��
	speechContest(3, v3, mSpeaker, v4);
	showScore(3, v4, mSpeaker);


	//���� 
	//for (map<int, Speaker>::iterator it = mSpeaker.begin(); it != mSpeaker.end();it++)
	//{
	//	cout << "��ţ� " << it->first << " ������ " << it->second.m_Name << " ������ " << it->second.m_Score[0] << endl;
	//}
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}