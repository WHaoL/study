#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	//�﷨�� char a = 'a';

	char ch = 'a';//�ַ����� �õ�����������
	
	//��ӡ�ַ�����
	printf("ch = %c\n", ch);
	
	//�鿴�ַ��� ռ���ڴ�ռ��Ƕ��٣���
	printf("sizeof char  = %d\n", sizeof(char)); //1���ֽ�

	//�ַ����� �������¸�ֵ
	ch = 'a';
	printf("ch = %c\n", ch);

	//ch = "abcde"; //��������˫����
	//ch = 'abcde'; //�������ڲ� ֻ����һ���ַ�


	//������д�ŵ��������ݶ��� 0����1  ����ô�ַ�����δ洢������
	//Ϊ�˴洢��Щ�ַ�����ÿ���ַ�����Ӧһ�����֣�Ȼ���ڽ��д洢
	//����һ���ַ������ֹ�ϵ�Ķ��ձ� ASCII���  ������Ϣ������׼����
	//char ����  С���� 
	printf("ch = %d\n", ch);


	char ch2 = 65;
	printf("ch2 = %c\n", ch2); // A 

	//A  ---  65    a --- 97    a-A = 32;

}

//��Сдת������
void test02()
{
	//a  -> A
	char ch = 'a';
	printf("ת��ǰ�� %c\n", ch);

	ch = ch - 32;
	printf("ת���� %c\n", ch);


	// Z  ->  z
	char ch2 = 'Z';
	printf("ת��ǰ�� %c\n", ch2);
	ch2 = ch2 + 32;
	printf("ת���� %c\n", ch2);
}

int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}