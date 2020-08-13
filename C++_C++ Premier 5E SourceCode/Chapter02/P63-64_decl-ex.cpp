#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int a = 0;
    decltype(a) c = a;   // c is an int
    decltype((a)) d = a; // d is a reference to a
    ++c;                 // increments c, a (and d) unchanged
    cout << "a: " << a << " c: " << c << " d: " << d << endl;
    ++d; // increments a through the reference d
    cout << "a: " << a << " c: " << c << " d: " << d << endl;

    int A = 0, B = 0;
    decltype((A)) C = A;   // C is a reference to A
    decltype(A = B) D = A; // D is also a reference to A
    ++C;
    cout << "A: " << A << " C: " << C << " D: " << D << endl;
    ++D;
    cout << "A: " << A << " C: " << C << " D: " << D << endl;

    return 0;
}
