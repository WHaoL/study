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
#include "singleton.h"
#include <time.h>

//--------------------
using std::list;
using std::map;
using std::ofstream;
using std::ostream;
using std::shared_ptr;
using std::string;
using std::stringstream;
using std::vector;

//---------------------------------------------------------------------------------------------------------------
//使用流式方式将日志级别level的日志写入到logger
#define SYLAR_LOG_LEVEL(logger, level, ThreadName)                                                            \
    if (logger->getLevel() <= level)                                                                          \
    sylar::LogEventWarp(sylar::LogEvent::ptr(new sylar::LogEvent(logger, level,                               \
                                                                 __FILE__, __LINE__, 0, sylar::GetThreadId(), \
                                                                 sylar::GetFiberId(), time(0), ThreadName)))  \
        .getSS()
#define SYLAR_LOG_DEBUG(logger, ThreadName) SYLAR_LOG_LEVEL(logger, sylar::LogLevel::DEBUG, ThreadName)
#define SYLAR_LOG_INFO(logger, ThreadName) SYLAR_LOG_LEVEL(logger, sylar::LogLevel::INFO, ThreadName)
#define SYLAR_LOG_WARN(logger, ThreadName) SYLAR_LOG_LEVEL(logger, sylar::LogLevel::WARN, ThreadName)
#define SYLAR_LOG_ERROR(logger, ThreadName) SYLAR_LOG_LEVEL(logger, sylar::LogLevel::ERROR, ThreadName)
#define SYLAR_LOG_FATAL(logger, ThreadName) SYLAR_LOG_LEVEL(logger, sylar::LogLevel::FATAL, ThreadName)
//---------------------------------------------------------------------------------------------------------------
//使用格式化方式将日志级别level的日志写入到logger
#define SYLAR_LOG_FMT_LEVEL(logger, level, ThreadName, fmt, ...)                                              \
    if (logger->getLevel() <= level)                                                                          \
    sylar::LogEventWarp(sylar::LogEvent::ptr(new sylar::LogEvent(logger, level,                               \
                                                                 __FILE__, __LINE__, 0, sylar::GetThreadId(), \
                                                                 sylar::GetFiberId(), time(0), ThreadName)))  \
        .getEvent()                                                                                           \
        ->format(fmt, __VA_ARGS__)
#define SYLAR_LOG_FMT_DEBUG(logger, ThreadName, fmt, ...) SYLAR_LOG_FMT_LEVEL(logger, sylar::LogLevel::DEBUG, ThreadName, fmt, __VA_ARGS__)
#define SYLAR_LOG_FMT_INFO(logger, ThreadName, fmt, ...) SYLAR_LOG_FMT_LEVEL(logger, sylar::LogLevel::INFO, ThreadName, fmt, __VA_ARGS__)
#define SYLAR_LOG_FMT_WARN(logger, ThreadName, fmt, ...) SYLAR_LOG_FMT_LEVEL(logger, sylar::LogLevel::WARN, ThreadName, fmt, __VA_ARGS__)
#define SYLAR_LOG_FMT_ERROR(logger, ThreadName, fmt, ...) SYLAR_LOG_FMT_LEVEL(logger, sylar::LogLevel::ERROR, ThreadName, fmt, __VA_ARGS__)
#define SYLAR_LOG_FMT_FATAL(logger, ThreadName, fmt, ...) SYLAR_LOG_FMT_LEVEL(logger, sylar::LogLevel::FATAL, ThreadName, fmt, __VA_ARGS__)

//---------------------------------------------------------------------------------------------------------------

//--------------------
namespace sylar
{
    class Logger;
    class LoggerManager;

    //--------------------01日志级别--------------------------//
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

    //--------------------02日志事件--------------------------//
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

        string getContent() const { return m_ss.str(); } //获取日志内容
        stringstream &getSS() { return m_ss; }           //注意：返回的是引用！！！！！！ 所以能在外部通过这个函数，直接输入内容
        // 因为m_ss不是固定的
        // 所以：设置m_ss时，传入的参数必须是可变的
        // 所以专门写了两个format()用于填充m_ss
        void format(const char *fmt, ...);        //格式化写入日志内容
        void format(const char *fmt, va_list al); //格式化写入日志内容
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
        shared_ptr<Logger> m_logger;      //日志器-使得LogEvent自己也能找到Logger
    };

    //--------------------08日志事件包装器--------------------------//
    // 用LogEvent的智能指针，来管理LogEvent
    // 当LogEventWrap析构时，即管理的LogEvent被释放时，
    //     把LogEvent对象写入到Logger里
    // 即：利用析构函数，触发日志写入到logger中,
    // 此时Logger()->log()写日志
    class LogEventWarp
    {
    public:
        LogEventWarp(LogEvent::ptr e);
        ~LogEventWarp();
        LogEvent::ptr getEvent() const { return m_event; }
        stringstream &getSS();

    private:
        LogEvent::ptr m_event;
    };
    //--------------------03-1日志格式化--------------------------//
    class LogFormatter
    {
    public:
        typedef shared_ptr<LogFormatter> ptr;
        /**
        * @brief 构造函数
        * @param[in] pattern 格式模板
        * @details 
        *  %m 消息
        *  %p 日志级别
        *  %r 累计毫秒数
        *  %c 日志名称
        *  %t 线程id
        *  %n 换行
        *  %d 时间
        *  %f 文件名
        *  %l 行号
        *  %T 制表符
        *  %F 协程id
        *  %N 线程名称
        *
        *  默认格式 "%d{%Y-%m-%d %H:%M:%S}%T%t%T%N%T%F%T[%p]%T[%c]%T%f:%l%T%m%n"
        */
        LogFormatter(const string &pattern);

        /**
         * @brief 返回格式化日志文本
        * @param[in] logger 日志器
        * @param[in] level 日志级别
        * @param[in] event 日志事件
        */
        string format(shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event);
        ostream &format(ostream &ofs, shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event);

    public:
        //--------------------03-2日志内容项格式化--------------------------//
        class FormatItem //日志内容项格式化
        {
        public:
            typedef std::shared_ptr<FormatItem> ptr;
            virtual ~FormatItem() {}
            /**
            * @brief 格式化日志到流
            * @param[in, out] os 日志输出流
            * @param[in] logger 日志器
            * @param[in] level 日志等级
            * @param[in] event 日志事件
            */
            virtual void format(ostream &os, shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) = 0;
        };

    public:
        void init();                                          //初始化,解析日志模板
        bool isError() const { return m_error; }              //是否有错误
        const string getPattern() const { return m_pattern; } //返回日志模板

    private:
        string m_pattern;                //日志格式模板
        vector<FormatItem::ptr> m_items; //日志格式解析后 得到一个个的FormatItem的子对象 代表着一个个子格式
        bool m_error = false;            //是否有错误-默认没错误-解析出错时 设置为true
    };
    //------------------------------------------------//

    //--------------------04-1日志输出地--------------------------//
    //日志输出地-基类
    class LogAppender
    {

        friend class Logger;

    public:
        typedef shared_ptr<LogAppender> ptr;
        virtual ~LogAppender() {}

        // 写入日志（纯虚函数  抽象接口）
        virtual void log(shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) = 0;

        void setFormatter(LogFormatter::ptr val); //更改日志格式器
        LogFormatter::ptr getFormatter();         //获取日志格式器

        //获取日志级别
        LogLevel::Level getLevel() const { return m_level; }
        //设置日志级别
        void setLevel(LogLevel::Level level) { m_level = level; }

    protected:
        LogLevel::Level m_level = LogLevel::DEBUG; //日志级别
        LogFormatter::ptr m_formatter = nullptr;   //日志格式器
        bool m_hasFormatter = false;               //是否有自己的日志格式器
    };

    //--------------------04-2输出到控制台的Appender
    class StdoutLogAppender : public LogAppender
    {
    public:
        typedef shared_ptr<StdoutLogAppender> ptr;
        void log(shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override;
    };

    //--------------------04-3输出到文件的Appender
    class FileLogAppender : public LogAppender
    {
    public:
        typedef shared_ptr<FileLogAppender> ptr;
        FileLogAppender(const string &filename); //设置文件名
        void log(shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override;
        bool reopen(); //重新打开日志文件，文件打开成功返回true

    private:
        string m_filename;           //文件路径+文件名
        ofstream m_filestream;       //文件流
        uint64_t m_lastOpenTime = 0; //上次重新打开的时间
    };

    //--------------------05日志器--------------------------//
    //日志器
    class Logger : public std::enable_shared_from_this<Logger>
    {

        friend class LoggerManager;

    public:
        typedef std::shared_ptr<Logger> ptr;

        Logger(const std::string &name = "root");

        void log(LogLevel::Level level, LogEvent::ptr event); //写日志
        void debug(LogEvent::ptr event);                      //写DEBUG级别日志
        void info(LogEvent::ptr event);
        void warn(LogEvent::ptr event);
        void error(LogEvent::ptr event);
        void fatal(LogEvent::ptr event);

        void addAppender(LogAppender::ptr appender);
        void delAppender(LogAppender::ptr appender);
        void clearAppenders();

        LogLevel::Level getLevel() const { return m_level; }
        void setLevel(LogLevel::Level val) { m_level = val; }

        const string &getLoggerName() const { return m_LoggerName; }

        LogFormatter::ptr getFormatter();
        void setFormatter(LogFormatter::ptr val); //给appender设置日志格式器
        void setFormatter(const string &val);     //给appender设置日志格式器

    private:
        string m_LoggerName;                //日志名称
        LogLevel::Level m_level;            //日志级别
        list<LogAppender::ptr> m_appenders; //Appender集合-日志目标集合
        LogFormatter::ptr m_formatter;      //日志格式器
        Logger::ptr m_root;                 //主日志器
    };

    //--------------------06日志器管理类--------------------------//
    class LoggerManager
    {
    public:
        LoggerManager();
        //根据日志器名称，获取日志器
        Logger::ptr getLogger(const string &name);
        //初始化
        void init();
        //返回主日志器
        Logger::ptr getRootLogger() const { return m_rootLogger; }

    private:
        map<string, Logger::ptr> m_loggers;
        Logger::ptr m_rootLogger;
    };
    //--------------------07日志器管理类单例模式--------------------------//
    // singleton.h
    typedef sylar::Singleton<LoggerManager> LoggerMgr;
    //------------------------------------------------//
    //------------------------------------------------//
    //------------------------------------------------//
    //------------------------------------------------//
    //------------------------------------------------//
    //------------------------------------------------//
    //------------------------------------------------//
    //------------------------------------------------//
    //------------------------------------------------//
    //------------------------------------------------//
    //------------------------------------------------//

};
#endif
