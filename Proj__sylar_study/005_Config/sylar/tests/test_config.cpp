#include "../sylar/log.h"
#include "../sylar/config.h"
#include <yaml-cpp/yaml.h>
// #include <string>
// using namespace YAML;
//---------------------------------------------------------------------------------------
/*****
 * 配置系统的原则，约定优于配置：
 * 
 * 
 */
//---------------------------------------------------------------------------------------
//自定义的配置(此处是约定，约定好两个参数)
sylar::ConfigVar<int>::ptr g_int_value_config =
    sylar::Config::Lookup("system.port", (int)8080, "system port");

sylar::ConfigVar<float>::ptr g_int_valuex_config = //解决的问题：key存在，但是value的类型不对
    sylar::Config::Lookup("system.port", (float)8080, "system port");

sylar::ConfigVar<float>::ptr g_float_value_config =
    sylar::Config::Lookup("system.value", (float)10.2f, "system value");

//--------------------05
sylar::ConfigVar<std::vector<int>>::ptr g_int_vec_value_config =
    sylar::Config::Lookup("system.int_vec", std::vector<int>{1, 2}, "system int vec");

sylar::ConfigVar<std::list<int>>::ptr g_int_list_value_config =
    sylar::Config::Lookup("system.int_list", std::list<int>{1, 2}, "system int list");

sylar::ConfigVar<std::set<int>>::ptr g_int_set_value_config =
    sylar::Config::Lookup("system.int_set", std::set<int>{1, 2}, "system int set");

sylar::ConfigVar<std::unordered_set<int>>::ptr g_int_unordered_set_value_config =
    sylar::Config::Lookup("system.int_unordered_set", std::unordered_set<int>{1, 2}, "system int unordered_set");

sylar::ConfigVar<std::map<string, int>>::ptr g_string_int_map_value_config =
    sylar::Config::Lookup("system.string_int_map", std::map<string, int>{{"k", 2}}, "system int string_int_map");

sylar::ConfigVar<std::unordered_map<string, int>>::ptr g_string_int_unordered_map_value_config =
    sylar::Config::Lookup("system.string_int_unordered_map", std::unordered_map<string, int>{{"k", 2}}, "system int string_int_unordered_map");

//---------------------------------------------------------------------------------------
void test_01_config()
{
    SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << g_int_value_config->getValue();
    SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << g_float_value_config->toString();
}

//---------------------------------------------------------------------------------------
void test_03_print_yaml(const YAML::Node &node, int level)
{
    if (node.IsScalar())
    { //简单的类型，直接输出
        SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << std::string(level * 4, ' ')
                                         << node.Scalar() << " - "
                                         << node.Type() << " - " << level;
    }
    else if (node.IsNull())
    {
        SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << std::string(level * 4, ' ')
                                         << "NULL - "
                                         << node.Type() << " - " << level;
    }
    else if (node.IsMap())
    { //遍历map
        for (auto it = node.begin(); it != node.end(); ++it)
        {
            SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << std::string(level * 4, ' ')
                                             << it->first << " - "
                                             << it->second.Type() << " - " << level;
            test_03_print_yaml(it->second, level + 1);
        }
    }
    else if (node.IsSequence())
    { //遍历数组
        for (size_t i = 0; i < node.size(); ++i)
        {
            SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << std::string(level * 4, ' ')
                                             << i << " - "
                                             << node[i].Type() << " - " << level;
            test_03_print_yaml(node[i], level + 1);
        }
    }
}
void test_02_yamlcpp()
{
    //加载yaml文件
    //加载yaml文件中的配置
    YAML::Node root = YAML::LoadFile("/home/lwh/workspace/sylar/bin/conf/log.yml");
    test_03_print_yaml(root, 0);

    SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << root.Scalar();
}
//---------------------------------------------------------------------------------------

void test_04_config()
{
    //--------------------05-1
    //实现了对 基础内置类型 的支持
    SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << "before: " << g_int_value_config->getValue();
    SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << "before: " << g_float_value_config->toString();

    //--------------------05-2 实现了对STL容器中各类型的支持
#define XX(g_var, name, prefix)                                                               \
    {                                                                                         \
        auto &v = g_var->getValue();                                                          \
        for (auto &i : v)                                                                     \
        {                                                                                     \
            SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << #prefix " " #name ": " << i;                  \
        }                                                                                     \
        SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << #prefix " " #name " yaml: " << g_var->toString(); \
    }

#define XX_map(g_var, name, prefix)                                                           \
    {                                                                                         \
        auto &v = g_var->getValue();                                                          \
        for (auto &i : v)                                                                     \
        {                                                                                     \
            SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << #prefix " " #name ": {"                       \
                                             << i.first << " , " << i.second << "}";          \
        }                                                                                     \
        SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << #prefix " " #name " yaml: " << g_var->toString(); \
    }

    XX(g_int_vec_value_config, int_vec, before);
    XX(g_int_list_value_config, int_list, before);
    XX(g_int_set_value_config, int_set, before);
    XX(g_int_unordered_set_value_config, int_unordered_set, before);
    XX_map(g_string_int_map_value_config, string_int_map, before);
    XX_map(g_string_int_unordered_map_value_config, string_int_unordered_map, before);

    //加载yaml文件中的配置
    //找约定的内容，把约定的内容给覆盖
    YAML::Node root = YAML::LoadFile("/home/lwh/workspace/sylar/bin/conf/log.yml");
    sylar::Config::LoadFromYaml(root);

    SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << "after: " << g_int_value_config->getValue();
    SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << "after: " << g_float_value_config->toString();

    XX(g_int_vec_value_config, int_vec, after);
    XX(g_int_list_value_config, int_list, after);
    XX(g_int_set_value_config, int_set, after);
    XX(g_int_unordered_set_value_config, int_unordered_set, after);
    XX_map(g_string_int_map_value_config, string_int_map, before);
    XX_map(g_string_int_unordered_map_value_config, string_int_unordered_map, after);

#undef XX
#undef XX_map
}
//---------------------------------------------------------------------------------------
//--------------------05-3 实现了对自定义类型的支持
class Person
{
public: //此处为了测试方便，不写Get方法了，直接设置为了public；平时还是要设置为private
    std::string m_name;
    int m_age = 0;
    bool m_sex = 0;

public:
    std::string toString() const
    {
        std::stringstream ss;
        ss << "[Person name=" << m_name
           << " age=" << m_age
           << " sex=" << m_sex
           << "]";
        return ss.str();
    }
};
//
namespace sylar
{
    //片特化  支持把string转换为Preson
    template <>
    class LexicalCast<std::string, Person>
    {
    public:
        Person operator()(const std::string &v)
        {
            YAML::Node node = YAML::Load(v);
            Person p;
            p.m_name = node["name"].as<std::string>();
            p.m_age = node["age"].as<int>();
            p.m_sex = node["sex"].as<bool>();
            return p;
        }
    };
    //片特化  支持把Person转换为string
    template <>
    class LexicalCast<Person, std::string>
    {
    public:
        std::string operator()(const Person &p)
        {
            YAML::Node node;
            node["name"] = p.m_name;
            node["age"] = p.m_age;
            node["sex"] = p.m_sex;
            std::stringstream ss;
            ss << node;
            return ss.str();
        }
    };
}
//自定义结构
sylar::ConfigVar<Person>::ptr g_person_config =
    sylar::Config::Lookup("class.person", Person(), "class preson");
//自定义结构+STL嵌套
//map<string, 自定义类>
sylar::ConfigVar<std::map<std::string, Person>>::ptr g_person_map_config =
    sylar::Config::Lookup("class.map", std::map<std::string, Person>(), "class preson_map");
//map<string, vector<自定义类> >
sylar::ConfigVar<std::map<std::string, std::vector<Person>>>::ptr g_map_vector_person_config =
    sylar::Config::Lookup("class.map_vec", std::map<std::string, std::vector<Person>>(), "class map_vector_person");

void test_05_class()
{
    SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << "before: " << g_person_config->getValue().toString() << " - " << g_person_config->toString();

#define XX_Person_Map(g_var, prefix)                                                     \
    {                                                                                    \
        auto m = g_var->getValue();                                                      \
        for (auto &i : m)                                                                \
        {                                                                                \
            SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << prefix << ": "                           \
                                             << i.first << " - " << i.second.toString(); \
        }                                                                                \
        SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << prefix << ": size=" << m.size();             \
    }

    XX_Person_Map(g_person_map_config, "class.map before");
    SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << "before: " << g_map_vector_person_config->toString();

    YAML::Node root = YAML::LoadFile("/home/lwh/workspace/sylar/bin/conf/log.yml");
    sylar::Config::LoadFromYaml(root);

    SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << "after: " << g_person_config->getValue().toString() << " - " << g_person_config->toString();
    XX_Person_Map(g_person_map_config, "class.map after");
    SYLAR_LOG_INFO(SYLAR_LOG_ROOT()) << "after: " << g_map_vector_person_config->toString();
}
//---------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------
int main(int argc, char **argv)
{
    // test_01_config();
    // test_02_yamlcpp();
    // test_04_config();
    test_05_class();
    return 0;
}