#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Teacher
{
	char * name; //老师姓名

	char ** student; //学生姓名的数组
};


void allocateSpace(struct Teacher ***arr)
{
	if (arr == NULL)
	{
		return;
	}

	//开辟内存
	struct Teacher ** temp = malloc(sizeof(struct Teacher *) * 3);

	//给每个老师分配内存
	for (int i = 0; i < 3;i++)
	{
		temp[i] = malloc(sizeof(struct Teacher));

		//给每个老师的姓名分配内存
		temp[i]->name = malloc(sizeof(char)* 64);
		//给老师姓名赋值
		sprintf(temp[i]->name, "Teacher_%d", i + 1);

		//给老师带的学生数组分配内存
		temp[i]->student = malloc(sizeof(char *)* 4);

		//给学生姓名分配内存
		for (int j = 0; j < 4;j++)
		{
			temp[i]->student[j] =  malloc(sizeof(char)* 64);
			//给学生姓名赋值
			sprintf(temp[i]->student[j], "%s_Student_%d", temp[i]->name, j + 1);
		}
	}

	//建立关系
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
		//老师姓名
		printf("%s\n", teachers[i]->name);

		//学生姓名
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
		//释放老师姓名
		if (teachers[i]->name != NULL)
		{
			free(teachers[i]->name);
			teachers[i]->name = NULL;
		}

		//释放学生姓名
		for (int j = 0; j < 4;j++)
		{
			if (teachers[i]->student[j] != NULL) 
			{
				free(teachers[i]->student[j]);
				teachers[i]->student[j] = NULL;
			}
		}
		//释放学生的姓名数组
		if (teachers[i]->student != NULL)
		{
			free(teachers[i]->student);
			teachers[i]->student = NULL;
		}

		//释放老师
		if (teachers[i] != NULL)
		{
			free(teachers[i]);
			teachers[i] = NULL;
		}
	}

	//释放老师的数组
	free(teachers);
	teachers = NULL;

}

void test01()
{
	//创建维护老师数组的指针
	struct Teacher ** pArray = NULL;

	//开辟内存函数
	allocateSpace(&pArray);

	//打印数组
	printTeachers(pArray);

	//释放堆区数据
	freeSpace(pArray);
	pArray = NULL;
}


int main(){

	test01();
	
	system("pause");
	return EXIT_SUCCESS;
}