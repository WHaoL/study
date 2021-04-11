#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::ostream; using std::cin; using std::cout; using std::endl;

#include <memory>
using std::shared_ptr;

int main() {
	shared_ptr<string> p(new string("Hello!"));
	shared_ptr<string> p2(p);    // two users of the allocated string
	string newVal;
	if (!p.unique())
		p.reset(new string(*p)); // we aren't alone; allocate a new copy
	*p += newVal; // now that we know we're the only pointer, okay to change this object 
	cout << *p << " " << *p2 << endl;
}
