#include <iostream>
using std::cout; using std::endl;

// declarations of our factorial functions
// definitions are in LocalMath.cc
#include "LocalMath.h"

int main()
{
	cout << factorial(5) << endl;
	cout << fact(5) << endl;
	cout << factorial(0) << endl;
	cout << fact(0) << endl;

	return 0;
}

