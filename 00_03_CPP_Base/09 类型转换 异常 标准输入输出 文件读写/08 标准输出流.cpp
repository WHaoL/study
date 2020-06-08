#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <iomanip>  //控制符的头文件

/*
cout.put() //向缓冲区写字符
cout.write() //从buffer中写num个字节到当前输出流中。
*/

void test01()
{
	//cout.put('h').put('e').put('l');

	//char buf[] = "hello world";

	//cout.write(buf, strlen(buf));

	cout << "hello world" << endl;
}

//1通过流成员函数
void test02(){

	int number = 99;
	cout.width(5);  //设置宽度
	cout.fill('*');  //填充
	cout.setf(ios::left);  //左对齐
	cout.unsetf(ios::dec); //卸载十进制
	cout.setf(ios::hex); //设置十六进制
	cout.setf(ios::showbase);  //显示基数
	cout.unsetf(ios::hex);
	cout.setf(ios::oct);  //设置八进制
	cout << number << endl;
}

//2 通过控制符
void test03(){

	int number = 99;
	cout << setw(20)  //设置宽度
		 << setfill('~')  //设置填充
		 << setiosflags(ios::showbase)  //显示基数
		 << setiosflags(ios::left) //设置左对齐
		 << hex   //十六进制
		 << number
		 << endl;

}



int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}