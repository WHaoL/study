#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
    //以“只读访问”方式，将标准输入重定向到 “./data/string_io 文件
    freopen("./data/string_io", "r", stdin);
	
	string s1, s2;

	cin >> s1 >> s2; // read first input into s1, second into s2
	cout << s1 << s2 << endl; // write both strings

	return 0;
}
