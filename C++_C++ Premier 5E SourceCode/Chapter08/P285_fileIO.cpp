#include <iostream>
using std::cerr; using std::cout; using std::endl;

#include <fstream>
using std::ifstream; 

#include <string>
using std::string;

#include <stdexcept>
using std::runtime_error;

void process(ifstream &is)
{
	string s;
	while (is >> s)
		cout << s << endl;
}

int main(int argc, char* argv[])
{
	// Note: fileio reads both add_item and sstream
	
	freopen("./data/add_item", "r", stdin);//以“只读访问”方式，将标准输入重定向到 “./data/add_item 文件
	
	freopen("./data/sstream", "r", stdin);//以“只读访问”方式，将标准输入重定向到 “./data/sstream 文件
	
	
	// for each file passed to the program
	for (auto p = argv + 1; p != argv + argc; ++p) 
	{
	    ifstream input(*p);   // create input and open the file
	    if (input) {          // if the file is ok, ``process'' this file
	        process(input);
		} else
	        cerr << "couldn't open: " + string(*p);
	} // input goes out of scope and is destroyed on each iteration
	
	auto p = argv + 1, end = argv + argc;
	
	ifstream input;           
	while (p != end)          // for each file passed to the program
	{        
		input.open(*p);       // open the file, automatically clears the stream 
	    if (input) {          // if the file is ok, read and ``process'' the input
	        	process(input);
		} else
			cerr << "couldn't open: " + string(*p);
	    input.close();        // close file when we're done with it
	    ++p;                  // increment pointer to get next file
	}
}
