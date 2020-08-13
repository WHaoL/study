#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
    //以“只读访问”方式，将标准输入重定向到 “./data/add_item 文件
    freopen("./data/add_item", "r", stdin);

    Sales_data data1, data2;

    // code to read into data1 and data2
    double price = 0; // price per book, used to calculate total revenue

    // read the first transactions: ISBN, number of books sold, price per book
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    // calculate total revenue from price and units_sold
    data1.revenue = data1.units_sold * price;

    // read the second transaction
    std::cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    // code to check whether data1 and data2 have the same ISBN
    //        and if so print the sum of data1 and data2
    if (data1.bookNo == data2.bookNo)
    {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;

        // print: ISBN, total sold, total revenue, average price per book
        std::cout << data1.bookNo << " " << totalCnt
                  << " " << totalRevenue << " ";
        if (totalCnt != 0)
            std::cout << totalRevenue / totalCnt << std::endl;
        else
            std::cout << "(no sales)" << std::endl;

        return 0; // indicate success
    }
    else
    { // transactions weren't for the same ISBN
        std::cerr << "Data must refer to the same ISBN"
                  << std::endl;
        return -1; // indicate failure
    }
}
