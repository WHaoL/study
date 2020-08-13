#include "Version_test.h"

#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#ifndef LIST_INIT
#include <iterator>
using std::begin; using std::end;
#endif

int main()
{
	vector<int> ivec;
#ifdef LIST_INIT
	vector<int> v = {0,1,2,3,4,5,6,7,8,9};
#else
	int temp[] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> v(begin(temp), end(temp));
#endif

	// range variable must be a reference so we can write to the elements
	for (auto &r : v)   // for each element in v
		r *= 2;         // double the value of each element in v
	
	// print every element in v
	for (int r : v)
		cout << r << " "; // print the elements in v
	cout << endl;

	return 0;
}
