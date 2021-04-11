#include <iostream>

#include "../sylar/log.h"
#include "../sylar/util.h"

using std::cout;
using std::endl;

//------------------------------------------------//
void test_01_LogLevel();
void test_02_LogEvent();

//------------------------------------------------//
int main()
{
    //test_01_LogLevel();
    test_02_LogEvent();
    return 0;
}

//------------------------------------------------//
void test_01_LogLevel()
{
    string level = "warn";
    cout << sylar::LogLevel::StringToLevel(level) << endl; // 3

    sylar::LogLevel::Level m_level = sylar::LogLevel::WARN;
    cout << sylar::LogLevel::LevelToString(m_level) << endl; //WARN
}
void test_02_LogEvent()
{
    sylar::LogEvent::ptr event(
        new sylar::LogEvent(nullptr, sylar::LogLevel::DEBUG,
                            __FILE__, __LINE__, 0,
                            sylar::GetThreadId(), sylar::GetFiberId(), time(0),
                            "test_log"));
    event->format("test_fmt: %s", "HHHHHHHKKKKKLLLLLIIOHJHKJHJK");
    cout << "Filename\t" << event->getFilename() << endl
         << "Line\t\t" << event->getLine() << endl
         << "ThreadId\t" << event->getThreadId() << endl
         << "ThreadName\t" << event->getThreadName() << endl
         << "FiberId\t\t" << event->getFiberId() << endl
         << "Time\t\t" << event->getTime() << endl
         << "Level\t\t" << sylar::LogLevel::LevelToString(event->getLevel()) << endl // 此处参考void test_01_LogLevel()
         << "Content\t" << event->getContent() << endl;
}