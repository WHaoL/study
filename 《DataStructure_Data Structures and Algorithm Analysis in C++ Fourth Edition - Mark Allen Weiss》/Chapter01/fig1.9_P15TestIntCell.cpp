// fig1.9_P15TestIntCell.cpp

#include <iostream>
#include "fig1.7_P14IntCell.h"
using namespace std;

int main()
{
    IntCell m;
    m.write(55);
    cout << "Cell contents: " << m.read() << endl;
    return 0;
}