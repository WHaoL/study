#include "Version_test.h"

#include <iostream>
#include <string>
#include <utility>
// for swap but we do not provide a using declaration for swap

// HasPtr with added move constructor
class HasPtr 
{
	friend void swap(HasPtr&, HasPtr&);
public:
	// default constructor and constructor that takes a string
    HasPtr(const std::string &s = std::string()): 
		ps(new std::string(s)), i(0) { }

	// copy constructor
    HasPtr(const HasPtr &p): 
		ps(new std::string(*p.ps)), i(p.i) { }

#ifdef NOEXCEPT
	// move constructor
	HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {p.ps = 0;}
#else
	HasPtr(HasPtr &&p) throw() : ps(p.ps), i(p.i) {p.ps = 0;}
#endif

	// assignment operator is both the move- and copy-assignment operator
	HasPtr& operator=(HasPtr rhs) 
	               { swap(*this, rhs); return *this; }

	// destructor
	~HasPtr() { delete ps; }
private:
    std::string *ps;
    int    i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
	swap(lhs.i, rhs.i);   // swap the int members
}

int main()
{
	HasPtr hp("hi mom");
	HasPtr hp2(hp);
	
	hp = hp2; // hp2 is an lvalue; copy constructor used to copy hp2 
	hp = std::move(hp2); // move constructor moves hp2
}
