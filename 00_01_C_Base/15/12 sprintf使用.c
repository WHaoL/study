#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//sprintfʹ��
void test01()
{
	char buf[1024] = { 0 };

	int a = 0;
	scanf("%d", &a);
	sprintf(buf, "������%d�� %d�� %d��", a, 6, 6);

	printf("buf = %s\n", buf);


	//�ַ���ƴ��
	memset(buf, 0, 1024);
	char str1[] = "hello";
	char str2[] = "world";
	int len = sprintf(buf, "%s %s", str1, str2);  //sprintf����ֵ���ַ����ĳ���
	printf("buf:%s len:%d\n", buf, len);

	//����ת�ַ���
	memset(buf, 0, 1024);
	int num = 100;
	sprintf(buf, "%d", num);
	printf("buf:%s\n", buf);

}

void test02()
{
	char buf[1024] = { 0 };
	int num = 100;
	//���ÿ�� �Ҷ���
	memset(buf, 0, 1024);
	sprintf(buf, "%8d", num); //���ÿ��Ϊ8  �������Ҷ���
	printf("buf:%s\n", buf);
	printf("buf:1111111111111\n");

	//���ÿ�� �����
	memset(buf, 0, 1024);
	sprintf(buf, "%-8d", num); //���ÿ��Ϊ8  �����������
	printf("buf:%s111\n", buf);
	printf("buf:1111111111111\n");

	////ת��16�����ַ��� Сд
	memset(buf, 0, 1024);
	sprintf(buf, "0x%x", num);
	printf("buf:%s\n", buf); //0x64

	//ת��8�����ַ���
	memset(buf, 0, 1024);
	sprintf(buf, "0%o", num); //0144
	printf("buf:%s\n", buf);

}


int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}