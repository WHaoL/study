#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	//�вι���  �û�ָ������
	explicit MyArray(int capacity)   // MyArray arr (10);
	{
		cout << "�вι������" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];//�����������飬������Ĭ�Ϲ��캯��
	}

	//��������
	MyArray(const MyArray & arr)
	{
		cout << "�������캯������" << endl;
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
		//���ж��Ƿ�������
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

	//����[]
	T& operator[](int pos)
	{
		return this->pAddress[pos];
	}

	//β��
	void push_back(const T & val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//βɾ
	void pop_back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//��ȡ����
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//��ȡ��С
	int getSize()
	{
		return this->m_Size;
	}

	//��������
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			cout << "������������" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	T * pAddress; //ά���ײ���ʵ����������ָ��
	int m_Capacity; //����
	int m_Size; //�����С
};
