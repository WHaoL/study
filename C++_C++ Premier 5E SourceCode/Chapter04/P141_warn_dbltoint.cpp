#include <iostream>
using std::cout; using std::endl;

int main()
{
	// the compiler might warn about loss of precision
	int ival = 3.541 + 3; // the compiler might warn about loss of precision
	cout << ival << endl;  // prints 6

	return 0;
}
