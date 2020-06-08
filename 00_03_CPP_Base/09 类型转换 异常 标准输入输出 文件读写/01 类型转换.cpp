#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1����̬ת��
//������������ת��
void test01()
{
	char a = 'a';
	//�﷨�� static_cast<Ŀ������>(ԭ����/����)
	double d = static_cast<double>(a);

	cout << d << endl;
}

//����֮��ָ���������
class Base{};
class Son :public Base{};
class Other{};
void test02()
{
	Base * base = NULL;
	Son * son = NULL;

	//��baseת Son *      ��ת��   ����ȫ  ��������ת��

	Son * son2 = static_cast<Son *>(base);


	//��son תΪ Base *   ��ת��   ��ȫ   ��������ת��
	Base * base2 = static_cast<Base *>(son);

	//��base תΪOther*
	//Other * other = static_cast<Other*>(base); //error ���Ǹ����� ת����Ч
}


//2����̬ת��
void test03()
{
	char a = 'a';

	//������������֮�䲻����ת��
	//double d = dynamic_cast<double>(a);
}

class Base2{ public: virtual void func(){} };
class Son2 :public Base2{ public: virtual void func(){} };
class Other2{};

void test04()
{
	Base2 * base = NULL;

	Son2 * son = NULL;

	//��base תΪSon2 *   ��ת��  ����ȫ ��������ת��
	//Son2 * son2 = dynamic_cast<Son2*>(base);  error����ȫ

	//��son  תΪ Base2 *   ��ת�� ��ȫ  ��������ת��
	//Base2 * base2 = dynamic_cast<Base2 *>(son);

	//���������̬��ת�����ǰ�ȫ��
	Base2 * base3 = new Son2;
	//��base3 תΪ Son2*
	Son2 * son3 = dynamic_cast<Son2*>(base3);

	//��base3 תΪ Other *
	//Other2 * other = dynamic_cast<Other2 *>(base3);  û�й�ϵ��������֮�� ��Ӧ��ת��
}


//����ת��
void test05()
{
	//ָ��֮��
	int * p = NULL;

	const int * pp = const_cast<const int *>(p);

	int * ppp= const_cast<int *>(pp);


	//����֮��
	int num = 10;
	int &ref = num;

	const int & ref2 = const_cast<const int &>(ref);

	int & ref3 = const_cast<int &>(ref2);

	//const_castֻ������ָ�������֮��ת��
	const int a = 10;
	//int b = const_cast<int>(a); //error 
}

//���½���ת��  ���Ƽ�ʹ��
void test06()
{
	int a = 10;
	int * p  = reinterpret_cast<int *>(a);

	//��baseתOther*
	Base * base = NULL;

	Other * other = reinterpret_cast<Other *>(base);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}