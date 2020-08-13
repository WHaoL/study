#include <iostream>

// using declarations for names from the standard library
using std::cin;
using std::cout; 
using std::endl;

int main()
{
    //以“只读访问”方式，将标准输入重定向到 “./data/add 文件
    freopen("./data/add", "r", stdin);
	
	cout << "Enter two numbers:" << endl;

	int v1, v2;
	cin >> v1 >> v2;

	cout << "The sum of " << v1 << " and " << v2
	     << " is " << v1 + v2 << endl;

	return 0;
}
