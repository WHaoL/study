#include "Sales_data.h"
#include <iostream>

using std::cerr; using std::cin; using std::cout; using std::endl;

int main()
{
	freopen("./data/add_item", "r", stdin);//以“只读访问”方式，将标准输入重定向到 “./data/add_item 文件
	
	Sales_data data1, data2;
	read(cin, data1);                       // read the transactions
	read(cin, data2);                      
	// code to add into data1 and data2 unchanged from chapter 7
	if (data1.isbn() == data2.isbn())       // check isbns
	{     
		Sales_data sum = add(data1, data2); // add the transactions
		print(cout, sum);                   // print the results
		cout << endl;                       // followed by a newline 
	}

	return 0;
}
