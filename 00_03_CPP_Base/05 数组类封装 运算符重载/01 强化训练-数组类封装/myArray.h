#ifndef __MYARRAY_H__
#define __MYARRAY_H__

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyArray
{
public:
    //����ӿ�
    //Ĭ�Ϲ���  ��ʼ������Ϊ100
    MyArray();

    //�вι���  �û�ָ������
    MyArray(int capacity);

    //��������
    MyArray(const MyArray &arr);

    //����λ����������
    void setData(int pos, int data);

    //����λ�û�ȡ����
    int getData(int pos);

    //β��
    void pushBack(int data);

    //��ȡ��������
    int getCapacity();

    //��ȡ�����С
    int getSize();

    //����[]�����
    int &operator[](int pos);

    //��������
    ~MyArray();

    //��Ա����
private:
    int m_Capacity; //��������--����һ�������ɶ��ٸ�Ԫ��

    int m_Size; //�����С--��ǰ�ж��ٸ�Ԫ��

    int *pAddress; //ά���ײ���ʵ�����ָ��--ָ��洢���ݵĿռ�
};

#endif
