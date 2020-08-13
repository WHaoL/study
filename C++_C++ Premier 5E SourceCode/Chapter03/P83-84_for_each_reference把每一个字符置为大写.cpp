#include <string> 
using std::string;
using std::getline;

#include <iostream> 
using std::cin;
using std::cout;
using std::endl;

int main()
{
	freopen("./data/word_echo", "r", stdin);//以“只读访问”方式，将标准输入重定向到 “./data/word_echo 文件
	
	string line;

	// read input a line atm until end-of-file
	while (getline(cin, line))
	{
		if(!line.empty())
		{
			for(auto &c : line)
	   		{
				c=toupper(c);
		 	 } 
		}
		cout << line << endl;
	}
	return 0;
}
