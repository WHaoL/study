#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int atk = 100;

void test01()
{
	int atk = 200;
	//�ͽ�ԭ��
	cout << "�ֲ�atk = " << atk << endl;

	//:: �����::ǰû���κ������򣬴���ʹ��ȫ��������
	cout << "ȫ��atk = " << ::atk << endl;
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}