#include "ZinxTimer.h"
#include <sys/timerfd.h>
#include <vector>
#include <list>
/*
 * 产生超时事件，timerfd
 */
bool ZinxTimerChannel::Init()
{
    //正向判断：判断成功的情况，失败的情况正常忽略掉，
    bool bRet = false;

    //创建文件描述符
    int iFd = timerfd_create(CLOCK_MONOTONIC, 0);
    if (iFd >= 0)
    {
        //设置定时周期
        struct itimerspec TimePeriod = {{1, 0},
                                        {1, 0}};
        if (0 == timerfd_settime(iFd, 0, &TimePeriod, NULL))
        {
            m_TimerFd = iFd;
            bRet = true;
        }
    }

    return bRet;
}

bool ZinxTimerChannel::ReadFd(std::string &_input)
{
    bool bRet = false;
    char buff[8] = {0};
    if (sizeof(buff) == read(m_TimerFd, buff, sizeof(buff)))
    {
        _input.assign(buff, sizeof(buff));
        bRet = true;
    }
    return bRet;
}
bool ZinxTimerChannel::WriteFd(std::string &_output)
{
    return false;
}
void ZinxTimerChannel::Fini()
{
    close(m_TimerFd);
    m_TimerFd = -1;
}
int ZinxTimerChannel::GetFd()
{
    return m_TimerFd;
}
std::string ZinxTimerChannel::GetChannelInfo()
{
    return "TimerFd";
}
AZinxHandler *ZinxTimerChannel::GetInputNextStage(BytesMsg &_oInput)
{
    return &TimeOutManager::GetInstance();
}
/*
 * 本类：管理超时任务，处理超时事件，任务分发
 * 作为TimeOut_Channel的下一个处理环节
 * 所有继承AZinxHandler
 */
// 单例的定义语句
TimeOutManager TimeOutManager::single;
// 构造函数：齿轮个数
//TimeOutManager::TimeOutManager(int TimeRoundNumTemp = 10) : TimeRoundNum{TimeRoundNumTemp}
TimeOutManager::TimeOutManager()
{
    // 默认创建10个齿
    int i = 0;
    for (i = 0; i < TimeRoundNum; ++i)
    {
        std::list<TimeOutProcess *> tmp;
        m_time_wheel.push_back(tmp);
    }
}
// 处理超时事件，遍历所有的超时任务
IZinxMsg *TimeOutManager::InternelHandle(IZinxMsg &_oInput)
{
    // 某个子环节比较耗时，有可能其他超时任务超时了好几次，那么超时几次我们处理几次
    unsigned long iTimeOutCount = 0;

    GET_REF2DATA(BytesMsg, obytes, _oInput);
    // 调用sting.copy()把string中的数字，转换为原来的整数类型
    obytes.szData.copy((char *)&iTimeOutCount, sizeof(iTimeOutCount), 0);

    while (iTimeOutCount-- > 0)
    {
        // 移动刻度
        current_TimeRound_index++;
        current_TimeRound_index %= TimeRoundNum;
        // 遍历当前刻度所有节点；
        // 若圈数为0，执行处理函数，摘除本节点，重新添加；
        // 若圈数不为0，圈数减一
        std::list<TimeOutProcess *> m_cache;//缓存超时的任务
        for (std::list<TimeOutProcess *>::iterator itr = m_time_wheel[current_TimeRound_index].begin();
             itr != m_time_wheel[current_TimeRound_index].end();)
        {
            if ((*itr)->iCount <= 0)
            {
                //有安全隐患，比如Proc()函数汇总调用了DelTask(),那么itr已经失效，接下来再操作itr都是违法的
                //(*itr)->Proc();
                //缓存待处理的超时节点,后面统一处理，避免了itr失效
                m_cache.push_back((*itr));

                TimeOutProcess *&pTmp = (*itr);
                itr = m_time_wheel[current_TimeRound_index].erase(itr);
                AddTask(pTmp);
            }
            else
            {
                (*itr)->iCount--;
                ++itr;
            }
        }
        //统一处理待处理超时任务
        for (TimeOutProcess *&task : m_cache)
        {
            task->Proc();
        }
    }

    return nullptr;
}

AZinxHandler *TimeOutManager::GetNextHandler(IZinxMsg &_oNextMsg)
{
    return nullptr;
}

void TimeOutManager::AddTask(TimeOutProcess *_poTask)
{
    //计算当前任务需要添加到哪个齿
    int index = (_poTask->GetTimeSecond() + current_TimeRound_index) % TimeRoundNum;
    //计算所需圈数
    _poTask->iCount = _poTask->GetTimeSecond() / TimeRoundNum;
    //把任务存到该齿上
    m_time_wheel[index].push_back(_poTask);
}
void TimeOutManager::DelTask(TimeOutProcess *_poTask)
{
    //遍历时间轮所有齿，删除特定定时器任务
    for (std::list<TimeOutProcess *> &chi : m_time_wheel)
    {
        for (TimeOutProcess *&task : chi)
        //for (TimeOutProcess *task : chi)
        {
            if (task == _poTask)
            {
                chi.remove(_poTask);
                return;
            }
        }
    }
}