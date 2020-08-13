#include <iostream>

int main()
{
    //以“只读访问”方式，将标准输入重定向到 “./data/add” 文件
    freopen("./data/add", "r", stdin);

    // prompt user to enter two numbers
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2
              << " is " << v1 + v2 << std::endl;
    return 0;
}
