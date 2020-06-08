#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son :public Base
{
public:
	//父类中所有的成员属性都被子类继承了一份，私有属性只是被编译器给隐藏了，因此访问不到
	int m_D;
};


// C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\Shortcuts
// 跳转盘符 F:
// cd 跳转.cpp文件目录下
// cl /d1 reportSingleClassLayoutSon 06.....cpp
void test01()
{
	cout << "sizeof Son =" << sizeof(Son) << endl; //16
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}