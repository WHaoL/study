#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int myStrstr(char * str , char * subStr)
{
	int num = 0;
	while (*str != '\0')
	{
		//���ָ��ָ������ݲ���d��strƫ�ƣ�ִ����һ��ѭ��
		if (*str != *subStr)
		{
			str++;
			num++;
			continue;
		}

		//����Ĵ��� ����strָ��d֮����߼�
		//����С����ʱָ��
		//memcmp(src,dst,3) == 0;

		char * tmpStr = str;
		char * tmpSubStr = subStr;

		while (*tmpSubStr != '\0')
		{
			if (*tmpStr != *tmpSubStr) //��ʱָ��ָ������ݲ���
			{
				//ƥ��ʧ�� ����
				str++;
				num++;
				break;
			}
			tmpStr++;
			tmpSubStr++;
		}

		//ƥ��ɹ�����
		if (*tmpSubStr == '\0')
		{
			return num;
		}
	}

	return -1;

}

void test01()
{
	char * str = "abcdefgdnfaaaa";

	int ret = myStrstr(str, "dnf");

	if (ret != -1)
	{
		printf("�ҵ����Ӵ���λ���ǣ�%d\n", ret);
	}
	else
	{
		printf("δ�ҵ��Ӵ�\n");
	}
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}