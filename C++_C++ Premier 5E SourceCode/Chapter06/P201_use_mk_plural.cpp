#include <cstddef>
using std::size_t;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

// return the plural version of word if ctr is greater than 1
string make_plural(size_t ctr, const string &word, 
                               const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

int main()
{
	size_t cnt = 1;
	cout << make_plural(cnt, "success", "es") << endl;
	cnt = 2;
	cout << make_plural(cnt, "failure", "s") << endl;

	return 0;
}
