#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1����������NULL�ͷǷ���ַ�����ڴ�
void test01(){
	//char *p = NULL;
	////��pָ����ڴ����򿽱�����
	//strcpy(p, "1111"); //err

	char *q = 0x1122;
	//��qָ����ڴ����򿽱�����
	strcpy(q, "2222"); //err		
}

int * func()
{
	int a = 10;
	int * p = &a;
	return p;
}

//2��Ұָ��������
void test02()
{
	//ָ�����δ��ʼ��
	//int * p;
	//printf("%d\n", *p);


	//ָ���ͷź�δ�ÿ�
	//int *  p = malloc(sizeof(int));
	//*p = 1000;

	//printf("%d\n", *p);
	//free(p);
	//
	//printf("%d\n", *p); //Ұָ��������Ѿ��ͷ��ˣ�����û���ÿ�
	

	//ָ��Ĳ��� ��Խ�˱�����������
	int * pp = func();
	//printf("*pp = %d\n", *pp);
	//printf("*pp = %d\n", *pp);


	int * p2 = NULL;
	free(p2); //��ָ������ͷ�
	//free(pp); //Ұָ�벻�����ͷŵ�
}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}