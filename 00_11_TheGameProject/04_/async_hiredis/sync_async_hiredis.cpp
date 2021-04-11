#include <cstdio>
#include <hiredis/hiredis.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <hiredis/async.h>
#include <event.h>
#include <hiredis/adapters/libevent.h>
using namespace std;
//---------------------------------------------------------------
//day15PM 
//redis异步机制--此处实现：发布订阅(异步)
//同步发 异步收
//---------------------------------------------------------------

//---------------------------------------------------------------
//redis同步机制
void redis_sync()
{
	auto pc = redisConnect("127.0.0.1", 6379);
	if (NULL != pc)
	{
		freeReplyObject(redisCommand(pc, "subscribe 1"));
		//接收redis发来的数据
		redisReply *reply = NULL;
		redisGetReply(pc, (void **)&reply);

		cout << "message from channel:" << string(reply->element[1]->str) << endl;
		cout << "message content is:" << string(reply->element[2]->str) << endl;


		redisFree(pc);
	}
}
//---------------------------------------------------------------
//redis异步机制--此处实现：发布订阅(异步)
//同步发 异步收
void my_callback(redisAsyncContext *c, void *preply, void *privdata)
{
	redisReply *reply = (redisReply *)preply;
	//只处理publish的数据
	if ("message" == string(reply->element[0]->str))
	{
		cout << "message from channel:" << string(reply->element[1]->str) << endl;
		cout << "message content is:" << string(reply->element[2]->str) << endl;
	}
}

void redis_async()
{
	//1. 创建libevent实例
	auto base = event_base_new();
	//2. 创建异步连接
	auto pc = redisAsyncConnect("127.0.0.1", 6379);
	//3. 关联libevent实例和异步连接
	redisLibeventAttach(pc, base);
	//4. 异步发消息(指定回复处理函数)
	redisAsyncCommand(pc, my_callback , NULL, "subscribe 1");
	//5. 开始事件循环
	event_base_dispatch(base);
}
//---------------------------------------------------------------
int main()
{
	redis_async();

	getchar();
    return 0;
}