#include <iostream>
#include "Sales_item.h"

int main()
{
    //以“只读访问”方式，将标准输入重定向到 “./data/add_item” 文件
    freopen("./data/add_item", "r", stdin);

    Sales_item item1, item2;

    std::cin >> item1 >> item2;
    // first check that item1 and item2 represent the same book
    if (item1.isbn() == item2.isbn())
    {
        std::cout << item1 + item2 << std::endl;
        return 0; // indicate success
    }
    else
    {
        std::cerr << "Data must refer to same ISBN"
                  << std::endl;
        return -1; // indicate failure
    }
}
