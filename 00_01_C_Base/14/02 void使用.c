#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1��voidʹ��
void test01()
{
	//�������ǲ����Դ��������ģ���Ϊ��֪����������ڴ�ռ�
	//void a = 10; //error
}

//2���޶������ķ���ֵ ,�޶������β�
int func(void)
{

	return 10;
}

void test02()
{
	//func();
	//printf("%d\n", func()); //error ��������%d��ӡvoid����

	//func(10, 10);
}


//3�� void *
void test03()
{

	printf("sizeof void * = %d\n", sizeof(void *));

	//void * ��Ϊ����ָ��

	void * p = NULL;

	int * pInt = NULL;
	char * pChar = NULL;

	pInt = (int *)pChar; //�����������ȵ�ָ������֮�丳ֵ����Ҫǿ������ת��������������ʾ


	pInt = p; //��������ָ�������ָ�븳ֵʱ�򣬲���Ҫ��ǿת�Ϳ���ֱ�Ӹ�ֵ
	pChar = p;

}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}