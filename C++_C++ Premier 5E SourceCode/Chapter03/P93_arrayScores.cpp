#include <cstddef>
using std::size_t;

#include <vector>
using std::vector;

#include <iostream>
using std::cin; using std::cout; using std::endl;


int main()
{
	freopen("./data/grades", "r", stdin);//以“只读访问”方式，将标准输入重定向到 “./data/grades 文件

	vector<unsigned> grades;
	// count the number of grades by clusters of ten:
	// 0--9, 10--19, . . . 90--99, 100
	vector<unsigned> scores(11,0);// 11 buckets, all value initialized to 0
	unsigned grade;
	while (cin >> grade)
	{
		if (grade <= 100)
			// increment the counter for the current cluster
			++scores[grade/10];
		grades.push_back(grade);
	}
	cout << "grades.size = " << grades.size() << endl;

	for (auto g : grades)  // for every element in grades
		cout << g << " ";
	cout << endl;

	for (auto i : scores)       // for each counter in scores
		cout << i << " ";       // print the value of that counter
	cout << endl;
}