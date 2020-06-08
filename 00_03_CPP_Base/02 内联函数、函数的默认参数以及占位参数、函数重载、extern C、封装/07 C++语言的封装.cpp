#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//人
struct Person
{
public:
	char m_Name[64];

	int m_Age;

	//吃饭
	void personEat()
	{
		printf("%s在吃人饭\n", m_Name);
	}

};

//狗
class Dog
{
public:
	char m_Name[64];
	int m_Age;

	//吃饭
	void dogEat()
	{
		printf("%s在吃狗粮\n", m_Name);
	}
};

//C++中封装思想1：将属性和行为作为一个整体，来表现生活中的事物
//C++中封装思想2：将所有属性和行为，加以权限控制
//访问权限 一共有三种
//public     公共权限   成员  类内可以访问  类外也可以访问
//protected  保护权限   成员  类内可以访问  类外不可以访问
//private    私有权限   成员  类内可以访问  类外不可以访问
//C++中struct 和class 的区别
// struct 默认访问权限是 public
// class  默认访问权限是 private
void test01()
{
	Person p;
	strcpy(p.m_Name, "老王");
	p.personEat();

	Dog d;
	strcpy(d.m_Name, "旺财");
	d.dogEat();

	//p.dogEat();  person的里面没有dogEat函数
}


class Person1
{
public:
	string m_Name; //姓名
protected:
	string m_Car; //汽车
private:
	int m_pwd; //银行卡密码

public:
	void func()
	{
		m_Name = "张三";	//public  类内可以访问
		m_Car = "劳斯莱斯";	//protected  类内可以访问
		m_pwd = 12345;		//privates  类内可以访问
	}
};

void test02()
{
	Person1 p1;
	p1.m_Name = "李四";    //public    类外可以访问
	//p1.m_Car = "拖拉机"; //protected 类外不可以访问
	//p1.m_pwd = 54321;    //private   类外不可以访问

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}