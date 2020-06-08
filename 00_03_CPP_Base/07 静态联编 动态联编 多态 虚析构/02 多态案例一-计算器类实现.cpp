#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//��������

//class calculator
//{
//public:
//
//	int getResult(string oper)
//	{
//		if (oper == "+")
//		{
//			return m_A + m_B;
//		}
//		else if (oper == "-")
//		{
//			return m_A - m_B;
//		}
//		else if (oper == "*")
//		{
//			return m_A * m_B;
//		}
//		else if (oper == "/")
//		{
//			return m_A / m_B;
//		}
//	}
//
//	int m_A;
//	int m_B;
//};

//����ԭ��  ����չ���п���  ���޸Ľ��йر�


//���ö�̬ʵ�ּ���������
class AbstractCalculator
{
public:
	//�麯��
	//virtual int getResult()
	//{
	//	return 0;
	//};

	//���麯��
	//��һ���������˴��麯������ô�������޷�ʵ����������
	//������˴��麯���������Ҳ��Ϊ������
	//�������Ҫ��д�����еĴ��麯������������Ҳ���ڳ�����
	virtual int getResult() = 0;
	int m_A;
	int m_B;
};

//�ӷ���������
class PlusCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A + m_B;
	};
};

//������������
class SubCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A - m_B;
	};
};

//�˷���������
class MulCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A * m_B;
	};
};

//��̬�ĺô����ɶ���ǿ����֯��ǿ������չ��ǿ
void test01()
{
	AbstractCalculator * abc;

	//�üӷ�
	abc = new PlusCalculator;
	abc->m_A = 100;
	abc->m_B = 100;

	cout << "ret = " << abc->getResult() << endl;

	delete abc;

	//�ü���
	abc = new SubCalculator;
	abc->m_A = 100;
	abc->m_B = 100;

	cout << "ret = " << abc->getResult() << endl;
	delete abc;

	//�ó˷�
	abc = new MulCalculator;
	abc->m_A = 100;
	abc->m_B = 100;

	cout << "ret = " << abc->getResult() << endl;
	delete abc;
}

class A :public AbstractCalculator
{
public:
	//������಻��д����Ĵ��麯���������޷�ʵ�����������ڳ�����
	virtual int getResult()
	{
		return m_A * m_B;
	};
};

int main(){

	//AbstractCalculator abc;
	PlusCalculator add;
	A a;

	test01();

	system("pause");
	return EXIT_SUCCESS;
}