#include "RandomName.h"
#include <random>
#include <fstream>
#include <vector>

RandomName::RandomName()
{
}
RandomName::~RandomName()
{
}

//随机数引擎，产生随机数
static std::default_random_engine random_engine(time(NULL));
std::string RandomName::GetName()
{
    unsigned long num = random_engine() % m_pool.size();
    std::string first = m_pool[num]->m_first_name;                                                                    //取姓,和其后名字对应的线性表
    std::string last = m_pool[num]->m_last_name_vector[random_engine() % ((m_pool[num]->m_last_name_vector).size())]; //取名

    //若本姓下的所有名字都取完了，把本姓删掉
    if (((m_pool[num]->m_last_name_vector).size()) <= 0)
    {
        delete m_pool[num];
        m_pool.erase((m_pool.begin() + num));
    }

    return (first + " " + last);
}
void RandomName::Release(std::string _name)
{
    //分隔名字，得到姓和名
    std::size_t space_pos = _name.find(" ", 0);                                   //找到 姓和名中间的空格 的位置
    std::string first = _name.substr(0, space_pos);                               //姓//参数是，其实位置、多少个字符
    std::string last = _name.substr(space_pos + 1, _name.size() - space_pos - 1); //名

    bool found = false;
    for (FirstName *first_name : m_pool)
    {
        if (first_name->m_first_name == first)
        {
            first_name->m_last_name_vector.push_back(last);
            found = true;
            break;
        }
    }
    if (false == found)
    {
        FirstName *first_name = new FirstName();
        first_name->m_first_name = first;
        first_name->m_last_name_vector.push_back(last);
        m_pool.push_back(first_name);
    }
}
void RandomName::LoadFile()
{
    std::ifstream file_firstname("random_FirstName.txt");
    std::ifstream file_lastname("random_LastName.txt");

    //读取所有名字组成一个线性表
    std::string last_name;
    std::vector<std::string> tmp_last_name_vector;
    while (getline(file_lastname, last_name))
    {
        tmp_last_name_vector.push_back(last_name);
    }

    //读取所有姓，
    //同时 创建姓名池节点，把名字组成的线性表，拷贝进来
    std::string first_name;
    while (getline(file_firstname, first_name))
    {
        FirstName *tmp_FirstName = new FirstName();
        tmp_FirstName->m_first_name = first_name;
        tmp_FirstName->m_last_name_vector = tmp_last_name_vector;
        m_pool.push_back(tmp_FirstName);
    }
}
