//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <functional> //内建函数对象！！！！ 头文件
#include <vector>
#include <algorithm>

// 取反仿函数（取正负相反数）
// template<class T>
// T negate<T>
void test01()
{
	negate<int> n;
	cout << n(10) << endl; //-10
}

// 加法仿函数
// template<class T>
// T plus<T>

void test02()
{
	plus<int> p;
	cout << p(1, 1) << endl; //2
}

// 大于仿函数
// template<class T>
// greater<T>

// 一元谓词
class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test03()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	sort(v.begin(), v.end(), greater<int>()); //降序//从大到小排序

	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}

// 逻辑非
// template<class T>
// bool logical_not<T>
void test04()
{
	vector<bool> v;

	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	/*
	transform(iterator beg1, iterator end1, iterator beg2, _callbakc)
	transform 算法 将指定容器区间元素搬运到另一容器中 
	注意 : transform 不会给目标容器分配内存，所以需要我们提前分配好内存 
	@param beg1 源容器开始迭代器 
	@param end1 源容器结束迭代器 
	@param beg2 目标容器开始迭代器 
	@param _cakkback 回调函数或者函数对象 
	@return 返回目标容器迭代器
	*/
	vector<bool> v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(), logical_not<int>());

	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test01();
	test02();
	test03();
	test04();

	//system("pause");
	return 0;
}