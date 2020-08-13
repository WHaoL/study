#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	freopen("./data/grades", "r", stdin);//以“只读访问”方式，将标准输入重定向到 “./data/grades 文件

	// P92
	// hold the grades we read from the standard input
	vector<unsigned> grades;

	// count the number of grades by clusters of ten: 
	// 0--9, 10--19, . ..  90--99, 100
	vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
	unsigned grade;
	while (cin >> grade) {      // read the grades
		if (grade <= 100)       // handle only valid grades
			grades.push_back(grade);
			++scores[grade/10]; // increment the counter for the current cluster
	}
	cout << "grades.size = " << grades.size() << endl;
	for (auto it : grades)
		cout << it << " " ;
	cout << endl;

	cout << "scores.size = " << scores.size() << endl;
	for (auto it : scores)
		cout << it << " " ;
	cout << endl;

	// P97
	// equivalent program using iterators instead of subscripts
	vector<unsigned> alt_scores(11, 0);  // 11 buckets, all initially 0
	// for each grade in the input
	for (auto it = grades.begin(); it != grades.end(); ++it) {
		unsigned i = *it;
		// increment the counter for the current cluster
		++(*(alt_scores.begin() + i/10));
	}

	cout << "alt_scores.size = " << alt_scores.size() << endl;
	for (auto it = alt_scores.begin(); it != alt_scores.end(); ++it) 
		cout << *it << " " ;
	cout << endl;

}

