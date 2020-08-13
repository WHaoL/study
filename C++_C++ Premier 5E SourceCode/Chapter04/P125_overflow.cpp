#include <iostream>
using std::cout; using std::endl;

int main() 
{
	short short_value = 32767; // max value if shorts are 16 bits

	short_value += 1; // this calculation overflows
	cout << "short_value: " << short_value << endl;

    return 0;
}
