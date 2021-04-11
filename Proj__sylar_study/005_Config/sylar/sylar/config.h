#ifndef __SYLAR_CONFIG_H__
#define __SYLAR_CONFIG_H__

#include <memory>                 //智能指针
#include <sstream>                //序列化
#include <boost/lexical_cast.hpp> //内存转换
#include <string>
#include <yaml-cpp/yaml.h>
#include "sylar/log.h"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

//--------------------
using std::map;
using std::shared_ptr;
using std::string;
//--------------------

//--------------------

namespace sylar
{
    //--------------------01--------------------------//
    //01定义基类 把公共属性都放进去
    class ConfigVarBase
    {
    public:
        typedef shared_ptr<ConfigVarBase> ptr;

        ConfigVarBase(const string &name, const string &description = "")
            : m_name(name),
              m_description(description)
        {
            std::transform(m_name.begin(), m_name.end(), m_name.begin(), ::tolower); //名字全用小写
        }
        virtual ~ConfigVarBase() {}

        const string &getName() const { return m_name; }
        const string &getDescription() const { return m_description; }

        virtual string toString() = 0;
        virtual bool formString(const string &val) = 0;
        virtual std::string getTypeName() const = 0;

    protected:
        string m_name;        //配置参数名称
        string m_description; //配置参数描述
    };
    //--------------------05--------------------------//
    //定义仿函数
    //支持基础类型、STL、自定义类型

    //--------------------05-1
    //支持基础类型：把F类型转成T类型
    //F from_type , T to_type
    template <class F, class T>
    class LexicalCast
    {
    public:
        T operator()(const F &v)
        {
            return boost::lexical_cast<T>(v);
        }
    };

    //--------------------05-2
    //片特化01-1  支持把string转换为vector<T>
    template <class T>
    class LexicalCast<std::string, std::vector<T>>
    {
    public:
        std::vector<T> operator()(const std::string &v)
        {
            //yaml-cpp加载数组成为一个string
            //调用yamp-cpp库中的函数Load()，把yaml-cpp加载成的string转换成Node，此处Node为数组
            //遍历这个Node，把每个Node[i]转换为T，并push_back到vector中
            //这样就把一个string，转换为了vector<T>
            YAML::Node node = YAML::Load(v);
            typename std::vector<T> vec;
            std::stringstream ss;
            for (size_t i = 0; i < node.size(); ++i)
            {
                ss.str(""); //把ss置空
                ss << node[i];
                vec.push_back(LexicalCast<std::string, T>()(ss.str()));
            }
            return vec;
        }
    };
    //片特化01-2  支持把vector<T>转换为string
    template <class T>
    class LexicalCast<std::vector<T>, std::string>
    {
    public:
        std::string operator()(const std::vector<T> &v)
        {
            YAML::Node node;
            for (auto &i : v)
            {
                //把每个vector<T>[i]转换为string，然后YAML::Load(string)转换为Node，然后push_back到Node
                node.push_back(YAML::Load(LexicalCast<T, std::string>()(i)));
            }
            std::stringstream ss;
            ss << node;
            return ss.str();
        }
    };
    //片特化02-1 支持把string转换为list<T>
    template <class T>
    class LexicalCast<std::string, std::list<T>>
    {
    public:
        std::list<T> operator()(const std::string &v)
        {
            YAML::Node node = YAML::Load(v);
            typename std::list<T> m_list;
            std::stringstream ss;
            for (size_t i = 0; i < node.size(); ++i)
            {
                ss.str(""); //把ss置空
                ss << node[i];
                m_list.push_back(LexicalCast<std::string, T>()(ss.str()));
            }
            return m_list;
        }
    };
    //片特化02-2  支持把list<T>转换为string
    template <class T>
    class LexicalCast<std::list<T>, std::string>
    {
    public:
        std::string operator()(const std::list<T> &v)
        {
            YAML::Node node;
            for (auto &i : v)
            {
                //把每个list<T>[i]转换为string，然后YAML::Load(string)转换为Node，然后push_back到Node
                node.push_back(YAML::Load(LexicalCast<T, std::string>()(i)));
            }
            std::stringstream ss;
            ss << node;
            return ss.str();
        }
    };
    //片特化03-1 支持把string转换为set<T>
    template <class T>
    class LexicalCast<std::string, std::set<T>>
    {
    public:
        std::set<T> operator()(const std::string &v)
        {
            YAML::Node node = YAML::Load(v);
            typename std::set<T> m_set;
            std::stringstream ss;
            for (size_t i = 0; i < node.size(); ++i)
            {
                ss.str(""); //把ss置空
                ss << node[i];
                m_set.insert(LexicalCast<std::string, T>()(ss.str()));
            }
            return m_set;
        }
    };
    //片特化03-2  支持把set<T>转换为string
    template <class T>
    class LexicalCast<std::set<T>, std::string>
    {
    public:
        std::string operator()(const std::set<T> &v)
        {
            YAML::Node node;
            for (auto &i : v)
            {
                //把每个set<T>[i]转换为string，然后YAML::Load(string)转换为Node，然后push_back到Node
                node.push_back(YAML::Load(LexicalCast<T, std::string>()(i)));
            }
            std::stringstream ss;
            ss << node;
            return ss.str();
        }
    };
    //片特化03-1 支持把string转换为unordered_set<T>
    template <class T>
    class LexicalCast<std::string, std::unordered_set<T>>
    {
    public:
        std::unordered_set<T> operator()(const std::string &v)
        {
            YAML::Node node = YAML::Load(v);
            typename std::unordered_set<T> m_unordered_set;
            std::stringstream ss;
            for (size_t i = 0; i < node.size(); ++i)
            {
                ss.str(""); //把ss置空
                ss << node[i];
                m_unordered_set.insert(LexicalCast<std::string, T>()(ss.str()));
            }
            return m_unordered_set;
        }
    };
    //片特化03-2  支持把unordered_set<T>转换为string
    template <class T>
    class LexicalCast<std::unordered_set<T>, std::string>
    {
    public:
        std::string operator()(const std::unordered_set<T> &v)
        {
            YAML::Node node;
            for (auto &i : v)
            {
                //把每个unordered_set<T>[i]转换为string，然后YAML::Load(string)转换为Node，然后push_back到Node
                node.push_back(YAML::Load(LexicalCast<T, std::string>()(i)));
            }
            std::stringstream ss;
            ss << node;
            return ss.str();
        }
    };

    //片特化04-1  支持把string转换为std::map<std::string, T>
    template <class T>
    class LexicalCast<std::string, std::map<std::string, T>>
    {
    public:
        std::map<std::string, T> operator()(const std::string &v)
        {
            YAML::Node node = YAML::Load(v);
            typename std::map<std::string, T> m_map;
            std::stringstream ss;
            for (auto it = node.begin(); it != node.end(); ++it)
            {
                ss.str(""); //把ss置空
                ss << it->second;
                m_map.insert(std::make_pair(it->first.Scalar(),
                                            LexicalCast<std::string, T>()(ss.str())));
            }
            return m_map;
        }
    };
    //片特化04-2  支持把std::map<std::string, T>转换为string
    template <class T>
    class LexicalCast<std::map<std::string, T>, std::string>
    {
    public:
        std::string operator()(const std::map<std::string, T> &v)
        {
            YAML::Node node;
            for (auto &i : v)
            {
                node[i.first] = (YAML::Load(LexicalCast<T, std::string>()(i.second)));
            }
            std::stringstream ss;
            ss << node;
            return ss.str();
        }
    };
    //片特化05-1  支持把string转换为std::unordered_map<std::string, T>
    template <class T>
    class LexicalCast<std::string, std::unordered_map<std::string, T>>
    {
    public:
        std::unordered_map<std::string, T> operator()(const std::string &v)
        {
            YAML::Node node = YAML::Load(v);
            typename std::unordered_map<std::string, T> m_unordered_map;
            std::stringstream ss;
            for (auto it = node.begin(); it != node.end(); ++it)
            {
                ss.str(""); //把ss置空
                ss << it->second;
                m_unordered_map.insert(std::make_pair(it->first.Scalar(),
                                                      LexicalCast<std::string, T>()(ss.str())));
            }
            return m_unordered_map;
        }
    };
    //片特化05-2  支持把std::unordered_map<std::string, T>转换为string
    template <class T>
    class LexicalCast<std::unordered_map<std::string, T>, std::string>
    {
    public:
        std::string operator()(const std::unordered_map<std::string, T> &v)
        {
            YAML::Node node;
            for (auto &i : v)
            {
                node[i.first] = (YAML::Load(LexicalCast<T, std::string>()(i.second)));
            }
            std::stringstream ss;
            ss << node;
            return ss.str();
        }
    };

    //--------------------02--------------------------//
    //02ConfigVarBase的子类
    //把某类型转换为string；把string转换为某类型
    // template <class T>

    //FromStr   T operator()(const std::string&) 把string类型转换为T类型
    //ToStr     std::string operator()(constT&)  把T类型转换为string类型
    //这里使用了LexicalCast的特例化
    template <class T, class FromStr = LexicalCast<std::string, T>,
              class ToStr = LexicalCast<T, std::string>>
    class ConfigVar : public ConfigVarBase
    {
    public:
        typedef shared_ptr<ConfigVar> ptr;

        ConfigVar(const string &name,
                  const T &default_value,
                  const string &description = "")
            : ConfigVarBase(name, description),
              m_val(default_value)
        {
        }

        string toString() override
        {
            try
            {
                // return boost::lexical_cast<string>(m_val);
                return ToStr()(m_val); //--------------------05
            }
            catch (std::exception &e)
            {

                SYLAR_LOG_ERROR(SYLAR_LOG_ROOT()) << "ConfigVar::toString() exception "
                                                  << e.what()
                                                  << " convert: " << typeid(m_val).name() << "to string";
            }
            return "";
        }
        bool formString(const string &val) override
        {
            try
            {
                // m_val = boost::lexical_cast<T>(val);
                setValue(FromStr()(val)); //--------------------05
            }
            catch (std::exception &e)
            {
                SYLAR_LOG_ERROR(SYLAR_LOG_ROOT()) << "ConfigVar::fromString() exception "
                                                  << e.what()
                                                  << " convert: string to " << typeid(m_val).name()
                                                  << " - " << val;
            }
            return false;
        }

        const T getValue() const { return m_val; }
        void setValue(const T &v) { m_val = v; }
        std::string getTypeName() const override { return typeid(T).name(); }

    private:
        T m_val;
    };

    //--------------------03--------------------------//
    //03管理上面的ConfigVar
    //单例
    class Config
    {
    public:
        typedef map<string, ConfigVarBase::ptr> ConfigVarMap; //此处unordered_map也行

        //根据name查找ConfigVar<T>::ptr，没找到就创建
        template <class T>
        static typename ConfigVar<T>::ptr Lookup( //此处的typename是为了之指明后面的ConfigVar<T>::ptr是个数据类型
            const string &name,
            const T &default_value,
            const string &description = "")
        {
            auto it = s_datas.find(name);
            if (it != s_datas.end())
            {
                auto tmp = std::dynamic_pointer_cast<ConfigVar<T>>(it->second);
                if (tmp)
                {
                    SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << "Lookup name= " << name << " exists";
                    return tmp;
                }
                else
                {
                    //解决的问题：key存在，但是value的类型不对
                    SYLAR_LOG_ERROR(SYLAR_LOG_ROOT())
                        << "Lookup name= " << name
                        << "  exists but type not: " << typeid(T).name()
                        << "  real_type: " << it->second->getTypeName()
                        << "  " << it->second->toString();
                    return nullptr;
                }
            }

            //如果没找到，先看看是否有错误
            //查看string中是否有非法字符(不属于这个指定集合的)，那么返回值是std::string::npos
            if (name.find_first_not_of("abcdefghijklmnopqrstuvwxyz._0123456789") != std::string::npos)
            {
                SYLAR_LOG_ERROR(SYLAR_LOG_ROOT()) << "Lookup name invalid " << name;
                throw std::invalid_argument(name);
            }
            //没错误就创建
            typename ConfigVar<T>::ptr v(new ConfigVar<T>(name, default_value, description));
            s_datas[name] = v;
            return v;
        }

        template <class T>
        static typename ConfigVar<T>::ptr Lookup(const string &name)
        {
            auto it = s_datas.find(name);
            if (it == s_datas.end())
            {
                return nullptr;
            }
            return std::dynamic_pointer_cast<ConfigVar<T>>(it->second);
        }

        //--------------------04--------------------------//
        //从yml中加载配置
        static void LoadFromYaml(const YAML::Node &root);
        static ConfigVarBase::ptr LookupBase(const std::string &name);

    private:
        static ConfigVarMap s_datas;
    };
}

#endif