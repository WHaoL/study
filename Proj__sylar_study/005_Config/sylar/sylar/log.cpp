#include <iostream>
#include <functional>
#include <time.h>
#include <string.h>
#include <vector>
#include <map>
#include <memory>
#include "log.h"
#include "util.h"

//--------------------
using std::cout;
using std::endl;
using std::function;
using std::make_tuple;
using std::map;
using std::ostream;
using std::shared_ptr;
using std::string;
using std::tuple;
using std::vector;

//--------------------

//--------------------
namespace sylar
{
    //------------------------------------------------//
    //--------------------01日志级别--------------------------//
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

    //--------------------02日志事件--------------------------//
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
    //--------------------08日志事件包装器--------------------------//
    LogEventWarp::LogEventWarp(LogEvent::ptr e)
        : m_event(e)
    {
    }
    LogEventWarp::~LogEventWarp()
    {
        m_event->getLogger()->log(m_event->getLevel(),m_event);
    }
    stringstream &LogEventWarp::getSS()
    {
        return m_event->getSS();
    }
    //--------------------03-2日志内容项格式化--------------------------//
    class MessageFormatItem : public LogFormatter::FormatItem
    {
    public:
        MessageFormatItem(const string &str = "") {}
        void format(ostream &os, shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override
        {
            os << event->getContent(); //日志内容
        }
    };
    class LevelFormatItem : public LogFormatter::FormatItem
    {
    public:
        LevelFormatItem(const string &str = "") {}
        void format(ostream &os, shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override
        {
            os << LogLevel::LevelToString(level); //日志等级
        }
    };
    class ElapseFormatItem : public LogFormatter::FormatItem
    {
    public:
        ElapseFormatItem(const string &str = "") {}
        void format(ostream &os, shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override
        {
            os << event->getElapse(); //程序启动到现在的毫秒数
        }
    };
    class LoggerNameFormatItem : public LogFormatter::FormatItem
    {
    public:
        LoggerNameFormatItem(const string &str = "") {}
        void format(ostream &os, shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override
        {
            os << event->getLogger()->getLoggerName(); //本次日志的名字
        }
    };
    class ThreadIdFormatItem : public LogFormatter::FormatItem
    {
    public:
        ThreadIdFormatItem(const string &str = "") {}
        void format(ostream &os, shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override
        {
            os << event->getThreadId(); //线程ID
        }
    };
    class ThreadNameFormatItem : public LogFormatter::FormatItem
    {
    public:
        ThreadNameFormatItem(const string &str = "") {}
        void format(ostream &os, shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override
        {
            os << event->getThreadName(); //线程名
        }
    };
    class FiberIdFormatItem : public LogFormatter::FormatItem
    {
    public:
        FiberIdFormatItem(const string &str = "") {}
        void format(ostream &os, shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override
        {
            os << event->getFiberId(); //协程ID
        }
    };
    class DateTimeFormatItem : public LogFormatter::FormatItem
    {
    public:
        DateTimeFormatItem(const string &fmt = "%Y-%m-%d %H:%M:%S")
            : m_format(fmt)
        {
            if (m_format.empty())
            {
                m_format = "%Y-%m-%d %H:%M:%S";
            }
        }

        void format(ostream &os, shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override
        {
            struct tm tm; // 时间
            time_t time = event->getTime();
            localtime_r(&time, &tm);
            char buf[64];
            strftime(buf, sizeof(buf), m_format.c_str(), &tm);
            os << buf;
        }

    private:
        string m_format;
    };
    class FilenameFormatItem : public LogFormatter::FormatItem
    {
    public:
        FilenameFormatItem(const string &str = "") {}
        void format(ostream &os, shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override
        {
            os << event->getFilename(); //文件名
        }
    };
    class LineFormatItem : public LogFormatter::FormatItem
    {
    public:
        LineFormatItem(const string &str = "") {}
        void format(ostream &os, shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override
        {
            os << event->getLine(); //行号
        }
    };
    class NewLineFormatItem : public LogFormatter::FormatItem
    {
    public:
        NewLineFormatItem(const string &str = "") {}
        void format(ostream &os, shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override
        {
            os << endl; //换行
        }
    };
    class TabFormatItem : public LogFormatter::FormatItem
    {
    public:
        TabFormatItem(const string &str = "") {}
        void format(ostream &os, shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override
        {
            os << "\t"; //Tab键
        }
    };
    class StringFormatItem : public LogFormatter::FormatItem
    {
    public:
        StringFormatItem(const string &str) : m_string(str) {}
        void format(ostream &os, shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override
        {
            os << m_string; //
        }

    private:
        string m_string;
    };

    //------------------------------------------------//
    //--------------------03-1日志格式化--------------------------//
    //构造
    LogFormatter::LogFormatter(const string &pattern)
        : m_pattern(pattern)
    {
        init(); //初始化，解析日志模板
    }

    /**
         * @brief 返回格式化日志文本
        * @param[in] logger 日志器
        * @param[in] level 日志级别
        * @param[in] event 日志事件
        */
    string LogFormatter::format(shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event)
    {
        stringstream ss;
        for (auto &i : m_items)
        {
            i->format(ss, logger, level, event);
        }
        return ss.str();
    }
    ostream &LogFormatter::format(ostream &ofs, shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event)
    {
        for (auto &i : m_items)
        {
            i->format(ofs, logger, level, event);
        }
        return ofs;
    }

    // %xxx %xxx{xxx} %%
    // 默认格式 "%d{%Y-%m-%d %H:%M:%S}%T%t%T%N%T%F%T[%p]%T[%c]%T%f:%l%T%m%n"
    void LogFormatter::init() //初始化,解析日志模板
    {
        // str, format, type
        vector<tuple<string, string, int>> vec;
        string nstr;
        for (size_t i = 0; i < m_pattern.size(); ++i)
        {
            //cout << "Test i= " << i << "\t\tm_pattern[i]= \t" << m_pattern[i] << "\t" << __LINE__ << endl;
            if (m_pattern[i] != '%') // 取出 [ ] : 等字符
            {
                nstr.append(1, m_pattern[i]);
                continue;
            }
            if ((i + 1) < m_pattern.size())
            {
                if (m_pattern[i + 1] == '%') // 取出字符 % (比如分式中是%%，那么在日志中显示一个%)
                {
                    nstr.append(1, '%');
                    continue;
                }
            }

            size_t n = i + 1;
            int fmt_status = 0;
            size_t fmt_begin = 0;

            string str;
            string fmt;

            while (n < m_pattern.size())
            {
                //取出两个百分号之间的字母 如 p T f
                if ((fmt_status == 0) &&
                    ((!isalpha(m_pattern[n])) && m_pattern[n] != '{' && m_pattern[n] != '}'))
                {
                    //cout << "isalpha: " << isalpha(m_pattern[n]) << " "<< n << " " << m_pattern[n] << endl;
                    str = m_pattern.substr(i + 1, n - i - 1);
                    //cout << "Test i= " << i << " n= " << n << " \tstr: \t\t" << str << "\t" << __LINE__ << endl;
                    break;
                }

                // %d{%Y-%m-%d %H:%M:%S}
                if (fmt_status == 0)
                {
                    if (m_pattern[n] == '{')
                    {
                        str = m_pattern.substr(i + 1, n - i - 1);
                        //cout << "Test i= " << i << " \t\tstr: \t\t" << str << "\t" << __LINE__ << endl; //相当于遇到了%d的d
                        fmt_status = 1;                                                                 //解析格式
                        fmt_begin = n;
                        ++n;
                        continue;
                    }
                    else
                    {
                        ++n;
                    }
                }
                else if (fmt_status == 1)
                {
                    if (m_pattern[n] == '}')
                    {
                        fmt = m_pattern.substr(fmt_begin + 1, n - fmt_begin - 1);
                        ////cout << "Test i= " << i << " \t\tfmt: \t\t" << fmt << "\t" << __LINE__ << endl; //相当于遇到了%d{%Y-%m-%d %H:%M:%S}的%Y-%m-%d %H:%M:%S
                        fmt_status = 0;
                        ++n;
                        break;
                    }
                    else
                    {
                        ++n;
                    }
                }
                // ++n;

                if (n == m_pattern.size())
                {
                    if (str.empty())
                    {
                        str = m_pattern.substr(i + 1);
                    }
                }
            }
            if (fmt_status == 0)
            {
                if (!nstr.empty())
                {
                    //
                    vec.push_back(make_tuple(nstr, string(), 0));
                    //cout << "Test i= " << i << " \t\tnstr: \t\t" << nstr << "\t" << __LINE__ << endl;
                    nstr.clear();
                }

                // 例如：make_tuple(d, %Y-%m-%d %H:%M:%S, 1)
                vec.push_back(make_tuple(str, fmt, 1));
                i = n - 1; // 此时：m_pattern[i] == '}'
                //cout << "Test i= " << i << " n= " << n << "\tm_pattern[i]= \t" << m_pattern[i] << "\t" << __LINE__ << endl;
            }
            else if (fmt_status == 1)
            {
                cout << "pattern parse error: " << m_pattern << " - " << m_pattern.substr(i) << endl;
                m_error = true;
                vec.push_back(make_tuple("<<pattern_error>>", fmt, 0));
            }
        }

        if (!nstr.empty())
        {
            vec.push_back(make_tuple(nstr, "", 0));
        }

        static map<std::string, function<FormatItem::ptr(const string &str)>> s_format_items = {
#define XX(str, ABC)                                                          \
    {                                                                         \
#str, [](const string &fmt) { return FormatItem::ptr(new ABC(fmt)); } \
    }

            XX(m, MessageFormatItem),    //m:消息
            XX(p, LevelFormatItem),      //p:日志级别
            XX(r, ElapseFormatItem),     //r:累计毫秒数
            XX(c, LoggerNameFormatItem), //c:日志名称
            XX(t, ThreadIdFormatItem),   //t:线程id
            XX(n, NewLineFormatItem),    //n:换行
            XX(d, DateTimeFormatItem),   //d:时间
            XX(f, FilenameFormatItem),   //f:文件名
            XX(l, LineFormatItem),       //l:行号
            XX(T, TabFormatItem),        //T:Tab
            XX(F, FiberIdFormatItem),    //F:协程id
            XX(N, ThreadNameFormatItem), //N:线程名称
#undef XX
        };

        for (auto &i : vec)
        {
            if (std::get<2>(i) == 0)
            {
                m_items.push_back(FormatItem::ptr(new StringFormatItem(std::get<0>(i))));
            }
            else
            {
                auto it = s_format_items.find(std::get<0>(i));
                if (it == s_format_items.end())
                {
                    m_items.push_back(FormatItem::ptr(
                        new StringFormatItem("<<error_format %" + std::get<0>(i) + ">>")));
                    m_error = true;
                }
                else
                {
                    m_items.push_back(it->second(std::get<1>(i)));
                }
            }
        }
    }
    //------------------------------------------------//
    //--------------------04-1日志输出地--------------------------//

    void LogAppender::setFormatter(LogFormatter::ptr val) //更改日志格式器
    {
        m_formatter = val;
        if (m_formatter)
        {
            m_hasFormatter = true;
        }
        else
        {
            m_hasFormatter = false;
        }
    }
    LogFormatter::ptr LogAppender::getFormatter() //获取日志格式器
    {
        return m_formatter;
    }

    //--------------------04-2输出到控制台的Appender
    void StdoutLogAppender::log(shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event)
    {
        if (level > m_level)
        {
            //输出日志到标准输出
            //仅仅比LogFormatter多指定了一个输出地：cout
            m_formatter->format(cout, logger, level, event);
        }
    }

    //--------------------04-3输出到文件的Appender

    FileLogAppender::FileLogAppender(const string &filename) //设置文件名
        : m_filename(filename)
    {
        reopen();
    }

    void FileLogAppender::log(shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event)
    {
        if (level >= m_level)
        {
            uint64_t now = event->getTime();
            if (now >= (m_lastOpenTime + 3))
            {
                reopen();
                m_lastOpenTime = now;
            }
            //输出日志到日志文件
            if (!m_formatter->format(m_filestream, logger, level, event))
            {
                cout << "error: 输出日志到日志文件 失败！" << endl;
            }
        }
    }

    bool FileLogAppender::reopen() //重新打开日志文件，文件打开成功返回true
    {
        if (m_filestream)
        {
            m_filestream.close();
        }
        m_filestream.open(m_filename.c_str(), std::ios::app);
        return m_filestream.is_open();
    }

    //------------------------------------------------//
    //--------------------05日志器--------------------------//

    Logger::Logger(const std::string &name)
        : m_LoggerName(name),             //设置日志名称
          m_level(LogLevel::Level::DEBUG) //设置日志级别
    {
        m_formatter.reset( //设置日志格式器
            new LogFormatter("%d{%Y-%m-%d %H:%M:%S}%T%t%T%N%T%F%T[%p]%T[%c]%T%f:%l%T%m%n"));
    }

    //--------------------
    //写日志
    void Logger::log(LogLevel::Level level, LogEvent::ptr event)
    {
        if (level >= m_level)
        {
            auto self = shared_from_this();
            if (!m_appenders.empty()) //若是有appender,则通过appender写日志
            {
                for (auto &i : m_appenders)
                {
                    //Logger的log()调用LogAppender的log()，
                    //LogAppender的log()调用LogFmrmatter的format()
                    //format()遍历FormatItem,
                    //同时 调用每个FormatItem子类的format()打印子格式信息到日志文件或者标准输出
                    i->log(self, level, event);
                }
            }
            else if (m_root) //若是没有appender但是有主日志器m_root，那通过m_root写日志
            {
                m_root->log(level, event);
            }
        }
    }
    //写DEBUG级别日志
    void Logger::debug(LogEvent::ptr event) { log(LogLevel::Level::DEBUG, event); }
    void Logger::info(LogEvent::ptr event) { log(LogLevel::Level::INFO, event); }
    void Logger::warn(LogEvent::ptr event) { log(LogLevel::Level::WARN, event); }
    void Logger::error(LogEvent::ptr event) { log(LogLevel::Level::ERROR, event); }
    void Logger::fatal(LogEvent::ptr event) { log(LogLevel::Level::FATAL, event); }
    //--------------------
    void Logger::addAppender(LogAppender::ptr appender)
    {
        if (!appender->getFormatter())
        {
            appender->m_formatter = m_formatter;
        }
        m_appenders.push_back(appender);
    }
    void Logger::delAppender(LogAppender::ptr appender)
    {
        for (auto it = m_appenders.begin();
             it != m_appenders.end();
             ++it)
        {
            if (*it == appender)
            {
                m_appenders.erase(it);
                break;
            }
        }
    }
    void Logger::clearAppenders()
    {
        m_appenders.clear();
    }

    //--------------------
    LogFormatter::ptr Logger::getFormatter()
    {
        return m_formatter;
    }
    void Logger::setFormatter(LogFormatter::ptr val) //给appender设置日志格式器
    {
        m_formatter = val;
        for (auto &i : m_appenders) //遍历appender
        {
            if (!i->m_hasFormatter)
            {
                i->m_formatter = m_formatter; //若某个appender没有日志格式器 则给它一个
            }
        }
    }

    void Logger::setFormatter(const string &val) //给appender设置日志格式器
    {
        cout << "---" << val << endl;

        //创建一个新的LogFormatter，构造函数的参数是 格式字符串
        sylar::LogFormatter::ptr new_val(new sylar::LogFormatter(val));
        if (new_val->isError()) //如果LogForrmatter构造时出错了
        {
            cout << "Logger setFormatter name=" << m_LoggerName
                 << "value=" << val
                 << " [Error] invalid format" << endl;
            return;
        }

        setFormatter(new_val);
    }
    //--------------------

    //--------------------06日志器管理类--------------------------//
    //在构造函数中 构造主 Logger
    LoggerManager::LoggerManager()
    {
        //创建主Logger
        m_rootLogger.reset(new Logger);

        //将主Logger的appender设置为cout
        m_rootLogger->addAppender(LogAppender::ptr(new StdoutLogAppender));
        //将主Logger添加到m_loggers中
        m_loggers[m_rootLogger->m_LoggerName] == m_rootLogger;

        init();
    }

    //根据日志器名称，获取日志器
    Logger::ptr LoggerManager::getLogger(const string &name)
    {
        auto it = m_loggers.find(name); //查找Logger
        if (it != m_loggers.end())
        {
            return it->second; //返回Logger
        }

        //没找到，则 创建一个Logger
        Logger::ptr logger(new Logger(name));
        logger->m_root = m_rootLogger;
        m_loggers[name] = logger;
        return logger;
    }

    //初始化
    void LoggerManager::init()
    {
    }

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
}