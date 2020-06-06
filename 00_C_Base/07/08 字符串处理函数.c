#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1��strcpy  �ַ�������
void test01()
{
	char buf[64] = {0};

	//buf = "hello world";  //error

	////�ַ�����ֵ
	strcpy(buf, "hello world");
	printf("buf = %s\n", buf);

	//strcpy����\0��������
	//strcpy(buf, "hello\0world");
	//printf("buf = %s\n", buf);


	//���Ŀ��ռ䲻�㣬��������쳣��ֹ
	char buf2[10] = { 0 };
	//strcpy(buf2, "hello world"); //error Ŀ��ռ䲻��
	//printf("buf = %s\n", buf2);
}

//2��strncpy
void test02()
{
	char buf[64] = {0};
	strncpy(buf, "hello world", 8);
	printf("buf = %s\n", buf); //hello wo

	char buf2[64] = { 0 };
	strncpy(buf2, "hello\0world", 8);
	printf("buf2 = %s\n", buf2);  //hello

}

//3��strcat  strncat �ַ���ƴ��
void test03()
{
	char buf1[64] = "hello";  //hello world\0
	char buf2[64] = " world";

	strcat(buf1, buf2);
	printf("%s\n", buf1); //hello world

	strncat(buf1, buf2, 3);
	printf("%s\n", buf1);  //hello world wo
}


//4��strcmp  �ַ����Ա�
void test04()
{
	char buf1[64] = "hello";
	printf("%s\n", buf1);

	printf("������һ���ַ���\n");
	char buf2[64] = "";

	fgets(buf2, sizeof(buf2), stdin);

	//hello\n ��\n��Ϊ\0
	buf2[strlen(buf2) - 1] = '\0';

	if ( strcmp(buf1,buf2) ==0) //ʹ�ñȽ϶�
	{
		printf("buf1 == buf2\n");
	}
	else if (strcmp(buf1, buf2) == 1)  //���ʷ��ص���1
	{
		printf("buf1 > buf2\n");
	}
	else if (strcmp(buf1, buf2) == -1) //���ʷ���-1
	{
		printf("buf1 < buf2\n");
	}
}

//5�� strncmp �ַ����Ա�
void test05()
{
	printf("������һ������ spring summer autumn winter\n");
	char buf[64] = { 0 };
	fgets(buf, 64, stdin);
	buf[strlen(buf) - 1] = '\0';

	if (strncmp(buf, "spring", 6) == 0)
	{
		printf("����\n");
	}
	else if (strncmp(buf, "summer", 6) == 0)
	{
		printf("����\n");
	}
	else if (strncmp(buf, "autumn", 6) == 0)
	{
		printf("����\n");
	}
	else if (strncmp(buf, "winter", 6) == 0)
	{
		printf("����\n");
	}

}


//sprintf
void test06()
{
	char buf[64] = { 0 };

	//��ʽ��������ַ�����
	//sprintf(buf, "������%d �� %d�� %d��", 2019, 5, 20);
	sprintf(buf, "hello world");
	printf("buf = %s\n", buf);
}

//sscanf �ַ������
void test07()
{
	char msg[1024] = "phone:13690000000;2019/5/20;�û�Ǯ��";

	unsigned long long phone = 0;
	int year = 0;
	int month = 0;
	int day = 0;
	char content[64] = { 0 };

	sscanf(msg, "phone:%llu;%d/%d/%d;%s", &phone, &year, &month, &day, content);

	printf("%llu\n", phone);
	printf("%d\n", year);
	printf("%d\n", month);
	printf("%d\n", day);
	printf("%s\n", content);
}

//strchr �ַ�����
void test08()
{
	char buf[1024] = "zhangtao@sina.com";

	char * ret = strchr(buf, '@');

	if (ret == NULL)
	{
		printf("û��@�ַ�\n");
	}
	else
	{
		printf("��@�ַ�\n");
		printf("λ���� %d\n", ret - buf);
	}
}
//strstr �ַ�������
void test09()
{
	char src[] = "ddddabcd123abcd333abcd";
	//����1  Դ�ַ���   ����2  ���ҵ��ַ���    
	//����ֵ ��Դ�ַ����г���Ŀ���ַ���������ĸ�ĵ�ַ
	char *p = strstr(src, "abcd");
	if (p == NULL)
	{
		printf("û���ҵ�Ŀ���ַ���\n");
	}
	else
	{
		printf("�ҵ���Ŀ���ַ���\n");
		printf("p = %s\n", p);
	}
}

//�ַ������Ұ���
void test10()
{
	/*
	"sb�ϵ� sb sb"
	"**�ϵ� ** **"
	*/

	char buf[1024] = { 0 };
	fgets(buf, sizeof(buf), stdin);
	buf[strlen(buf) - 1] = '\0';

	char * p = buf;
	while (1)
	{
		//"sb�ϵ� sb sb abcde"  
		// p
		char * ret = strstr(p, "sb"); 

		if (ret != NULL) //�ҵ���sb����
		{
			strncpy(ret, "**", 2);
			p = ret + 2;
		}
		else
		{
			break; //û�н��� �˳�ѭ��
		}

	}
	printf("%s\n", buf);
}

//strtok �ַ����ָ�
void test11()
{
	//char buf[1024] = "������:����:����:����:����:�Ǻ�";

	//char* names[64] = { 0 };//��buf�е���Ϣ����:�ָ���뵽�ַ�������names��

	//int i = 0;
	//names[i] = strtok(buf, ":");

	//while ( names[i] != NULL)
	//{
	//	i++;
	//	names[i] = strtok(NULL, ":");
	//}

	////�����ַ�������
	//i = 0;
	//while (names[i] != NULL)
	//{
	//	printf("%s\n", names[i++]);
	//}


	//��� �Ż�����
	char buf[1024] = "������:����:����:����:����:�Ǻ�";

	char* names[64] = { buf,NULL };//��buf�е���Ϣ����:�ָ���뵽�ַ�������names��

	int i = 0;
	while ( (names[i++]= strtok(names[i],":")) != NULL)
	{
		//i++;
	}

	//�����ַ�������
	i = 0;
	while (names[i] != NULL)
	{
		printf("%s\n", names[i++]);
	}

}

void test12()
{
	char buf[1024] = "������:����!����#����******����@@@@�Ǻ�";

	char* names[64] = { buf, NULL };

	int i = 0;
	while ((names[i++] = strtok(names[i], ":!#*@")) != NULL)
	{
		//i++;
	}

	//�����ַ�������
	i = 0;
	while (names[i] != NULL)
	{
		printf("%s\n", names[i++]);
	}

}

//atoi ���ַ���תΪint
void test13()
{
	char buf[1024] = "123abc";

	int num = 0;

	num = atoi(buf);

	printf("%d\n", num);


	//����һ������Ҳ�������� ���ַ���תΪint


	int num1 = 0;
	int num2 = 0;

	sscanf("456 789", "%d %d", &num1,&num2);
	printf("num1 = %d\n", num1);
	printf("num2 = %d\n", num2);

}

int main(){

	test13();

	system("pause");
	return EXIT_SUCCESS;
}