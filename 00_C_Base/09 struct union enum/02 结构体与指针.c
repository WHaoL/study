#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student
{
	int id; //�����Ը���ʼֵ  int id = 0; ����Ǵ����д��
	char name[64];
	float score;
};

void test01()
{
	struct student s1 = { 1, "Tom", 100 };

	struct student * p = &s1;

	printf("id = %d name = %s score = %.2f\n", p->id,p->name,p->score);
	printf("id = %d name = %s score = %.2f\n", s1.id, s1.name, s1.score);

	printf("id = %d name = %s score = %.2f\n", (&s1)->id, (&s1)->name, (&s1)->score);
	printf("id = %d name = %s score = %.2f\n", (*p).id, (*p).name, (*p).score);

}

//ָ�� ͨ�����̻�ȡ����
void test02()
{
	struct student s1;
	//���
	memset(&s1, 0, sizeof(struct student));

	struct student* p = &s1;

	scanf("%d %s %f", &p->id, p->name, &p->score);
	printf("id = %d name = %s score = %.2f\n", p->id, p->name, p->score);
	
}

//�ṹ�崴���ڶ���
void test03()
{
	struct student * p = NULL;

	p = malloc(sizeof(struct student));

	//���
	memset(p, 0, sizeof(struct student));

	printf("������ѧ�ţ�����������\n");
	scanf("%d %s %f", &p->id, p->name, &p->score);

	printf("id = %d name = %s score = %.2f\n", p->id, p->name, p->score);
	
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}

//�ṹ������ �����ڶ���
void test04()
{
	int num = 0;
	printf("������ѧ������\n");
	scanf("%d", &num);

	struct student * arr = malloc(sizeof(struct student) * num);

	//���
	memset(arr, 0, sizeof(struct student)*num);

	//�Ӽ��̻�ȡ�û�����
	for (int i = 0; i < num; i++)
	{
		printf("����� %d ��ѧ��������Ϣ", i + 1);
		//scanf("%d %s %f", &arr[i].id , arr[i].name, &arr[i].score );
		scanf("%d %s %f",  &(arr+i)->id ,  (arr+i)->name , &(arr+i)->score  );
	}

	for (int i = 0; i < num; i++)
	{
		printf("id = %d name = %s score = %.2f\n", arr[i].id, arr[i].name, arr[i].score);
	}

	//�ͷ�����
	if (arr != NULL)
	{
		free(arr);
		arr = NULL;
	}
}


//�ṹ��ָ������������
void setStudent(struct student *p)
{
	scanf("%d %s %f", &p->id,  p->name, &p->score);
}

void test05()
{
	struct student s1;
	memset(&s1, 0, sizeof(struct student));

	setStudent(&s1);
	printf("id = %d name = %s score = %.2f\n", s1.id, s1.name, s1.score);
}


//�ṹ���������������� 
void setArray(struct student* arr, int num)
{
	printf("������%d��ѧ������Ϣ\n",num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %s %f", &arr[i].id, arr[i].name, &arr[i].score);
	}
}

void printArray(struct student* arr, int num)
{
	for (int i = 0; i < num;i++)
	{
		printf("id = %d name = %s score = %.2f\n", arr[i].id, arr[i].name, arr[i].score);
	}
}

void test06()
{
	struct student arr[2];

	memset(arr, 0, sizeof(arr));

	setArray(arr, 2);

	printArray(arr, 2);
}

int main(){
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	
	system("pause");
	return EXIT_SUCCESS;
}