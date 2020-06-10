//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>
#include <vector>

/* 
3.1.2.1 string 构造函数
string();				   //创建一个空的字符串 例如: string str;
string(const string &str); //使用一个string对象初始化另一个string对象
string(const char *s);	   //使用字符串s初始化
string(int n, char c);	   //使用n个字符c初始化

3.1.2.2 string基本赋值操作
string &operator=(const char *s);				   //char*类型字符串 赋值给当前的字符串
string &operator=(const string &s);				   //把字符串s赋给当前的字符串
string &operator=(char c);						   //字符赋值给当前的字符串
string &assign(const char *s);					   //把字符串s赋给当前的字符串
string &assign(const char *s, int n);			   //把字符串s的前n个字符赋给当前的字符串
string &assign(const string &s);				   //把字符串s赋给当前字符串
string &assign(int n, char c);					   //用n个字符c赋给当前字符串
string &assign(const string &s, int start, int n); //将s从start开始n个字符赋值给字符串 
*/

void test01()
{
	//构造
	string str1;
	string str2 = str1;
	string str3 = "abcd";
	string str4(5, 'a');

	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	//赋值
	string str5;
	str5.assign("abcdefghi", 6);
	cout << "str5 = " << str5 << endl; //abcdef

	//string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
	string str6;
	str6.assign(str5, 1, 4);		   //
	cout << "str6 = " << str6 << endl; //bcde
}

/*
3.1.2.3 string存取字符操作
char& operator[](int n);//通过[]方式取字符
char& at(int n);//通过at方法获取字符
*/

void test02()
{
	string s = "hello world";

	//for (int i = 0; i < s.size();i++)
	//{
	//	//cout << s[i] << endl;
	//	//cout << s.at(i) << endl;
	//}

	//[]和at区别，[]访问越界 直接挂掉，at访问越界，抛出异常 out_of_range

	try
	{
		//cout << s[100] << endl;
		cout << s.at(100) << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}

/* 
3.1.2.4 string拼接操作
string &operator+=(const string &str);			 //重载+=操作符
string &operator+=(const char *str);			 //重载+=操作符
string &operator+=(const char c);				 //重载+=操作符
string &append(const char *s);					 //把字符串s连接到当前字符串结尾
string &append(const char *s, int n);			 //把字符串s的前n个字符连接到当前字符串结尾
string &append(const string &s);				 //同operator+=()
string &append(const string &s, int pos, int n); //把字符串s中从pos开始的n个字符连接到当前字符串结尾
string &append(int n, char c);					 //在当前字符串结尾添加n个字符c 
*/

//拼接
void test03()
{
	string s1 = "我";
	s1 += "爱北京";

	cout << s1 << endl;

	s1.append("天安门");
	cout << s1 << endl;
}
/* 
//3.1.2.5 string查找和替换
int find(const string &str, int pos = 0) const;		//查找str第一次出现位置,从pos开始查找
int find(const char *s, int pos = 0) const;			//查找s第一次出现位置,从pos开始查找
int find(const char *s, int pos, int n) const;		//从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;			//查找字符c第一次出现位置
int rfind(const string &str, int pos = npos) const; //查找str最后一次位置,从pos开始查找
int rfind(const char *s, int pos = npos) const;		//查找s最后一次出现位置,从pos开始查找
int rfind(const char *s, int pos, int n) const;		//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const;			//查找字符c最后一次出现位置
string &replace(int pos, int n, const string &str); //替换 从pos开始的n个字符 为字符串str
string &replace(int pos, int n, const char *s);		//替换 从pos开始的n个字符 为字符串s
 */
//查找
void test04()
{
	string str1 = "abcdefghde";

	int pos = str1.find("de"); //参数2(默认是0)：代表起始查找位置，
	//find  从左往右查
	//rfind 从右往左查

	if (pos == -1)
	{
		cout << "未找到子串" << endl;
	}
	else
	{
		cout << "找到子串，位置：" << pos << endl;
	}

	//替换
	string str2 = "abcdefg";
	//string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
	str2.replace(1, 3, "11111");
	cout << str2 << endl; // a11111efg
}

/*
3.1.2.6 string比较操作
compare函数 
	在>时返回 1，<时返回 -1，==时返回 0。
	比较区分大小写，比较时参考字典顺序，排越前面的越小。大写的A比小写的a小。
int compare(const string &s) const;	//与字符串s比较
int compare(const char *s) const;	//与字符串s比较
*/

void test05()
{
	string str1 = "abcde";
	string str2 = "abcdefgh";

	int ret = str1.compare(str2);

	if (ret == 0)
	{
		cout << " str1 ==  str2 " << endl;
	}
	else if (ret == 1)
	{
		cout << " str1  >  str2 " << endl;
	}
	else
	{
		cout << " str1  <  str2 " << endl;
	}
}

/*
3.1.2.7 string子串
string substr(int pos = 0, int n = npos) const;	//返回由pos开始的n个字符组成的字符串
*/
void test06()
{
	string str = "abcdefg";
	string subS = str.substr(0, 4); // abcd
	cout << subS << endl;

	string email = "zhangtao@sina.com";
	int pos = email.find("@");			   // pos = 8(从0开始)
	string usrName = email.substr(0, pos); // 8
	cout << "name = " << usrName << endl;
}

//提高
void test07()
{
	string str = "www.XTU.com.cn";
	vector<string> v;

	int pos = -1;
	int start = 0;

	while (true)
	{
		pos = str.find(".", start);
		if (pos == std::string::npos) //  std::string::npos一般定义为-1
		{
			// 截取最后一段字串
			string subS = str.substr(start, str.size() - start);
			v.push_back(subS);
			break;
		}
		// 截取前面的各个字串
		string subS = str.substr(start, pos - start); // pos = 10  start  = 4

		v.push_back(subS);

		start = pos + 1;
	}

	for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
}

/*
3.1.2.8 string插入和删除操作
string& insert(int pos, const char* s); 	//插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c);		//在指定位置插入n个字符c
string& erase(int pos, int n = npos);		//删除从Pos开始的n个字符
*/
void test08()
{
	string str = "hello";
	//插入，参数1 指定位置  参数2 插入数据
	str.insert(1, "2333");

	cout << str << endl; //h111ello

	//删除
	str.erase(1, 3);
	cout << str << endl;
}

void doWork(const char *str)
{
}

void doWork2(string str)
{
}

//string和c-style字符串转换
void test09()
{
	const char *str = "hello";

	//const char * 转string
	string str2 = string(str);

	//string 转  const char *
	const char *str3 = str2.c_str();

	//doWork(str2); //string 不会隐式转为 const char *
	doWork2(str3); //const char * 可以隐式转为 string
}

//字符串重新分配内存后，再使用原来的引用可能会发生错误
void test10()
{
	string s = "abcdefg";
	char &a = s[2];
	char &b = s[3];

	a = '1';
	b = '2';

	cout << s << endl;
	cout << (int *)s.c_str() << endl;

	s = "pppppppppppppppppppppppp";

	//a和b不可以再使用了
	//a = '1';
	//b = '2';

	cout << s << endl;
	cout << (int *)s.c_str() << endl;
}

/*
写一个函数，函数内部将string字符串中的所有小写字母都变为大写字母。
*/
void test11()
{
	string str = "abCDefg";

	for (int i = 0; i < str.size(); i++)
	{
		//小写转大写
		//str[i] = toupper(str[i]);

		//大写转小写
		str[i] = tolower(str[i]);
	}

	cout << str << endl;
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
	//test08();
	//test09();
	//test10();
	test11();

	//system("pause");
	return 0;
}