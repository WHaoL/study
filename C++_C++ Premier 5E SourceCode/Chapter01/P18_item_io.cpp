#include <iostream>
#include "Sales_item.h"

int main()
{
    //以“只读访问”方式，将标准输入重定向到 “./data/book_sales 文件
    freopen("./data/book_sales", "r", stdin);

    Sales_item book;

    // read ISBN, number of copies sold, and sales price
    std::cin >> book;
    // write ISBN, number of copies sold, total revenue, and average price
    std::cout << book << std::endl;

    return 0;
}

