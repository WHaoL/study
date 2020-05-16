#include <stdio.h>
#include "server.h"
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		printf("eg: ./a.out port 资源目录\n");
		exit(0);
	}
	// ./a.out 9999 /home/hello
	// 初始化监听的套接字
	// 修改当前进程的工作目录
	chdir(argv[2]);	// 进程切换到资源目录的根目录
	unsigned short port = atoi(argv[1]);
	int lfd = initListen(port);
	// 启动epoll
	epollRun(lfd);

    return 0;
}