#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "myString.h"

void test01()
{
	MyString str1 = "abc";

	MyString str2 = str1;

	cout << "str1 = " << str1 << endl;

	cout << "str2 = " << str2 << endl;

	cout << "�����¸�str1��ֵ" << endl;

	cin >> str1;

	cout << "str1�µ�ֵΪ�� " << str1 << endl;
}

void test02()
{
	MyString str1 = "abc";

	cout << "��һ���ַ�Ϊ�� "<<  str1[0] << endl;

	str1[0] = 'z';

	cout << "str1 = " << str1 << endl; //zbc

	MyString str2 = "aaa";
	str2 = str1; //��ֵ

	cout << "str2 = " << str2 << endl; //zbc

	MyString str3 = "abc";
	MyString str4 = "def";
	MyString str5 = str3 + str4;
	cout << "str5 = " << str5 << endl;

	MyString str6 = str5 + "ghi";
	cout << "str6 = " << str6 << endl;

	if (str5==str6)
	{
		cout << "str5 == str6" << endl;
	}
	else
	{
		cout << "str5 != str6" << endl;
	}
	
	if (str5 == "abcdef")
	{
		cout << "str5 == abcdef" << endl;
	}
	else
	{
		cout << "str5 != abcdef" << endl;
	}

	//��ϰ�� ���� +=  �ַ���׷��
	//Mystring str1 = "abc" ;  str1 += "def"
}

int main(){

	test02();

	//char buf[1024];
	//cin >> buf;
	//cout << buf << endl;

	//int a = 0;
	//int b = 0;
	//cin >> a >> b;
	//cout << "a: " << a << endl;
	//cout << "b: " << b << endl;

	system("pause");
	return EXIT_SUCCESS;
}