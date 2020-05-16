#include "server.h"
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <dirent.h>

int initListen(unsigned short port)
{
	// 1. 创建监听的fd
	int lfd = socket(AF_INET, SOCK_STREAM, 0);
	if(lfd == -1)
	{
		perror("socket");
		exit(0);
	}
	// 2. lfd和本地ip port绑定
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);
	// 2.5 设置端口复用
	int opt = 1;
	int ret = setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	if(ret == -1)
	{
		perror("setsockopt");
		exit(0);
	}

	ret = bind(lfd, (struct sockaddr*)&addr, sizeof(addr));
	if(ret == -1)
	{
		perror("bind");
		exit(0);
	}
	// 3. 设置监听
	ret = listen(lfd, 128);
	if(ret == -1)
	{
		perror("listenk");
		exit(0);
	}

	return lfd;
}

int epollRun(int lfd)
{
	// 1. 创建epoll模型
	int epfd = epoll_create(10);
	if(epfd == -1)
	{
		perror("epoll_create");
		exit(0);
	}
	// 2. 将lfd挂到树上
	struct epoll_event ev;
	ev.data.fd = lfd;
	ev.events = EPOLLIN;
	int ret = epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);
	if(ret == -1)
	{
		perror("epoll_ctl");
		exit(0);
	}
	// 3. 检测
	struct epoll_event events[1024];
	int len = sizeof(events) / sizeof(struct epoll_event);
	while (1)
	{
		int num = epoll_wait(epfd, events, len, -1);
		for (int i = 0; i < num; ++i)
		{
			int curfd = events[i].data.fd;
			// 3.1 有新连接
			if (curfd == lfd)
			{
				// 接受连接
				acceptConn(lfd, epfd);
			}
			// 3.2 通信
			else
			{
				// 接收数据
				recvRequstMsg(curfd);
			}
		}
	}
	return 0;
}

int acceptConn(int lfd, int epfd)
{
	struct sockaddr_in cliaddr;
	int len = sizeof(cliaddr);
	// 接受客户端连接
	int cfd = accept(lfd, (struct sockaddr*)&cliaddr, &len);
	if(cfd == -1)
	{
		perror("accept");
		exit(0);
	}
	
	// 设置cfd非阻塞
	int flag = fcntl(cfd, F_GETFL);
	flag |= O_NONBLOCK;
	fcntl(cfd, F_SETFL, flag);
	
	// 设置边沿模式
	struct epoll_event ev;
	ev.events = EPOLLIN | EPOLLET;
	ev.data.fd = cfd;
	
	// cfd添加到树上
	int ret = epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
	if(ret == -1)
	{
		perror("epoll_ctl");
		exit(0);
	}

	return 0;
}

int getRequestLine(int cfd, char* reqMsg)
{
	// 因为通信的cfd为非阻塞 -> 并且epoll是边沿模式
	int total = 0, len = 0;

	char buf[256];
	while ((len = recv(cfd, buf, sizeof(buf), 0)) > 0)
	{
		// 将每次读到的数据拼接
		strcpy(reqMsg + total, buf);
		total += len;
	}
	printf("recv client data: \n");
	printf("%s\n", reqMsg);
	if (len == -1)
	{
		if (errno == EAGAIN || errno == EWOULDBLOCK)
		{
			// 数据读完了
			// 取出第一行 -> 请求行
			char* pt = strstr(reqMsg, "\r\n");
			int lineLen = pt - reqMsg;
			reqMsg[lineLen] = '\0';
		}
		else
		{
			perror("recv");
			return -1;
		}
	}
	else if (len == 0)
	{
		printf("客户端已经断开了连接...\n");
		return -1;
	}

	return 0;
}

int parseRequestLine(int cfd, char * reqLine)
{
	// 请求行分三部分  GET /xxx/xxx http/1.1
	char method[12];	// post/get
	char path[4096];	// 路径
	sscanf(reqLine, "%[^ ] %[^ ]", method, path);
	printf("request line: %s\n", reqLine);
	// 判断客户端请求是不是get
	if (strcasecmp(method, "get") != 0)
	{
		printf("用户提交的不是get请求, 忽略处理...\n");
		return -1;
	}
	// 转码
	decode_str(path, path);
	// 是get请求 -> 判断path中是目录还是文件
	// path: /xxx/xxx ->  需要取得第一个/ 得到  ./xxx/xxx == xxx/xxx
	// path: / -> 服务器资源根目录, 需要设置   ==> 对于当前进程来说 ./
	char* file = NULL;	// 存储文件名, 使用的相对路径
	if (strcmp(path, "/") == 0)
	{
		file = "./";
	}
	else
	{
		file = path + 1;
	}
	// 判断这个文件的属性 ->文件还是目录
	struct stat st;
	int ret = stat(file, &st);
	if(ret == -1)
	{
		perror("stat");
		//  如果没有, 发送404
		sendRespondHead(cfd, 404, "not found", getFileType("404.html"), -1);
		sendFile(cfd, "404.html");
		return -1;
	}
	// 判断是不是目录
	if (S_ISDIR(st.st_mode))
	{
		// 发送-> 客户端 -> 是 http响应
		// 状态行  消息报头 空行  回复的数据
		// 发送目录的内容给客户端
		sendRespondHead(cfd, 200, "OK", getFileType(".html"), -1);
		sendDir(cfd, file);
	}
	else
	{
		// 发送文件内容给客户端
		sendRespondHead(cfd, 200, "OK", getFileType(file), st.st_size);
		sendFile(cfd, file);
	}

	return 0;
}

int sendRespondHead(int cfd, int status, const char* desc, 
	const char* type, int length)
{
	char buf[1024];
	// 状态行
	sprintf(buf, "http/1.1 %d %s\r\n", status, desc);
	// 消息报头 + 空行
	sprintf(buf + strlen(buf), "content-type: %s\r\n", type);
	sprintf(buf + strlen(buf), "content-length: %d\r\n\r\n", length);
	// 发送消息
	send(cfd, buf, strlen(buf), 0);
	return 0;
}

int sendFile(int cfd, const char * filename)
{
	// 打开文件
	int fd = open(filename, O_RDONLY);
	if(fd == -1)
	{
		perror("open");
		return -1;
	}
	
	// 读文件
	int len = 0;
	char buf[512];
	while ((len = read(fd, buf, sizeof(buf))) > 0)
	{
		// 将读出的内容发送给客户端
		send(cfd, buf, len, 0);
		usleep(300);
	}
	close(fd);

	return 0;
}

// 需要将目录中的文件读出, 将其放到一个table表中 -> html 中的talbe
// 在服务器端拼一个网页发送给浏览器
/*
	<html>
		<head><title>标题</title></head>
		<body>
			<table>
				<tr>
					<td></td>
					<td></td>
				</tr>
			</table>
		</body>
	</html>
*/
int sendDir(int cfd, const char * dirname)
{
#if 0
	// 1. 打开目录
	DIR* dir = opendir(dirname);
	if(dir == NULL)
	{
		perror("opendir");
		return -1;
	}
	// 2. 遍历目录中的文件
	struct dirent* ptr = NULL;
	while ((ptr = readdir(dir)) != NULL)
	{
		char* name = ptr->d_name;
	}
	// 3. 关闭目录
	closedir(dir);
#else
	char buf[4096];
	sprintf(buf, "<html><head><title>%s</title></head><body><table>", dirname);
	struct dirent **ptr;
	int num = scandir(dirname, &ptr, NULL, alphasort);
	for (int i = 0; i < num; ++i)
	{
		// 取出文件名
		char* name = ptr[i]->d_name;
		char path[1024];
		sprintf(path, "%s%s", dirname, name);
		struct stat st;
		int ret = stat(path, &st);
		if(ret == -1)
		{
			perror("stat");
			sendRespondHead(cfd, 404, "not found", getFileType("404.html"), -1);
			sendFile(cfd, "404.html");
			return -1;
		}
		printf("当前文件的相对路径: %s\n", path);
		if (S_ISDIR(st.st_mode))
		{
			sprintf(buf + strlen(buf), 
				"<tr><td><a href=\"%s/\">%s/</a><td><td>%ld</td></tr>",
				name, name, st.st_size);
		}
		else
		{
			sprintf(buf + strlen(buf), 
				"<tr><td><a href=\"%s\">%s</a><td><td>%ld</td></tr>",
				name, name, st.st_size);
		}
		// 发送数据
		send(cfd, buf, strlen(buf), 0);
		printf("%s", buf);
		memset(buf, 0, sizeof(buf));
	}
	sprintf(buf, "</table></body></html>");
	printf("%s", buf);
	send(cfd, buf, strlen(buf), 0);
#endif
	// 4. 发送得到的所有的文件名到客户端
	return 0;
}

// newptr = realloc(ptr, size);
int recvRequstMsg(int cfd)
{
	char reqMsg[4096];
	// 将请求行读出来
	int ret = getRequestLine(cfd, reqMsg);
	// 将请求行第二部分读出来并解析
	if (ret == 0)
	{
		parseRequestLine(cfd, reqMsg);
	}

	return 0;
}

// 通过文件名获取文件的类型
const char *getFileType(const char *name)
{
	char* dot;

	// 自右向左查找‘.’字符, 如不存在返回NULL
	dot = strrchr(name, '.');
	if (dot == NULL)
		return "text/plain; charset=utf-8";
	if (strcmp(dot, ".html") == 0 || strcmp(dot, ".htm") == 0)
		return "text/html; charset=utf-8";
	if (strcmp(dot, ".jpg") == 0 || strcmp(dot, ".jpeg") == 0)
		return "image/jpeg";
	if (strcmp(dot, ".gif") == 0)
		return "image/gif";
	if (strcmp(dot, ".png") == 0)
		return "image/png";
	if (strcmp(dot, ".css") == 0)
		return "text/css";
	if (strcmp(dot, ".au") == 0)
		return "audio/basic";
	if (strcmp(dot, ".wav") == 0)
		return "audio/wav";
	if (strcmp(dot, ".avi") == 0)
		return "video/x-msvideo";
	if (strcmp(dot, ".mov") == 0 || strcmp(dot, ".qt") == 0)
		return "video/quicktime";
	if (strcmp(dot, ".mpeg") == 0 || strcmp(dot, ".mpe") == 0)
		return "video/mpeg";
	if (strcmp(dot, ".vrml") == 0 || strcmp(dot, ".wrl") == 0)
		return "model/vrml";
	if (strcmp(dot, ".midi") == 0 || strcmp(dot, ".mid") == 0)
		return "audio/midi";
	if (strcmp(dot, ".mp3") == 0)
		return "audio/mpeg";
	if (strcmp(dot, ".ogg") == 0)
		return "application/ogg";
	if (strcmp(dot, ".pac") == 0)
		return "application/x-ns-proxy-autoconfig";

	return "text/plain; charset=utf-8";
}

// 16进制数转化为10进制
int hexit(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	if (c >= 'A' && c <= 'F')
		return c - 'A' + 10;

	return 0;
}

// 解码
void decode_str(char *to, char *from)
{
	for (; *from != '\0'; ++to, ++from)
	{
		// isxdigit -> 判断字符是不是16进制格式
		if (from[0] == '%' && isxdigit(from[1]) && isxdigit(from[2]))
		{
			// 将16进制的数 -> 十进制 将这个数值赋值给了字符 int -> char
			*to = hexit(from[1]) * 16 + hexit(from[2]);

			from += 2;
		}
		else
		{
			*to = *from;

		}

	}
	*to = '\0';
}

