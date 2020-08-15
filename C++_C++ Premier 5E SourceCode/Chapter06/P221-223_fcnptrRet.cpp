#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

// declarations (not strictly speaking necessary in this file)
string::size_type sumLength(const string&, const string&);
string::size_type largerLength(const string&, const string&);

// definition of these functions
string::size_type sumLength(const string &s1, const string &s2)
{
	return s1.size() + s2.size();
}

string::size_type largerLength(const string &s1, const string &s2)
{
	return (s1.size() > s2.size()) ? s1.size() : s2.size();
}

// depending on the value of its string parameter,
// getFcn returns a pointer to sumLength or to largerLength

// three ways to declare getFcn 
// 1. use decltype for the return type, 
//    remembering to add a * to indicate that getFcn returns a pointer
decltype(sumLength) *getFcn(const string &);

//P206
// use trailing return type
auto getFcn(const string&) -> string::size_type(*)(const string&, const string&);

// direct definition
string::size_type (*getFcn(const string&))(const string&, const string&);

// define getFcn
decltype(sumLength)* 
getFcn(const string &fetch)
{
	if (fetch == "sum")
		return sumLength;
	return largerLength;
}

int main()
{
	// "sum" is the argument to getFcn
	// ("hello", "world!") are arguments to the function getFcn returns
	cout << getFcn("sum")("hello", "world!") << endl;    // prints 11
	cout << getFcn("larger")("hello", "world!") << endl; // prints 6

	return 0;
}
