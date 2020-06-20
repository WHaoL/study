#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int myUpload(const char* confFile, const char* localFile, char* fileID, int size)
{
    // 1. 创建管道
    int fd[2];
    int ret = pipe(fd);
    if(ret == -1)
    {
        perror("pipe error");
        exit(0);
    }

    // 2. 创建子进程
    pid_t pid = fork();
    if(pid == 0)
    {
        // 子进程
        close(fd[0]);
        // 重定向
        dup2(fd[1], STDOUT_FILENO);
        // 子进执行execlp
        execlp("fdfs_upload_file", "fdfs_upload_file", confFile, localFile, NULL);
        perror("execlp error");
        exit(0);
    }
    else
    {
        // 父进程
        // 关闭管道的写端
        close(fd[1]);
        // 读管道
        read(fd[0], fileID, size);
        close(fd[1]);
        // 释放子进程
        wait(NULL);
    }
    return 0;
}

if (argc >= 4)
	{
		const char *pPort;
		const char *pIpAndPort;

		pIpAndPort = argv[3];
		pPort = strchr(pIpAndPort, ':');
		if (pPort == NULL)
		{
			fdfs_client_destroy();
			fprintf(stderr, "invalid storage ip address and " \
				"port: %s\n", pIpAndPort);
			usage(argv);
			return 1;
		}

		storageServer.sock = -1;
		snprintf(storageServer.ip_addr, sizeof(storageServer.ip_addr), \
			 "%.*s", (int)(pPort - pIpAndPort), pIpAndPort);
		storageServer.port = atoi(pPort + 1);
		if (argc >= 5)
		{
			store_path_index = atoi(argv[4]);
		}
		else
		{
			store_path_index = -1;
		}
	}
int main()
{
    char buf[1024];
    myUpload("/etc/fdfs/client.conf", "fdfs_upload.c", buf,1024);
    printf("fileID: %s\n", buf);
	return 0;
}
