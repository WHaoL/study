#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	char * p = malloc(sizeof(char)* 64);

	char *pp = p; //������ʱָ�� ָ��p��������ʱָ�룬�����ƶ�pָ��

	for (int i = 0; i < 10;i++)
	{
		*pp = i + 97;
		printf("%c\n", *pp); // a ~ 97   A ~ 65   0 ~ 48
		pp++; //ָ���ƫ�Ƹı�ָ���ָ���ͷų���
	}

	if (p != NULL)
	{
		free(p);
	}

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}