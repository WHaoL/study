#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//mallocͷ�ļ�   stdlib.h
//malloc������ڴ治����գ�����ڴ������������������������󣬲��ͷţ�Ҳ����ͨ��free�ĺ����ͷſռ�
//ͨ���ɳ���Ա�ֶ����٣��ֶ��ͷ�
//malloc���ص��������ڴ�ռ���׵�ַ���������ʧ�ܣ�����NULL

void test01()
{
	int * p = malloc(sizeof(int));

	if (p == NULL)
	{
		printf("��������ڴ�ʧ��\n");
		return;
	}

	//����ɹ��������ڴ�
	memset(p, 0, sizeof(int));

	//������ֵ
	*p = 1000;
	printf("*p = %d\n", *p);

	//�ͷ��ڴ�
	free(p);

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}