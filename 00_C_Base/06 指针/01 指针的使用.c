#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//ָ���ʹ��
void test01()
{
	int a = 10;
	//����һ��ָ��
	int* p;
	//������ϵ
	p = &a;

	printf("&a = %d\n", &a);
	printf("p = %d\n", p);


	//ָ��Ĳ���
	*p = 100;
	printf("a = %d\n", a);
	printf("*p = %d\n", *p);

	//ע�⣺��ʹ��ָ��ʱ������ &*��ϣ����Դ����������ε���
	//*p == a ???  *&p  == &a     *p = *&a;   *p = a
}

//ָ��Ĵ�С
void test02()
{
	//��32λ����ϵͳ��  ָ��Ĵ�С��4���ֽ�
	//��64λ����ϵͳ��  ָ��Ĵ�С��8���ֽ�
	printf("sizeof int * = %d\n", sizeof(int *));
	printf("sizeof char * = %d\n", sizeof(char *));
	printf("sizeof float * = %d\n", sizeof(float *));
	printf("sizeof double * = %d\n", sizeof(double *));
}

//��ָ��
void test03()
{
	int * p = NULL; //NULL���ʾ��� 0

	//���ʿ�ָ��Ĵ洢���� �ᱨ��
	//�ڴ��ַ���Ϊ 0 ~ 255֮���ϵͳռ�õ��ڴ棬�û������Է���
	//printf("%d\n", *p); //error ��ָ�벻���Է���
}

//Ұָ��
void test04()
{
	//����ָ�����pָ��Ƿ��ڴ�ռ� 0x1100
	int * p = 0x1100;

	//printf("%d\n", *p);
}

//ע�������Ҫ����δ��ʼ����ָ�����
void test05()
{
	int * p; //Ҳ����Ұָ��
	//*p = 100; //vs Ҳ��gccҲ�� ���ʷǷ��ڴ� ���ᱨ��
	//printf("%d\n", *p);  //error �Ƿ������ڴ�
}

int main(){
	test05();



	system("pause");
	return EXIT_SUCCESS;
}