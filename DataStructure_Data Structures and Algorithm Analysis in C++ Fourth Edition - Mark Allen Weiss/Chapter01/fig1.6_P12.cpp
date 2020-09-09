// fig1.6_P12.cpp

#include <iostream>
using namespace std;

//A class for simulating an integer memory cell
class IntCell
{
public:
    //初始化列表中使用{}，而不是传统的()，是C++11新规定的
    explicit IntCell(int initialValue = 0) : storeValue{initialValue}
    {
    }

    //常成员函数
    int read() const
    {
        return storeValue;
    }
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
    IntCell m2{}; //在对单参数构造函数使用了explicit之后，想使用默认参数时，C++11中可以这样写(推荐)
    m.write(5555);
    cout << "m  Cell contents: " << m.read() << endl;
    cout << "m2 Cell contents: " << m2.read() << endl;
    return 0;
}