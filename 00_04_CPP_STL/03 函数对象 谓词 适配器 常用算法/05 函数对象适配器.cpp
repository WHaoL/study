/* 
// unary_function和binary_function详解 https://www.cnblogs.com/blueoverflow/p/4738964.html
// Boost::bind使用详解 https://www.cnblogs.com/blueoverflow/p/4740093.html
//  
*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
// binary_function 接收两个参数的适配器基类

// 1、定义函数对象适配器MyPrint()
class MyPrint : public binary_function<int, int, void>
{
public:
	void operator()(int num, int start) const
	{
		cout << "num = " << num << " start = " << start << " sum = " << num + start << endl;
	}
};

//1、函数对象适配器
//1.1 绑定  bind2nd
//1.2 继承  public binary_function<参数类型,参数类型 ,返回值类型>
//1.3 加const

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << "请输入起始累加值：" << endl;
	int start;
	cin >> start;

	//for_each(v.begin(), v.end(), call_back());
	//说明：
	//		for_each()只能接收三个参数，第三个参数是个回调函数
	//		然后for_each()给call_back()传递一个参数(迭代器所指的对象)
	//说明：
	//		函数对象适配器MyPrint()，它接收两个参数
	//      	bind2nd(MyPrint(), start) 指定把start绑定为MyPrint()的的第二个参数
	//      	bind1st(MyPrint(), start) 指定把start绑定为MyPrint()的的第一个参数
	//		for_each()给它传递一个，我们给它绑定了一个参数，加起来正好两个参数
	// 		这样虽然只给for_each()传递进去一个回调函数MyPrint()，但这个回调函数实际接到了两个参数
	//		也起到了只给for_each()传递一个回调函数的初衷
	//      只不过是进过我们的改造，给回调函数绑定了一个参数
	for_each(v.begin(), v.end(), bind2nd(MyPrint(), start));
	//此处推荐：for_each(v.begin(), v.end(), bind1st(MyPrint(), start));
}

// unary_function 接收一个参数的适配器基类

//2、取反适配器

class GreaterFive : public unary_function<int, bool>
{
public:
	bool operator()(int val) const
	{
		return val > 5;
	}
};
//2.1 取反适配器 not1
//2.2 继承 public unary_function<参数类型,返回值类型>
//2.3 加const
void test02()
{
	//一元取反适配器
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//vector<int>::iterator ret = find_if(v.begin(), v.end(), not1( GreaterFive()));

	vector<int>::iterator ret = find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 5)));
	if (ret != v.end())
	{
		cout << "找到小于5的数据为" << *ret << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//二元取反适配器
	sort(v.begin(), v.end(), not2(less<int>()));
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//3、函数指针适配器

void myPrint(int val, int start)
{
	cout << val + start << endl;
}

void test03()
{

	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << "请输入起始累加值：" << endl;
	int start;
	cin >> start;
	//将myPrint函数指针 适配成 函数对象 即可
	//利用 ptr_fun
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(myPrint), start));
}

//4、成员函数适配器
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "姓名： " << this->m_Name << " 年龄： " << this->m_Age << endl;
	}

	void addAge()
	{
		this->m_Age++;
	}

	string m_Name;
	int m_Age;
};

void test04()
{
	vector<Person> v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//利用mem_fun_ref 将成员函数进行适配
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::addAge));
	cout << "-------------------------" << endl;
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}

int main()
{

	test01();
	test02();
	test03();
	test04();

	//system("pause");
	return EXIT_SUCCESS;
}