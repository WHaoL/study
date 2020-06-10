//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;
/* 
//list˫��ѭ������
void test01()
{
	list<int> myList;
	for (int i = 0; i < 10; i++)
	{
		myList.push_back(i);
	}

	list<int>::_Nodeptr node = myList._Myhead->_Next;

	for (int i = 0; i < myList._Mysize * 2; i++)
	{
		cout << "Node:" << node->_Myval << endl;
		node = node->_Next;

		//node->_Prev; ǰһ���ڵ��ַ
		if (node == myList._Myhead)
		{
			node = node->_Next;
		}
	}
}
 */

/* 
//3.6.4.1 list���캯��
list<T> lstT;		   //list����ģ����ʵ��,�����Ĭ�Ϲ���
list(beg, end);		   //���캯����[beg, end)�����е�Ԫ�ؿ���������
list(n, elem);		   //���캯����n��elem����������
list(const list &lst); //�������캯����

//3.6.4.2 list����Ԫ�ز����ɾ������
push_back(elem);	   //������β������һ��Ԫ��
pop_back();			   //ɾ�����������һ��Ԫ��
push_front(elem);	   //��������ͷ����һ��Ԫ��
pop_front();		   //��������ͷ�Ƴ���һ��Ԫ��
insert(pos, elem);	   //��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
insert(pos, n, elem);  //��posλ�ò���n��elem���ݣ��޷���ֵ��
insert(pos, beg, end); //��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
clear();			   //�Ƴ���������������
erase(beg, end);	   //ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
erase(pos);			   //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
remove(elem);		   //ɾ��������������elemֵƥ���Ԫ�ء�
 */
void test02()
{
	list<int> L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	for (list<int>::iterator it = L1.begin(); it != L1.end(); it++)
	{
		cout << *it << endl;
	}

	cout << "----------------------" << endl;

	for (list<int>::reverse_iterator it = L1.rbegin(); it != L1.rend(); it++)
	{
		cout << *it << endl;
	}

	//������
	//�Ƿ�֧���������
	list<int>::iterator it = L1.begin();
	it++;
	it--;
	//it = it + 1;  ���󣬲�֧���������
}

void printList(const list<int> &L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		//*it = 1000;
		cout << *it << " ";
	}
	cout << endl;
}

void test03()
{
	list<int> L(10, 100);
	printList(L);

	list<int> L2;
	L2.push_back(10);
	L2.push_back(20);
	L2.push_back(30);
	L2.push_front(100);
	L2.push_front(200);
	L2.push_front(300); //300 200 100 10 20 30
	printList(L2);

	L2.pop_back();
	L2.pop_front(); // 200 100 10 20
	printList(L2);

	//���� insert
	L2.insert(L2.begin(), 1000); // 1000 200 100 10 20
	printList(L2);

	//ɾ��erase
	L2.erase(L2.begin()); // 200 100 10 20
	printList(L2);

	//remove(elem);//ɾ��������������elemֵƥ���Ԫ�ء�
	L2.push_front(100);
	L2.push_back(100);
	L2.remove(100); //ɾ������ֵΪ100��Ԫ��	//ɾ��100
	printList(L2);

	//���
	L2.clear();
	printList(L2);
}
/* 
//3.6.4.3 list��С����
size();			   //����������Ԫ�صĸ���
empty();		   //�ж������Ƿ�Ϊ��
resize(num);	   //����ָ�������ĳ���Ϊnum��
				   //�������䳤������Ĭ��ֵ�����λ�á�
				   //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(num, elem); //����ָ�������ĳ���Ϊnum��
				   //�������䳤������elemֵ�����λ�á�
                   //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

//3.6.4.4 list��ֵ����
assign(beg, end);				  //��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);				  //��n��elem������ֵ������
list &operator=(const list &lst); //���صȺŲ�����
swap(lst);						  //��lst�뱾���Ԫ�ػ�����

//3.6.4.5 list���ݵĴ�ȡ
front(); //���ص�һ��Ԫ�ء�
back();	 //�������һ��Ԫ�ء�
 */
void test04()
{
	list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	if (L.empty())
	{
		cout << "LΪ��" << endl;
	}
	else
	{
		cout << "L��Ϊ�գ����ȣ�" << L.size() << endl;
	}

	cout << "��һ��Ԫ�أ�" << L.front() << endl;
	cout << "���һ��Ԫ�أ�" << L.back() << endl;
}

/*
3.6.4.6 list��ת����
reverse();	//��ת��������lst����1,3,5Ԫ�أ����д˷�����lst�Ͱ���5,3,1Ԫ�ء�
sort(); 	//list����
*/

void test05()
{
	list<int> L;
	for (int i = 0; i < 10; i++)
	{
		L.push_back(i);
	}

	printList(L);

	//��ת  �ʱ��㷨
	L.reverse();

	printList(L);
}

bool myCompare(int v1, int v2)
{
	return v1 > v2;
}

//����
void test06()
{
	list<int> L;
	L.push_back(10);
	L.push_back(30);
	L.push_back(50);
	L.push_back(20);
	L.push_back(40);

	//��׼�㷨������  ֻ֧��������ʵ�����������
	//��֧��������ʵ��������������ڲ����Ӧ�ṩһЩ�㷨
	//sort(L.begin(), L.end());

	L.sort();
	printList(L);

	//����
	L.sort(myCompare); //����
	printList(L);
}

class Person
{
public:
	Person(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	bool operator==(const Person &p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age && this->m_Height == p.m_Height)
		{
			return true;
		}
		return false;
	}

	string m_Name; //����
	int m_Age;	   //����
	int m_Height;  // ���
};

bool myComparePerson(Person &p1, Person &p2)
{
	//���������� , ���������ͬ����߽���
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	return p1.m_Age < p2.m_Age;
}

void test07()
{
	list<Person> L;

	Person p1("�ŷ�", 18, 200);
	Person p2("����", 20, 185);
	Person p3("����", 19, 150);
	Person p4("����", 17, 170);
	Person p5("���", 21, 160);
	Person p6("����", 21, 175);
	Person p7("��", 21, 140);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	L.push_back(p7);

	//����ǰ��
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "������ " << (*it).m_Name << " ���䣺" << it->m_Age << " ��ߣ� " << it->m_Height << endl;
	}

	//�Զ����������ͣ�����ָ���������
	L.sort(myComparePerson); //�������� ����
	cout << "-------------------------------" << endl;
	//�����
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "������ " << (*it).m_Name << " ���䣺" << it->m_Age << " ��ߣ� " << it->m_Height << endl;
	}

	//ɾ������
	L.remove(p4);
	cout << "----------   ɾ�����ƺ�  ---------------------" << endl;
	//�����
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "������ " << (*it).m_Name << " ���䣺" << it->m_Age << " ��ߣ� " << it->m_Height << endl;
	}
}

int main()
{

	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();

	//system("pause");
	return 0;
}