#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1��sizeof�ı��� 
// �ǲ���һ������������ ���Ǻ���  
// ��һ�������    + - * /
void test01()
{
	//���sizeof������һ�����ͣ����������
	printf("sizeof int = %d\n", sizeof(int)); 


	//���ͳ�Ƶ��Ǳ��������Բ�������
	int a = 10;
	printf("sizeof int = %d\n", sizeof a);

}


//2��sizeof����ֵ����  unsigned int
void test02()
{
	//unsigned int a = 10;
	//if (a - 20 > 0) //��һ��unsigned int��int����ʱ���ȶ�תΪ unsigned int
	//{
	//	printf("����0\n");
	//}
	//else
	//{
	//	printf("С��0\n");
	//}

	if ( sizeof(int) - 5 > 0)
	{
		printf("����0\n");
		printf("%u\n", sizeof(int)-5);
	}
	else
	{
		printf("С��0\n");
	}

}

//3��ͳ�����鳤��
//�����뵽�����У����������˻�Ϊһ��ָ�룬ָ�������е�һ��Ԫ�صĵ�ַ
void calculateArray(int * arr)
{
	printf("calculateArray: %d\n", sizeof(arr));

}

void test03()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	printf("test03: %d\n", sizeof(arr));

	calculateArray(arr);

}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}