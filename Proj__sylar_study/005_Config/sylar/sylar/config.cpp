//--------------------01日志级别--------------------------//

#include "config.h"

namespace sylar
{
    Config::ConfigVarMap Config::s_datas;

    //--------------------04--------------------------//
    //查找当前有没有 当前命名的项 有就返回它的智能指针
    ConfigVarBase::ptr Config::LookupBase(const std::string &name)
    {
        auto it = s_datas.find(name);
        return (it == s_datas.end() ? nullptr : it->second);
    }

    //从yml中加载配置
    /***
         * "A.B",10
         * "A.C",str
         * 映射为
         *  A: 
         *    B: 10
         *    C：str
         * 
        */
    static void ListAllMember(const std::string &prefix,
                              const YAML::Node &node,
                              std::list<std::pair<std::string, const YAML::Node>> &output)
    {
        //如果字符不属于指定集合(即含有非法字符)
        if (prefix.find_first_not_of("abcdefghijklmnopqrstuvwxyz._0123456789") != std::string::npos)
        {
            SYLAR_LOG_ERROR(SYLAR_LOG_ROOT()) << "Config invalid name: " << prefix << " : " << node;
            return;
        }

        //没问题的话，放进去一个node
        output.push_back(std::make_pair(prefix, node));
        //下一层如果是map
        if (node.IsMap())
        {
            for (auto it = node.begin(); it != node.end(); ++it)
            {
                ListAllMember(prefix.empty() ? it->first.Scalar() : prefix + "." + it->first.Scalar(),
                              it->second,
                              output);
            }
        }
    }

    void Config::LoadFromYaml(const YAML::Node &root)
    {
        std::list<std::pair<std::string, const YAML::Node>> all_nodes;
        ListAllMember("", root, all_nodes);

        for (auto &i : all_nodes)
        {
            std::string key = i.first;
            if (key.empty())
            {
                continue; //key为空 跳过
            }

            //转换成小写-统一使用小写
            std::transform(key.begin(), key.end(), key.begin(), ::tolower);
            
            //找约定的内容，把约定的内容给覆盖
            ConfigVarBase::ptr var = LookupBase(key); //根据key查找
            if (var)                                  //找到
            {
                if (i.second.IsScalar()) //它的Scalar是个string
                {
                    var->formString(i.second.Scalar());
                }
                else
                {
                    std::stringstream ss;
                    ss << i.second; //如果不是scalar就转换为string
                    var->formString(ss.str());
                }
            }
        }
    }
    //------------------------------------------------//
}
//--------------------
//------------------------------------------------//
