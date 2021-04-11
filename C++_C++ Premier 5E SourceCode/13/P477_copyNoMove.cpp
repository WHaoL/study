#include "Version_test.h"

#include <utility>
#include <iostream>

class Foo 
{
public:
#ifdef DEFAULT_FCNS
	Foo() = default; // default constructor needed because Foo has a copy constructor
#else
	Foo() { }  // nothing for the default constructor to do, but must be defined
#endif
	Foo(const Foo&);  // copy constructor
	// other members, but Foo does not define a move constructor
};

Foo::Foo(const Foo&) 
{ 
	std::cout << "Foo copy ctor" << std::endl; 
}

int main()
{
	Foo x;
	Foo y(x);            // copy constructor; x is an lvalue
	Foo z(std::move(x)); // copy constructor, because there is no move constructor

	return 0;
}
