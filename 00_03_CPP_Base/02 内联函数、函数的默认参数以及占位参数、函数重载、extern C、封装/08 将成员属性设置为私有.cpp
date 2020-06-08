#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

class Person
{
public:

	//设置姓名
	void setName(string name)
	{
		m_Name = name;
	}
	//获取姓名
	string getName()
	{
		return m_Name;
	}

	//获取年龄
	int getAge()
	{
		return m_Age;
	}

	//设置年龄
	void setAge(int age)
	{
		if (age <0 || age > 150)
		{
			cout << "你这个老妖精！" << endl;
			return;
		}
		m_Age = age;
	}

	//设置情人
	void setLover(string lover)
	{
		m_Lover = lover;
	}
	

private:
	string m_Name; //姓名  可读可写

	int m_Age = 18; //年龄  只读       可写  0 ~ 150

	string m_Lover; //情人  只写
};

//将成员属性设置私有好处： 自己控制读写权限
//对于写权限，可以验证数据的有效性
void test01()
{
	Person p1;
	p1.setName("张三");
	cout << "姓名： " << p1.getName() << endl;

	//p1.m_Age = 19;  //私有成员 类外访问不到
	//p1.setAge(19);  //没有提供设置接口

	//p1.setAge(1000);
	p1.setAge(100);
	cout << "年龄： " << p1.getAge() << endl;

	p1.setLover("仓井"); //只写
	//cout << "情人： " << p1.getLover() << endl;  访问不到私有成员，没提供读的接口

}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}