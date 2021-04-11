#include <iostream>

#include "../sylar/log.h"
#include "../sylar/util.h"

using std::cout;
using std::endl;

//------------------------------------------------//
void test_01_LogLevel();
void test_02_LogEvent();
void test_03_LogFormatter();
void test_04();

//------------------------------------------------//
int main()
{
    // test_01_LogLevel();
    // test_02_LogEvent();
    //test_03_LogFormatter();
    test_04();
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

void test_03_LogFormatter()
{
    // cout << !isalpha('T') << endl << isalpha('%') << endl;

    //sylar::LogFormatter::ptr form1(new sylar::LogFormatter("%d%T%p%T%m%n"));
    sylar::LogFormatter::ptr form2(new sylar::LogFormatter("%d{%Y-%m-%d %H:%M:%S}%T%t%T%N%T%F%T[%p]%T[%c]%T%f:%l%T%m%n%%"));
    //把LogFormatter::init()中的 test输出打开，就可以看到解析步骤
}
void test_04()
{
    //-----------------------------------------------------
    //Logger
    sylar::Logger::ptr logger(new sylar::Logger);

    //StdoutLogAppender
    logger->addAppender(sylar::LogAppender::ptr(new sylar::StdoutLogAppender));

    //FileLogAppender
    sylar::FileLogAppender::ptr file_appender(new sylar::FileLogAppender("./log.txt"));
    sylar::LogFormatter::ptr fmt(new sylar::LogFormatter("%d%T%p%T%m%n"));
    file_appender->setFormatter(fmt);
    file_appender->setLevel(sylar::LogLevel::ERROR);
    logger->addAppender(file_appender);

    //LogEvent
    sylar::LogEvent::ptr event(new sylar::LogEvent(
        logger, sylar::LogLevel::DEBUG,
        __FILE__, __LINE__, 0,
        sylar::GetThreadId(), sylar::GetFiberId(),
        time(0), "test_log"));
    //输入日志内容
    event->getSS() << "——@Hello这是日志内容@——" << endl;

    //直接调用Logger的log()函数 打印日志
    logger->log(sylar::LogLevel::DEBUG, event);
    logger->log(sylar::LogLevel::INFO, event);
    logger->log(sylar::LogLevel::WARN, event);
    logger->log(sylar::LogLevel::ERROR, event);
    logger->log(sylar::LogLevel::FATAL, event);

    //-----------------------------------------------------

    //利用宏
    //使用流式方式将日志级别level的日志写入到logger
    SYLAR_LOG_DEBUG(logger) << "@debug@";
    SYLAR_LOG_INFO(logger) << "@info@";
    SYLAR_LOG_WARN(logger) << "@warn@";
    SYLAR_LOG_ERROR(logger) << "@error@";
    SYLAR_LOG_FATAL(logger) << "@fatal@";

    //利用宏
    //使用格式化方式将日志级别level的日志写入到logger
    SYLAR_LOG_FMT_DEBUG(logger, "test macro fmt error %s", "@debug@");
    SYLAR_LOG_FMT_INFO(logger, "test macro fmt error %s", "@info@");
    SYLAR_LOG_FMT_WARN(logger, "test macro fmt error %s", "@warn@");
    SYLAR_LOG_FMT_ERROR(logger, "test macro fmt error %s", "@error@");
    SYLAR_LOG_FMT_FATAL(logger, "test macro fmt error %s", "@fatal@");

    //-----------------------------------------------------
    auto LL = sylar::LoggerMgr::GetInstance()->getLogger("XX");
    SYLAR_LOG_INFO(LL) << "@XXXXXXXXXXXXXXXXXXXXXX@";
}