#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "myArray.h"

void test01()
{
    cout << "------test01()本次调用开始------" << endl;
    MyArray arr1;
    //MyArray arr2(10);
    //MyArray arr3(arr2);
    cout << "-------------------------" << endl;
    cout << "数组容量： " << arr1.getCapacity() << endl;
    cout << "数组大小： " << arr1.getSize() << endl;

    cout << "-------------------------" << endl;
    arr1.pushBack(100);
    cout << "数组容量： " << arr1.getCapacity() << endl;
    cout << "数组大小： " << arr1.getSize() << endl;

    cout << "-------------------------" << endl;
    arr1.pushBack(200);
    cout << "数组容量： " << arr1.getCapacity() << endl;
    cout << "数组大小： " << arr1.getSize() << endl;

    cout << "-------------------------" << endl;
    arr1.pushBack(300);
    cout << "数组容量： " << arr1.getCapacity() << endl;
    cout << "数组大小： " << arr1.getSize() << endl;

    cout << "-------------------------" << endl;
    arr1.pushBack(400);
    cout << "数组容量： " << arr1.getCapacity() << endl;
    cout << "数组大小： " << arr1.getSize() << endl;

    cout << "-------------------------" << endl;
    cout << "arr1遍历：" << endl;
    for (int i = 0; i < arr1.getSize(); i++)
    {
        cout << arr1.getData(i) << endl;
    }

    //设置第一个元素的数值为1000
    cout << "-------------------------" << endl;
    cout << "arr1遍历：设置第一个元素的数值为1000" << endl;
    arr1.setData(0, 1000);
    for (int i = 0; i < arr1.getSize(); i++)
    {
        cout << arr1.getData(i) << endl;
    }

    cout << "-------------------------" << endl;
    MyArray arr2(arr1);
    cout << "arr2遍历：" << endl;
    for (int i = 0; i < arr2.getSize(); i++)
    {
        cout << arr2.getData(i) << endl;
    }
    cout << "------test01()本次调用结束------" << endl;
}

void test02()
{
    cout << "------test02()本次调用开始------" << endl;

    MyArray arr(10);

    arr.pushBack(10);
    arr.pushBack(20);
    arr.pushBack(30);

    cout << "第一个数据为： " << arr.getData(0) << endl;
    cout << "第一个数据为： " << arr[0] << endl;

    arr[0] = 1000;
    cout << "第一个数据为： " << arr[0] << endl;

    //预留小任务
    //arr2[0] = 2000;
    //cout << arr2[0] << endl;
    cout << "------test02()本次调用结束------" << endl;
}

int main()
{
    test01();
    test02();

    system("pause");
    return EXIT_SUCCESS;
}