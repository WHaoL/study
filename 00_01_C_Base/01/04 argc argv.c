#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�����д������
//argc �����б�������  
//argv ������������
int main(int argc ,char * argv[])
{
	printf("�����б������� = %d\n", argc);

	//���������������1
	//-std = c99
	if (argc > 1)
	{
		//����ѭ�� ��ӡ���������������ʲô��Ϣ
		//int i = 0;
		for (int i = 0; i < argc;i++)
		{
			printf("%s\n", argv[i]);
		}
	}

	system("pause");
	return EXIT_SUCCESS;
}

