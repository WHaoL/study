// fig1.11_P18.cpp

#include <iostream>
#include "fig1.7_P14IntCell.h"
using namespace std;
int main()
{
    IntCell *m = new IntCell{0};
    m->write(12345);
    cout << "Cell contents: " << m->read() << endl;

    if (m != nullptr)
    {
        delete m;
        m = nullptr;
        if (m != nullptr)
        {
            delete m;
            m = nullptr;
        }
    }
    return 0;
}