#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//1���ṩһ����������ӡ�������͵�����

//����1  �����׵�ַ  ����2 ÿ��Ԫ��ռ���ڴ�ռ�  ����3 Ԫ�ظ���  ����4 �ص�����
void printAllArray( void * arr, int eleSize, int len , void(*myPrint)(void *)  )
{
	char * p = arr;
	for (int i = 0; i < len;i++)
	{
		//eleAddr���Է��������� ÿ��Ԫ�صĵ�ַ
		char *eleAddr = p + eleSize * i;
		//printf("%d\n", *(int*)eleAddr);
		myPrint(eleAddr);
	}

}







void myPrintInt(void * data)
{
	int * num = data;
	printf("%d\n", *num);
}

void test01()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	int len = sizeof(arr) / sizeof(int);
	printAllArray(arr, sizeof(int), len, myPrintInt);
}


struct Person
{
	char name[64];
	int age;
};
void myPrintPerson(void *data)
{
	struct Person * p = data;
	printf("������%s  ����:%d\n", p->name, p->age);
}
void test02()
{
	struct Person pArray[] =
	{
		{ "aaa", 10 },
		{ "bbb", 20 },
		{ "ccc", 30 },
		{ "ddd", 40 },
	};
	int len = sizeof(pArray) / sizeof(struct Person);

	printAllArray(pArray, sizeof(struct Person), len, myPrintPerson);
}

//����ֵ�����Ƿ��ҵ�Ԫ��  1�����ҵ�  0����δ�ҵ�
int findArrayEle(void * arr , int eleSize , int len ,void * data  , int(*myCompare)(void * ,void *)  )
{
	char * p = arr;
	for (int i = 0; i < len;i++)
	{
		//eleAddr���Է��������� ÿ��Ԫ�صĵ�ַ
		char *eleAddr = p + eleSize * i;
		
		//if (�ұ��������� == �û����������)
		//if ( eleAddr == data )
		if (myCompare(eleAddr,data))
		{
			return 1;
		}
	}
	return 0;
}

int myComparePerson(void * data1,void * data2)
{
	struct Person * p1 = data1;
	struct Person * p2 = data2;

	if (p1->age == p2->age &&  strcmp(p1->name,p2->name)==0 )
	{
		return 1;
	}
	return 0;
}

void test03()
{
	struct Person pArray[] =
	{
		{ "aaa", 10 },
		{ "bbb", 20 },
		{ "ccc", 30 },
		{ "ddd", 40 },
	};

	struct Person p = { "ccc", 30 };

	int len = sizeof(pArray) / sizeof(struct Person);

	//���������е�ָ��Ԫ���Ƿ���ڣ�������ڷ����棬���򷵻ؼ�


	int ret = findArrayEle(pArray, sizeof(struct Person), len, &p, myComparePerson);

	if (ret)
	{
		printf("�ҵ���\n");
	}
	else
	{
		printf("δ�ҵ�\n");
	}

}


int main(){
	test03();


	system("pause");
	return EXIT_SUCCESS;
}