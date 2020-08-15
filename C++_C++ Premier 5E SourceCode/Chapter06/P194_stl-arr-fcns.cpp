#include <iostream>
using std::endl; using std::cout;

#include <iterator>
using std::begin; using std::end;

// prints a null-terminated array of characters
void print(const char *cp)
{
	if (cp)          // if cp is not a null pointer
		while (*cp)  // so long as the character it points to is not a null character
			cout << *cp++;  // print the character and advance the pointer
}

// print ints in the given range
void print(const int *beg, const int *end) 
{
	// print every element starting at beg up to but not including end
    while (beg != end) 
        cout << *beg++ << " "; // print the current element 
		                       // and advance the pointer
}

int main() 
{
	print("hi world!"); // calls first version of print
	cout << endl;

    // j is converted to a pointer to the first element in j
    // the second argument is a pointer to one past the end of j
    int j[2] = {0, 1};  
    print(begin(j), end(j));  // library begin and end functions
	cout << endl;

	// equivalent call, directly calculate the begin and end pointers
	print(j, j + 2); 
	cout << endl;

    return 0;
}
