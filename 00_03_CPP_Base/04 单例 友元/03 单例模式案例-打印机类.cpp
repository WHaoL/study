#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>

//打印机类
class printer
{
public:
    static printer *getInstance()
    {
        return singlePrinter;
    }

    void printText(string text)
    {
        cout << text << endl;
        m_Count++;
    }

    int m_Count;

private:
    printer() { m_Count = 0; };
    printer(const printer &) {}

    static printer *singlePrinter;
};
printer *printer::singlePrinter = new printer;

void test01()
{
    printer *p1 = printer::getInstance();

    p1->printText("入职申请");
    p1->printText("离职申请");
    p1->printText("调休申请");
    p1->printText("升职申请");

    cout << "打印机使用次数为： " << p1->m_Count << endl;

    printer *p2 = printer::getInstance();

    p2->printText("旅游申请");
    cout << "打印机使用次数为： " << p2->m_Count << endl;
}

int main()
{

    test01();

    system("pause");
    return EXIT_SUCCESS;
}