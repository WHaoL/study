#ifndef __SYLAR_UTIL_H__
#define __SYLAR_UTIL_H__

#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <stdint.h>
#include <string>
namespace sylar
{
    pid_t GetThreadId();         //获取进程ID
    uint32_t GetFiberId();       //获取协程ID
    std::string GetThreadName(); //获取进程名称

}

#endif