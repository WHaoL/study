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
//公司今天招聘了5个员工，5名员工进入公司之后，需要指派员工在那个部门工作
//人员信息有: 姓名 工资等组成
//通过Multimap进行信息的插入 保存 显示
//分部门显示员工信息 显示全部员工信息
*/

class Worker
{
public:
	string m_Name; //姓名
	int m_Money;   //工资
};

//创建员工
void createWorker(vector<Worker> &v)
{
	string nameSeed = "ABCDE";

	for (int i = 0; i < 5; i++)
	{
		Worker worker;
		worker.m_Name = "员工";
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
		m.insert(make_pair(dId, *it)); //将部门编号 和 人员 插入到map容器中
									   //multimap会按照key自动排序
	}
}

void showGroup(multimap<int, Worker> &m)
{
	// 0 A   0 B   1 C  2  D  2 E

	multimap<int, Worker>::iterator pos = m.find(CAIWU); //查询：CAIWU部门是否有员工
	int num = m.count(CAIWU);							 //计算：CAIWU部门员工个数
	int index = 0;										 //用来：依次遍历num个员工
	cout << "CAIWU财务部门人员信息如下------总员工数为 num = " << num << endl;
	for (; pos != m.end() && index < num; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Money << endl;
	}

	pos = m.find(RENLI);
	num = m.count(RENLI);
	index = 0;
	cout << "RENLI人力部门人员信息如下------总员工数为 num = " << num << endl;
	for (; pos != m.end() && index < num; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Money << endl;
	}

	pos = m.find(YANFA);
	num = m.count(YANFA);
	index = 0;
	cout << "YNAFA研发部门人员信息如下------总员工数为 num = " << num << endl;
	for (; pos != m.end() && index < num; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Money << endl;
	}
}

void test01()
{

	srand((unsigned int)time(NULL)); //随机数种子
	vector<Worker> v;				 //存放员工的容器
	createWorker(v);				 //创建5名员工

	//for (vector<Worker>::iterator it = v.begin(); it != v.end();it++)
	//{
	//	cout << "姓名： " << it->m_Name << " 工资： " << it->m_Money << endl;
	//}

	multimap<int, Worker> m; // 存放员工部门和员工信息
	setGroup(v, m);			 //员工分发到各个部门
	showGroup(m);			 //分部门显示人员
}

int main()
{
	test01();
	//system("pause");
	return 0;
}