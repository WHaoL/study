#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:

	//���캯��
	//1 û�з���ֵ  ����дvoid
	//2 ��������������ͬ
	//3 �����в��������Է�������
	//���캯���ɱ������Զ����ã������ֶ�������ֻ�����һ��
	Person()
	{
		cout << "Person���޲ι��캯������" << endl;
	}
	//��������
	//1 û�з���ֵ  ����дvoid
	//2 ��������������ͬ �ں�����ǰ��� ~ 
	//3 �������в�������˲��ܷ�������
	//���������ɱ������Զ����ã������ֶ�������ֻ�����һ��
	~Person()
	{
		cout << "Person��������������" << endl;
	}
};

void test01()
{
	Person p1;
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}