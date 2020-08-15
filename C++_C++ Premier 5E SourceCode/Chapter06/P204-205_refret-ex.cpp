#include <iostream>
using std::cout; using std::endl;

// get returns a reference to an element in the given array
int &get(int *arry, int index) { return arry[index]; }

int main() 
{
    int ia[10];  // array of ten uninitialized ints

    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;  // call get to assign values to the elements

	for (auto i : ia)    // print the elements
		cout << i << " ";
	cout << endl;

	return 0;
}
