#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

const double PI = 3.14;

//类关键字  class + 类名
class Circle
{
public: //公共权限

	//获取圆周长的函数
	double calculateZC()
	{
		return 2 * PI * m_R;
	}

	//设置圆的半径
	void setR(int r)
	{
		m_R = r;
	}

	//获取圆的半径
	int getR()
	{
		return m_R;
	}

	//半径
	int m_R;
};

void test01()
{
	Circle c1; //通过圆类 创建圆对象

	//给圆对象的半径赋值
	//c1.m_R = 10;
	c1.setR(10);

	cout << "圆的周长为： " << c1.calculateZC() << endl;
	cout << "圆的半径为： " << c1.getR() << endl;
}


//设计学生类  属性 姓名和学号，可以设置和获取，显示信息
class Student
{
public:
	
	//类中所有内容都叫成员
	//类中所有属性  成员属性  成员变量
	//类中所有函数  成员函数  成员方法

	//设置姓名
	void setName(string name)
	{
		m_Name = name;
	}
	//设置学号
	void setId(int id)
	{
		m_Id = id;
	}

	//获取姓名
	string getName()
	{
		return m_Name;
	}
	//获取学号
	int getId()
	{
		return m_Id;
	}

	//显示信息
	void showInfo()
	{
		cout << "姓名： " << m_Name << " 学号： " << m_Id << endl;
	}

	//姓名
	string m_Name;
	//学号
	int m_Id;
};

void test02()
{
	//通过类 创建对象  过程 实例化对象
	Student s1;
	s1.setName("张三");
	s1.setId(1);
	cout << "姓名： " << s1.getName() << " 学号： " << s1.getId() << endl;

	Student s2;
	s2.setName("李四");
	s2.setId(2);
	s2.showInfo();
}


int main(){
	test02();


	system("pause");
	return EXIT_SUCCESS;
}