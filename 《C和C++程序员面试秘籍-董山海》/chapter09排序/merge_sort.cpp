#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

// this is a sort function
void merge_sort(vector<int> &li)
{
	int len = li.size();
	if (len <= 1) //分到只含有一个元素
	{
		return;
	}

	vector<int> left(li.begin(), li.begin() + len / 2); //左半段
	vector<int> right(li.begin() + len / 2, li.end());	//右半段

	merge_sort(left);  //左半段 已经有序
	merge_sort(right); //右半段 已经有序

	li.clear();

	//合并左右 到 vector<int> &li 中
	int lindex = 0;
	int rindex = 0;
	while (lindex < left.size() && rindex < right.size())
	{
		if (left[lindex] <= right[rindex])
		{
			li.push_back(left[lindex]);
			lindex++;
		}
		else
		{
			li.push_back(right[rindex]);
			rindex++;
		}
	}

	li.insert(li.end(), left.begin() + lindex, left.end());
	li.insert(li.end(), right.begin() + rindex, right.end());
	//此时li是合并后的有序的...
}

int main()
{
	srand(time(NULL));

	vector<int> li;
	for (int i = 0; i < 16; i++)
	{
		int a = rand() % 50;
		li.push_back(a);
		cout << a << " ";
	}

	cout << endl;

	merge_sort(li);
	for (auto itr : li)
	{
		cout << itr << " ";
	}
	cout << endl;
}