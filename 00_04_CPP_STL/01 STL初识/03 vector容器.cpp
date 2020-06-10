//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <list>

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		cout << v.capacity() << endl; // v.capacity()容器的容量
	}
}

/*
3.2.4.1 vector构造函数
vector<T> v; 				//采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());	//将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem);			//构造函数将n个elem拷贝给本身。
vector(const vector &vec);	//拷贝构造函数。

//例子 使用第二个构造函数 我们可以...
int arr[] = {2,3,4,1,9};
vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

3.2.4.2 vector常用赋值操作
assign(beg, end);						//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);						//将n个elem拷贝赋值给本身。
vector& operator=(const vector  &vec);	//重载等号操作符
swap(vec);								// 将vec与本身的元素互换。
*/

void printVector(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test02()
{
	vector<int> v;			 //默认构造
	vector<int> v2(10, 100); //10个100
	printVector(v2);

	vector<int> v3(v2.begin(), v2.end());
	printVector(v3);

	vector<int> v4(v3);
	printVector(v4);
}

void test03()
{
	//赋值
	int arr[] = {2, 3, 4, 1, 9};
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	vector<int> v2;
	v2 = v1;
	printVector(v2);

	vector<int> v3;
	v3.assign(v2.begin(), v2.end());
	printVector(v3);

	vector<int> v4(10, 100);
	printVector(v4);

	cout << "v3 和 v4 互换后：" << endl;

	v3.swap(v4);
	printVector(v3);
	printVector(v4);
}
/* 
//3.2.4.3 vector大小操作
size();				   //返回容器中元素的个数
empty();			   //判断容器是否为空
resize(int num);	   //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
capacity();			   //容器的容量
reserve(int len);	   //容器预留len个元素长度，预留位置不初始化，元素不可访问。
front();			   //返回容器中第一个数据元素
back();				   //返回容器中最后一个数据元素
 */
void test04()
{
	int arr[] = {2, 3, 4, 1, 9};
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	if (v1.empty())
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1不为空" << endl;
		cout << "size = " << v1.size() << endl;
	}
	printVector(v1);
	v1.resize(10, 100); //参数2  填充数据，填充值设置为0
	printVector(v1);

	v1.resize(3); // 2 3 4
	printVector(v1);

	cout << "第一个元素为： " << v1.front() << endl;  //2
	cout << "最后一个元素为： " << v1.back() << endl; //4
}
/* 
3.2.4.5 vector插入和删除操作
insert(const_iterator pos, int count, ele);		 //迭代器指向位置pos插入count个元素ele.
push_back(ele);									 //尾部插入元素ele
pop_back();										 //删除最后一个元素
erase(const_iterator start, const_iterator end); //删除迭代器从start到end之间的元素
erase(const_iterator pos);						 //删除迭代器指向的元素
clear();										 //删除容器中所有元素
 */
void test05()
{
	int arr[] = {2, 3, 4, 1, 9};
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	v1.insert(v1.begin(), 100);
	v1.insert(v1.begin(), 2, 1000);
	printVector(v1); // 1000 1000  100 2 3 4 1 9

	v1.push_back(10000);
	printVector(v1); // 1000 1000  100 2 3 4 1 9 10000
	v1.pop_back();
	printVector(v1); //  1000 1000  100 2 3 4 1 9

	v1.erase(v1.begin());
	printVector(v1); //  1000  100 2 3 4 1 9

	//v1.erase(v1.begin(), v1.end());
	v1.clear();
	printVector(v1);
}

//案例1  巧用swap收缩内存
void test06()
{
	vector<int> v;

	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "size = " << v.size() << endl;		   // 100000
	cout << "capacity = " << v.capacity() << endl; // 130000+

	v.resize(3);
	cout << "size = " << v.size() << endl;		   // 3
	cout << "capacity = " << v.capacity() << endl; //130000+

	//巧用swap收缩内存
	//说明：
	//		vector<int>(v) //调用拷贝构造函数，(利用v对象的实际数据占有量,来初始化)构造出来一个临时(匿名)的vector对象
	//      vector<int>(v).swap(v);// 临时对象和v对象，进行swap；匿名对象系统负责回收，v对象已经收缩了内存
	vector<int>(v).swap(v);
	cout << "size = " << v.size() << endl;		   // 3
	cout << "capacity = " << v.capacity() << endl; //3
}

//2、巧用reserve 预留内存空间
//reserve  预留空间
//reverse  反转
void test07()
{

	vector<int> v;

	v.reserve(100000); //利用reserve可以提前预留空间

	int *p = NULL;
	int num = 0;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++; //统计开辟了多少次内存
		}
	}

	cout << "num = " << num << endl;			   //num统计 添加100000数据，重新开辟空间次数
	cout << "size = " << v.size() << endl;		   //100000   reserve之后为100000
	cout << "capacity = " << v.capacity() << endl; //130000+  reserve之后为100000
}

void test08()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << "正序遍历结果" << endl;
	printVector(v);

	cout << "逆序遍历结果" << endl;
	//逆序遍历 非质变
	//reverse_iterator 反转迭代器
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//如果判断一个容器的迭代器是否支持随机访问
	vector<int>::iterator itBegin = v.begin();
	itBegin++;			   //++(向前)
	itBegin--;			   //++(向前)
						   //++(向前) --(向后) 语法都通过的话-->说明这是一个双向迭代器
	itBegin = itBegin + 1; //+ 操作 语法通过的话-->说明支持随机访问

	list<int> L;
	L.push_back(10);
	L.push_back(10);
	L.push_back(10);

	list<int>::iterator lBegin = L.begin();
	lBegin++;
	lBegin--;
	//lBegin = lBegin + 1; //不支持随机访问
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	test08();
	//system("pause");
	return 0;
}