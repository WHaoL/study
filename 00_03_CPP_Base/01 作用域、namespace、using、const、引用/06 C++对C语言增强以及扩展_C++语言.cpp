#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1��ȫ�ֱ��������ǿ
int a;
//int a = 10;  error�ض���


//2��������ǿ  C++����ֵ�����ǿ���βμ����ǿ,���θ��������ǿ
int getRectS(int w, int h)
{
	return w * h;
}

void test01()
{
	getRectS(10, 10);
}

//3������ת�������ǿ
void test02()
{
	char *  p = (char *)malloc(64);
}


//4��struct ��ǿ
//C++������ �ṹ���п����к���
struct Person
{
	int age;
	void showAge(){ cout << age << endl; };
};
void test03()
{
	Person p1;  //���Լ�struct�ؼ���
	p1.age = 18;
	p1.showAge();
}

//5��bool���� �������
bool flag = true; //true ������ 1   false ����� 0
void test04()
{
	cout << "sizeof bool = " << sizeof(bool) << endl; // 1

	flag = false; 
	//flag = 100;
	cout << flag << endl;
}


//6����Ŀ�������ǿ
void test05()
{
	int a = 10;
	int b = 20;

	printf("ret = %d\n", a > b ? a : b);

	(a < b ? a : b )= 100; //���ص��Ǳ���������

	printf("a = %d\n", a); //100
	printf("b = %d\n", b); //20
}


//7��const��ǿ  �ܵ�����������
const int m_a = 100;
void test06()
{
	//m_a = 200;
	//int * p = (int *)&m_a;
	//*p = 1000;

	//C++�з��� ���ű�
	const int m_b = 100;
	//m_b = 200;
	int * p =(int*)&m_b;
	*p = 1000;
	cout << "m_b = " << m_b << endl;

	int arr[m_b] = {0};
}

int main(){
	test06();


	system("pause");
	return EXIT_SUCCESS;
}