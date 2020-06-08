#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:

	void showPerson()
	{
		cout << "this is Person class" << endl;
	}

	void showAge()
	{
		if (this == NULL)
		{
			return;
		}
		cout << "age = " << this->m_Age << endl;
	}

	int m_Age = 18;

};

void test01()
{
	Person * p = NULL;
	p->showPerson(); //Ã»´í
	p->showAge();    //³ö´í
	
}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}