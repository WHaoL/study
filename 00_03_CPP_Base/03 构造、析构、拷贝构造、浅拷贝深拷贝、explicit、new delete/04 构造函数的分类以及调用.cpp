#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//构造函数的分类
//按参数分类   无参构造 (默认构造) ， 有参构造
//按类型分类   普通构造  拷贝构造
class Person
{
public:

	//无参
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}

	//有参
	Person(int a)
	{
		cout << "Person的有参构造函数调用" << endl;
	}

	//拷贝构造  拷贝 -- 复制  -- 克隆
	Person( const Person & p)
	{
		cout << "Person的拷贝构造函数调用" << endl;
	}

	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
};

//构造函数的调用
void test01()
{
	//默认构造
	Person p;
}

void test02()
{
	//1、括号法
	//Person p1(10); //有参构造
	//Person p2(p1);   //拷贝构造

	//注意事项1  不要利用括号法 调用默认构造函数
	//解释：Person p3(); 编译器认为是函数的声明，而不会认为是实例化对象
	//Person p3(); 不是创建对象

	//2、显示法
	//Person p1 = Person(10);  //有参构造
	//Person p2 = Person(p1); //拷贝构造

	//Person(10);//匿名对象 特点：当前行执行过后，由编译器释放掉

	//注意事项2 不要利用拷贝构造函数 初始化匿名对象
	//Person(p2);//编译器认为 Person(p2);  是   Person p2

	//3、隐式法  隐式类型转换法  可读性比较低 
	Person p3 = 10;  // Person p3 = Person(10);
	Person p4 = p3;  // Person p4 = Person(p3);
}

int main(){
	test02();


	system("pause");
	return EXIT_SUCCESS;
}