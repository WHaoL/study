#include "Version_test.h"

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout; using std::endl;

// code to illustrate declarations of array-related types
int arr[10];          // arr is an array of ten ints
int *p1[10];          // p1 is an array of ten pointers
int (*p2)[10] = &arr; // p2 points to an array of ten ints

#ifdef TYPE_ALIAS_DECLS
using arrtT = int[10]; // arrT is a synonym for the type array of ten ints
#else
typedef int arrT[10];  // arrT is a synonym for the type array of ten ints
#endif

// three ways to declare function returning pointer to array of ten ints
arrT* func(int i);               // use a type alias
auto func(int i) -> int(*)[10];  // use a trailing return type
int (*func(int i))[10];          // direct declaration

auto func2(int i) -> int(&)[10]; // func2 returns a refernce to an array

// two arrays
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

// function that returns a pointer to an int in one of these arrays
int *elemPtr(int i)
{
	// returns a pointer to the first element in one of these arrays
	return (i % 2) ? odd : even;  
}
	
// returns a pointer to an array of five int elements
decltype(odd) *arrPtr(int i)
{
	return (i % 2) ? &odd : &even; // returns a pointer to the array 
}

// returns a reference to an array of five int elements
int (&arrRef(int i))[5]
{
	return (i % 2) ? odd : even;
}

int main()
{
	int *p = elemPtr(6);         // p points to an int
	int (*arrP)[5] = arrPtr(5);  // arrP points to an array of five ints
	int (&arrR)[5] = arrRef(4);  // arrR refers to an array of five ints

	for (size_t i = 0; i < 5; ++i)
		// p points to an element in an array, which we subscript
		cout << p[i] << endl;  

	for (size_t i = 0; i < 5; ++i)
		// arrP points to an array, 
		// we must dereference the pointer to get the array itself
		cout << (*arrP)[i] << endl;

	for (size_t i = 0; i < 5; ++i)
		// arrR refers to an array, which we can subscript
		cout << arrR[i] << endl;

	return 0;
}
