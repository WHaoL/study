#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hiredis/hiredis.h>

int main()
{
	const char *ip = "127.0.0.1"; //ip
	int port = 6379;			  //port
	redisContext *context;		  //管理连接服务器的指针
	redisReply *reply;			  //执行命令后返回的结构体指针，存储了处理结果

	//1.连接redis服务器
	context = redisConnect(ip, port);
	if (context == NULL || context->err)
	{
		if (context)
		{
			printf("Connection error contex->errstr: %s\n", context->errstr);
			redisFree(context);
		}
		else
		{
			printf("Connection error: can't allocate redis context\n");
		}
		exit(1);
	}
	//2.执行操作
	reply = (redisReply *)redisCommand(context, "hmset user name zhangsanfeng age 24 sex man password 123456");
	if (reply->type == 5)
	{
		printf("命令执行完毕，状态码：%s\n", reply->str);
	}
	freeReplyObject(reply);
	// 将hash的value值读出
	reply = (redisReply *)redisCommand(context, "hgetall user");
	if (reply->type == 2)
	{
		//遍历数组
		for (int i = 0; i < reply->elements; i += 2)
		{
			printf("%s : %s\n", reply->element[i]->str, reply->element[i + 1]->str);
		}
	}
	freeReplyObject(reply);

	//3.断开连接
	redisFree(context);

	return 0;
}