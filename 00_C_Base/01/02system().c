#include <stdio.h>

/*
常用快捷键

启动调试  f5
开始执行不调试 ctrl + f5 不建议用

格式化代码  ctrl + k + f   
注释代码  ctrl + k + c
取消注释  ctrl + k + u
*/


//利用新的测试函数 演示system函数使用
//测试函数不会默认执行，因为程序的入口函数是  main
//如果想调用这个函数 需要在main中去调用
void test01()
{
	//system("mspaint"); //画图工具打开
	//system("calc");//计算器
	//system("ping www.baidu.com"); //ping百度网址
	//system("pause");//让程序进入阻塞阶段  请按任意键继续
	printf("hello\n");
	printf("hello\n");
	printf("hello\n");
}


int main()
{

	printf("hello world\n");
	printf("hello world\n");

	test01(); //调用test01 这个函数
	
	printf("hello world\n");

	system("pause"); //让程序阻塞到退出窗口前，不让窗口一闪而过
	return 0;
}