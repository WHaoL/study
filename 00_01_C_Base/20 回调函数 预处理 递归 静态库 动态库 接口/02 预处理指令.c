#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1��ͷ�ļ� 
//<> ����ϵͳͷ�ļ�   ""�����Զ���ͷ�ļ�

//2���궨��
//�곣��   ������������
//��������#undef  ж�غ�
//û��������������
void test01()
{
#define MAX 1024
//#undef  MAX //ж�غ�
}

//3����������

//���Դ���
#define  DEBUG
#ifdef  DEBUG

	#if 0  //�Զ�������
	void func()
	{
		printf("DEBUG1�汾\n");
	}
	#else 
	void func()
	{
		printf("DEBUG2�汾\n");
	}
	#endif

#else 
void func()
{
	printf("RELEASE�汾\n");
}

#endif


//�����
void myFunc(char * p)
{
	if (p == NULL)
	{
		printf("�ļ���%s �� %d�� ����\n", __FILE__, __LINE__);
		printf("���ڣ�%s\n", __DATE__); // date ����  data ����
		printf("ʱ�䣺%s\n", __TIME__); 
		return;
	}
}

void test02()
{
	char * p = NULL;
	myFunc(p);
}

int main(){

	//printf("%d\n", MAX);

	//func();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}