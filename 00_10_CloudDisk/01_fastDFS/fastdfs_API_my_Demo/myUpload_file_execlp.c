#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void myUpload_file_execlp(const char *conf_filename, const char *local_filename, char *file_id, int len)
{
	// 1.创建管道
	int fd[2];
	int ret = pipe(fd);
	if (-1 == ret)
	{
		perror("pipe error");
		exit(0);
	}

	// 2.创建子进程
	pid_t pid = fork();
	if (pid == 0)
	{
		//子进程
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execlp("fdfs_upload_file", "fdfs_upload_file", conf_filename, local_filename, NULL);
		perror("execlp() error");
		exit(-1);
	}
	else if (pid > 0)
	{
		//父进程
		close(fd[1]);
		read(fd[0], file_id, len);
		close(fd[0]);
		wait();
	}
}

int main()
{
	char file_id[1024] = {0};
	int len = sizeof(file_id);
	myUpload_file_execlp("/etc/fdfs/client.conf", "test.cpp", file_id, len);
	printf("file_id: %s", file_id);
	return 0;
}