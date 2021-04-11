#include <map>
#include <iostream>
#include <iostream>
#include <functional>
#include <time.h>
#include <string.h>
#include <vector>

#include "log.h"

using std::cout;
using std::endl;
using std::make_tuple;
using std::ostream;
using std::string;
using std::tuple;
using std::vector;

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
    //--------------------日志事件包装器--------------------------//
    LogEventWarp::LogEventWarp(LogEvent::ptr e)
        : m_event(e)
    {
    }
    LogEventWarp::~LogEventWarp()
    {
        //m_event->getLogger()->log(m_event->getLevel(),m_event);
    }
    stringstream &LogEventWarp::getSS()
    {
        return m_event->getSS();
    }
    //--------------------03日志格式化--------------------------//
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
            cout << "Test i= " << i << "\t\tm_pattern[i]= \t" << m_pattern[i] << "\t" << __LINE__ << endl;
            if (m_pattern[i] != '%') // 取出 [ ] : 等字符
            {	
                nstr.append(1, m_pattern[i]);
                continue;
            }
            if ((i + 1) < m_pattern.size()) 
            {
                if (m_pattern[i + 1] == '%')// 取出字符 % (比如分式中是%%，那么在日志中显示一个%)
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
                    cout << "isalpha: " << isalpha(m_pattern[n]) << " "
                         << n << " " << m_pattern[n] << endl;
                    str = m_pattern.substr(i + 1, n - i - 1);
                    cout << "Test i= " << i << " n= " << n << " \tstr: \t\t" << str << "\t" << __LINE__ << endl;
                    break;
                }

                // %d{%Y-%m-%d %H:%M:%S}
                if (fmt_status == 0)
                {
                    if (m_pattern[n] == '{')
                    {
                        str = m_pattern.substr(i + 1, n - i - 1);
                        cout << "Test i= " << i << " \t\tstr: \t\t" << str << "\t" << __LINE__ << endl; //相当于遇到了%d的d
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
                        cout << "Test i= " << i << " \t\tfmt: \t\t" << fmt << "\t" << __LINE__ << endl; //相当于遇到了%d{%Y-%m-%d %H:%M:%S}的%Y-%m-%d %H:%M:%S
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

            //cout << "Test i= " << i << " n= " << n << "\tm_pattern[i]= \t" << m_pattern[i] << "\t" << __LINE__ << endl;

            if (fmt_status == 0)
            {
                if (!nstr.empty())
                {
                    //
                    vec.push_back(make_tuple(nstr, string(), 0));
                    cout << "Test i= " << i << " \t\tnstr: \t\t" << nstr << "\t" << __LINE__ << endl;
                    nstr.clear();
                }

                // 例如：make_tuple(d, %Y-%m-%d %H:%M:%S, 1)
                vec.push_back(make_tuple(str, fmt, 1));
                i = n - 1; // 此时：m_pattern[i] == '}'
                cout << "Test i= " << i << " n= " << n << "\tm_pattern[i]= \t" << m_pattern[i] << "\t" << __LINE__ << endl;
            }
            else if (fmt_status == 1)
            {
                cout << "pattern parse error: " << m_pattern
                     << " - " << m_pattern.substr(i) << endl;
                m_error = true;
                vec.push_back(make_tuple("<<pattern_error>>", fmt, 0));
            }
        }
        if (!nstr.empty())
        {
            vec.push_back(make_tuple(nstr, "", 0));
        }
    }

    //日志内容项格式化

    //------------------------------------------------//
    //------------------------------------------------//
}