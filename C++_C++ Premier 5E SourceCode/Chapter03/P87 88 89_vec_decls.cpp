

#include "Version_test.h"

#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Sales_item.h"

#ifndef LIST_INIT
#include <iterator>
using std::begin; using std::end;
#endif

int main()
{
#ifdef LIST_INIT
	// list initialization, articles has 3 elements
	vector<string> articles = {"a", "an", "the"};
#else
	string temp[] = {"a", "an", "the"};
	vector<string> articles(begin(temp), end(temp));
#endif

	vector<string> svec; // default initialization; svec has no elements
	vector<int> ivec;             // ivec holds objects of type int
	vector<Sales_item> Sales_vec; // holds Sales_items
	
	vector<vector<string>> file;  // vector whose elements are vectors
	vector<vector<int>> vecOfvec; // each element is itself a vector
	
	// all five vectors have size 0
	cout << svec.size() << " " << ivec.size() << " "
	     << Sales_vec.size() << " "
	     << file.size() << " " << vecOfvec.size() << endl;
	
	vector<int> ivec2(10);     // ten elements, each initialized to 0
	vector<int> ivec3(10, -1); // ten int elements, each initialized to -1
	vector<string> svec2(10);  // ten elements, each an empty string
	vector<string> svec3(10, "hi!"); // ten strings; each element is "hi!"
	cout << ivec2.size() << " " << ivec3.size() << " "
	     << svec2.size() << " " << svec3.size() << endl;
	
	// 10 is not a string, so cannot be list initialization
	vector<string> v1(10); // construct v1 with ten value-initialized elements
#ifdef LIST_INIT
	vector<string> v2{10}; // ten elements value-initialized elements
#else
	vector<string> v2(10); 
#endif
	vector<string> v3(10, "hi");  // ten elements with value "hi"
#ifdef LIST_INIT
	// again list initialization is not viable, so ordinary construction
	vector<string> v4{10, "hi"};  // ten elements with values "hi"
#else
	vector<string> v4(10, "hi");  // ten elements with values "hi"
#endif
	
	// all four vectors have size ten
	cout << v1.size() << " " << v2.size() 
	     << " " << v3.size() << " " << v4.size() << endl;
	
#ifdef LIST_INIT
	vector<string> vs1{"hi"}; // list initialization: vs1 has 1 element 
	vector<string> vs2{10};   // ten default-initialized elements
	vector<string> vs3{10, "hi"}; // has ten elements with value "hi"
#else
	vector<string> vs1;
	vs1.push_back("hi"); // explicitly add the element; vs1 has 1 element 
	vector<string> vs2(10); // don't use curlies; 
	                        // vs2 has ten default-initialized elements
	vector<string> vs3(10, "hi"); // don't use curlies; 
	                              // vs3 has ten elements with value "hi"
#endif
	cout << vs1.size() << " " << vs2.size() << " " << vs3.size() << endl;
	
	vector<int> v5(10, 1);  // ten elements with value 1
#ifdef LIST_INIT
	vector<int> v6{10, 1};  // two elements with values 10 and 1
#else
	vector<int> v6;
	v6.push_back(10);
	v6.push_back(1);
#endif
	cout << v5.size() << " " << v6.size() << endl;
	
#ifdef LIST_INIT
	// intention is clearer
	vector<int> alt_v3 = {10};    // one element with value 10
	vector<int> alt_v4 = {10, 1}; // two elements with values 10 and 1
#else
	vector<int> alt_v3;
	alt_v3.push_back(10);    // one element with value 10

	vector<int> alt_v4;
	alt_v4.push_back(10); 
	alt_v4.push_back(1); // two elements with values 10 and 1
#endif
	cout << alt_v3.size() << " " << alt_v4.size() << endl;

	return 0;
}
