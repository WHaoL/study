#ifndef PRINTFCNS_H
#define PRINTFCNS_H
#include <vector>
void print(const char *cp);
void print(const int *beg, const int *end); 
void print(std::vector<int>::const_iterator beg,
           std::vector<int>::const_iterator end);
void print(const int ia[], size_t size);
void print(const std::vector<int>&);

inline foo() 
{
	int j[2] = {0,1};
	print("Hello World");        // calls print(const char*)
	print(j, end(j) - begin(j)); // calls print(const int*, size_t)
	print(begin(j), end(j));     // calls print(const int*, const int*)
}
#endif
