#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��
struct Person
{
	char m_Name[64];
	int m_Age;
};

//�Է�
void personEat(struct Person * p)
{
	printf("%s�ڳ��˷�\n", p->m_Name);
}


//��
struct Dog
{
	char m_Name[64];
	int m_Age;
};

//�Է�
void dogEat(struct Dog* d)
{
	printf("%s�ڳԹ���\n", d->m_Name);
} 

void test01()
{
	struct Person p;
	strcpy(p.m_Name, "����");
	p.m_Age = 18;
	personEat(&p);
}

void test02()
{
	struct Dog d;
	strcpy(d.m_Name, "����");
	d.m_Age = 19;
	dogEat(&d);

	struct Person p;
	strcpy(p.m_Name, "����");
	p.m_Age = 18;
	dogEat(&p);
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}