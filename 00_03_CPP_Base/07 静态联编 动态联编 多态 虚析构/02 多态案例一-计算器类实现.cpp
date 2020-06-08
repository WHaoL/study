#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//计算器类

//class calculator
//{
//public:
//
//	int getResult(string oper)
//	{
//		if (oper == "+")
//		{
//			return m_A + m_B;
//		}
//		else if (oper == "-")
//		{
//			return m_A - m_B;
//		}
//		else if (oper == "*")
//		{
//			return m_A * m_B;
//		}
//		else if (oper == "/")
//		{
//			return m_A / m_B;
//		}
//	}
//
//	int m_A;
//	int m_B;
//};

//开闭原则  对扩展进行开放  对修改进行关闭


//利用多态实现计算器案例
class AbstractCalculator
{
public:
	//虚函数
	//virtual int getResult()
	//{
	//	return 0;
	//};

	//纯虚函数
	//当一个类中有了纯虚函数，那么这个类就无法实例化对象了
	//如果有了纯虚函数，这个类也称为抽象类
	//子类必须要重写父类中的纯虚函数，否则子类也属于抽象类
	virtual int getResult() = 0;
	int m_A;
	int m_B;
};

//加法计算器类
class PlusCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A + m_B;
	};
};

//减法计算器类
class SubCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A - m_B;
	};
};

//乘法计算器类
class MulCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A * m_B;
	};
};

//多态的好处：可读性强，组织性强，可扩展性强
void test01()
{
	AbstractCalculator * abc;

	//用加法
	abc = new PlusCalculator;
	abc->m_A = 100;
	abc->m_B = 100;

	cout << "ret = " << abc->getResult() << endl;

	delete abc;

	//用减法
	abc = new SubCalculator;
	abc->m_A = 100;
	abc->m_B = 100;

	cout << "ret = " << abc->getResult() << endl;
	delete abc;

	//用乘法
	abc = new MulCalculator;
	abc->m_A = 100;
	abc->m_B = 100;

	cout << "ret = " << abc->getResult() << endl;
	delete abc;
}

class A :public AbstractCalculator
{
public:
	//如果子类不重写父类的纯虚函数，子类无法实例化对象，属于抽象类
	virtual int getResult()
	{
		return m_A * m_B;
	};
};

int main(){

	//AbstractCalculator abc;
	PlusCalculator add;
	A a;

	test01();

	system("pause");
	return EXIT_SUCCESS;
}