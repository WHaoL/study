#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

/*
find算法 查找元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 查找的元素
@return 返回查找元素的位置
*/
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//查找5元素是否存在
	vector<int>::iterator ret = find(v.begin(), v.end(), 5);
	if (ret != v.end())
	{
		cout << "找到了元素：" << *ret << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//查找大于5的元素
	vector<int>::iterator ret2 = find_if(v.begin(), v.end(), GreaterFive());
	if (ret2 != v.end())
	{
		cout << "找到了大于5的元素：" << *ret2 << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}
//find_if 自定义类型数据查找
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	bool operator==(const Person & p)
	{
		return this->m_Name == p.m_Name && this->m_Age == p.m_Age;
	}

	string m_Name;
	int m_Age;
};

void test02()
{
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//查找p4 的数据
	Person p("ddd", 40);
	vector<Person>::iterator ret = find(v.begin(), v.end(), p);
	if (ret != v.end())
	{
		cout << "找到了 姓名：" << (*ret).m_Name << " 年龄： " << ret->m_Age << endl;
	}
}

class myCompare:public binary_function<Person*,Person*,bool>
{
public:
	bool operator()(Person * p1 , Person * p2)const
	{
		if (p1->m_Name == p2->m_Name  && p1->m_Age == p2->m_Age)
		{
			return true;
		}
		return false;
	}

};

void test03()
{
	vector<Person*>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	Person * person = new Person("bbb", 20);

	vector<Person *>::iterator ret = find_if(v.begin(), v.end(), bind2nd( myCompare(), person ));

	if (ret != v.end())
	{
		cout << "找到了元素姓名： " << (*ret)->m_Name << " 年龄： " << (*ret)->m_Age << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

}


/*
adjacent_find算法 查找相邻重复元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  _callback 回调函数或者谓词(返回bool类型的函数对象)
@return 返回相邻元素的第一个位置的迭代器
*/
void test04()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(3);
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it != v.end())
	{
		cout << "找到相邻重复元素为： " << *it << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

/*
binary_search算法 二分查找法
注意: 在无序序列中不可用
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 查找的元素
@return bool 查找返回true 否则false
*/
void test05()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//v.push_back(3); 容器必须是有序序列！！

	bool ret = binary_search(v.begin(), v.end(), 9);
	if (ret)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

/*
count算法 统计元素出现次数
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  value回调函数或者谓词(返回bool类型的函数对象)
@return int返回元素个数
*/

void test06()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);

	//统计5的元素个数  按值统计个数
    int num	= count(v.begin(), v.end(), 5);
	cout << "5的个数为：" << num << endl;

}

/*
count_if算法 统计元素出现次数
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  callback 回调函数或者谓词(返回bool类型的函数对象)
@return int返回元素个数
*/
class GreaterFive1
{
public:
	bool operator()(int val)
	{
		return val >= 5;
	}

};
void test07()
{
	vector<int>v;
	// 0 1 2 3 4 5 6 7 8 9 5 5 5 5
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);

	//查找大于等于5的元素个数
	int num = count_if(v.begin(), v.end(), GreaterFive1());
	cout << "大于等于5的个数为：" << num << endl;
}

int main(){
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();



	system("pause");
	return EXIT_SUCCESS;
}