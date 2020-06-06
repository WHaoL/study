#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//д�ļ�  fputs
void test01()
{
	FILE * fp = fopen("test1.txt", "w");
	if (fp == NULL)
	{
		printf("��ʧ��\n");
		return;
	}

	char *buf[] = { "��ǰ���¹�\n", "���ǵ���˪\n", "��ͷ������\n", "��ͷ˼����\n" };

	for (int i = 0; i < sizeof(buf)/sizeof(char*); i++)
	{
		//����д�ļ�
		fputs(buf[i], fp);
	}

	fclose(fp);
}

void test02()
{
	FILE * fp = fopen("test1.txt", "r");
	if (fp == NULL)
	{
		printf("��ʧ��\n");
		return;
	}

#if 0
	printf("��һ���汾\n");
	char buf[1024] = {0};

	//feof() ����ֵ��int�����Ϊ�棬�����ȡ���ļ�β����û�е��ļ�β
	while (!feof(fp)) //���û�ж�ȡ���ļ�β��ִ��ѭ��
	{
		char * ret = fgets(buf, sizeof(buf), fp);

		if (ret != NULL)
		{
			//����ȡ������Ϣ�е�\n ��Ϊ \0
			buf[strlen(buf) - 1] = '\0';
			printf("%s\n", buf);
		}
		else
		{
			break;
		}

	}
#else
	printf("�ڶ����汾\n");
	char buf[1024] = {0};

	while (fgets(buf, sizeof(buf), fp)) //������ص���NULL�������ȡ���
	{
		buf[strlen(buf) - 1] = '\0';
		printf("%s\n", buf);
	}

#endif

	fclose(fp);
}

int main(){
	test02();


	system("pause");
	return EXIT_SUCCESS;
}