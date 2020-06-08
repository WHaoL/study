#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:

	Person()
	{
		cout << "Person默认构造调用" << endl;
	}

	Person(int a )
	{
		cout << "Person有参构造调用" << endl;
	}

	Person(const Person &)
	{
		cout << "Person拷贝构造调用" << endl;
	}

	~Person()
	{
		cout << "Person析构函数调用" << endl;
	}
};


//malloc 和 new 区别
//1、malloc 和 free 属于库函数    new  delete 属于运算符
//2、malloc 对应free      new  对应 delete
//3、malloc返回是void *     new 返回创建的对象的指针
//4、malloc不会调用构造函数       new 调用构造函数
//5、free 不会调用析构函数        delete 调用析构函数
//6、malloc开辟内存需要我们计算大小    new 不需要计算

void test01()
{
	//	Person p1;  栈上

	Person * p1 = new Person;  //默认

	Person * p2 = new Person(10); //有参

	Person * p3 = new Person(*p2); //拷贝

	//利用delete释放堆区数据
	delete p1;
	delete p2;
	delete p3;

}

//2、不要利用void*接受new出来的对象
void test02()
{
	void * p = new Person;

	//无法释放对象
	delete p;
}

//3、new开辟数组
void test03()
{
	//int * pInt = new int[10];
	//char * pChar =  new char[64];


	//在堆区创建数组，必须有默认构造
	Person * pArray = new Person[10];


	//释放堆区数组 加[] 
	delete [] pArray;


	//提高   在栈上创建数组的时候，可以没有默认构造
	Person arr[3] = { Person(10), Person(20), Person(30) };
}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}