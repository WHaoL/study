#include "AOIWorld.h"
#include <list>
using namespace std;


/*
 * 游戏世界矩形：包含固定数量的网格
 * */
// 通过构造函数，指定矩形的大小和分割粒度
AOIWorld::AOIWorld(int _x_begin, int _x_end,
                   int _y_begin, int _y_end,
                   int _x_count, int _y_count) : x_begin(_x_begin), x_end(_x_end),
                                                 y_begin(_y_begin), y_end(_y_end),
                                                 x_count(_x_count), y_count(_y_count)
{
    // x轴网格宽度=(x轴结束坐标-x轴起始坐标)/x轴网格数量；
    // y轴的计算方式相同
    x_width = (x_end - x_begin) / x_count;
    y_width = (y_end - y_begin) / y_count;

    //创建格子
    for (int i = 0, Count = x_count * y_count; i < Count; ++i)
    {
        Grid grid;
        m_grids.push_back(grid);
    }
}
AOIWorld::~AOIWorld()
{
}
// 核心功能：获取周围玩家
std::list<Player *> AOIWorld::GetSurrendPlayers(Player *_player)
{
    list<Player *> ret;

    // 计算所属编号
    // 网格编号=(x-x轴起始坐标)/x轴网格宽度 + (y-y轴起始坐标)/y轴宽度*x轴网格数量
    int grid_id = (_player->GetX() - x_begin) / x_width +
                  (_player->GetY() - y_begin) / y_width * x_count;
    //判断具体情况，取出邻居网格的玩家们
    //计算当前网格横向在第几个格，纵向在第几个格
    int x_index = grid_id % x_count;
    int y_index = grid_id / x_count;
    if (x_index >= 1 && y_index >= 1)
    {
        // 有左上角的格子
        // 把左上角格子中的所有玩家取出来
        ret.insert(ret.begin(),
                   m_grids[grid_id - 1 - x_count].m_players.begin(),
                   m_grids[grid_id - 1 - x_count].m_players.end());
    }
    if (y_index >= 1)
    {
        // 有正上方的格子
        // 把正上方格子中的所有玩家取出来
        ret.insert(ret.begin(),
                   m_grids[grid_id - x_count].m_players.begin(),
                   m_grids[grid_id - x_count].m_players.end());
    }
    if (x_index <= (x_count - 2) && y_index >= 1)
    {
        // 有右上角的格子
        // 把右上角格子中的所有玩家取出来
        ret.insert(ret.begin(),
                   m_grids[grid_id - x_count + 1].m_players.begin(),
                   m_grids[grid_id - x_count + 1].m_players.end());
    }
    if (x_index >= 1)
    {
        // 有左侧的格子
        // 把左侧格子中的所有玩家取出来
        ret.insert(ret.begin(),
                   m_grids[grid_id - 1].m_players.begin(),
                   m_grids[grid_id - 1].m_players.end());
    }
    {
        // 本格子中的玩家
        // 把本格子中的所有玩家取出来
        ret.insert(ret.begin(),
                   m_grids[grid_id].m_players.begin(),
                   m_grids[grid_id].m_players.end());
    }
    if (x_index <= (x_count - 2))
    {
        // 有右侧的格子
        // 把右侧格子中的所有玩家取出来
        ret.insert(ret.begin(),
                   m_grids[grid_id + 1].m_players.begin(),
                   m_grids[grid_id + 1].m_players.end());
    }
    if (x_index >= 1 && y_index <= (y_count - 2))
    {
        // 有左下角的格子
        // 把左下角格子中的所有玩家取出来
        ret.insert(ret.begin(),
                   m_grids[grid_id + x_count - 1].m_players.begin(),
                   m_grids[grid_id + x_count - 1].m_players.end());
    }
    if (y_index <= (y_count - 2))
    {
        // 有正下方的格子
        // 把正下方格子中的所有玩家取出来
        ret.insert(ret.begin(),
                   m_grids[grid_id + x_count].m_players.begin(),
                   m_grids[grid_id + x_count].m_players.end());
    }
    if (x_index <= (x_count - 2) && y_index <= (y_count - 2))
    {
        // 有左下角的格子
        // 把左下角格子中的所有玩家取出来
        ret.insert(ret.begin(),
                   m_grids[grid_id + x_count + 1].m_players.begin(),
                   m_grids[grid_id + x_count + 1].m_players.end());
    }

    return ret;
}
// 添加玩家到AOI网格
bool AOIWorld::AddPlayer(Player *_player)
{
    // 计算Player所属的网格号
    // 网格编号=(x-x轴起始坐标)/x轴网格宽度 + (y-y轴起始坐标)/y轴宽度*x轴网格数量
    int grid_id = (_player->GetX() - x_begin) / x_width +
                  (_player->GetY() - y_begin) / y_width * x_count;
    // 添加到该网格中
    m_grids[grid_id].m_players.push_back(_player);
    return true;
}
// 摘除AOI网格中的玩家
void AOIWorld::DelPlayer(Player *_player)
{
    // 计算Player所属的网格号
    int grid_id = (_player->GetX() - x_begin) / x_width +
                  (_player->GetY() - y_begin) / y_width * x_count;
    // 从该网格中删除Player
    m_grids[grid_id].m_players.remove(_player);
}