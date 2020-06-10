//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <list>

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		cout << v.capacity() << endl; // v.capacity()����������
	}
}

/*
3.2.4.1 vector���캯��
vector<T> v; 				//����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
vector(v.begin(), v.end());	//��v[begin(), end())�����е�Ԫ�ؿ���������
vector(n, elem);			//���캯����n��elem����������
vector(const vector &vec);	//�������캯����

//���� ʹ�õڶ������캯�� ���ǿ���...
int arr[] = {2,3,4,1,9};
vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

3.2.4.2 vector���ø�ֵ����
assign(beg, end);						//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);						//��n��elem������ֵ������
vector& operator=(const vector  &vec);	//���صȺŲ�����
swap(vec);								// ��vec�뱾���Ԫ�ػ�����
*/

void printVector(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test02()
{
	vector<int> v;			 //Ĭ�Ϲ���
	vector<int> v2(10, 100); //10��100
	printVector(v2);

	vector<int> v3(v2.begin(), v2.end());
	printVector(v3);

	vector<int> v4(v3);
	printVector(v4);
}

void test03()
{
	//��ֵ
	int arr[] = {2, 3, 4, 1, 9};
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	vector<int> v2;
	v2 = v1;
	printVector(v2);

	vector<int> v3;
	v3.assign(v2.begin(), v2.end());
	printVector(v3);

	vector<int> v4(10, 100);
	printVector(v4);

	cout << "v3 �� v4 ������" << endl;

	v3.swap(v4);
	printVector(v3);
	printVector(v4);
}
/* 
//3.2.4.3 vector��С����
size();				   //����������Ԫ�صĸ���
empty();			   //�ж������Ƿ�Ϊ��
resize(int num);	   //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(int num, elem); //����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á����������̣���ĩβ����������>�ȵ�Ԫ�ر�ɾ����
capacity();			   //����������
reserve(int len);	   //����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
front();			   //���������е�һ������Ԫ��
back();				   //�������������һ������Ԫ��
 */
void test04()
{
	int arr[] = {2, 3, 4, 1, 9};
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	if (v1.empty())
	{
		cout << "v1Ϊ��" << endl;
	}
	else
	{
		cout << "v1��Ϊ��" << endl;
		cout << "size = " << v1.size() << endl;
	}
	printVector(v1);
	v1.resize(10, 100); //����2  ������ݣ����ֵ����Ϊ0
	printVector(v1);

	v1.resize(3); // 2 3 4
	printVector(v1);

	cout << "��һ��Ԫ��Ϊ�� " << v1.front() << endl;  //2
	cout << "���һ��Ԫ��Ϊ�� " << v1.back() << endl; //4
}
/* 
3.2.4.5 vector�����ɾ������
insert(const_iterator pos, int count, ele);		 //������ָ��λ��pos����count��Ԫ��ele.
push_back(ele);									 //β������Ԫ��ele
pop_back();										 //ɾ�����һ��Ԫ��
erase(const_iterator start, const_iterator end); //ɾ����������start��end֮���Ԫ��
erase(const_iterator pos);						 //ɾ��������ָ���Ԫ��
clear();										 //ɾ������������Ԫ��
 */
void test05()
{
	int arr[] = {2, 3, 4, 1, 9};
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	v1.insert(v1.begin(), 100);
	v1.insert(v1.begin(), 2, 1000);
	printVector(v1); // 1000 1000  100 2 3 4 1 9

	v1.push_back(10000);
	printVector(v1); // 1000 1000  100 2 3 4 1 9 10000
	v1.pop_back();
	printVector(v1); //  1000 1000  100 2 3 4 1 9

	v1.erase(v1.begin());
	printVector(v1); //  1000  100 2 3 4 1 9

	//v1.erase(v1.begin(), v1.end());
	v1.clear();
	printVector(v1);
}

//����1  ����swap�����ڴ�
void test06()
{
	vector<int> v;

	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "size = " << v.size() << endl;		   // 100000
	cout << "capacity = " << v.capacity() << endl; // 130000+

	v.resize(3);
	cout << "size = " << v.size() << endl;		   // 3
	cout << "capacity = " << v.capacity() << endl; //130000+

	//����swap�����ڴ�
	//˵����
	//		vector<int>(v) //���ÿ������캯����(����v�����ʵ������ռ����,����ʼ��)�������һ����ʱ(����)��vector����
	//      vector<int>(v).swap(v);// ��ʱ�����v���󣬽���swap����������ϵͳ������գ�v�����Ѿ��������ڴ�
	vector<int>(v).swap(v);
	cout << "size = " << v.size() << endl;		   // 3
	cout << "capacity = " << v.capacity() << endl; //3
}

//2������reserve Ԥ���ڴ�ռ�
//reserve  Ԥ���ռ�
//reverse  ��ת
void test07()
{

	vector<int> v;

	v.reserve(100000); //����reserve������ǰԤ���ռ�

	int *p = NULL;
	int num = 0;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++; //ͳ�ƿ����˶��ٴ��ڴ�
		}
	}

	cout << "num = " << num << endl;			   //numͳ�� ���100000���ݣ����¿��ٿռ����
	cout << "size = " << v.size() << endl;		   //100000   reserve֮��Ϊ100000
	cout << "capacity = " << v.capacity() << endl; //130000+  reserve֮��Ϊ100000
}

void test08()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << "����������" << endl;
	printVector(v);

	cout << "����������" << endl;
	//������� ���ʱ�
	//reverse_iterator ��ת������
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//����ж�һ�������ĵ������Ƿ�֧���������
	vector<int>::iterator itBegin = v.begin();
	itBegin++;			   //++(��ǰ)
	itBegin--;			   //++(��ǰ)
						   //++(��ǰ) --(���) �﷨��ͨ���Ļ�-->˵������һ��˫�������
	itBegin = itBegin + 1; //+ ���� �﷨ͨ���Ļ�-->˵��֧���������

	list<int> L;
	L.push_back(10);
	L.push_back(10);
	L.push_back(10);

	list<int>::iterator lBegin = L.begin();
	lBegin++;
	lBegin--;
	//lBegin = lBegin + 1; //��֧���������
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	test08();
	//system("pause");
	return 0;
}