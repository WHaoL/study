#include <hiredis.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void test_hiredis(const char *_ip, const int _port);
int main(int argc, char **argv)
{
    const char *ip = (argc > 1) ? argv[1] : "127.0.0.1";
    const int port = (argc > 2) ? atoi(argv[2]) : 6379;

    test_hiredis(ip, port);

    return 0;
}
void test_hiredis(const char *_ip, const int _port)
{
    /* connect redis */
    redisContext *C = redisConnect(_ip, _port);
    if (C == NULL || C->err)
    {
        if (C)
        {
            printf("Connection Error: %s\n", C->errstr);
        }
        else
        {
            printf("Connection error: can't allocate redis context\n");
        }
        exit(1);
    }

    /* PING server */
    redisReply *reply = (redisReply *)redisCommand(C, "PING");
    printf("PING:%s\n", reply->str);
    freeReplyObject(reply);

    /* Set a key */
    reply = (redisReply *)redisCommand(C, "SET %s %s", "foo", "Hello world foo");
    printf("SET: %s\n", reply->str);
    freeReplyObject(reply);

    /* Set a key using binary safe API */
    reply = (redisReply *)redisCommand(C, "SET %b %b", "bar", (size_t)3, "Hello world bar", (size_t)15);
    printf("SET (binary API): %s\n", reply->str);

    /* Try GET and two INCR */
    reply = (redisReply *)redisCommand(C, "GET foo");
    printf("GET foo: %s\n", reply->str);
    freeReplyObject(reply);
    reply = (redisReply *)redisCommand(C, "GET bar");
    printf("GET foo: %s\n", reply->str);
    freeReplyObject(reply);

    reply = (redisReply *)redisCommand(C, "INCR counter");
    printf("INCR counter: %lld\n", reply->integer);
    freeReplyObject(reply);
    reply = (redisReply *)redisCommand(C, "INCR counter");
    printf("INCR counter: %lld\n", reply->integer);
    freeReplyObject(reply);

    /* Create a list of numbers, from 0 to 9 */
    reply = (redisReply *)redisCommand(C, "DEL mylist");
    freeReplyObject(reply);
    for (int j = 0; j < 10; ++j)
    {
        char buf[64] = {'\0'};
        snprintf(buf, 64, "%u", j);
        reply = (redisReply *)redisCommand(C, "LPUSH mylist element_is_%s", buf);
        freeReplyObject(reply);
    }

    /* Let's check what we have inside the list */
    reply = (redisReply *)redisCommand(C, "LRANGE mylist 0 -1");
    if (reply->type == REDIS_REPLY_ARRAY)
    {
        for (int j = 0; j < reply->elements; ++j)
        {
            printf("%u) %s\n", j, reply->element[j]->str);
        }
    }
    freeReplyObject(reply);

    /* Disconnects and frees the context */
    redisFree(C);
}