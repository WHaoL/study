#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

//谓词
//指的是普通函数 或者仿函数 的返回值是 bool数据类型

class Greater20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};

class myCompare
{
public:
	bool operator()(int v1 , int v2)
	{
		return v1 > v2;
	}
};

//一元谓词
void test01()
{
	vector<int>v;
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



int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}