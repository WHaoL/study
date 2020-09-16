#ifndef __RANDOMNAME_H__
#define __RANDOMNAME_H__
#include <string>
#include <vector>
/*本类：生成随机姓名  */

/*
 *数据结构：随机姓名池
 *      线性表存姓和名(线性表)
 *      取名字：随机取姓，随机取名
 *      还名字：尾部追加姓或名字
 *      读姓氏文件的同时读名字文件，边读边追加节点
*/

//一个姓和一堆名，组成的线性表
class FirstName
{
public:
    std::string m_first_name;
    std::vector<std::string> m_last_name_vector;
};

class RandomName
{
private:
    std::vector<FirstName *> m_pool; //随机姓名池

public:
    RandomName();
    virtual ~RandomName();

public:
    std::string GetName();           //取名字
    void Release(std::string _name); //还名字
    void LoadFile();                 //读文件，构造m_pool
};

#endif