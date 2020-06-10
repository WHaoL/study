//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <iterator>

/*
copy(iterator beg, iterator end, iterator dest)
copy�㷨 ��������ָ����Χ��Ԫ�ؿ�������һ������
	@param beg ������ʼ������
	@param end ��������������
	@param dest Ŀ����ʼ��������Ŀ�������ǵ÷���ռ䣺resize�� 
*/
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int> v2;
	v2.resize(v.size());
	copy(v.begin(), v.end(), v2.begin());

	//for_each(v2.begin(), v2.end(), [](int val){cout << val << " "; });
	//cout << endl;

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

/*
replace(iterator beg, iterator end, oldvalue, newvalue)
replace�㷨 ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
	@param beg ������ʼ������
	@param end ��������������
	@param oldvalue ��Ԫ��
	@param newvalue ��Ԫ��

replace_if(iterator beg, iterator end, _callback, newvalue)
replace_if�㷨 ��������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
	@param beg ������ʼ������
	@param end ��������������
	@param callback�����ص�����ν��(����Bool���͵ĺ�������)
	@param newvalue ��Ԫ��
*/
class ReplaceIF
{
public:
	bool operator()(int val)
	{
		return val > 3;
	}
};
void test02()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//�������е�3  �滻Ϊ 3000
	replace(v.begin(), v.end(), 3, 3000);
	// 0 1 2 3000 4 5 6 7 8 9
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//�����д���3��ֵ �滻Ϊ30000
	replace_if(v.begin(), v.end(), ReplaceIF(), 30000);
	// // 0 1 2 30000  30000 ....
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

/*
swap(container c1, container c2)
swap�㷨 ��������������Ԫ��
	@param c1����1
	@param c2����2
*/
void test03()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
	}

	cout << "����ǰ�Ľ��Ϊ��" << endl;
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	swap(v1, v2);
	cout << "������Ľ��Ϊ��" << endl;
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{

	//test01();
	//test02();
	test03();

	//system("pause");
	return 0;
}