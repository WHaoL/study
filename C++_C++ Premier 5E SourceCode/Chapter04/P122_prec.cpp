#include <iostream>
using std::cout; using std::endl;

int main() 
{
	cout << 6 + 3 * 4 / 2 + 2 << endl;

	// parentheses in this expression match default precedence and associativity
	cout << ((6 + ((3 * 4) / 2)) + 2) << endl; // prints 14

	int temp = 3 * 4;         // 12
	int temp2 = temp / 2;     // 6
	int temp3 = temp2 + 6;    // 12
	int result = temp3 + 2;   // 14
	cout << result << endl;

	// parentheses result in alternative groupings
	cout << (6 + 3) * (4 / 2 + 2) << endl;     // prints 36
	cout << ((6 + 3) * 4) / 2 + 2 << endl;     // prints 20
	cout << 6 + 3 * 4 / (2 + 2) << endl;       // prints 9

    return 0;
}
