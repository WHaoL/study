#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    //以“只读访问”方式，将标准输入重定向到 “./data/string_io 文件
    freopen("./data/string_io", "r", stdin);
	
    string s;          // empty string
    cin >> s;          // read a whitespace-separated string into s
    cout << s << endl; // write s to the output
    return 0;
}
