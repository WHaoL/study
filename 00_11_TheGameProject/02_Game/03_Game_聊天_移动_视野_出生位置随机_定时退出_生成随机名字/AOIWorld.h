#ifndef __AOIWORLD_H__
#define __AOIWORLD_H__
#include <list>
#include <vector>
/*
 * 玩家：拥有横纵坐标的对象
 * */
class Player
{
public:
    // 面向接口编程：不规定具体的数据结构，只规定你的抽象类，后续使用时，继承抽象类就行了
    virtual int GetX() = 0;
    virtual int GetY() = 0;
};

/*
 * 网格：包含若干玩家
 * */
class Grid
{
public:
    std::list<Player *> m_players;
};

/*
 * 游戏世界矩形：包含固定数量的网格
 * */
class AOIWorld
{
public:
    // 通过构造函数，指定矩形的大小和分割粒度
    AOIWorld(int _x_begin, int _x_end, int _y_begin, int _y_end, int _x_count, int _y_count);
    virtual ~AOIWorld();

public:
    // 核心功能：获取周围玩家
    std::list<Player *> GetSurrendPlayers(Player *_player);
    // 添加玩家到AOI网格
    bool AddPlayer(Player *_player);
    // 摘除AOI网格中的玩家
    void DelPlayer(Player *_player);

public:
    // 存储网格
    std::vector<Grid> m_grids;
private:
    // 矩形本身的特性，要先确定下来，AOI对象
    int x_begin = 0; // x方向起始坐标
    int x_end = 0;   // x方向结束坐标
    int y_begin = 0; // y方向起始坐标
    int y_end = 0;   // y方向结束坐标
    int x_count = 0; // x方向分几份
    int y_count = 0; // y方向分几份
    int x_width = 0; // x轴步长，网格每格宽度
    int y_width = 0; // y轴步长，网格每格宽度

};
#endif