#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

struct Person
{
	int age;
};

void allocateSpace(Person ** pp) // pp - 实参p的地址    *pp - p的值   **pp - p指向内存的值
{
	*pp = (Person *)malloc(sizeof(Person));
	(*pp)->age = 100;
}
void test01()
{
	Person * p = NULL;
	allocateSpace(&p);
	cout << "p的age = " << p->age << endl;
}

void allocateSpace2(Person* &pp)
{
	pp =(Person *)malloc(sizeof(Person));
	pp->age = 200;
}

//利用引用实现
void test02()
{
	Person * p = NULL;
	allocateSpace2(p);
	cout << "p的age = " << p->age << endl;
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}