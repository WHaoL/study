#pragma once
// 初始化监听的套接字
int initListen(unsigned short port);
// 初始化并启动epoll
int epollRun(int lfd);
// 接受客户端连接
int acceptConn(int lfd, int epfd);
// 接受客户端的请求数据
int recvRequstMsg(int cfd);
// 读请求行
int getRequestLine(int cfd, char* reqMsg);
// 解析请求行
int parseRequestLine(int cfd, char * reqLine);
// 发送响应头
int sendRespondHead(int cfd, int status, const char* desc, const char* type, int length);
// 发送文件
int sendFile(int cfd, const char* filename);
// 发送目录
int sendDir(int cfd, const char* dirname);
// 根据文件名得到文件类型
const char *getFileType(const char *name);
int hexit(char c);
void decode_str(char *to, char *from);
