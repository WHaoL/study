//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
/*
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
merge算法 把两个容器中的元素合并，并存储到另一容器中
注意:两个容器必须是有序的 ,而且必须同序
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
*/

void test01()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	vector<int> vTarget; //目标容器
	vTarget.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	// [](){} 匿名函数  lambda表达式
	for_each(vTarget.begin(), vTarget.end(), [](int val) { cout << val << " "; });

	cout << endl;
}

/*
sort(iterator beg, iterator end, _callback
sort算法 容器元素排序
@param beg 容器1开始迭代器
@param end 容器1结束迭代器
@param _callback 回调函数或者谓词(返回bool类型的函数对象)
*/
void test02()
{
	vector<int> v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//利用sort降序
	sort(v1.begin(), v1.end(), greater<int>());

	for_each(v1.begin(), v1.end(), [](int val) { cout << val << " "; });
	cout << endl;
}

/*
random_shuffle(iterator beg, iterator end)
random_shuffle 算法 对指定范围内的元素随机调整次序：洗牌算法
注意：加上随机数种子才能实现真随机
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
*/
void test03()
{
	vector<int> v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	random_shuffle(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), [](int val) { cout << val << " "; });
	cout << endl;
}

/*
reverse(iterator beg, iterator end)
reverse算法 反转指定范围的元素
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
*/

void test04()
{
	vector<int> v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	v1.push_back(100);
	v1.push_back(50);
	cout << "反转前遍历结果： " << endl;
	for_each(v1.begin(), v1.end(), [](int val) { cout << val << " "; });
	cout << endl;

	reverse(v1.begin(), v1.end());
	cout << "反转后遍历结果： " << endl;
	for_each(v1.begin(), v1.end(), [](int val) { cout << val << " "; });
	cout << endl;
}

int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	//test01();
	//test02();
	//test03();
	test04();

	//system("pause");
	return 0;
}