#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�������� ����
void test01()
{
	int num = 0;
	printf("�����¸�num��ֵ\n");

	//scanf(��ʽ�����ݣ��������ݵĵ�ַ)
	//scanf��������Ϊ���ȴ��û�������
	scanf("%d", &num);

	printf("num = %d\n",num);
}

//�ַ�������
void test02()
{
	char ch = 'a';
	printf("�����¸�ch��ֵ\n");
	scanf("%c", &ch);
	printf("ch = %c\n", ch);
}

//����������
void test03()
{
	double d = 0;
	printf("�����¸�d��ֵ\n");
	scanf("%lf", &d);
	printf("d = %.2lf\n", d);
}

//�ַ��� ����
void test04()
{
	char ch[64] = "";
	printf("�����¸�ch��ֵ\n");

	scanf("%s", ch);
	printf("ch = %s\n", ch);
}

void test05()
{
	int num = 0;
	printf("�����¸�num��ֵ\n");
	scanf("%d", &num); //\n
	printf("num = %d\n", num);

	char ch1;
	ch1 =getchar();//�ӻ������л�ȡһ���ַ�

	char ch = 'a';
	printf("�����¸�ch��ֵ\n");
	scanf("%c", &ch);
	printf("ch = %c\n", ch);

	putchar('a'); //����Ļ�д�ӡ1���ַ�
}

int main(){



	//test05();

	system("pause");
	return EXIT_SUCCESS;
}