#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

class MyPrint : public binary_function<int,int ,void>
{
public:
	void operator()(int num , int start) const 
	{
		cout << "num = " <<  num << " start = " << start << " sum = " << num  + start  << endl;
	}
};

//1����������������
//1.1 ��  bind2nd
//1.2 �̳� public binary_function<��������,�������� ,����ֵ����>
//1.3 ��const

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}
	cout << "��������ʼ�ۼ�ֵ��" << endl;
	int start;
	cin >> start;

	for_each(v.begin(), v.end(), bind2nd( MyPrint(), start)  ); //�Ƽ�
	//for_each(v.begin(), v.end(), bind1st(MyPrint(), start));
}


//2��ȡ��������
class GreaterFive : public unary_function<int,bool>
{
public:
	bool operator()(int val)const 
	{
		return val > 5;
	}
};
//2.1 ȡ�������� not1
//2.2 �̳� public unary_function<��������,����ֵ����>
//2.3 ��const
void test02()
{
	//һԪȡ��������
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}

	//vector<int>::iterator ret = find_if(v.begin(), v.end(), not1( GreaterFive()));

	vector<int>::iterator ret = find_if(v.begin(), v.end(), not1(  bind2nd( greater<int>(), 5 )));
	if (ret != v.end())
	{
		cout << "�ҵ�С��5������Ϊ" << *ret << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	//��Ԫȡ��������
	sort(v.begin(), v.end(),  not2( less<int>()));
	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//3������ָ��������

void myPrint(int val , int start)
{
	cout << val + start << endl;
}

void test03()
{

	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << "��������ʼ�ۼ�ֵ��" << endl;
	int start;
	cin >> start;
	//��myPrint����ָ�� ����� �������� ����
	//���� ptr_fun
	for_each(v.begin(), v.end(), bind2nd( ptr_fun(myPrint), start));
}


//4����Ա����������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "������ " << this->m_Name << " ���䣺 " << this->m_Age << endl;
	}

	void addAge()
	{
		this->m_Age++;
	}

	string m_Name;
	int m_Age;
};

void test04()
{
	vector<Person>v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//����mem_fun_ref ����Ա������������
	for_each(v.begin(), v.end(), mem_fun_ref( &Person::showPerson));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::addAge));
	cout << "-------------------------" << endl;
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}

int main(){
	
	//test01();
	//test02();
	//test03();
	test04();


	system("pause");
	return EXIT_SUCCESS;
}