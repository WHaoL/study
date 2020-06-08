#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	//有参构造  用户指定容量
	explicit MyArray(int capacity)   // MyArray arr (10);
	{
		cout << "有参构造调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];//堆区创建数组，必须有默认构造函数
	}

	//拷贝构造
	MyArray(const MyArray & arr)
	{
		cout << "拷贝构造函数调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Size;i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operato= 
	MyArray& operator=(const MyArray & arr)
	{
		//先判断是否有数据
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	
		return *this;
	}

	//重载[]
	T& operator[](int pos)
	{
		return this->pAddress[pos];
	}

	//尾插
	void push_back(const T & val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//尾删
	void pop_back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//获取容量
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//获取大小
	int getSize()
	{
		return this->m_Size;
	}

	//析构函数
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			cout << "析构函数调用" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	T * pAddress; //维护底层真实堆区的数组指针
	int m_Capacity; //容量
	int m_Size; //数组大小
};
