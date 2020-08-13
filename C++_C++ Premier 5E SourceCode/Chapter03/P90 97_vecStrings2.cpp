#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <vector>
using std::vector; 

#include <string>
using std::string;

int main()
{
	vector<string> text;     // holds the input

	string s;
	while (getline(cin, s))  // read the entire input file
		text.push_back(s);   // storing each line as an element in text
	cout << "text.size: " << text.size() << endl;

	// print each line in text up to the first blank line
	for (auto it = text.cbegin(); 
	     it != text.cend() && !(*it).empty(); ++it) 
		cout << *it << endl;

	// equivalent loop using arrow to dereference it and call empty
	for (auto it = text.cbegin(); 
	     it != text.cend() && !it->empty(); ++it) 
		cout << *it << endl;
}
		
