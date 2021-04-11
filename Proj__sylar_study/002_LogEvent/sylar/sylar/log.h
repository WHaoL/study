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
//--------------------
using std::shared_ptr;
using std::string;
using std::stringstream;

//--------------------
namespace sylar
{
    class Logger;
    class LoggerManager;

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

    //--------------------日志事件--------------------------//
    //日志事件
    //每一次的日志输出封装为一个事件
    class LogEvent
    {
    public:
        typedef shared_ptr<LogEvent> ptr;

        LogEvent(shared_ptr<Logger> logger, LogLevel::Level level,
                 const char *filename, int32_t line, uint32_t elapse,
                 uint32_t thread_id, uint32_t fiber_id, uint64_t time,
                 const string &thread_name);

        const char *getFilename() const { return m_filename; }
        int32_t getLine() const { return m_line; }
        uint32_t getElapse() const { return m_elapse; }
        uint32_t getThreadId() const { return m_threadId; }
        const string &getThreadName() const { return m_threadName; }
        uint32_t getFiberId() const { return m_fiberId; }
        uint64_t getTime() const { return m_time; }
        LogLevel::Level getLevel() const { return m_level; }
        shared_ptr<Logger> getLogger() const { return m_logger; }

        string getContent() const { return m_ss.str(); }
        stringstream &getSS() { return m_ss; }
        // 因为m_ss不是固定的
        // 所以：设置m_ss时，传入的参数必须是可变的
        // 所以专门写了两个format()用于填充m_ss
        void format(const char *fmt, ...);        //格式化写入内容
        void format(const char *fmt, va_list al); //格式化写入内容
    private:
        const char *m_filename = nullptr; //文件名
        int32_t m_line = 0;               //行号
        uint32_t m_elapse = 0;            //程序启动到现在的毫秒数
        uint32_t m_threadId = 0;          //线程ID
        string m_threadName;              //线程名
        uint32_t m_fiberId = 0;           //协程ID
        uint64_t m_time = 0;              //时间戳
        LogLevel::Level m_level;          //日志等级
        stringstream m_ss;                //日志内容-流
        shared_ptr<Logger> m_logger;      //日志器
    };
};
#endif
