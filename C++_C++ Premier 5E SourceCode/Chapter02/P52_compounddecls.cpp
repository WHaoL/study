#include <iostream>
int main()
{
    // i is an int; p is a pointer to int; r is a reference to int
    int i = 1024, *p = &i, &r = i;

    // three ways to print the value of i
    std::cout << i << " " << *p << " " << r << std::endl;

    int j = 42, *p2 = &j;
    int *&pref = p2; // pref is a reference to the pointer p2

    // prints the value of j, which is the int to which p2 points
    std::cout << *pref << std::endl;

    // pref refers to a pointer; assigning &i to pref makes p2 point to i
    pref = &i;
    std::cout << *pref << std::endl; // prints the value of i

    // dereferencing pref yields i, the int to which p2 points;
    *pref = 0; // changes i to 0

    std::cout << i << " " << *pref << std::endl;

    return 0;
}