#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "Animal的构造函数调用" << endl;
	}

	//虚析构
	//virtual ~Animal()
	//{
	//	cout << "Animal的析构函数调用" << endl;
	//}

	//纯虚析构
	//需要有实现体，类外做实现
	//当类中有了纯虚析构，这个类也属于抽象类
	virtual ~Animal() = 0;

	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};
Animal::~Animal()
{
	cout << "Animal的纯虚析构调用" << endl;
}



class Cat :public Animal
{
public:
	Cat(char * name)
	{
		cout << "Cat的构造函数调用" << endl;
		this->m_Name = new char[strlen(name) + 1];
		strcpy(this->m_Name, name);
	}


	~Cat()
	{
		if (this->m_Name != NULL)
		{
			cout << "Cat的析构函数调用" << endl;
			delete[] this->m_Name;
			this->m_Name;
		}
	}


	virtual void speak()
	{
		cout << "小猫" << this->m_Name << "在说话" << endl;
	}

	char * m_Name;
};

void test01()
{
	Animal * animal = new Cat("Tom");
	animal->speak();

	//通过父类指针释放的时候，是无法释放子类对象，导致清理不干净
	//解决方式：利用虚析构，或者纯虚析构
	delete animal;
}

int main(){

	test01();

	//Animal a; //抽象类无法实例化对象

	system("pause");
	return EXIT_SUCCESS;
}