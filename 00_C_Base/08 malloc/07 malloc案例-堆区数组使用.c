#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "07 myArray.h"

void test01()
{
	int num = 0;
	int * arr = NULL;
	printf("����������Ԫ�ظ���\n");
	scanf("%d", &num);

	//��������
	allocateSpace(&arr,num);

	//����������Ԫ��
	setArray(arr, num);

	//��ӡ����Ԫ��
	printArray(arr, num);

	//��������
	sortArray(arr, num);
	printf("���������Ľ��Ϊ\n");
	printArray(arr, num);

	//ʣ�����
	printf("��������ֵΪ:%d ��СֵΪ:%d �ܺ�Ϊ:%d ƽ����Ϊ:%d\n",
		getMax(arr, num), getMin(arr, num), getSum(arr, num), getAvgArray(arr, num));

	//�ͷ�����
	freeArray(&arr);

}


int main(){

	test01();


	system("pause");
	return EXIT_SUCCESS;
}