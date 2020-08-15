#include <cstddef>
using std::size_t;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include "make_plural.h"

int main()
{
	size_t cnt = 1;
	cout << make_plural(cnt, "success", "es") << endl;

	cnt = 2;
	cout << make_plural(cnt, "failure", "s") << endl;

	return 0;
}
