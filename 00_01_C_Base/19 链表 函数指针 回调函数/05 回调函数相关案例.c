#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//1、提供一个函数，打印任意类型的数组

//参数1  数组首地址  参数2 每个元素占用内存空间  参数3 元素个数  参数4 回调函数
void printAllArray( void * arr, int eleSize, int len , void(*myPrint)(void *)  )
{
	char * p = arr;
	for (int i = 0; i < len;i++)
	{
		//eleAddr可以访问数组中 每个元素的地址
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
	printf("姓名：%s  年龄:%d\n", p->name, p->age);
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

//返回值代表是否找到元素  1代表找到  0代表未找到
int findArrayEle(void * arr , int eleSize , int len ,void * data  , int(*myCompare)(void * ,void *)  )
{
	char * p = arr;
	for (int i = 0; i < len;i++)
	{
		//eleAddr可以访问数组中 每个元素的地址
		char *eleAddr = p + eleSize * i;
		
		//if (我遍历的数据 == 用户传入的数据)
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

	//查找数组中的指定元素是否存在，如果存在返回真，否则返回假


	int ret = findArrayEle(pArray, sizeof(struct Person), len, &p, myComparePerson);

	if (ret)
	{
		printf("找到了\n");
	}
	else
	{
		printf("未找到\n");
	}

}


int main(){
	test03();


	system("pause");
	return EXIT_SUCCESS;
}