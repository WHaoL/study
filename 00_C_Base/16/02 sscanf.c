#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//sscanf
//1��%*s��%*d	��������
void test01()
{
	char * str = "12345abcde";

	char buf[1024] = { 0 };

	sscanf(str, "%*d%s", buf);

	printf("buf:%s\n", buf);
}

void test02()
{
	char * str = "abcde12345"; //�����ո��������\t �������� 

	char buf[1024] = { 0 };

	//sscanf(str, "%*s%s", buf);

	sscanf(str, "%*[a-z]%s", buf);

	printf("buf:%s\n", buf);
}


//2��%[width]s	��ָ����ȵ�����
void test03()
{
	char * str = "12345abcde";

	char buf[1024] = { 0 };

	sscanf(str, "%6s", buf);

	printf("buf:%s\n", buf);
}

//3��%[a-z]	ƥ��a��z�������ַ�(�����ܶ��ƥ��)
void test04()
{
	char * str = "12345abcde";

	char buf[1024] = { 0 };
	//���ƥ��ʧ�ܣ��Ͳ���������ƥ��
	sscanf(str, "%*d%[a-z]", buf);

	printf("buf:%s\n", buf);
}

//4��%[aBc]	ƥ��a��B��c��һԱ��̰����
void test05()
{
	char * str = "aaBbcde12345";

	char buf[1024] = { 0 };

	sscanf(str, "%[abc]", buf);

	printf("buf:%s\n", buf);
}

//5��%[^a] 	ƥ���a�������ַ���̰����  
//%[^a-z]	��ʾ��ȡ��a-z����������ַ�
void test06()
{
	char * str = "aaBbcde12345";

	char buf[1024] = { 0 };

	sscanf(str, "%[^0-9]", buf);

	printf("buf:%s\n", buf);

}

//����1 ����ip��ַ  127.0.0.1 ������ַ����е�ÿ�����ֱַ�ŵ�num1 ~ num4��
void test07()
{
	char * ip = "127.0.0.1";

	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;

	sscanf(ip, "%d.%d.%d.%d", &num1, &num2, &num3, &num4);

	printf("num1 = %d\n", num1);
	printf("num2 = %d\n", num2);
	printf("num3 = %d\n", num3);
	printf("num4 = %d\n", num4);
}

//����2 ��ȡ��Ч��Ϣ
void test08()
{
	char * str = "abcde#zhangtao@12345;aldkj";

	char buf[1024] = { 0 };

	sscanf(str, "%*[^#]#%[^@]",buf);

	printf("buf = %s\n", buf);

}

//����3 �Ѹ����ַ���Ϊ: helloworld@itcast.cn,�����ʵ��helloworld�����itcast.cn���
void test09()
{
	char * str = "helloworld@itcast.cn";

	char buf1[1024] = { 0 };
	char buf2[1024] = { 0 };

	sscanf(str, "%[a-z]%*[@]%s", buf1, buf2);

	printf("%s\n", buf1);
	printf("%s\n", buf2);
}

int main(){
	test09();


	system("pause");
	return EXIT_SUCCESS;
}