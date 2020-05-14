#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    int i = 0;
    alarm(1);
    while(1)
    {
        printf("%d\n",++i);
    }
    return 0;
	
	
	// // 取消定时
	// int ret = alarm(10);
	// if(ret == 5)
	// {
	// 	alarm(0);	// 取消倒计时(参数为0，函数就不工作了)
	// }
}

