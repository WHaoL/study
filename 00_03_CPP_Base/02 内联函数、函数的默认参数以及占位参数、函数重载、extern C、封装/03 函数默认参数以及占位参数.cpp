#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//����Ĭ�ϲ��� 

//ע������1 �������������һ��Ĭ�ϲ����������λ���𣬺����ֵ��������Ĭ�ϲ���
int func(int a, int b = 20 , int c = 20 )
{
	return a + b + c;
}

void test01()
{
	cout << "ret = " << func(10,30) << endl;
}

//ע������2�� ������������ʵ��ֻ����һ����Ĭ�ϲ�����������ͬʱӵ��
int func2(int a = 10, int b = 10);
int func2(int a, int b)
{
	return a + b;
}

//ռλ����
//�﷨���ں�����ֻд����
//��;��Ŀǰ��˵��ûɶ��;����ѧ����������������ʱ���е���;
//ռλ����  ������Ĭ�ϲ���
void func3(int a , int = 10)
{

}
void test02()
{
	func3(10);
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}