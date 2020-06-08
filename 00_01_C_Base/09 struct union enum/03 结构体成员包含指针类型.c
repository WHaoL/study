#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student
{
	int id; //ѧ��
	char * name; //������ ָ��
	float score; //����
};

void test01()
{
	struct student s1 = { 1, "hello world", 99 };

	printf("%c\n", s1.name[0]);

	//s1.name[0] = 'x'; //error "hello world"�ڳ�����
}

//�ṹ���Ա �����ڶ���
void test02()
{
	struct student s1 = {1 , NULL , 100};

	//�����������ڶ���
	s1.name =  malloc(sizeof(char)* 64);
	strcpy(s1.name, "Tom");
	strcpy(s1.name, "Jerry");
	printf("id =%d name = %s score = %f\n", s1.id, s1.name, s1.score);

	if (s1.name != NULL)
	{
		free(s1.name);
		s1.name = NULL;
	}
}

//�ṹ���Ա�ڶ������ṹ�����Ҳ�ڶ�������
void test03()
{

   struct student * s1 = malloc(sizeof(struct student));

   s1->id = 1;
   s1->name = malloc(sizeof(char)* 64);
   strcpy(s1->name, "Bill");
   s1->score = 99.9;

   printf("id =%d name = %s score = %f\n", s1->id, s1->name, s1->score);

   //���ͷŵ�ʱ��Ҫ���ͷų�Ա�����ͷŽṹ�����
   //�ͷŵ�˳�� �빹���˳�����෴��
   if (s1->name != NULL)
   {
	   free(s1->name);
	   s1->name = NULL;
   }
   if (s1 != NULL)
   {
	   free(s1);
	   s1 = NULL;
   }
}


//const���νṹ��ָ��
void test04()
{
	struct student s1 = { 10, "Tom", 66 };
	struct student s2 = { 20, "Jerry", 77 };

	// *p ֻ��  p �ɶ���д     ����ָ��
	const struct student  * p = &s1;  //�ȼ��� struct student const * p

	//(*p).id = 15;  //error ָ��ָ���ֵ �������޸ĵ�

	p = &s2;  //ָ���ָ���ǿ����޸ĵ�


	// p2 ֻ��  *p2 �ɶ���д    ָ�볣��
	struct student *  const  p2 = &s1;

	(*p2).id = 100;  //ָ��ָ���ֵ ���Ը�
	//p2 = &s2; //ָ���ָ�򲻿����޸�


	// *p3  p3 ����ֻ����
	const struct student * const  p3 = &s1;
	//(*p3).id = 100; //error ָ��ָ���ֵ �������޸�
	//p3 = &s2; //error ָ���ָ�򲻿����޸�
}

int main(){
	//test03();


	system("pause");
	return EXIT_SUCCESS;
}