#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

struct Person
{
	int age;
};

void allocateSpace(Person ** pp) // pp - ʵ��p�ĵ�ַ    *pp - p��ֵ   **pp - pָ���ڴ��ֵ
{
	*pp = (Person *)malloc(sizeof(Person));
	(*pp)->age = 100;
}
void test01()
{
	Person * p = NULL;
	allocateSpace(&p);
	cout << "p��age = " << p->age << endl;
}

void allocateSpace2(Person* &pp)
{
	pp =(Person *)malloc(sizeof(Person));
	pp->age = 200;
}

//��������ʵ��
void test02()
{
	Person * p = NULL;
	allocateSpace2(p);
	cout << "p��age = " << p->age << endl;
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}