#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//���캯���ķ���
//����������   �޲ι��� (Ĭ�Ϲ���) �� �вι���
//�����ͷ���   ��ͨ����  ��������
class Person
{
public:

	//�޲�
	Person()
	{
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}

	//�в�
	Person(int a)
	{
		cout << "Person���вι��캯������" << endl;
	}

	//��������  ���� -- ����  -- ��¡
	Person( const Person & p)
	{
		cout << "Person�Ŀ������캯������" << endl;
	}

	~Person()
	{
		cout << "Person��������������" << endl;
	}
};

//���캯���ĵ���
void test01()
{
	//Ĭ�Ϲ���
	Person p;
}

void test02()
{
	//1�����ŷ�
	//Person p1(10); //�вι���
	//Person p2(p1);   //��������

	//ע������1  ��Ҫ�������ŷ� ����Ĭ�Ϲ��캯��
	//���ͣ�Person p3(); ��������Ϊ�Ǻ�������������������Ϊ��ʵ��������
	//Person p3(); ���Ǵ�������

	//2����ʾ��
	//Person p1 = Person(10);  //�вι���
	//Person p2 = Person(p1); //��������

	//Person(10);//�������� �ص㣺��ǰ��ִ�й����ɱ������ͷŵ�

	//ע������2 ��Ҫ���ÿ������캯�� ��ʼ����������
	//Person(p2);//��������Ϊ Person(p2);  ��   Person p2

	//3����ʽ��  ��ʽ����ת����  �ɶ��ԱȽϵ� 
	Person p3 = 10;  // Person p3 = Person(10);
	Person p4 = p3;  // Person p4 = Person(p3);
}

int main(){
	test02();


	system("pause");
	return EXIT_SUCCESS;
}