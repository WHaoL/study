#include <stdio.h>

/*
���ÿ�ݼ�

��������  f5
��ʼִ�в����� ctrl + f5 ��������

��ʽ������  ctrl + k + f   
ע�ʹ���  ctrl + k + c
ȡ��ע��  ctrl + k + u
*/


//�����µĲ��Ժ��� ��ʾsystem����ʹ��
//���Ժ�������Ĭ��ִ�У���Ϊ�������ں�����  main
//��������������� ��Ҫ��main��ȥ����
void test01()
{
	//system("mspaint"); //��ͼ���ߴ�
	//system("calc");//������
	//system("ping www.baidu.com"); //ping�ٶ���ַ
	//system("pause");//�ó�����������׶�  �밴���������
	printf("hello\n");
	printf("hello\n");
	printf("hello\n");
}


int main()
{

	printf("hello world\n");
	printf("hello world\n");

	test01(); //����test01 �������
	
	printf("hello world\n");

	system("pause"); //�ó����������˳�����ǰ�����ô���һ������
	return 0;
}