#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//��ͨ�����ͺ���ģ�� ����
template<class T>
T myPlus(T a, T b)
{
	return a + b;
}

int myPlus2(int a, int b)
{
	return a + b;
}


void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';//a - 97 
	//cout << myPlus(a, c) << endl; //�Զ������Ƶ� �Ƶ�����һ�µ�T���޷����� ���޷�������ʽ����ת��
	cout << myPlus2(a, c) << endl; //��ͨ�������Է�����ʽ����ת��

	myPlus<int>(a, c); //��ʾָ������ ���� ��ʽ����ת��

}

//��ͨ�����ͺ���ģ��ĵ��ù���

//����ģ��ͨ���������Ͳ�����ͬ�ĺ���
//ͨ������ģ������ĺ��� ����Ϊ  ģ�庯��

template<class T>
void myPrint(T a ,T b)
{
	cout << "����ģ��ĵ���" << endl;
}
/*
void myPrint(int a ,int b)
{
cout << "����ģ��ĵ���" << endl;
}

void myPrint(double a ,double b)
{
cout << "����ģ��ĵ���" << endl;
}
*/

template<class T>
void myPrint(T a, T b,T c)
{
	cout << "����ģ��myPrint(T a, T b,T c)�ĵ���" << endl;
}

void myPrint(int a, int b)
{
	cout << "��ͨ�����ĵ���" << endl;
}

void test02()
{
	//1�������ͨ�����ͺ���ģ�嶼����ƥ��ɹ�������ѡ����ͨ����
	int a = 10;
	int b = 20;
	//myPrint(a, b);

	//2�������ǿ���ߺ���ģ������ݣ���Ҫ���ÿ�ģ������б�
	//myPrint<>(a, b);

	//3������ģ��Ҳ���Է�����������
	//myPrint(a, b, 10);

	//4���������ģ����Բ������õ�ƥ�䣬��ô����ѡ����ģ��
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}