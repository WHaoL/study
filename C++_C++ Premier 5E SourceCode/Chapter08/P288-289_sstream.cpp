#include <iostream>
using std::cin; 
using std::cout; 
using std::cerr;
using std::istream; 
using std::ostream; 
using std::endl;

#include <sstream>
using std::ostringstream; 
using std::istringstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

// members are public by default
struct PersonInfo 
{ 
	string name;
	vector<string> phones;
};

// we'll see how to reformat phone numbers in chapter 17
// for now just return the string we're given
string format(const string &s) { return s; }

bool valid(const string &s)
{
	// we'll see how to validate phone numbers 
	// in chapter 17, for now just return true
	return true;
}

//P288
vector<PersonInfo>
getData(istream &is)
{
	// will hold a line and word from input, respectively
	string line, word;

	// will hold all the records from the input
	vector<PersonInfo> people;

	// read the input a line at a time until end-of-file (or other error)
	while (getline(is, line)) 
	{       
		PersonInfo info;            // object to hold this record's data
	    istringstream record(line); // bind record to the line we just read
		record >> info.name;        // read the name
	    while (record >> word)      // read the phone numbers 
			info.phones.push_back(word);  // and store them
		people.push_back(info); // append this record to people
	}
	
	return people;
}

ostream& process(ostream &os, vector<PersonInfo> people)
{
	for (const auto &entry : people)      // for each entry in people
	{    
		ostringstream formatted, badNums; // objects created on each loop
		for (const auto &nums : entry.phones) // for each number
		{   
			if (!valid(nums)) 
			{           
				badNums << " " << nums;  // string in badNums
			} 
			else                        
				// ``writes'' to formatted's string
				formatted << " " << format(nums); 
		}
		if (badNums.str().empty())      // there were no bad numbers
			os << entry.name << " "     // print the name 
			   << formatted.str() << endl; // and reformatted numbers 
		else                   // otherwise, print the name and bad numbers
			cerr << "input error: " << entry.name 
			     << " invalid number(s) " << badNums.str() << endl;
	}
	
	return os;
}

int main()
{
	freopen("./data/sstream", "r", stdin);//以“只读访问”方式，将标准输入重定向到 “./data/sstream 文件
	
	process(cout, getData(cin));

	return 0;
}
