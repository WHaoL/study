#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyString
{
public:

	explicit MyString(char * str) // MyString str = "abcd";
	{
		
	}

	//���� explicit  ��ֹ����ʽ�� ��������
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


	//MyString str4 = 10; //���ܻ��������   10���ַ�������    �ַ������� "10"
	MyString str5(10);
	MyString str6 = MyString(10);
}

int main(){



	system("pause");
	return EXIT_SUCCESS;
}