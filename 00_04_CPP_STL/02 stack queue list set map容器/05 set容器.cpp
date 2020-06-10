//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <set>
#include <string>

/* 
//3.7.2.1 set构造函数
set<T> st;			//set默认构造函数：
mulitset<T> mst;	//multiset默认构造函数:
set(const set &st); //拷贝构造函数

//3.7.2.2 set赋值操作
set &operator=(conts set &st); //重载等号操作符
swap(st);					   //交换两个集合容器

//3.7.2.3 set大小操作
size();	 //返回容器中元素的数目
empty(); //判断容器是否为空

//3.7.2.4 set插入和删除操作
insert(elem);	 //在容器中插入元素。
clear();		 //清除所有元素
erase(pos);		 //删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(elem);	 //删除容器中值为elem的元素。
 */
void printSet(set<int> &s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	set<int> s;
	s.insert(10);
	s.insert(30);
	s.insert(40);
	s.insert(40);
	s.insert(20);
	s.insert(50);
	//set容器会自动排序，默认排序规则 从小到大
	//set不允许插入重复的值
	printSet(s);

	//删除 30
	s.erase(30);
	printSet(s);
}

/*
3.7.2.5 set查找操作
find(key);				//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key);				//查找键key的元素个数
lower_bound(keyElem);	//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);	//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);	//返回容器中key与keyElem相等的上下限的两个迭代器。
*/

void test02()
{
	set<int> s;
	s.insert(10);
	s.insert(30);
	s.insert(40);
	s.insert(20);
	s.insert(50);

	set<int>::iterator pos = s.find(30);
	if (pos != s.end())
	{
		cout << "找到了元素：" << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//count统计  set而言，结果要么是0，要么是1
	int num = s.count(40);
	cout << "40的元素个数为：" << num << endl;

	//lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
	set<int>::iterator ret = s.lower_bound(30);
	if (ret != s.end())
	{
		cout << "找到lower_bound的值为： " << *ret << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
	ret = s.upper_bound(30);
	if (ret != s.end())
	{
		cout << "找到upper_bound的值为： " << *ret << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
	pair<set<int>::iterator, set<int>::iterator> ret2 = s.equal_range(30);

	if (ret2.first != s.end())
	{
		cout << "找的了equal_range中的lower_bound的值为" << *(ret2.first) << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	if (ret2.second != s.end())
	{
		cout << "找的了equal_range中的upper_bound的值为" << *(ret2.second) << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

//对组的创建
void test03()
{
	pair<string, int> p1("Tom", 18);
	cout << "姓名： " << p1.first << endl;
	cout << "年龄： " << p1.second << endl;

	pair<string, int> p2 = make_pair("Jerry", 20);
	cout << "姓名： " << p2.first << endl;
	cout << "年龄： " << p2.second << endl;
}

//set 和 multiset区别
void test04()
{
	set<int> s;
	pair<set<int>::iterator, bool> ret = s.insert(10);

	if (ret.second)
	{
		cout << "第一次插入成功" << endl;
	}
	else
	{
		cout << "第一次插入失败" << endl;
	}
	ret = s.insert(10);
	if (ret.second)
	{
		cout << "第二次插入成功" << endl;
	}
	else
	{
		cout << "第二次插入失败" << endl;
	}

	//printSet(s);

	multiset<int> multi;
	multi.insert(10);
	multi.insert(10);

	for (multiset<int>::iterator it = multi.begin(); it != multi.end(); it++)
	{
		cout << *it << endl;
	}
}

class myCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

//set容器排序
void test05()
{
	//通过仿函数 改变set容器的排序规则
	set<int, myCompare> s;

	s.insert(10);
	s.insert(30);
	s.insert(40);
	s.insert(20);
	s.insert(50);

	//printSet(s);

	for (set<int, myCompare>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//对于自定义数据类型set容器排序
class Person
{
public:
	Person(string name, int age) : m_Name(name), m_Age(age)
	{
	}

	string m_Name;
	int m_Age;
};

class myComparePerson
{
public:
	bool operator()(const Person &p1, const Person &p2)
	{
		//年龄降序
		return p1.m_Age > p2.m_Age;
	}
};

void test06()
{
	//对于自定义数据类型，指定排序规则
	set<Person, myComparePerson> s;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	s.insert(p4);
	s.insert(p2);
	s.insert(p5);
	s.insert(p1);
	s.insert(p3);

	for (set<Person, myComparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << " 年龄： " << it->m_Age << endl;
	}
}

int main()
{

	test01();
	test02();
	test03();
	test04();
	test05();
	test06();

	//system("pause");
	return EXIT_SUCCESS;
}