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
using std::ostream;
using std::shared_ptr;
using std::string;
using std::stringstream;
using std::vector;

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
        shared_ptr<Logger> m_logger;      //日志器-使得LogEvent自己也能找到Logger
    };

    //--------------------日志事件包装器--------------------------//
    // 用LogEvent的智能指针，来管理LogEvent
    // 当LogEventWrap析构时，即管理的LogEvent被释放时，
    //     把LogEvent对象写入到Logger里
    // 即：利用析构函数，触发日志写入到logger中(写完Logger后完善)
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
    //--------------------03日志格式化--------------------------//
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
        class FormatItem //日志内容项格式化
        {
        public:
            typedef shared_ptr<FormatItem> ptr;
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
        void init();                                    //初始化,解析日志模板
        bool isError() const { return m_error; }        //是否有错误
        string getPattern() const { return m_pattern; } //返回日志模板

    private:
        string m_pattern;                //日志格式模板
        vector<FormatItem::ptr> m_items; //日志格式解析后格式
        bool m_error = false;            //是否有错误
    };
    //------------------------------------------------//

};
#endif
