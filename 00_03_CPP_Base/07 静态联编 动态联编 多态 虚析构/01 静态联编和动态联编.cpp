#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	//�麯��
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}

	virtual void eat(int a)
	{
		cout << "�����ڳԷ�" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}

	virtual void eat(int a)
	{
		cout << "Сè�ڳԷ�" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;
	}
};

//�ڼ̳��У������ָ����������ǿ���ֱ��ָ������Ķ����
void DoSpeak(Animal & animal)
{
	animal.speak(); //��̬���� ������ַ��� ��������è˵������ַ�Ͳ�������󶨣�����������ʱ��󶨣���̬���ࣩ
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

	//*(int *)animal �����õ��麯������
	//*(int*)*(int *)animal �����õ������������ڵ�ַ 0x0011233

	//Сè˵��
	((void(*)()) (*(int*)*(int *)animal))();


	//C/C++Ĭ�ϵ��ù�����  cdecl
	//����д�����ù��� �� stdcall
	//Сè�Է�
	typedef void(__stdcall *FUNC_POINT)(int);
	(FUNC_POINT(*((int*)*(int *)animal + 1)))(10);
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}