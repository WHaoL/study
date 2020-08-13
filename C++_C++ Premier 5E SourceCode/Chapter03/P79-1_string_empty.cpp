#include <string> 
using std::string; using std::getline;

#include <iostream> 
using std::cin; using std::cout; using std::endl;

int main() 
{
	//以“只读访问”方式，将标准输入重定向到 “./data/string_io 文件
    freopen("./data/string_io", "r", stdin);
	
	string line;

	// read input a line at a time and discard blank lines
	while (getline(cin, line))
		if (!line.empty())
			cout << line << endl;

	return 0;
}
