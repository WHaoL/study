//#define  _CRT_SECURE_NO_WARNINGS //����� ��ֹC4996�Ĵ��󾯸�
//#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> //system������ͷ�ļ�

int main()
{
	//��vs�� ������ʹ�ô�ͳ��C�⺯�� scanf  sprintf  ʹ�þͱ���Ϊ�˷�ֹ������Ҫ����һ����

	//�����ʽ1  ����� #define  _CRT_SECURE_NO_WARNINGS   �Ƽ�������
	//�����ʽ2  #pragma warning(disable:4996)
	//�����ʽ3  �������Ԥ��������Ԥ����������� �� _CRT_SECURE_NO_WARNINGS

	char buf[1024] = { 0 };
	sprintf(buf, "%s", "helloworld");
	printf("%s\n", buf);
	

	system("pause");
	return 0;
}