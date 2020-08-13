#include "Version_test.h"

#include <vector>
using std::vector;

#include <iostream>
using std::cout; 
using std::endl; 

#ifndef LIST_INIT
#include <iterator>
using std::begin; 
using std::end;
#endif

int main()
{
#ifdef LIST_INIT
	vector<int> v{1,2,3,4,5,6,7,8,9};
#else
	// P97
	int temp[] = {1,2,3,4,5,6,7,8,9};
	vector<int> v(begin(temp), end(temp));
#endif
	// P92
	for (auto &i : v) // for each element in v (note: i is a reference)
		i *= i;           // square the element value
	for (auto i : v)      // for each element in v
		cout << i << " "; // print the element
	cout << endl;

	return 0;
}

