//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <fstream>
#include <string>

// out ：把程序中的数据，写入到磁盘文件
// in  ：把文件中的数据，读取到程序

//------------------------------把程序中的数据写入到磁盘--------------------------------//
void test01()
{
	//设置打开方式 利用位或可以设置多个方式
	// ios::out 写数据到文件
	// ios::trunc 打开并清空一个文件、或者、创建一个文件

	ofstream ofs;

	ofs.open("./testSourceFile.txt", ios::out | ios::trunc);

	// bool std::ofstream::is_open()
	// 说明：
	// 		检查文件流是否有关联文件。
	// 返回值
	// 		若文件流有关联文件，则为 true ，(证明成功打开了文件)
	//      否则为 false 。 (证明当前对象没有成功打开文件)
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

//------------------------------从磁盘读数据到程序中--------------------------------//

void test021()
{
	ifstream ifs;
	ifs.open("./testSourceFile.txt", ios::in);

	ofstream ofs;
	ofs.open("./testTargetFile021.txt", ios::out | ios::trunc);

	if ((!ifs.is_open()) || (!ofs.is_open()))
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//第一种读取写入方式
	// ifs.eof()
	//		返回true时，证明指针在文件尾(文件读取完毕)
	//      返回false时，证明指针没在文件尾(文件没有读取完毕)
	while (!ifs.eof())
	{
		char buf[1024] = {0};
		ifs.getline(buf, 1024); //读出
		//ofs << buf ;		//写入
		ofs << buf << endl; //写入（最后一行会多写入一个回车）
	}

	//关闭文件流对象
	ifs.close();
	ofs.close();
}
//------------------------------从磁盘读数据到程序中--------------------------------//
void test022()
{
	ifstream ifs;
	ifs.open("./testSourceFile.txt", ios::in);

	ofstream ofs;
	ofs.open("./testTargetFile022.txt", ios::out | ios::trunc);

	if ((!ifs.is_open()) || (!ofs.is_open()))
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//第二种读取写入方式 按字符读取写入
	char c;
	while ((c = ifs.get()) != EOF)
	{
		ofs << c; //最后一行不会多写入一个回车，完美！
	}

	//关闭文件流对象
	ifs.close();
	ofs.close();
}
//------------------------------从磁盘读数据到程序中--------------------------------//
// 粗略
void test02()
{
	ifstream ifs;
	ifs.open("./testSourceFile.txt", ios::in);

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
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}

	//关闭文件流对象
	ifs.close();
}

int main()
{

	test01();

	test021();
	test022();

	//system("pause");
	return EXIT_SUCCESS;
}