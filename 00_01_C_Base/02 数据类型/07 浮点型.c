#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//������

//������ ����
void test01()
{
	//float �������ȣ�ռ��4�ֽ� 
	//double ��˫���ȣ�ռ��8�ֽ�

	printf("sizeof = %d\n",sizeof(3.14));//Ĭ����ΪС����double��������

	printf("sizeof = %d\n", sizeof(3.14f));//����f��Ϊfloat��������
}

//������ ����
void test02()
{
	//float a = 1.111f; //Ĭ��С����� ��ʾ6λ
	//printf("%f\n", a);
	//printf("%.2f\n", a); //����ʾ��λС��

	//double b = 2.222;
	//printf("%lf\n", b);
	//printf("%.3lf\n", b); //��ʾ3λС��

	//float ��ȷ 7��Ч����
	//double ��ȷ 15~16��Ч����
	float PI1 = 3.141592653589793f;
	printf("PI1 = %.10f\n", PI1);
	
	double PI2 = 3.141592653589793;
	printf("PI1 = %.10lf\n", PI2);
}

//������ ��ʾ��ʽ ֮  ��ѧ������
void test03()
{
	float f1 = 3e2; // 3 * 10 ^ 2
	printf("%f\n", f1);
	float f2 = 3e-2;  //  3 * 0.1 ^ 2
	printf("%f\n", f2);

}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}