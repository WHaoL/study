

#include <iostream> 
using std::cin; using std::cout; using std::endl;

#include <string> 
using std::string;

int main() 
{
	//以“只读访问”方式，将标准输入重定向到 “./data/word_echo 文件
    freopen("./data/word_echo", "r", stdin);	
	
	string word;
	while (cin >> word)       // read until end-of-file 
		cout << word << endl; // write each word followed by a new line
	return 0;
}
