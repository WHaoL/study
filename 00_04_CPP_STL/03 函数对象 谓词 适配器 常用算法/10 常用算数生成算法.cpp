//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric> //accumulate头文件
#include <iterator>

/*
accumulate(iterator beg, iterator end, value)
accumulate 算法 计算容器元素累计总和（#include<numeric>
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param value 起始累加值
*/
void test01()
{
	vector<int> v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	int sum = accumulate(v.begin(), v.end(), 1000); //参数3 累加起始值
	cout << sum << endl;
}

/*
fill(iterator beg, iterator end, value)
fill算法 向容器中添加元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param value 填充元素
*/
void test02()
{
	vector<int> v;
	v.resize(10);

	fill(v.begin(), v.end(), 100);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{

	//test01();
	test02();

	//system("pause");
	return 0;
}