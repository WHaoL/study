//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
/*
set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
set_intersection算法 求两个set集合的交集
注意:两个集合必须是有序序列
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器（resize( min(v1.size(),v2.size()) )） 
@return 目标容器的最后一个元素的迭代器地址
*/

void test01()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int> vTarget;
	vTarget.resize(min(v1.size(), v2.size()));
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, [](int val) { cout << val << " "; });
	cout << endl;
}

/*
set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
set_union算法 求两个set集合的并集
注意:两个集合必须是有序序列
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器
@return 目标容器的最后一个元素的迭代器地址
*/
void test02()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int> vTarget;
	vTarget.resize(v1.size() + v2.size());
	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, [](int val) { cout << val << " "; });
	cout << endl;
}

/*
set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
set_difference算法 求两个set集合的差集
注意:两个集合必须是有序序列
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest 目标容器开始迭代器（resize(max(v1.size(),v2.size()) )）
@return 目标容器的最后一个元素的迭代器地址
*/
void test03()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int> vTarget;
	vTarget.resize(max(v1.size(), v2.size()));
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, [](int val) { cout << val << " "; });
	cout << endl;

	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, [](int val) { cout << val << " "; });
	cout << endl;
}

int main()
{

	//test01();
	//test02();

	test03();

	//system("pause");
	return 0;
}