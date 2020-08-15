#include "LocalMath.h"
#include <iostream>
using std::cout; using std::endl;

int main()
{
	freopen("./data/mainmath", "r", stdin);//以“只读访问”方式，将标准输入重定向到 “./data/mainmath 文件
	
	// P182
	// pass a literal to fact
    int f = fact(5);  // f equals 120, i.e., the result of fact(5)
	cout << "5! is " << f << endl;

    // call fact on i and print the result*
	int i = 5;
    int j = fact(i);
	cout << i << "! is " << j << endl;

	// call fact on a const int
    const int ci = 3;
    int k = fact(ci);   
	cout << ci << "! is " << k << endl;

    return 0;
}

