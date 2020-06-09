//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
cin.get() //一次只能读取一个字符
cin.get(一个参数) //读一个字符
cin.get(两个参数) //可以读字符串
cin.getline()
cin.ignore()
cin.peek()
cin.putback()
*/

void test01()
{
	char ch = cin.get();
	cout << "ch = " << ch << endl;

	ch = cin.get();
	cout << "ch = " << ch << endl;

	ch = cin.get();
	cout << "ch = " << ch << endl;

	ch = cin.get();
	cout << "ch = " << ch << endl;
	//输入as，第一次输出a，第二次s，第三次 换行 第四次等待下次输入
}

void test02()
{
	//char ch;
	//cin.get(ch);
	//读一个字符
	//cout << "ch = " << ch << endl;

	//cin.get(两个参数)
	//可以读字符串
	//但是换行符会遗留在缓冲区中
	char buf[1024] = {0};
	cin.get(buf, 1024);
	cout << "test02()：buf = " << buf << endl;

	char ch = cin.get();
	if (ch == '\n')
	{
		cout << "ch == \\n"
			 << endl;
		cout << "换行符遗留在缓冲区中" << endl;
		cout << ch;
		cout << "换行符遗留在缓冲区中" << endl;
	}
}

void test03()
{
	//cin.getline()   注意：换行符不会在缓冲区中，而是直接扔掉
	char buf[1024] = {0};
	cin.getline(buf, 1024);
	cout << "test03()：buf = " << buf << endl;

	char ch = cin.get(); //'\n'已经被扔掉了，所以需要再次输入cin.get()才能读到一个字符
	do
	{
		if (ch == '\n')
		{
			cout << "换行符遗留在缓冲区中" << endl;
			break;
		}
		cout << "test03()：ch = " << ch << endl;
	} while (0);

	cout << "test03()：buf = " << buf << endl;
}

//cin.ignore() 忽略
void test04()
{
	cin.ignore(2); //默认会忽略一个字符，可以传int参数，代表忽略字符个数
	char ch = cin.get();

	cout << "test04()：ch = " << ch << endl;
}

//cin.peek()
void test05()
{
	char ch = cin.peek(); //提前查看一个字符(不读走，只查看)，一次查看缓冲区中一个字符
	cout << "test05()：cin.peek() ch = " << ch << endl;

	ch = cin.get();
	cout << "test05()：cin.get() ch = " << ch << endl;
}

//cin.putback()
void test06()
{
	char ch = cin.get();

	cin.putback(ch); //放回到原来的位置

	char buf[1024] = {0};
	cin.getline(buf, 1024);
	cout << "buf = " << buf << endl;
}

//案例1 ： 用户输入字符串 或者 数字 ，我们判断
void test07()
{
	cout << "test07()：开始" << endl;
	cout << "请输入一个数字或者字符串" << endl; // 一个！！！！！别输入多了
	char ch = cin.peek();

	if (ch >= '0' && ch <= '9')
	{
		int num;
		cin >> num; //把
		cout << "test07()：您输入的是数字： " << num << endl;
	}
	else
	{
		char buf[1024] = {0};
		cin >> buf;
		cout << "test07()：您输入的是字符串： " << buf << endl;
	}

	//cin.getline()   注意：换行符不会在缓冲区中，而是直接扔掉
	char buf[1024] = {0};
	cin.getline(buf, 1024); // 应该是只读到了一个 '\n'
	cout << "test07()：buf = " << buf << endl;
	cout << "test07()：结束" << endl;
}

//案例2：让用户输入一个区间的数字 1 ~ 10 闭区间，如果输入正确，验证成功，输入失败，重新输入
void test08()
{
	cout << "test08()：开始" << endl;
	int num = 0;

	cout << "请输入1~10之间的数字" << endl;

	while (true)
	{
		cin >> num;

		if (num >= 1 && num <= 10)
		{
			cout << "输入正确： " << num << endl;
			cout << "标志位： " << cin.fail() << endl;
			break;
		}
		//cout << "输入有误，请重新输入" << endl;

		//重置标志位
		cin.clear();
		//刷新缓冲区
		cin.sync(); //vs高级版本失效，利用getline将缓冲区的数据全部取走

		//标志位 正常 0  异常  1
		cout << "标志位： " << cin.fail() << endl;
	}

	cout << "test08()：结束" << endl;
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
	return EXIT_SUCCESS;
}