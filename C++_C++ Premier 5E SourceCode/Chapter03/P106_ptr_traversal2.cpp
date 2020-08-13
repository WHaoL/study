 

#include <iterator>
using std::begin; using std::end;

#include <cstddef>
using std::size_t; 

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	freopen("./data/ptr_traversal2", "r", stdin);//以“只读访问”方式，将标准输入重定向到 “./data/ptr_traversal2 文件
	
	int ia[] = {0,1,2,3,4,5,6,7,8,9};

	int *p = ia; // p points to the first element in ia
	++p;           // p points to ia[1]

	int *e = &ia[10]; // pointer just past the last element in ia
	for (int *b = ia; b != e; ++b)
		cout << *b << " "; // print the elements in ia
	cout << endl;

	const size_t sz = 10;
	int arr[sz];  // array of 10 ints

	for (auto &n : arr) // for each element in arr
		cin >> n;  // read values from the standard input

	for (auto i : arr)
		cout << i << " ";
	cout << endl;

	// pbeg points to the first and 
	// pend points just past the last element in arr
	int *pbeg = begin(arr),  *pend = end(arr);

	// find the first negative element, 
	// stopping if we've seen all the elements
	while (pbeg != pend && *pbeg >= 0)
		++pbeg;
	if (pbeg == pend)
		cout << "no negative elements in arr" << endl;
	else
		cout << "first negative number was " << *pbeg << endl;
	return 0;
}

