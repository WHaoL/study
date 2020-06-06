#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Teacher
{
	char * name; //��ʦ����

	char ** student; //ѧ������������
};


void allocateSpace(struct Teacher ***arr)
{
	if (arr == NULL)
	{
		return;
	}

	//�����ڴ�
	struct Teacher ** temp = malloc(sizeof(struct Teacher *) * 3);

	//��ÿ����ʦ�����ڴ�
	for (int i = 0; i < 3;i++)
	{
		temp[i] = malloc(sizeof(struct Teacher));

		//��ÿ����ʦ�����������ڴ�
		temp[i]->name = malloc(sizeof(char)* 64);
		//����ʦ������ֵ
		sprintf(temp[i]->name, "Teacher_%d", i + 1);

		//����ʦ����ѧ����������ڴ�
		temp[i]->student = malloc(sizeof(char *)* 4);

		//��ѧ�����������ڴ�
		for (int j = 0; j < 4;j++)
		{
			temp[i]->student[j] =  malloc(sizeof(char)* 64);
			//��ѧ��������ֵ
			sprintf(temp[i]->student[j], "%s_Student_%d", temp[i]->name, j + 1);
		}
	}

	//������ϵ
	*arr = temp;
}

void printTeachers(struct Teacher ** teachers)
{
	if (teachers == NULL)
	{
		return;
	}

	for (int i = 0; i < 3;i++)
	{
		//��ʦ����
		printf("%s\n", teachers[i]->name);

		//ѧ������
		for (int j = 0; j < 4; j++)
		{
			printf("\t%s\n", teachers[i]->student[j]);
		}
	}
}

void freeSpace(struct Teacher ** teachers)
{
	if (teachers == NULL)
	{
		return;
	}


	for (int i = 0; i < 3;i++)
	{
		//�ͷ���ʦ����
		if (teachers[i]->name != NULL)
		{
			free(teachers[i]->name);
			teachers[i]->name = NULL;
		}

		//�ͷ�ѧ������
		for (int j = 0; j < 4;j++)
		{
			if (teachers[i]->student[j] != NULL) 
			{
				free(teachers[i]->student[j]);
				teachers[i]->student[j] = NULL;
			}
		}
		//�ͷ�ѧ������������
		if (teachers[i]->student != NULL)
		{
			free(teachers[i]->student);
			teachers[i]->student = NULL;
		}

		//�ͷ���ʦ
		if (teachers[i] != NULL)
		{
			free(teachers[i]);
			teachers[i] = NULL;
		}
	}

	//�ͷ���ʦ������
	free(teachers);
	teachers = NULL;

}

void test01()
{
	//����ά����ʦ�����ָ��
	struct Teacher ** pArray = NULL;

	//�����ڴ溯��
	allocateSpace(&pArray);

	//��ӡ����
	printTeachers(pArray);

	//�ͷŶ�������
	freeSpace(pArray);
	pArray = NULL;
}


int main(){

	test01();
	
	system("pause");
	return EXIT_SUCCESS;
}