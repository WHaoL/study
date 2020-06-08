#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "Animal�Ĺ��캯������" << endl;
	}

	//������
	//virtual ~Animal()
	//{
	//	cout << "Animal��������������" << endl;
	//}

	//��������
	//��Ҫ��ʵ���壬������ʵ��
	//���������˴��������������Ҳ���ڳ�����
	virtual ~Animal() = 0;

	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};
Animal::~Animal()
{
	cout << "Animal�Ĵ�����������" << endl;
}



class Cat :public Animal
{
public:
	Cat(char * name)
	{
		cout << "Cat�Ĺ��캯������" << endl;
		this->m_Name = new char[strlen(name) + 1];
		strcpy(this->m_Name, name);
	}


	~Cat()
	{
		if (this->m_Name != NULL)
		{
			cout << "Cat��������������" << endl;
			delete[] this->m_Name;
			this->m_Name;
		}
	}


	virtual void speak()
	{
		cout << "Сè" << this->m_Name << "��˵��" << endl;
	}

	char * m_Name;
};

void test01()
{
	Animal * animal = new Cat("Tom");
	animal->speak();

	//ͨ������ָ���ͷŵ�ʱ�����޷��ͷ�������󣬵��������ɾ�
	//�����ʽ�����������������ߴ�������
	delete animal;
}

int main(){

	test01();

	//Animal a; //�������޷�ʵ��������

	system("pause");
	return EXIT_SUCCESS;
}