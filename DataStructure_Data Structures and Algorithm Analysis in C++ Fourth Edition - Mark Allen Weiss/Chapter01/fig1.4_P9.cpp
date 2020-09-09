/* ####################打印一个正整数n########################
    要求：正常顺序显示，即先打印最高位再打印次高位
    分析
    一位数：判断出来是一位数，直接打印
    两位数：先打印十位、再打印个位(一位数：)
    三位数：先打印千位、再打印下面两位(两位数：)
    ...
    可以看出不论是几位数，函数内部形式相同，可以用小的定义大的--->递归函数
    fig1.4_P9.cpp 
*/
#include <iostream>
using namespace std;
void printDigit(int OnePsitiveInteger) //打印一位正整数
{
    cout << OnePsitiveInteger;
}
void printOut(int n) // Print nonnegative n //for example output 90
{
    if (n >= 10)          //先判断是不是多位数，一层层的递归，找到最高位那个数
        printOut(n / 10); //printOut(9)-->printDigit(9%10)-->9
    printDigit(n % 10);   //printDigit(0%10)-->0
}
int main()
{
    printOut(12345678);
    getchar();
    return 0;
}