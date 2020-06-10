//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric> //accumulateͷ�ļ�
#include <iterator>

/*
accumulate(iterator beg, iterator end, value)
accumulate �㷨 ��������Ԫ���ۼ��ܺͣ�#include<numeric>
	@param beg ������ʼ������
	@param end ��������������
	@param value ��ʼ�ۼ�ֵ
*/
void test01()
{
	vector<int> v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	int sum = accumulate(v.begin(), v.end(), 1000); //����3 �ۼ���ʼֵ
	cout << sum << endl;
}

/*
fill(iterator beg, iterator end, value)
fill�㷨 �����������Ԫ��
	@param beg ������ʼ������
	@param end ��������������
	@param value ���Ԫ��
*/
void test02()
{
	vector<int> v;
	v.resize(10);

	fill(v.begin(), v.end(), 100);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{

	//test01();
	test02();

	//system("pause");
	return 0;
}