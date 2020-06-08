#include "myString.h"


//重载 <<
ostream& operator<<(ostream& cout, MyString&str)
{
	cout << str.pString;
	return cout;
}

//重载 >>
istream& operator>>(istream& cin, MyString&str)
{
	//先判断原来是否有数据，如果有先释放
	if (str.pString!=NULL)
	{
		delete[] str.pString;
		str.pString = NULL;
	}

	char buf[1024] = { 0 };
	cin >> buf;

	str.pString = new char[strlen(buf) + 1];
	strcpy(str.pString, buf);
	str.m_Size = strlen(buf);

	return cin;
}

//有参构造
MyString::MyString(const char * str)
{
	//cout << "有参构造函数调用" << endl;
	this->pString = new char[strlen(str) + 1];
	strcpy(this->pString, str);

	this->m_Size = strlen(str);
}

//拷贝构造
MyString::MyString(const MyString & str)
{
	//cout << "拷贝构造函数调用" << endl;
	this->pString = new char[strlen(str.pString) + 1];
	strcpy(this->pString, str.pString);

	this->m_Size = strlen(str.pString);
}

//重载[]
char& MyString::operator[](int pos)
{
	return this->pString[pos];
}

MyString& MyString::operator=(const char * str)
{
	//先释放干净，再深拷贝
	if (this->pString!=NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}

	this->pString = new char[strlen(str) + 1];
	strcpy(this->pString, str);
	this->m_Size = strlen(str);

	return *this;
}

MyString& MyString::operator=(const MyString& str)
{
	//先释放干净，再深拷贝
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}

	this->pString = new char[strlen(str.pString) + 1];
	strcpy(this->pString, str.pString);
	this->m_Size = strlen(str.pString);

	return *this;
}

MyString MyString::operator+(const char * str)
{
	//假设 自身 abc  传入的是 def

	int newSize = this->m_Size + strlen(str) + 1;

	char * temp = new char[newSize];

	memset(temp, 0, newSize);

	strcat(temp, this->pString);
	strcat(temp, str);

	MyString newString(temp);

	delete [] temp;

	return newString;
}

MyString MyString::operator+(const MyString& str)
{
	int newSize = this->m_Size + strlen(str.pString) + 1;

	char * temp = new char[newSize];

	memset(temp, 0, newSize);

	strcat(temp, this->pString);
	strcat(temp, str.pString);

	MyString newString(temp);

	delete[] temp;

	return newString;
}

bool MyString::operator==(const char * str)
{
	if ( strcmp( this->pString,  str) == 0)
	{
		return true;
	}
	return false;
}

bool MyString::operator==(const MyString& str)
{
	if (strcmp(this->pString, str.pString) == 0)
	{
		return true;
	}
	return false;
}

//析构
MyString::~MyString()
{
	if (this->pString != NULL)
	{
		//cout << "析构函数调用" << endl;
		delete[] this->pString;
		this->pString = NULL;
	}

}
