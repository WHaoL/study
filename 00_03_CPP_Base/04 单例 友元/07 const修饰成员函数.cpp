#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:

	Person()
	{
		this->m_A = 1000;
	}

	//ÿ���Ǿ�̬��Ա�����ж����ص������thisָ��
	//  thisָ��ı��� ��һ��ָ�볣��
	//  const Person * const this  
	//  const���εĳ�Ա���� ��Ϊ ������ 
	void showM_A()const
	{
		//this = NULL; thisָ���ָ���ǲ������޸ĵ�
		//this->m_A = 2000; //const�����У�ָ��ָ���ֵ�������޸�
		cout << "showM_A����" << endl;
		this->m_B = 1000;
		cout << "m_A  = " << this->m_A << endl;
	}
	void func()
	{
		//m_A = 1000;
		cout << "func����" << endl;
	}

	int m_A;

	mutable int m_B; //��mutable�ؼ���֮�󣬼�ʹ�ڳ����� �� ������ �У�Ҳ�����޸�
};

void test01()
{
	const Person p1; //const���εĶ��󣬳�Ϊ������
	//p1.m_A = 1000;
	p1.m_B = 1000; //��mutable�ؼ������κ��ڳ���������Ȼ�����޸�

	p1.showM_A(); //������  ���Ե��� ������

	//p1.func();    //������  �����Ե��� ��ͨ��Ա����

}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}