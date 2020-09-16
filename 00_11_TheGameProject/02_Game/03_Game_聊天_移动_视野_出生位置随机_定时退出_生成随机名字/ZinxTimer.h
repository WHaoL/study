#ifndef __ZINXTIMER_H__
#define __ZINXTIMER_H__
#include <zinx.h>
#include <vector>
#include <list>

/*
 * 产生超时事件，timerfd
 */
class ZinxTimerChannel : public Ichannel
{
public:
    ZinxTimerChannel() {}
    virtual ~ZinxTimerChannel() {}

public:
    //创建定时器文件描述符timerfd
    virtual bool Init() override;
    //读取超时次数
    virtual bool ReadFd(std::string &_input) override;
    virtual bool WriteFd(std::string &_output) override;
    //关闭文件描述符timerfd
    virtual void Fini() override;
    //返回当前定时器文件描述符
    virtual int GetFd() override;
    //返回一个字符串，方便查找本类的对象
    virtual std::string GetChannelInfo() override;
    //超时事件，由该函数的返回对象来处理
    //返回处理超时事件的对象
    virtual AZinxHandler *GetInputNextStage(BytesMsg &_oInput) override;

private:
    int m_TimerFd = -1;
};

/*
 *超时任务类
 * 本类：处理具体的超时事件
 */
class TimeOutProcess
{
public:
    // 超时事件发生后干什么
    virtual void Proc() = 0;

    // 返回定时时间
    virtual int GetTimeSecond() = 0;

    //private:
    // 记录当前还有几秒达到定时
    // 记录所剩循环圈数
    int iCount = -1;
};

/*
 * 本类：管理超时任务，处理超时事件，任务分发
 * 作为TimeOut_Channel的下一个处理环节
 * 所有继承AZinxHandler
 */
class TimeOutManager : public AZinxHandler
{
public:
    // 处理超时事件，遍历所有的超时任务
    virtual IZinxMsg *InternelHandle(IZinxMsg &_oInput) override;
    virtual AZinxHandler *GetNextHandler(IZinxMsg &_oNextMsg) override;
    //添加一个定时器任务
    void AddTask(TimeOutProcess *_poTask);
    //删除一个定时器任务
    void DelTask(TimeOutProcess *_poTask);
    //获取单例
    static TimeOutManager &GetInstance()
    {
        return single;
    }

private:
    //单例的声明语句
    static TimeOutManager single;
    // 构造函数：齿轮个数
    TimeOutManager();

private:
    // 任务列表
    std::list<TimeOutProcess *> m_task_list;
    // vector : 存 齿轮
    // list   : 存 定时任务
    std::vector<std::list<TimeOutProcess *>> m_time_wheel;

    int current_TimeRound_index = 0; // 当前刻度在哪个齿上
    int TimeRoundNum = 10;           //齿轮个数,默认为10
};

#endif