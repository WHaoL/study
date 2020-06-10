//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//ν��
//ָ������ͨ���� ���߷º��� �ķ���ֵ�� bool��������
// ν�ʣ���ָ��ͨ���������ص�operator()����ֵ��bool���͵ĺ�������������(�º���)��
// ���operator����һ����������ô����һԪν��,
// �������������������ô������Ԫν�ʣ�
// ν�ʿ���Ϊһ���ж�ʽ��

//һԪν��
class Greater20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};

//��Ԫν��
class myCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

//���ԣ�һԪν��
void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//�ҵ���һ������20��Ԫ��
	vector<int>::iterator ret = find_if(v.begin(), v.end(), Greater20());
	if (ret != v.end())
	{
		cout << "�ҵ���Ԫ�ش���20��ֵΪ�� " << *ret << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	//��Ԫν��
	sort(v.begin(), v.end(), myCompare());
}

//��Ԫν��
class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2;
	}
};

//���ԣ���Ԫν��
void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(90);
	v.push_back(60);

	//Ĭ�ϴ�С����
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "----------------------------" << endl;
	//ʹ�ú�������ı��㷨���ԣ�����Ӵ�С
	sort(v.begin(), v.end(), MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{

	//test01();
	test02();

	//system("pause");
	return 0;
}