#include <iostream>
int main()
{
    int i = 0, &ri = i; // ri is a reference to i
    // ri is just another name for i;
    // this statement prints the value of i twice
    std::cout << i << " " << ri << std::endl;

    i = 5; // changing i is reflected through ri as well
    std::cout << i << " " << ri << std::endl;

    ri = 10; // assigning to ri actually assigns to i
    std::cout << i << " " << ri << std::endl;

    return 0;
}