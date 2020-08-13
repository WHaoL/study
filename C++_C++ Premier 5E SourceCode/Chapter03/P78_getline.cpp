#include <string> 
using std::string; 
using std::getline;

#include <iostream> 
using std::cin; 
using std::cout; 
using std::endl;

int main() 
{
    //以“只读访问”方式，将标准输入重定向到 “./data/word_echo 文件
    freopen("./data/word_echo", "r", stdin);
	
	string line;

	// read input a line at a time until end-of-file
	while (getline(cin, line))
		cout << line << endl;

	return 0;
}
