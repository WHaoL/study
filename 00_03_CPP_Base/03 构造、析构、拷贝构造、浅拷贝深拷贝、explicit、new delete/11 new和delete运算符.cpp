#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:

	Person()
	{
		cout << "PersonĬ�Ϲ������" << endl;
	}

	Person(int a )
	{
		cout << "Person�вι������" << endl;
	}

	Person(const Person &)
	{
		cout << "Person�����������" << endl;
	}

	~Person()
	{
		cout << "Person������������" << endl;
	}
};


//malloc �� new ����
//1��malloc �� free ���ڿ⺯��    new  delete ���������
//2��malloc ��Ӧfree      new  ��Ӧ delete
//3��malloc������void *     new ���ش����Ķ����ָ��
//4��malloc������ù��캯��       new ���ù��캯��
//5��free ���������������        delete ������������
//6��malloc�����ڴ���Ҫ���Ǽ����С    new ����Ҫ����

void test01()
{
	//	Person p1;  ջ��

	Person * p1 = new Person;  //Ĭ��

	Person * p2 = new Person(10); //�в�

	Person * p3 = new Person(*p2); //����

	//����delete�ͷŶ�������
	delete p1;
	delete p2;
	delete p3;

}

//2����Ҫ����void*����new�����Ķ���
void test02()
{
	void * p = new Person;

	//�޷��ͷŶ���
	delete p;
}

//3��new��������
void test03()
{
	//int * pInt = new int[10];
	//char * pChar =  new char[64];


	//�ڶ����������飬������Ĭ�Ϲ���
	Person * pArray = new Person[10];


	//�ͷŶ������� ��[] 
	delete [] pArray;


	//���   ��ջ�ϴ��������ʱ�򣬿���û��Ĭ�Ϲ���
	Person arr[3] = { Person(10), Person(20), Person(30) };
}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}