#include "myArray.h"

//Ĭ�Ϲ���  ��ʼ������Ϊ100
MyArray::MyArray()
{
    cout << "Ĭ�Ϲ��캯������" << endl;
    this->m_Capacity = 100;
    this->m_Size = 0;
    this->pAddress = new int[this->m_Capacity];
}

//�вι���  �û�ָ������
MyArray::MyArray(int capacity)
{
    cout << "�вι��캯������" << endl;
    this->m_Capacity = capacity;
    this->m_Size = 0;
    this->pAddress = new int[this->m_Capacity];
}

//��������
MyArray::MyArray(const MyArray &arr)
{
    cout << "�������캯������" << endl;
    this->m_Capacity = arr.m_Capacity;
    this->m_Size = arr.m_Size;
    //this->pAddress = arr.pAddress;

    this->pAddress = new int[arr.m_Capacity];
    for (int i = 0; i < arr.m_Size; i++)
    {
        this->pAddress[i] = arr.pAddress[i];
    }

    //memcpy(this->pAddress, arr.pAddress, arr.m_Size * sizeof(int));
}

//����λ����������
void MyArray::setData(int pos, int data)
{
	if(pos < 0 || pos > m_Capacity-1)
		return;
    this->pAddress[pos] = data;
}

//����λ�û�ȡ����
int MyArray::getData(int pos)
{
    return this->pAddress[pos];
}

//β��
void MyArray::pushBack(int data)
{
	if(m_Size >= m_Capacity)
		return ;
    
	this->pAddress[this->m_Size] = data;
    this->m_Size++;
}

//��ȡ��������
int MyArray::getCapacity()
{
    return this->m_Capacity;
}

//��ȡ�����С
int MyArray::getSize()
{
    return this->m_Size;
}

//��������
MyArray::~MyArray()
{
    if (this->pAddress != NULL)
    {
        cout << "������������" << endl;
        delete[] this->pAddress;
        this->pAddress = NULL;
    }
}

//����[]�����
int &MyArray::operator[](int pos)
{

    return this->pAddress[pos];
}