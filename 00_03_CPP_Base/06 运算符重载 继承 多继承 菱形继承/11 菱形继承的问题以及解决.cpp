#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//������
class Animal
{
public:
	int m_Age;
};

//������̳еķ�ʽ ������μ̳е�����
//������̳к�Animal��Ϊ �����

//����
class Sheep : virtual public Animal{};

//���� 
class Tuo : virtual public Animal{};

//������
class SheepTuo :public Sheep, public Tuo{};

void test01()
{
	SheepTuo st;
	//����һ��ʹ�����ݲ���ȷ�������ʽ��������
	st.Sheep::m_Age = 100;

	st.Tuo::m_Age = 200;

	st.m_Age = 300;

	//�������age������һ�ݾͿ����ˣ������ݵĻ��޷��������ĸ��ʺϣ����������Դ�˷�

	cout << st.Sheep::m_Age << endl;
	cout << st.Tuo::m_Age << endl;
}

void test02()
{
	SheepTuo st;
	st.m_Age = 100;

	//ͨ��Sheep�ҵ���Ӧ��ƫ����
	// *(int*)&st �����ҵ�Sheep��vbtable��
	cout << "ͨ��sheep�ҵ���ƫ�ƣ� "<< *((int *)*(int*)&st + 1) << endl;

	//ͨ��Tuo�ҵ���Ӧ��ƫ��
	//*((int *)&st + 1) �����ҵ�Tuo��Ӧ��vbtable
	cout << "ͨ��Tuo�ҵ���ƫ�ƣ� " << *((int *)*((int *)&st + 1) + 1) << endl;

	//ͨ��ƫ�� ����age����
	cout << "m_Age = " << *((int *)((char *)&st + *((int *)*(int*)&st + 1))) << endl;

	cout << "m_Age = " << ((Animal *)((char *)&st + *((int *)*(int*)&st + 1)))->m_Age << endl;
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}