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
1) 产生选手 （ ABCDEFGHIJKLMNOPQRSTUVWX ） 姓名、得分；选手编号
2) 第1轮	选手抽签 选手比赛 查看比赛结果
3) 第2轮	选手抽签 选手比赛 查看比赛结果
4) 第3轮	选手抽签 选手比赛 查看比赛结果
*/

//选手类
class Speaker
{
public:
	string m_Name;//姓名
	int m_Score[3];//记录分数的数组
};


//创建选手
void createSpeaker(vector<int>&v,map<int,Speaker>&m)
{
	string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWX";
	for (int i = 0; i < 24;i++)
	{
		string name = "选手";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;

		//清空分数数组
		for (int j = 0; j < 3;j++)
		{
			sp.m_Score[j] = 0;
		}

		//创建编号   100 ~ 123  
		v.push_back(i + 100);

		//创建编号 和 对应的人员 放入到m容器中
		m.insert(make_pair(i + 100, sp));

	}


}

//抽签
void speechDraw(vector<int>&v)
{
	random_shuffle(v.begin(), v.end());
}

//比赛  参数1 比赛轮数   参数2  参赛选手比赛编号   参数3  具体编号和对应选手容器   参数4  存放晋级人员编号容器
void speechContest(int index, vector<int>&v, map<int,Speaker>&m, vector<int>&v2)
{
	//key  分数    value  对应选手编号   greater<int>排序规则
	multimap<int, int, greater<int>>mGroup; //存放小组容器，每6个人的信息，单独放入到这个容器中，取前三名用

	int num = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		num++;

		//存放评委打分容器
		deque<int>d;

		for (int i = 0; i < 10;i++)
		{
			int score = rand() % 41 + 60;  // 60 ~ 100
			d.push_back(score);
		}
		//排序
		sort(d.begin(), d.end());
		//去除最高分 最低分
		d.pop_back(); //最高
		d.pop_front(); //最低

		//总分
		int sum = accumulate(d.begin(), d.end(), 0);

		//平均分
		int avg = sum / d.size();

		//将平均分 赋值给 具体的人员
		m[*it].m_Score[index - 1] = avg;

		//每6个人为一组，晋级前三名
		mGroup.insert(make_pair(avg, *it));
		if (num % 6== 0)
		{
			//cout << "小组比赛成绩如下：" << endl;
			//for (multimap<int, int, greater<int>>::iterator mit = mGroup.begin(); mit != mGroup.end(); mit++)
			//{
			//	cout << "编号： " << mit->second << " 姓名： " << m[mit->second].m_Name << " 成绩： " << m[mit->second].m_Score[index - 1] << endl;
			//}

			//取出前三名
			int count = 0;

			for (multimap<int, int, greater<int>>::iterator mit = mGroup.begin(); mit != mGroup.end() && count < 3 ;mit++ , count++)
			{
				//将前三名的编号 放入到 v2容器中
				v2.push_back((*mit).second);
			}

			mGroup.clear(); //临时容器 清空
		}

	}


}

//显示分数函数
void showScore(int index , vector<int>&v , map<int,Speaker>&m)
{
	cout << "第" << index << "轮的比赛成绩如下：" << endl;

	for (map<int, Speaker>::iterator it = m.begin(); it != m.end();it++)
	{
		cout << "编号： " << it->first << " 姓名： " << it->second.m_Name << " 分数： " << it->second.m_Score[index-1] << endl;
	}

	cout << "晋级人员编号为： " << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << *it << endl;
	}
}

void test01()
{
	//随机数种子
	srand( (unsigned int)time(NULL));

	//1、将所有选手的编号放入到 vector容器中
	vector<int>vSpeaker;

	//2、创建 维护选手编号 和对应的选手的容器
	map<int, Speaker>mSpeaker;

	//3、创建选手
	createSpeaker(vSpeaker, mSpeaker);

	//4、抽签
	speechDraw(vSpeaker);

	//5、比赛
	vector<int>v2; //第一轮晋级选手的编号
	speechContest(1,vSpeaker, mSpeaker, v2);

	//6、查看比赛结果
	showScore(1,v2 , mSpeaker);

	//第二轮比赛
	//抽签  比赛   显示
	speechDraw(v2);
	vector<int>v3; //第二轮晋级选手的编号
	speechContest(2, v2, mSpeaker, v3);
	showScore(2, v3, mSpeaker);

	//第三轮比赛
	speechDraw(v3);
	vector<int>v4; //第二轮晋级选手的编号
	speechContest(3, v3, mSpeaker, v4);
	showScore(3, v4, mSpeaker);


	//测试 
	//for (map<int, Speaker>::iterator it = mSpeaker.begin(); it != mSpeaker.end();it++)
	//{
	//	cout << "编号： " << it->first << " 姓名： " << it->second.m_Name << " 分数： " << it->second.m_Score[0] << endl;
	//}
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}