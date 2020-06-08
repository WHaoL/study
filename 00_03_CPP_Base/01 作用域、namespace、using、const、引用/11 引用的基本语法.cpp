#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//���ã������������
//�﷨������  & ���� = ԭ��
void test01()
{
	int a = 10;

	int &b = a;

	b = 20;

	cout << a << endl;
	cout << b << endl;
}

//���ñ����ʼ��
void test02()
{
	int a = 10;
	//int &b;  err �����ʼ������
	int &b = a;

	//����һ����ʼ���󣬲����Ըı����õ�ָ��
	int c = 20;
	b = c; //�����ٸı����ã�ֻ��ͨ�����ö�ԭ�������и�ֵ

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

//���������������
void test03()
{
	//1���ȶ�����������ͣ���ͨ�����Ͷ�������
	int arr[5] = { 1, 2, 3, 4, 5 };

	typedef int(ARRAY_TYPE)[5];
	//����  & ���� = ԭ��
	ARRAY_TYPE & pArr = arr;
	for (int i = 0; i < 5;i++)
	{
		cout << pArr[i] << endl;
	}


	//2���ȶ����������õ����ͣ���ͨ�����Ͷ�������
	typedef int(&ARRAY_TYPE_REF)[5];

	ARRAY_TYPE_REF  pArr2 = arr;
	for (int i = 0; i < 5; i++)
	{
		cout << pArr2[i] << endl;
	}

	//3��ֱ�Ӷ�������
	int(&pArr3)[5] = arr;
	for (int i = 0; i < 5; i++)
	{
		cout << pArr3[i] << endl;
	}
}

int main(){
	test03();


	system("pause");
	return EXIT_SUCCESS;
}