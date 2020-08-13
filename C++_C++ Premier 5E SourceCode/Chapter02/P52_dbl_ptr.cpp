#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int ival = 1024;
    int *pi = &ival; // pi points to an int
    int **ppi = &pi; // ppi points to a pointer to an int
    cout << "The value of ival\n"
         << "direct value: " << ival << "\n"
         << "indirect value: " << *pi << "\n"
         << "doubly indirect value: " << **ppi
         << endl;

    int i = 2;
    int *p1 = &i;    // p1 points to i
    *p1 = *p1 * *p1; // equivalent to i = i * i
    cout << "i  = " << i << endl;

    *p1 *= *p1; // equivalent to i *= i
    cout << "i  = " << i << endl;

    return 0;
}
