#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//人
struct Person
{
	char m_Name[64];
	int m_Age;
};

//吃饭
void personEat(struct Person * p)
{
	printf("%s在吃人饭\n", p->m_Name);
}


//狗
struct Dog
{
	char m_Name[64];
	int m_Age;
};

//吃饭
void dogEat(struct Dog* d)
{
	printf("%s在吃狗粮\n", d->m_Name);
} 

void test01()
{
	struct Person p;
	strcpy(p.m_Name, "张三");
	p.m_Age = 18;
	personEat(&p);
}

void test02()
{
	struct Dog d;
	strcpy(d.m_Name, "旺财");
	d.m_Age = 19;
	dogEat(&d);

	struct Person p;
	strcpy(p.m_Name, "老王");
	p.m_Age = 18;
	dogEat(&p);
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}