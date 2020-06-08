#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//抽象CPU类
class CPU
{
public:
	//计算
	virtual void calculate() = 0;
};
//抽象显卡
class VideoCard
{
public:
	//显示
	virtual void display() = 0;
};

//抽象内存条
class Memory
{
public:
	virtual void storage() = 0;
};

//电脑类
class Computer
{
public:
	Computer(CPU * cpu, VideoCard * vc, Memory * mem)
	{
		this->m_CPU = cpu;
		this->m_VC = vc;
		this->m_Mem = mem;
	}

	//电脑工作的函数
	void doWork()
	{
		this->m_CPU->calculate();
		this->m_VC->display();
		this->m_Mem->storage();
	}

	//电脑析构函数
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

//intel厂商
class intelCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel的CPU开始计算了" << endl;
	}
};

class intelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel的显卡开始显示了" << endl;
	}
};

class intelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel的内存条开始存储了" << endl;
	}
};

//Lenove厂商
class LenoveCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenove的CPU开始计算了" << endl;
	}
};

class LenoveVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenove的显卡开始显示了" << endl;
	}
};

class LenoveMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenove的内存条开始存储了" << endl;
	}
};

void test01()
{
	CPU * intelCpu = new intelCPU;
	VideoCard * intelVC = new intelVideoCard;
	Memory * intelMem = new intelMemory;

	Computer * computer1 = new Computer(intelCpu, intelVC, intelMem);
	cout << "第一台电脑组装结果为： " << endl;
	computer1->doWork();

	delete computer1;


	CPU * LenoveCpu = new LenoveCPU;
	VideoCard * LenoveVC = new LenoveVideoCard;
	Memory * LenoveMem = new LenoveMemory;

	Computer * computer2 = new Computer(LenoveCpu, LenoveVC, LenoveMem);
	cout << "第二台电脑组装结果为： " << endl;
	computer2->doWork();

	delete computer2;


	CPU * cpu = new intelCPU;
	VideoCard * vc = new LenoveVideoCard;
	Memory * mem = new intelMemory;

	Computer * computer3 = new Computer(cpu, vc, mem);
	cout << "第三台电脑组装结果为： " << endl;
	computer3->doWork();
}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}