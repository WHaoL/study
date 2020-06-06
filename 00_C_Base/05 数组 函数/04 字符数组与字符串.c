#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�ַ����鶨�巽ʽ
void test01()
{
	char ch[5]; //�����ַ����� ��ÿ��Ԫ���� char���ͣ�һ����5��Ԫ��
	printf("sizeof = %d\n", sizeof(ch));
}

//�����ַ�����
void test02()
{
	//�����ʼ���ַ�����
	//char arr[5] = { 'h', 'e', 'l', 'l', 'o' }; //error ��Ϊû��\0 �������
	//char arr[6] = { 'h', 'e', 'l', 'l', 'o','\0' }; // '\0' ���ʾ���0

	char arr[] = "hello"; //�Դ� \0

	//�����ַ�����
	//for (int i = 0; i < sizeof(arr) / sizeof(char); i++)
	//{
	//	printf("%c", arr[i]);
	//}
	//printf("\n");

	printf("%s\n", arr); //%s �ӿ�ʼ arr  ������ \0
}

//�ַ���ͳ��
void  test03()
{
	char buf1[32] = "hello world";

	printf("%d\n", strlen(buf1));//strlen(�ַ�������) ͳ���ַ�������  ��ͳ��\0
	printf("%d\n", sizeof(buf1));//ͳ������ռ���ڴ�ռ��С


	char buf2[] = "hello world";
	printf("buf2 strlen = %d\n", strlen(buf2));//11
	printf("buf2 sizeof = %d\n", sizeof(buf2));//12

	char buf3[] = "hello\0world";
	printf("buf3 strlen = %d\n", strlen(buf3));//5  ͳ�Ƶ�\0����
	printf("buf3 sizeof = %d\n", sizeof(buf3));//12 

	//  / / \\ 1 \123 a b c \xac h e h e
	char buf4[] = "//\\1\123abc\xachehe";

	printf("buf4 strlen = %d\n", strlen(buf4));//13
	printf("buf4 sizeof = %d\n", sizeof(buf4));//13 + 1 = 14

}


//�ַ���������
void test04()
{
	//�����ַ����鲢�ҳ�ʼ��Ϊ��
	//char buf[16] = "";
	char buf[16] = {0};

	scanf("%s", buf); //�����ո� ��������
	printf("%s\n", buf);
}

//gets ���Ƽ�
void test05()
{
	char buf[16] = { 0 };
	gets(buf);
	//��������ո����ַ�������
	//�����������Ƿ������һ�������Խ�磩�ǳ������ڴ棬������ֹ
	printf("%s\n", buf);
}

//fgets() �Ƽ�
void test06()
{
	char buf[16] = { 0 };
	fgets(buf, sizeof(buf), stdin); //stdin��׼�����豸 �������
	printf("%s\n", buf);
}

//�ַ������ puts  fputs
void test07()
{
	char buf[16] = "hello world";

	printf("%s\n", buf); //����
	puts(buf); //�Դ�����
	fputs(buf, stdout); //stdout�����׼����豸 ��Ļ   ��������

}


int main(){

	test07();

	system("pause");
	return EXIT_SUCCESS;
}