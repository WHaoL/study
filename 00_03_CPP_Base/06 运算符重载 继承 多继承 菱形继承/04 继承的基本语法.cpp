#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

////Java页面
//class Java
//{
//public:
//
//	//公共的头
//	void header()
//	{
//		cout << "公共的头部" << endl;
//	}
//
//	//公共底部
//	void footer()
//	{
//		cout << "公共的底部" << endl;
//	}
//
//	//公共的分类列表
//	void list()
//	{
//		cout << "公共的学科分类列表" << endl;
//	}
//
//	//显示具体教程
//	void content()
//	{
//		cout << "Java教程" << endl;
//	}
//
//};
//
////Python页面
//class Python
//{
//public:
//
//	//公共的头
//	void header()
//	{
//		cout << "公共的头部" << endl;
//	}
//
//	//公共底部
//	void footer()
//	{
//		cout << "公共的底部" << endl;
//	}
//
//	//公共的分类列表
//	void list()
//	{
//		cout << "公共的学科分类列表" << endl;
//	}
//
//	//显示具体教程
//	void content()
//	{
//		cout << "Python教程" << endl;
//	}
//};
////CPP
//class CPP
//{
//public:
//	//公共的头
//	void header()
//	{
//		cout << "公共的头部" << endl;
//	}
//
//	//公共底部
//	void footer()
//	{
//		cout << "公共的底部" << endl;
//	}
//
//	//公共的分类列表
//	void list()
//	{
//		cout << "公共的学科分类列表" << endl;
//	}
//
//	//显示具体教程
//	void content()
//	{
//		cout << "C++教程" << endl;
//	}
//};


//利用继承实现页面
//公共页面

//继承的好处： 减少重复代码

class BasePage
{
public:
	//公共的头
	void header()
	{
		cout << "公共的头部" << endl;
	}
	
	//公共底部
	void footer()
	{
		cout << "公共的底部" << endl;
	}
	
	//公共的分类列表
	void list()
	{
		cout << "公共的学科分类列表" << endl;
	}
};

//语法：class 子类 : 继承方式  父类
//子类 --- 派生类
//父类 --- 基类

//Java页面
class Java : public BasePage
{
public:
	//显示具体教程
	void content()
	{
		cout << "Java教程" << endl;
	}
};

//Python页面
class Python :public BasePage
{
public:
	//显示具体教程
	void content()
	{
		cout << "Python教程" << endl;
	}
};
//CPP页面
class CPP :public BasePage
{
public:
	//显示具体教程
	void content()
	{
		cout << "CPP教程" << endl;
	}
};

void test01()
{
	cout << "Java的页面内容如下： " << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.list();
	ja.content();
	cout << "-----------------------" << endl;


	cout << "Python的页面内容如下： " << endl;
	Python py;
	py.header();
	py.footer();
	py.list();
	py.content();

	cout << "-----------------------" << endl;
	cout << "CPP的页面内容如下： " << endl;
	CPP cpp;
	cpp.header();
	cpp.footer();
	cpp.list();
	cpp.content();
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}