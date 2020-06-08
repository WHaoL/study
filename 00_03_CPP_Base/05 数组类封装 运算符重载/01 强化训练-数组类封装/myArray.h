#ifndef __MYARRAY_H__
#define __MYARRAY_H__

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyArray
{
public:
    //对外接口
    //默认构造  初始化容量为100
    MyArray();

    //有参构造  用户指定容量
    MyArray(int capacity);

    //拷贝构造
    MyArray(const MyArray &arr);

    //根据位置设置数据
    void setData(int pos, int data);

    //根据位置获取数据
    int getData(int pos);

    //尾插
    void pushBack(int data);

    //获取数组容量
    int getCapacity();

    //获取数组大小
    int getSize();

    //重载[]运算符
    int &operator[](int pos);

    //析构函数
    ~MyArray();

    //成员属性
private:
    int m_Capacity; //数组容量

    int m_Size; //数组大小

    int *pAddress; //维护底层真实数组的指针
};

#endif
