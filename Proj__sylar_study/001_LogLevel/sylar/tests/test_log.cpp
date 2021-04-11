#include "../sylar/log.h"
#include <iostream>
using std::cout;
using std::endl;

//------------------------------------------------//
void test_01_LogLevel();

//------------------------------------------------//
int main()
{
    test_01_LogLevel();
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