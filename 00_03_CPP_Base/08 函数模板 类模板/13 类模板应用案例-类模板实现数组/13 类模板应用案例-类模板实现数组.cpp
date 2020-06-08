#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "myArray.hpp"
#include <string>

//��ӡ����
void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize();i++)
	{
		cout << arr[i] << endl;
	}
}

void test01()
{
	MyArray<int>intArr(10);

	for (int i = 0; i < intArr.getCapacity();i++)
	{
		intArr.push_back(i + 100);
	}

	//��������
	printIntArray(intArr);


	MyArray <int>arr2 = intArr;
	printIntArray(arr2);


	MyArray <int>arr3(10);
	arr3 = arr2;
	arr3.pop_back();
	printIntArray(arr3);
}


class Person
{
public:
	Person(){};
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void printPersonArr(MyArray<Person>&pArr)
{
	for (int i = 0; i < pArr.getSize();i++)
	{
		cout << "������ " << pArr[i].m_Name << " ���䣺 " << pArr[i].m_Age << endl;
	}
}

void test02()
{
	MyArray<Person>pArr(10);

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	pArr.push_back(p1);
	pArr.push_back(p2);
	pArr.push_back(p3);
	pArr.push_back(p4);
	pArr.push_back(p5);

	printPersonArr(pArr);

	cout << "������ " << pArr.getCapacity() << endl;
	cout << "��С�� " << pArr.getSize() << endl;
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}