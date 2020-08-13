#include <iostream>
#include "Sales_item.h"

int main()
{
	//以“只读访问”方式，将标准输入重定向到 “./data/add_item” 文件
    freopen("./data/add_item", "r", stdin);

    Sales_item item1, item2;

    std::cin >> item1 >> item2;              //read a pair of transactions
    std::cout << item1 + item2 << std::endl; //print their sum

    return 0;
}
