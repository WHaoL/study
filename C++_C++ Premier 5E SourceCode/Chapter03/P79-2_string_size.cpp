#include <cstddef>
using std::size_t;

#include <string> 
using std::string; using std::getline;

#include <iostream> 
using std::cin; using std::cout; using std::endl;

int main()
{
	//以“只读访问”方式，将标准输入重定向到 “./data/word_echo 文件
    freopen("./data/word_echo", "r", stdin);	string line;
	
    string line;

    // read input a line at a time and print lines that are longer than 80 characters
    while (getline(cin, line))
        if (line.size() > 80)
            cout << line << endl;

    return 0;
}
