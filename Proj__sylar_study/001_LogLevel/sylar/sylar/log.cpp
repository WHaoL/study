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

    XX(DEBUG,debug);
    XX(INFO,info);
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

    //------------------------------------------------//
    //------------------------------------------------//
    //------------------------------------------------//
}