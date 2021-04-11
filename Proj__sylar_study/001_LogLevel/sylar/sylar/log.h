#ifndef __SYLAR_LOG_H__
#define __SYLAR_LOG_H__

#include <string>
#include <stdint.h>
#include <memory>
#include <list>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <stdarg.h>

using std::string;

namespace sylar
{
    //--------------------日志级别--------------------------//
    class LogLevel
    {
    public:
        enum Level //日志级别枚举
        {
            UNKNOW = 0,
            DEBUG = 1,
            INFO = 2,
            WARN = 3,
            ERROR = 4,
            FATAL = 5
        };

        //将日志级别转成文本
        static const char *LevelToString(LogLevel::Level level);
        //将文本转成日志级别
        static LogLevel::Level StringToLevel(const string &str);
    };
};
#endif
