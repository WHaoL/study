#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "myArray.h"

void test01()
{
    cout << "------test01()���ε��ÿ�ʼ------" << endl;
    MyArray arr1;
    //MyArray arr2(10);
    //MyArray arr3(arr2);
    cout << "-------------------------" << endl;
    cout << "���������� " << arr1.getCapacity() << endl;
    cout << "�����С�� " << arr1.getSize() << endl;

    cout << "-------------------------" << endl;
    arr1.pushBack(100);
    cout << "���������� " << arr1.getCapacity() << endl;
    cout << "�����С�� " << arr1.getSize() << endl;

    cout << "-------------------------" << endl;
    arr1.pushBack(200);
    cout << "���������� " << arr1.getCapacity() << endl;
    cout << "�����С�� " << arr1.getSize() << endl;

    cout << "-------------------------" << endl;
    arr1.pushBack(300);
    cout << "���������� " << arr1.getCapacity() << endl;
    cout << "�����С�� " << arr1.getSize() << endl;

    cout << "-------------------------" << endl;
    arr1.pushBack(400);
    cout << "���������� " << arr1.getCapacity() << endl;
    cout << "�����С�� " << arr1.getSize() << endl;

    cout << "-------------------------" << endl;
    cout << "arr1������" << endl;
    for (int i = 0; i < arr1.getSize(); i++)
    {
        cout << arr1.getData(i) << endl;
    }

    //���õ�һ��Ԫ�ص���ֵΪ1000
    cout << "-------------------------" << endl;
    cout << "arr1���������õ�һ��Ԫ�ص���ֵΪ1000" << endl;
    arr1.setData(0, 1000);
    for (int i = 0; i < arr1.getSize(); i++)
    {
        cout << arr1.getData(i) << endl;
    }

    cout << "-------------------------" << endl;
    MyArray arr2(arr1);
    cout << "arr2������" << endl;
    for (int i = 0; i < arr2.getSize(); i++)
    {
        cout << arr2.getData(i) << endl;
    }
    cout << "------test01()���ε��ý���------" << endl;
}

void test02()
{
    cout << "------test02()���ε��ÿ�ʼ------" << endl;

    MyArray arr(10);

    arr.pushBack(10);
    arr.pushBack(20);
    arr.pushBack(30);

    cout << "��һ������Ϊ�� " << arr.getData(0) << endl;
    cout << "��һ������Ϊ�� " << arr[0] << endl;

    arr[0] = 1000;
    cout << "��һ������Ϊ�� " << arr[0] << endl;

    //Ԥ��С����
    //arr2[0] = 2000;
    //cout << arr2[0] << endl;
    cout << "------test02()���ε��ý���------" << endl;
}

int main()
{
    test01();
    test02();

    system("pause");
    return EXIT_SUCCESS;
}