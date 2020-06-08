#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//动物类
class Animal
{
public:
	int m_Age;
};

//利用虚继承的方式 解决菱形继承的问题
//当做虚继承后，Animal称为 虚基类

//羊类
class Sheep : virtual public Animal{};

//驼类 
class Tuo : virtual public Animal{};

//羊驼类
class SheepTuo :public Sheep, public Tuo{};

void test01()
{
	SheepTuo st;
	//问题一，使用数据不明确，解决方式加作用域
	st.Sheep::m_Age = 100;

	st.Tuo::m_Age = 200;

	st.m_Age = 300;

	//问题二：age属性有一份就可以了，有两份的话无法区分用哪个适合，并且造成资源浪费

	cout << st.Sheep::m_Age << endl;
	cout << st.Tuo::m_Age << endl;
}

void test02()
{
	SheepTuo st;
	st.m_Age = 100;

	//通过Sheep找到对应的偏移量
	// *(int*)&st 可以找到Sheep的vbtable表
	cout << "通过sheep找到的偏移： "<< *((int *)*(int*)&st + 1) << endl;

	//通过Tuo找到对应的偏移
	//*((int *)&st + 1) 可以找到Tuo对应的vbtable
	cout << "通过Tuo找到的偏移： " << *((int *)*((int *)&st + 1) + 1) << endl;

	//通过偏移 访问age数据
	cout << "m_Age = " << *((int *)((char *)&st + *((int *)*(int*)&st + 1))) << endl;

	cout << "m_Age = " << ((Animal *)((char *)&st + *((int *)*(int*)&st + 1)))->m_Age << endl;
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}