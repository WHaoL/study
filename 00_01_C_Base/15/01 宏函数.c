#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�ú�������ʽд�� ���꺯��
//�꺯������һЩ���ű�֤�����������
//�꺯��ʹ�ó�����ͨ����һЩ�Ƚ�Ƶ����С�ĺ�����д�ɺ꺯��
//�ŵ㣺����ʡȥ��ͨ��������ջ����ջ��ʱ���ϵĿ���     �Կռ任ʱ��
#define MYADD(x,y) ((x)+(y))

int myAdd(int x,int y)
{
	return x + y;
}

void test01()
{
	int a = 10;
	int b = 20;

	printf("a + b = %d\n", MYADD(a, b)  * 20); // ((10) + (20)) * 20

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}