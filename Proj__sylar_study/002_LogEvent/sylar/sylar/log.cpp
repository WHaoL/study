#include <map>
#include <iostream>
#include <iostream>
#include <functional>
#include <time.h>
#include <string.h>

#include "log.h"

using std::string;

namespace sylar
{
    //------------------------------------------------//

    //--------------------日志级别--------------------------//
    //将日志级别转成文本
    const char *LogLevel::LevelToString(LogLevel::Level level)
    {
        switch (level)
        {
#define XX(name)         \
    case LogLevel::name: \
        return #name;    \
        break;
            XX(DEBUG);
            XX(INFO);
            XX(WARN);
            XX(ERROR);
            XX(FATAL);
#undef XX

        default:
            return "UNKNOW";
            break;
        }
        return "UNKNOW";
    }
    //将文本转成日志级别
    LogLevel::Level LogLevel::StringToLevel(const string &str)
    {
#define XX(level, v)            \
    if (str == #v)              \
    {                           \
        return LogLevel::level; \
    }

        XX(DEBUG, debug);
        XX(INFO, info);
        XX(WARN, warn);
        XX(ERROR, error);
        XX(FATAL, fatal);

        XX(DEBUG, DEBUG);
        XX(INFO, INFO);
        XX(WARN, WARN);
        XX(ERROR, ERROR);
        XX(FATAL, FATAL);

        return LogLevel::UNKNOW;
#undef XX
    }

    //--------------------日志事件--------------------------//
    //日志事件
    //每一次的日志输出封装为一个事件

    LogEvent::LogEvent(shared_ptr<Logger> logger, LogLevel::Level level,
                       const char *filename, int32_t line, uint32_t elapse,
                       uint32_t thread_id, uint32_t fiber_id, uint64_t time,
                       const string &thread_name)
        : m_filename(filename),
          m_line(line),
          m_elapse(elapse),
          m_threadId(thread_id),
          m_threadName(thread_name),
          m_fiberId(fiber_id),
          m_time(time),
          m_level(level),
          m_logger(logger)

    {
    }
    void LogEvent::format(const char *fmt, ...) //格式化写入内容
    {
        va_list al;        //创建指向参数的指针
        va_start(al, fmt); //此时al指向第一个可变参数
        format(fmt, al);   //调用下面的format()
        va_end(al);        //释放指针
    }
    void LogEvent::format(const char *fmt, va_list al) //格式化写入内容
    {
        char *buf = nullptr;
        // al中包含了一堆可变参数(用户传入的)
        // vasprintf()根据fmt的格式 从al中提取数据 封装数据
        // 根据封装后的数据大小，为buf动态申请内存，并放入buf
        // 返回值是 封装后的数据长度,失败返回-1
        int len = vasprintf(&buf, fmt, al);
        if (-1 != len)
        {
            m_ss << string(buf, len);
            free(buf);
        }
    }
    //------------------------------------------------//
    //------------------------------------------------//
}