#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1�� memset �ڴ渳ֵ
void test01()
{
	char buf[32] = "hello world";
	printf("buf = %s\n", buf);

	//����1  Ŀ���ڴ��׵�ַ   ����2  ���ľ���ֵ   ����3  ��ֵ��С 
	memset(buf, 'a', 32);
	printf("buf = %s\n", buf);

	//��;������ڴ�
	memset(buf, 0, 32);
	printf("buf = %s\n", buf);

}

//2 memcpy �ڴ濽��
void printArray(char * arr , int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%c", arr[i]);
	}
	printf("###\n");
}

void test02()
{
	//�����ַ���
	char dst[64] = { 0 };
	char src[64] = "hello\0world";

	strcpy(dst, src); //����\0��������
	printArray(dst, sizeof(dst)); 

	//�ڴ濽��
	memset(dst, 0, sizeof(dst));
	memcpy(dst, src, sizeof(src)); //��������\0�ͽ���

	printArray(dst, sizeof(dst));

	//��;�������鸳ֵ
	int arr1[5] = { 0 };
	int arr2[5] = { 1, 2, 3, 4, 5 };

	memcpy(arr1, arr2, sizeof(arr2));
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", arr1[i]);
	}
}

//3��memmove �ڴ��ƶ�
void test03()
{
	int arr[5] = { 10, 20, 30, 40, 50 };

	//memcpy(arr + 2, arr + 1, 3 * sizeof(int));

	memmove(arr + 2, arr + 1, 3 * sizeof(int)); //Ч�ʱ�memcpy��΢�ͣ���ȫ

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", arr[i]);
	}
}

//4��memcmp  �ڴ�Ƚ�   
void test04()
{
	char str1[32] = "hello\0world";
	char str2[32] = "hello\0c";

	if (strcmp(str1,str2) == 0)
	{
		printf("���\n");
	}
	else if (strcmp(str1, str2) > 0)
	{
		printf("str1 > str2 \n");
	}
	else
	{
		printf("str1 < str2 \n");
	}

	//��������\0�����Ƚ�
	if (memcmp(str1, str2, sizeof(str1)) == 0)
	{
		printf("���\n");
	}
	else if (memcmp(str1, str2, sizeof(str1)) > 0)
	{
		printf("str1 > str2 \n");
	}
	else
	{
		printf("str1 < str2 \n");
	}

	//�Ա���������
	int arr1[] = { 10, 20, 30, 30, 50 };
	int arr2[] = { 10, 20, 30, 30, 50 };

	if (memcmp(arr1, arr2, sizeof(arr1)) == 0)
	{
		printf("���\n");
	}
	else if (memcmp(arr1, arr2, sizeof(arr1)) > 0)
	{
		printf("arr1 > arr2 \n");
	}
	else
	{
		printf("arr1 < arr2 \n");
	}
    
}


int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}