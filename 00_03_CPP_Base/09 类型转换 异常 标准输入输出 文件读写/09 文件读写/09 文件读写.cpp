#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <fstream>
#include <string>


void test01()
{
	//写文件
	//ofstream ofs("./test.txt", ios::out | ios::trunc); //设置打开方式 利用位或可以设置多个方式

	ofstream ofs;
	ofs.open("./test.txt", ios::out | ios::trunc);

	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	ofs << "姓名：Tom" << endl;
	ofs << "年龄：18" << endl;
	ofs << "性别：男" << endl;

	//关闭对象
	ofs.close();
}

void test02()
{
	//读文件

	ifstream ifs;
	ifs.open("./test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
	}

	//第一种读取方式
	//char buf[1024] = { 0 };

	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}


	//第二种方式
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}
	//第三种方式
	//string buf;
	//while (getline(ifs,buf))
	//{
	//	cout << buf << endl;
	//}

	//第四种方式 按字符读
	char c;
	while ( (c = ifs.get()) !=EOF)
	{
		cout << c;
	}

	//关闭文件
	ifs.close();

}

int main(){

	//test01();

	test02();

	system("pause");
	return EXIT_SUCCESS;
}