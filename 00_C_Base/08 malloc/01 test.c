#include <stdio.h>
int g_b = 1000; //��ͨȫ�ֱ���


//ȫ�ֺ���

void func1()
{
	printf("func1������!\n");
}

//��̬����  ֻ���ڱ��ļ���ʹ��
static void func2()
{
	printf("func2������!\n");
}
