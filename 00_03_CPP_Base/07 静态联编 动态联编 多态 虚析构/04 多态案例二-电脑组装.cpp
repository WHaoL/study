#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//����CPU��
class CPU
{
public:
	//����
	virtual void calculate() = 0;
};
//�����Կ�
class VideoCard
{
public:
	//��ʾ
	virtual void display() = 0;
};

//�����ڴ���
class Memory
{
public:
	virtual void storage() = 0;
};

//������
class Computer
{
public:
	Computer(CPU * cpu, VideoCard * vc, Memory * mem)
	{
		this->m_CPU = cpu;
		this->m_VC = vc;
		this->m_Mem = mem;
	}

	//���Թ����ĺ���
	void doWork()
	{
		this->m_CPU->calculate();
		this->m_VC->display();
		this->m_Mem->storage();
	}

	//������������
	~Computer()
	{
		if (this->m_CPU != NULL)
		{
			delete this->m_CPU;
			this->m_CPU = NULL;
		}
		if (this->m_VC != NULL)
		{
			delete this->m_VC;
			this->m_VC = NULL;
		}
		if (this->m_Mem != NULL)
		{
			delete this->m_Mem;
			this->m_Mem = NULL;
		}
	}

	CPU * m_CPU;
	VideoCard * m_VC;
	Memory * m_Mem;
};

//intel����
class intelCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel��CPU��ʼ������" << endl;
	}
};

class intelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel���Կ���ʼ��ʾ��" << endl;
	}
};

class intelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel���ڴ�����ʼ�洢��" << endl;
	}
};

//Lenove����
class LenoveCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenove��CPU��ʼ������" << endl;
	}
};

class LenoveVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenove���Կ���ʼ��ʾ��" << endl;
	}
};

class LenoveMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenove���ڴ�����ʼ�洢��" << endl;
	}
};

void test01()
{
	CPU * intelCpu = new intelCPU;
	VideoCard * intelVC = new intelVideoCard;
	Memory * intelMem = new intelMemory;

	Computer * computer1 = new Computer(intelCpu, intelVC, intelMem);
	cout << "��һ̨������װ���Ϊ�� " << endl;
	computer1->doWork();

	delete computer1;


	CPU * LenoveCpu = new LenoveCPU;
	VideoCard * LenoveVC = new LenoveVideoCard;
	Memory * LenoveMem = new LenoveMemory;

	Computer * computer2 = new Computer(LenoveCpu, LenoveVC, LenoveMem);
	cout << "�ڶ�̨������װ���Ϊ�� " << endl;
	computer2->doWork();

	delete computer2;


	CPU * cpu = new intelCPU;
	VideoCard * vc = new LenoveVideoCard;
	Memory * mem = new intelMemory;

	Computer * computer3 = new Computer(cpu, vc, mem);
	cout << "����̨������װ���Ϊ�� " << endl;
	computer3->doWork();
}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}