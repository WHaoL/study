#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//  �ṹ�嶨��
//  struct student��һ����������   ����  int  double  char
//  ����Ҫ��{}���������еĳ�Ա {}����Ҫ���Ϸֺš�;��
//  ����ṹ������ֻ��һ��ģ�ߣ�û��ռ�þ����ڴ�ռ�
struct student
{
	int id;			//ѧ��
	char name[64];  //����
	float score;	//����
	int age;		//����
};

void test01()
{
	//ͨ���ṹ�����ͣ������ṹ�����
	//���ṹ�������ֵ��ʱ��Ҫ����˳��ֵ
	struct student s1 = { 1, "Tom", 99.9, 18 };

	//ͨ�� '.' ���� �����ҵ�����ĳ�Ա
	printf("id = %d\n", s1.id);
	printf("name = %s\n", s1.name);
	printf("score = %f\n", s1.score);
	printf("age = %d\n", s1.age);

}


//�ڶ���ṹ��ʱ��˳�㴴���ṹ�����
struct student2
{
	int id;			//ѧ��
	char name[64];  //����
	float score;	//����
	int age;		//����
}s;  //s���� ͨ��struct sutdent2�����Ľṹ�����
void test02()
{
	s.id = 2;
	//s.name = "Jerry";  //error
	strcpy(s.name, "Jerry");
	s.score = 80;
	s.age = 19;

	
	printf("id = %d\n", s.id);
	printf("name = %s\n", s.name);
	printf("score = %f\n", s.score);
	printf("age = %d\n", s.age);
}


//�Ӽ��̻�ȡ��Ա����
void test03()
{
	struct student s1;// = { 3, "Tom", 66.6, 20 };

	//ͨ�����̻�ȡ����
	printf("���ѧ�Ÿ�ֵ\n");
	scanf("%d", &s1.id);

	printf("���������ֵ\n");
	scanf("%s", s1.name);

	printf("���������ֵ\n");
	scanf("%f", &s1.score);

	printf("������丳ֵ\n");
	scanf("%d", &s1.age);

	printf("id = %d\n", s1.id);
	printf("name = %s\n", s1.name);
	printf("score = %f\n", s1.score);
	printf("age = %d\n", s1.age);

}


//�ṹ���Ա��ֵ
void test04()
{
	struct student s1;
	struct student s2 = {1,"Tom",99,18};


	//����1  �����Ա��ֵ
	//s1.id = s2.id;
	//strcpy(s1.name, s2.name);
	//s1.score = s2.score;
	//s1.age = s2.age;

	//����2 ���������������ͬ�Ľṹ�����������ֱ��=��ֵ  �Ƽ�
	//s1 = s2;

	//����3 �����ڴ�������� memcpy
	memcpy(&s1, &s2, sizeof(struct student));

	
	printf("id = %d\n", s1.id);
	printf("name = %s\n", s1.name);
	printf("score = %f\n", s1.score);
	printf("age = %d\n", s1.age);
}

//���������ṹ�����
void test05()
{
	struct student s1 = {10,"Jerry",10, 20};
	struct student s2 = { 1, "Tom", 99, 18 };

	//������ʱ�ṹ����������н���
	struct student temp;
	temp = s1;
	s1 = s2;
	s2 = temp;

	printf("s1 --- id = %d  name = %s score = %f age = %d\n", s1.id , s1.name,s1.score,s1.age);
	printf("s2 --- id = %d  name = %s score = %f age = %d\n", s2.id, s2.name, s2.score, s2.age);
}

//�ṹ������
void test06()
{
	struct student arr[5] =
	{
		{ 1, "����", 100, 30 },
		{ 2, "�ŷ�", 90, 31 },
		{ 3, "����", 80, 32 },
		{ 4, "����", 88, 34 },
		{ 5, "����", 96, 33 }  //���һ�е� ',' ����ʡ��
	};
	int num = sizeof(arr) / sizeof(struct student);
	for (int i = 0; i < num;i++)
	{
		printf("id = %d  name = %s score = %.2f age = %d\n", arr[i].id, arr[i].name, arr[i].score, arr[i].age);
	}

	//�������ƽ��ֵ
	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum += arr[i].age;
	}
	printf("����ƽ��ֵΪ:%d\n", sum / num);
}

//�ṹ��Ƕ�׽ṹ��
struct stu
{
	int id;
	int age;
};

struct Teacher
{
	int id;
	struct stu s; //��ʦ�ṹ�����и�ѧ���ĳ�Ա
};
void test07()
{
	struct Teacher t1 = { 1000, { 100, 18 } };
	struct Teacher t2 = { 1001, 101, 19 };

	printf("t1  id = %d  stu id = %d  age = %d\n", t1.id, t1.s.id, t1.s.age);
	printf("t2  id = %d  stu id = %d  age = %d\n", t2.id, t2.s.id, t2.s.age);
}

int main(){
	test07();


	system("pause");
	return EXIT_SUCCESS;
}