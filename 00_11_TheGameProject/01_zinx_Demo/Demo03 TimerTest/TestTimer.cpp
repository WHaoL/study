#include <sys/timerfd.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int iTimerfd = timerfd_create(CLOCK_MONOTONIC, 0);

    struct itimerspec TimerPeriod = {{5, 0}, {1, 0}};
    /*     TimerPeriod.it_interval.tv_sec = 5;
    TimerPeriod.it_interval.tv_nsec = 0;
    TimerPeriod.it_value.tv_sec = 1;
    TimerPeriod.it_value.tv_nsec = 0; */
    timerfd_settime(iTimerfd, 0, &TimerPeriod, nullptr);

    while (1)
    {
		// 此处使用read()，项目中是使用epoll IO多路复用
        __uint64_t count = 0;
        read(iTimerfd, &count, sizeof(count));

        puts("time out");
    }

    return 0;
}