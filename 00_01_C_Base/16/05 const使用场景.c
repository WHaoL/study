#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Person
{
	char name[64]; // 0 ~ 63

	int age;  // 64 ~ 67

	int id;  //68 ~ 71

	double score; // 72 ~ 79
};

//���õ�ַ���ݣ����Խ�ʡ��Դ
//ȱ�㣬����ں��������޸������ԣ�����ʵ��Ҳ���ĵ�
void printPerson(const struct Person *p)
{
	//p->age = 100; // ��const���ֹ��������޸�����
	printf("������%s ���䣺%d ѧ�ţ�%d ������%lf\n", p->name, p->age, p->id, p->score);
}

void test01()
{
	struct Person p1 = { "����", 18, 1, 100 };

	printPerson(&p1);
}



int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}