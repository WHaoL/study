#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	int arr[5] = { 1, 2, 3, 4, 5 };

	//1�����������Ի�ȡ��������ռ���ڴ��С
	printf("%d\n", sizeof(arr));

	//2����ȡ������Ԫ�ص�ַ
	printf("��Ԫ�ص�ַ��%d\n", arr);
	printf("�ڶ���Ԫ�صĵ�ַ��%d\n", arr+1);
	printf("��һ��Ԫ��Ϊ:%d\n", arr[0]);
	printf("��һ��Ԫ��Ϊ:%d\n", *(arr + 0) );

	printf("�ڶ���Ԫ��Ϊ:%d\n", arr[1]);
	printf("�ڶ���Ԫ��Ϊ:%d\n", *(arr + 1));

	for (int i = 0; i < 5; i++)
	{
		//printf("%d ", arr[i]);
		//printf("%d ", *(arr + i) );
		printf("%d ", i[arr]);

	}
	printf("\n");

	//[] ����  * ()��д
	printf("�ڶ���Ԫ��Ϊ: %d\n", *(1 + arr));
	printf("�ڶ���Ԫ��Ϊ: %d\n",1[arr] );


	//arrΪʲô�ǵ�һ��Ԫ�صĵ�ַ
	// &arr[0]  ==  &*(arr+0) ==   (arr + 0)  ==  arr 
}

//����ָ���������
void test02()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	//����һ��ָ�����������������
	int * p = arr;

	for (int i = 0; i < 5; i++)
	{
		//printf("%d ", *(p + i));
		printf("%d ", p[i]);
	}
	printf("\n");

	//p ��arr����
	printf("sizeof arr = %d\n", sizeof (arr)); //20
	printf("sizeof p = %d\n", sizeof (p)); //4


	int *p2 = &arr[2];
	printf("%d\n", p2[1]); // 4
	printf("%d\n", p2[-1]);// 2
}


void test03()
{
	int arr[5] = { 1, 4, 7, 11, 14 };
	int * p = arr;

	printf("%d\n", *p++);   //1-��ȡ��arr[0]==1��2-Ȼ��p++ pָ����arr[1]==4
	printf("%d\n", *p);//��ʱpָ����arr[1]==4
	printf("\n");

	printf("%d\n", (*p)++); //1-��ʱp����ָ��arr[1]==4,����ȡ����*p����ӡ�Ľ��Ϊ4��2-Ȼ��(*p)++,��arr[1]��ֵ��4��Ϊ5
	printf("%d\n", *p);//��ʱpָ��arr[1]==5
	printf("\n");

	printf("%d\n", *(p++)); //����++���ڼ��㵥Ԫ�������ִ�У����ԣ�1-��ȡ��*p==5��2-Ȼ��p++��ʹ��pָ����arr[3]==7
	printf("%d\n", *p);//��ʱpָ����arr[3]==7
	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		printf("%d ",arr[i]);
	}

	printf("\n");
}

void test04()
{
	int arr[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

	printf("%d\n", arr[*(arr + *(arr + arr[3]))]); // 7 

}

int main(){

	test03();

	
	system("pause");
	return EXIT_SUCCESS;
}