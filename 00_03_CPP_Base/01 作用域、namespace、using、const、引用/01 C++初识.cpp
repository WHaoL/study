#include <iostream> //iostream  相当于C语言中的stdio.h  i  input 输入  o output 输出
using namespace std; //使用标准命名空间  理解为 打开一个房间，这个房间中有我们所需要的东西

#include <math.h> // C头文件风格
#include <cmath>  //C++头文件风格
#include <time.h>
#include <ctime>

//程序入口
int main()
{
	//cout 输出流对象 可以利用这个对象 向屏幕中输出内容
	//<< 用cout输出时候，后面需要拼接<<运算符  在C++中有了其他用法
	//C++输出不需要记住格式化符号  %d  %s  %f %c %lf %hd
	//endl  --- end line  刷新缓冲区 并且换行 
	//\n  \r\n    endl 统一换行
	cout << "hello world" <<  endl;


	system("pause"); //阻塞 
	return EXIT_SUCCESS;  //返回正常退出值
}
