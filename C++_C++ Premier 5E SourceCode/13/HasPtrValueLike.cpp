#include <string>

// value-like implementation of HasPtr
class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string &s = std::string()): 
		ps(new std::string(s)), i(0) { }

	// each HasPtr  has its own copy of the string to which ps points
    HasPtr(const HasPtr &p): 
		ps(new std::string(*p.ps)), i(p.i) { }

	HasPtr& operator=(const HasPtr &);

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

using std::string;
HasPtr& HasPtr::operator=(const HasPtr &rhs) 
{
	auto newp = new string(*rhs.ps);  // copy the underlying string
	delete ps;       // free the old memory
	ps = newp;       // copy data from rhs into this object
	i = rhs.i;
	return *this;    // return this object
}

HasPtr f(HasPtr hp)  // HasPtr passed by value, so it is copied
{
	HasPtr ret = hp; // copies the given HasPtr
	// process ret
	return ret;      // ret and hp are destroyed
}

int main()
{ 
	HasPtr h("hi mom!");  // allocates a new copy of "hi mom!"
	f(h);  // copy constructor copies h in the call to f
		   // that copy is destroyed when f exits
}  // h is destroyed on exit, which destroys its allocated memory
