#include "myArray.h"

//默认构造  初始化容量为100
MyArray::MyArray()
{
    cout << "默认构造函数调用" << endl;
    this->m_Capacity = 100;
    this->m_Size = 0;
    this->pAddress = new int[this->m_Capacity];
}

//有参构造  用户指定容量
MyArray::MyArray(int capacity)
{
    cout << "有参构造函数调用" << endl;
    this->m_Capacity = capacity;
    this->m_Size = 0;
    this->pAddress = new int[this->m_Capacity];
}

//拷贝构造
MyArray::MyArray(const MyArray &arr)
{
    cout << "拷贝构造函数调用" << endl;
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

//根据位置设置数据
void MyArray::setData(int pos, int data)
{
	if(pos < 0 || pos > m_Capacity-1)
		return;
    this->pAddress[pos] = data;
}

//根据位置获取数据
int MyArray::getData(int pos)
{
    return this->pAddress[pos];
}

//尾插
void MyArray::pushBack(int data)
{
	if(m_Size >= m_Capacity)
		return ;
    
	this->pAddress[this->m_Size] = data;
    this->m_Size++;
}

//获取数组容量
int MyArray::getCapacity()
{
    return this->m_Capacity;
}

//获取数组大小
int MyArray::getSize()
{
    return this->m_Size;
}

//析构函数
MyArray::~MyArray()
{
    if (this->pAddress != NULL)
    {
        cout << "析构函数调用" << endl;
        delete[] this->pAddress;
        this->pAddress = NULL;
    }
}

//重载[]运算符
int &MyArray::operator[](int pos)
{

    return this->pAddress[pos];
}