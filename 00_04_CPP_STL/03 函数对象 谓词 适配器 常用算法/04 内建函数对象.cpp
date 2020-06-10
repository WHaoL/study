//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <functional> //�ڽ��������󣡣����� ͷ�ļ�
#include <vector>
#include <algorithm>

// ȡ���º�����ȡ�����෴����
// template<class T>
// T negate<T>
void test01()
{
	negate<int> n;
	cout << n(10) << endl; //-10
}

// �ӷ��º���
// template<class T>
// T plus<T>

void test02()
{
	plus<int> p;
	cout << p(1, 1) << endl; //2
}

// ���ڷº���
// template<class T>
// greater<T>

// һԪν��
class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test03()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	sort(v.begin(), v.end(), greater<int>()); //����//�Ӵ�С����

	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}

// �߼���
// template<class T>
// bool logical_not<T>
void test04()
{
	vector<bool> v;

	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	/*
	transform(iterator beg1, iterator end1, iterator beg2, _callbakc)
	transform �㷨 ��ָ����������Ԫ�ذ��˵���һ������ 
	ע�� : transform �����Ŀ�����������ڴ棬������Ҫ������ǰ������ڴ� 
	@param beg1 Դ������ʼ������ 
	@param end1 Դ�������������� 
	@param beg2 Ŀ��������ʼ������ 
	@param _cakkback �ص��������ߺ������� 
	@return ����Ŀ������������
	*/
	vector<bool> v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(), logical_not<int>());

	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test01();
	test02();
	test03();
	test04();

	//system("pause");
	return 0;
}