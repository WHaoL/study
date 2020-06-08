#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	//虚函数
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}

	virtual void eat(int a)
	{
		cout << "动物在吃饭" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}

	virtual void eat(int a)
	{
		cout << "小猫在吃饭" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};

//在继承中，父类的指针或者引用是可以直接指向子类的对象的
void DoSpeak(Animal & animal)
{
	animal.speak(); //静态联编 函数地址早绑定 如果想调用猫说话，地址就不可以早绑定，而是在运行时晚绑定（动态联编）
}

void test01()
{
	Cat cat;
	DoSpeak(cat);

	Dog dog;
	DoSpeak(dog);
}

void test02()
{
	
	//cout << "sizeof Animal = " << sizeof(Animal) << endl;

	Animal * animal = new Cat;
	//animal->speak();

	//*(int *)animal 解引用到虚函数表中
	//*(int*)*(int *)animal 解引用到函数具体的入口地址 0x0011233

	//小猫说话
	((void(*)()) (*(int*)*(int *)animal))();


	//C/C++默认调用惯例是  cdecl
	//下面写法调用惯例 用 stdcall
	//小猫吃饭
	typedef void(__stdcall *FUNC_POINT)(int);
	(FUNC_POINT(*((int*)*(int *)animal + 1)))(10);
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}