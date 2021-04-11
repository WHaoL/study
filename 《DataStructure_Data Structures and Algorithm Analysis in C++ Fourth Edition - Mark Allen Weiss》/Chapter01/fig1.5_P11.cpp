// fig1.5_P11.cpp

#include <iostream>
using namespace std;

//A class for simulating an integer memory cell
//一个模拟整数内存单元的类
class IntCell
{
public:
    //Construct the IntCell
    //Initial value is 0
    IntCell()
    {
        storeValue = 0;
    }

    //Construct the IntCell
    //Initial value is initialValue
    IntCell(int initialValue)
    {
        storeValue = initialValue;
    }

    //Return the storeValue
    int read()
    {
        return storeValue;
    }

    //Change the storedvalue to x
    void write(int x)
    {
        storeValue = x;
    }

private:
    int storeValue;
};

int main()
{
    IntCell m;
    m.write(5);
    cout << "Cell contents: " << m.read() << endl;
}
