#include <stdexcept>
using std::runtime_error;

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include "Sales_item.h"

int main() 
{
	freopen("./data/add_item_data", "r", stdin);//以“只读访问”方式，将标准输入重定向到 “./data/add_item_data 文件
	
	Sales_item item1, item2;
	
	while (cin >> item1 >> item2) 
	{
	    try {
	        // execute code that will add the two Sales_items
	        // if the addition fails, the code throws a runtime_error exception
	        // first check that the data are for the same item 
	        if (item1.isbn() != item2.isbn())
	            throw runtime_error("Data must refer to same ISBN");
	
	        // if we're still here, the ISBNs are the same
	        cout << item1 + item2 << endl;
	    } catch (runtime_error err) {
	        // remind the user that the ISBNs must match 
			// and prompt for another pair
	        cout << err.what() 
	             << "\nTry Again?  Enter y or n" << endl;
	        char c;
	        cin >> c;
	        if (!cin || c == 'n')
	            break;      // break out of the while loop
	    }  // ends the catch clause
	}  // ends the while loop
	
	return 0;   // indicate success
}
