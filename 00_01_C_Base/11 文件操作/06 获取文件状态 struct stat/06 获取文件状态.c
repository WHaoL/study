#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <time.h> //ctime��ͷ�ļ�

//stat ����
void test01()
{
	struct stat mystat;
	stat("test.txt", &mystat);

	//��ȡ�ļ���С
	printf("�ļ��Ĵ�СΪ��%d\n", mystat.st_size);


	//��������  
	char * str = ctime(&mystat.st_atime);
	char atime[1024] = { 0 };

	//��ʽ1 
	//strcpy(atime, str);
	//atime[strlen(atime) - 1] = '\0';

	//��ʽ2 
	strncpy(atime, str, strlen(str) - 1);


	printf("%s\n", atime);


	str = ctime(&mystat.st_mtime);
	char mtime[1024] = { 0 };
	strncpy(mtime, str, strlen(str) - 1);
	printf("%s\n", mtime);
}

//�������ļ�  ɾ���ļ�
void test02()
{
	//������
	rename("test.txt", "test2.txt");

	//ɾ��  ����ļ����ڣ�ִ��ɾ������������ڣ�û��Ч��
	remove("aaa.txt");
}

int main(){

	//test01();

	test02();

	system("pause");
	return EXIT_SUCCESS;
}