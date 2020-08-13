#include <iostream>
using std::cout; using std::endl;

int main()
{
	int grade = 75;
	cout << ((grade < 60) ?  "fail" : "pass"); // prints pass or fail
	cout << endl;

	cout << (grade < 60) ?  "fail" : "pass";   // prints 1 or 0!
	cout << endl;

	// previous expression is equivalent to the following
	cout << (grade < 60);    // prints 1 or 0
	cout ?  "fail" : "pass"; // test cout and then yield one of the two literals
	                         // depending on whether cout is true or false
	cout << endl;
	int i = 15, j = 20;
	cout << (i < j ? i : j);  // ok: prints smaller of i and j
	cout << endl;

	cout << (i < j) ? i : j;  // ok: prints 1 or 0!
	cout << endl;
	
	// previous expression is equivalent to the following
	cout << (i < j); // prints 1 or 0
	cout ? i : j;    // test cout and then evaluate i or j
	                 // depending on whether cout evaluates to true or false
	cout << endl;

	return 0;
}
