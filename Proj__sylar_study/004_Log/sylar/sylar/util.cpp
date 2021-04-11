#include "util.h"
namespace sylar
{
    pid_t GetThreadId() //获取进程ID
    {
        return syscall(SYS_gettid);
    }
    uint32_t GetFiberId() //获取协程ID
    {
        return 0; // 写完协程以后再来完善
    }
    
}
