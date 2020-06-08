#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyString
{
public:

	explicit MyString(char * str) // MyString str = "abcd";
	{
		
	}

	//加上 explicit  防止用隐式法 创建对象
	explicit MyString(int n)
	{
		m_Size = n;
	}

	char * m_Str;
	int m_Size;

};

void test01()
{

	//MyString str = "abcd";
	MyString str2("abcd");
	MyString str3 = MyString("abcd");


	//MyString str4 = 10; //可能会产生歧义   10是字符串长度    字符串本身 "10"
	MyString str5(10);
	MyString str6 = MyString(10);
}

int main(){



	system("pause");
	return EXIT_SUCCESS;
}