#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��һ��ʵ�� �����±귽ʽ  []
void copyString1(char* dest,char * src )
{
	int len = strlen(src);
	for (int i = 0; i < len;i++)
	{
		dest[i] = src[i];
	}
	dest[len] = '\0';
}


//�ڶ���ʵ��  �����ַ���ָ��
void copyString2(char* dest, char * src)
{
	while (*src != '\0')
	{
		*dest = *src;

		dest++;
		src++;
	}

	*dest = '\0';
}

//������ 
void copyString3(char* dest, char * src)
{
	while (*dest++ = *src++){}

	//int a = 0;
	//while (a = 0)
	//{
	//	printf("a");
	//}

}

void test01()
{
	char * str = "hello world";

	char buf[1024];

	//���� ��str�е����ݣ������� buf��
	//copyString1(buf,str);
	//copyString2(buf, str);
	copyString3(buf, str);
	printf("buf = %s\n", buf);
}

int main(){

	test01();



	system("pause");
	return EXIT_SUCCESS;
}