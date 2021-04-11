#include <iostream>
using namespace std;

int bad(int n)
{
    if (n == 0)
        return 0;
    else
        return bad(n / 3 + 1) + n - 1; //bad(1)定义bad(1),造成死循环
}

int main()
{
    cout << "bad is infinite recursion" << endl;
    return 0;
}
