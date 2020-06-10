//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//谓词
//指的是普通函数 或者仿函数 的返回值是 bool数据类型
// 谓词：是指普通函数或重载的operator()返回值是bool类型的函数、函数对象(仿函数)。
// 如果operator接受一个参数，那么叫做一元谓词,
// 如果接受两个参数，那么叫做二元谓词，
// 谓词可作为一个判断式。

//一元谓词
class Greater20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};

//二元谓词
class myCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

//测试：一元谓词
void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//找到第一个大于20的元素
	vector<int>::iterator ret = find_if(v.begin(), v.end(), Greater20());
	if (ret != v.end())
	{
		cout << "找到了元素大于20的值为： " << *ret << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//二元谓词
	sort(v.begin(), v.end(), myCompare());
}

//二元谓词
class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2;
	}
};

//测试：二元谓词
void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(90);
	v.push_back(60);

	//默认从小到大
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "----------------------------" << endl;
	//使用函数对象改变算法策略，排序从大到小
	sort(v.begin(), v.end(), MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{

	//test01();
	test02();

	//system("pause");
	return 0;
}