#include <iostream>
using std::cin; 
using std::cout; 
using std::endl;

#include <string>
using std::string;

#include <cstddef>
using std::size_t;

int main()
{
	freopen("./data/hexify", "r", stdin);//以“只读访问”方式，将标准输入重定向到 “./data/hexify 文件
	
	const string hexdigits = "0123456789ABCDEF";  // possible hex digits

	cout << "Enter a series of numbers between 0 and 15"
		<< " separated by spaces.  Hit ENTER when finished: "
		<< endl;
	string result;        // will hold the resulting hexify'd string

	string::size_type n;  // hold numbers from the input
	while (cin >> n)
		if (n < hexdigits.size())    // ignore invalid input
			result += hexdigits[n];  // fetch the indicated hex digit

	cout << "Your hex number is: " << result << endl;

	return 0;
}