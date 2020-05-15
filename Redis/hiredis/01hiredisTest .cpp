#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <sstream>
#include <hiredis/hiredis.h> //头文件在 /usr/local/include/hiredis/
using namespace std;
/*
    1、调用RedisConnect()建立连接
    2、调用redisCommand()发送命令
    3、接收回复，封装parse()解析Redis执行后的数据(Redis的回复)
*/

//parse()函数 解析redis回复的数据
//只能解析基本类型--复杂类型，封装为了单个函数进行处理(下面都有)
void parse(redisReply *reply)
{
    int seq = 0;
    if (NULL == reply)
    {
        printf("redisReplay id NULL\n");
        return;
    }
    switch (reply->type) //根据回复Redis数据库回复的类型，进行解析
    {

    //返回了一个状态回复
    case REDIS_REPLY_STATUS:
        cout << "REDIS_REPLY_STATUS：" << reply->str << endl; //打印：状态字符串
        break;

    //返回了一个错误
    case REDIS_REPLY_ERROR:
        cout << "REDIS_REPLY_ERROR：" << reply->str << endl; //打印：错误字符串
        break;

    //返回了一个整数应答
    case REDIS_REPLY_INTEGER:
        cout << "REDIS_REPLY_INTEGER：" << reply->integer << endl; //打印：这个整数值
        break;

    //返回了一个nil对象/零对象,没有数据可以访问
    case REDIS_REPLY_NIL:
        cout << "REDIS_REPLY_NIL：NULL" << endl; //打印：NULL
        break;

    //返回了一个大容量(字符串)
    case REDIS_REPLY_STRING:
        cout << "REDIS_REPLY_STRING：" << reply->str << endl; //打印：应答的值
        break;

    //返回了一个多批量回复(字符串)
    case REDIS_REPLY_ARRAY: //reply->element 也是有类型的，不都是string
        cout << "---REDIS_REPLY_ARRAY---" << endl;
        while (seq < reply->elements)
        {
            //REDIS_REPLY_ARRAY里每一个elements[i]都是一个指向 redisReply的指针
            parse(reply->element[seq++]);
        }
        break;

    default:
        break;
    }
}

//测试1.1、string
void TestString(redisContext *&context, redisReply *&reply)
{

    cout << "测试1.1、string" << endl;
    reply = (redisReply *)redisCommand(context, "set name zhang3");
    parse(reply);
    freeReplyObject(reply);
    reply = (redisReply *)redisCommand(context, "get name");
    parse(reply);
    freeReplyObject(reply);
    reply = (redisReply *)redisCommand(context, "del name");
    parse(reply);
    freeReplyObject(reply);
}

//测试1.2、string的二进制
void TestStringBinary(redisContext *&context, redisReply *&reply)
{
    cout << "测试1.2、string的二进制" << endl;
    char name[] = "zhang3-----123456789-----test--Binary secure transmission";
    reply = (redisReply *)redisCommand(context, "set name %b", name, (size_t)(strlen(name)));
    parse(reply);
    freeReplyObject(reply);
    reply = (redisReply *)redisCommand(context, "get name");
    parse(reply);
    freeReplyObject(reply);
    reply = (redisReply *)redisCommand(context, "del name");
    parse(reply);
    freeReplyObject(reply);
}

//测试2、hash
void TestHash(redisContext *&context, redisReply *&reply)
{
    cout << "测试2、hash" << endl;
    reply = (redisReply *)redisCommand(context, "hmset user name zhang3 age 24 sex man passwd 123456");
    parse(reply);
    freeReplyObject(reply);
    reply = (redisReply *)redisCommand(context, "hgetall user");
    parse(reply);
    freeReplyObject(reply);
    reply = (redisReply *)redisCommand(context, "del user");
    parse(reply);
    freeReplyObject(reply);
}

//测试3、set
void Testset(redisContext *&context, redisReply *&reply)
{
    cout << "测试3、set" << endl;
    reply = (redisReply *)redisCommand(context, "sadd user name_zhang3 age_24 sex_man passwd_123456");
    parse(reply);
    freeReplyObject(reply);
    reply = (redisReply *)redisCommand(context, "smembers user");
    parse(reply);
    freeReplyObject(reply);
    reply = (redisReply *)redisCommand(context, "del user");
    parse(reply);
    freeReplyObject(reply);
}

//测试4、zset
void Testzset(redisContext *&context, redisReply *&reply)
{
    cout << "测试4、zset" << endl;
    reply = (redisReply *)redisCommand(context, "zadd user 1 name_zhang3 2 age_24 3 sex_man 4 passwd_123456");
    parse(reply);
    freeReplyObject(reply);
    reply = (redisReply *)redisCommand(context, "zrangebyscore user 0 4 withscores");
    parse(reply);
    freeReplyObject(reply);
    reply = (redisReply *)redisCommand(context, "del user");
    parse(reply);
    freeReplyObject(reply);
}

//测试5、set get 把struct写入redis
//二进制写入读取
void set_get_TestStruct(redisContext *&context, redisReply *&reply)
{
    cout << "测试5、set get 把struct写入redis" << endl;
    struct Test
    {
        uint32_t a;
        uint32_t b;
        uint32_t c;
        char str1[20];
    };
    struct Test testStruct = {100, 0, 2000, "hello world"};
    /* string _str;
    _str.assign((char *)&test, sizeof(test)); */

    //-----------------------------------set---------------------------------//
    const char *vvv[3];
    size_t vvv_len[3];

    vvv[0] = "set"; //设置set
    vvv_len[0] = strlen("set");

    vvv[1] = "InfoStruct"; //设置key的名字
    vvv_len[1] = strlen("InfoStruct");

    vvv[2] = (const char *)&testStruct; //把结构体地址设置进去
    vvv_len[2] = sizeof(testStruct);

    reply = (redisReply *)redisCommandArgv(context, sizeof(vvv) / sizeof(vvv[0]), vvv, vvv_len);
    parse(reply);
    freeReplyObject(reply);
    //-----------------------------------get---------------------------------//
    cout << "------------InfoStruct_get 等待进入------------" << endl;
    reply = (redisReply *)redisCommand(context, "get InfoStruct");
    if (reply->len == sizeof(struct Test))
    {
        cout << "------------InfoStruct_get 已进入------------" << endl;
        Test *temp = (Test *)malloc(sizeof(Test));
        memcpy(temp, reply->str, reply->len);
        cout << "temp --> uint32_t a =  " << temp->a << endl
             << "temp --> uint32_t b =  " << temp->b << endl
             << "temp --> uint32_t c =  " << temp->c << endl
             << "temp --> string str1 =  " << temp->str1 << endl;
        free(temp);
    }
    freeReplyObject(reply);

    reply = (redisReply *)redisCommand(context, "del userInformation");
    parse(reply);
    freeReplyObject(reply);
}

//测试6、zzset zget 把struct写入redis
//二进制写入读取
void zset_zget_TestStruct(redisContext *&context, redisReply *&reply)
{
    cout << "测试6、zzset zget 把struct写入redis" << endl;
    struct Test
    {
        uint32_t a;
        uint32_t b;
        uint32_t c;
        char str1[20];
    };
    struct Test testStruct = {100, 0, 2000, "hello world"};
    //-----------------------------------zadd---------------------------------//
    const char *vvv[4];
    size_t vvv_len[4];

    vvv[0] = "zadd"; //设置zset
    vvv_len[0] = strlen("zadd");

    vvv[1] = "InfoStruct_Zset"; //设置集合的名字
    vvv_len[1] = strlen("InfoStruct_Zset");

    std::stringstream ssss;
    ssss << time(0); //时间作为score
    vvv[2] = ssss.str().c_str();
    vvv_len[2] = ssss.str().size();

    vvv[3] = (const char *)&testStruct; //把结构体地址设置进去
    vvv_len[3] = sizeof(testStruct);

    reply = (redisReply *)redisCommandArgv(context, sizeof(vvv) / sizeof(vvv[0]), vvv, vvv_len);
    parse(reply);
    freeReplyObject(reply);
    //-----------------------------------zget---------------------------------//
    cout << "------------InfoStruct_Zget 等待进入------------" << endl;
    reply = (redisReply *)redisCommand(context, "zrange InfoStruct_Zset 0 -1");
    if (reply)
    {
        cout << "------------InfoStruct_Zget 已进入------------" << endl;
        Test *temp = (Test *)malloc(sizeof(Test));
        for (int i = 0; i < reply->elements; i++)
        {
            if (reply->element[i]->len == sizeof(testStruct))
            {
                memcpy(temp, reply->element[i]->str, reply->element[i]->len);
                cout << "temp --> uint32_t a =  " << temp->a << endl
                     << "temp --> uint32_t b =  " << temp->b << endl
                     << "temp --> uint32_t c =  " << temp->c << endl
                     << "temp --> string str1 =  " << temp->str1 << endl;
            }
        }
        free(temp);
    }
    freeReplyObject(reply);

    reply = (redisReply *)redisCommand(context, "del userInformation");
    parse(reply);
    freeReplyObject(reply);
}


/*
先zadd，给USER 插入一些member和score ，--7、测试--会对这些插入进行zscan 
        127.0.0.1:6379> zadd USER 1 redis1
        (integer) 1
        127.0.0.1:6379> zadd USER 2 redis2
        (integer) 1
        127.0.0.1:6379> zadd USER 3 redis3
        (integer) 1
        127.0.0.1:6379> zadd USER 4 redis4
        (integer) 1
        127.0.0.1:6379> zadd USER 4 redis4
        (integer) 0
        127.0.0.1:6379> 
*/

//测试7、hiredis处理zscan和hscan的reply
void hscan_zscan_TestStruct(redisContext *&context, redisReply *&reply)
{
    //cLocal points to the local redis
    cout << "测试7、hiredis处理zscan和hscan的reply" << endl;
    int64_t current_Cursor = 0; //游标是64位的整型数
    bool done = false;          //标志位
    stringstream ssss;          //输入输出流
    string setName = " USER ";  //存储了key的名字
    string cmd = " ";
    while (!done)
    {
        //zscan语法
        //zscan keyname cursor match match_str count count_num
        ssss << "zscan " << setName << " %lld count 10"; //拼接命令

        reply = (redisReply *)redisCommand(context, ssss.str().c_str(), current_Cursor); //发送命令
        if (reply == NULL)                                                               //判断回复是否有效
        {
            cout << "scan " << setName << " failed,err is：" << context->errstr;
            redisFree(context);
            context = NULL;
            break;
        }

        if (reply->type == REDIS_REPLY_ARRAY) //判断回复的类型是不是REDIS_REPLY_ARRAY
        {
            if (reply->elements == 0)
            {
                done = true;
                cout << "get 0 message from " << setName << endl;
            }
            else
            {
                //更新游标
                //reply->element[0] contains cursor
                current_Cursor = (long long)reply->element[0]->str;

                //拿到返回的数组
                //reply->element[1] contains elements array:value1,score1,value2,score2,…
                redisReply **sitecounters = reply->element[1]->element;

                //reply->element[1]->elements记录了数组中的元素个数
                //遍历输出数组中的 member和score
                for (int i = 0; i < reply->element[1]->elements; ++i) //
                {
                    string member = sitecounters[i++]->str;
                    cout << "member：" << member << endl;

                    string score = sitecounters[i]->str;
                    cout << "score：" << score << endl;
                }
                if (current_Cursor == 0)
                {
                    done = true;
                }
            }
        }
        else
        {
            done = true;
        }
    }
    cout << "--------cmd--------" << ssss.str() << endl;
    freeReplyObject(reply);
}
//zrangebyscore 加withscores参数的用法、
int main()
{
    //1、调用RedisConnect()建立连接，并判断是否成功建立连接
    redisContext *context = redisConnect("127.0.0.1", 6379); //Redis默认监听端口
    if (context == NULL || context->err)
    {
        if (context)
        {
            cout << "Error：" << context->err << endl;
            redisFree(context);
        }
        else
        {
            cout << "Can't allocate redis context" << endl;
        }
        return -1;
    }
    redisReply *reply = (redisReply *)redisCommand(context, "set company changliaotianxia");

    //测试1.1、string
    TestString(context, reply);

    //测试1.2、string的二进制
    TestStringBinary(context, reply);

    //测试2、hash
    TestHash(context, reply);

    //测试3、set
    Testset(context, reply);

    //测试4、zset
    Testzset(context, reply);

    //测试5、set get 把struct写入redis
    //二进制写入读取
    set_get_TestStruct(context, reply);

    //测试6、zzset zget 把struct写入redis
    //二进制写入读取
    zset_zget_TestStruct(context, reply);

    //测试7、hiredis处理zscan和hscan的reply
    hscan_zscan_TestStruct(context, reply);

    //关闭连接
    redisFree(context);
    return 0;
}

/*
    /usr/local/include/hiredis/read.h
        
    #define REDIS_REPLY_STRING 1
    #define REDIS_REPLY_ARRAY 2
    #define REDIS_REPLY_INTEGER 3
    #define REDIS_REPLY_NIL 4
    #define REDIS_REPLY_STATUS 5
    #define REDIS_REPLY_ERROR 6
    #define REDIS_REPLY_DOUBLE 7
    #define REDIS_REPLY_BOOL 8
    #define REDIS_REPLY_VERB 9
    #define REDIS_REPLY_MAP 9
    #define REDIS_REPLY_SET 10
    #define REDIS_REPLY_ATTR 11
    #define REDIS_REPLY_PUSH 12
    #define REDIS_REPLY_BIGNUM 13
*/

// typedef struct redisReply
// {
//     int type;                    /* REDIS_REPLY_* */
//     long long integer;           /* The integer when type is REDIS_REPLY_INTEGER */  //3
//     double dval;                 /* The double when type is REDIS_REPLY_DOUBLE */   //7
//     size_t len;                  /* Length of string */
//     char *str;                   /* Used for REDIS_REPLY_ERROR, REDIS_REPLY_STRING   //1、7
//                                  and REDIS_REPLY_DOUBLE (in additionl to dval). */
//     size_t elements;             /* number of elements, for REDIS_REPLY_ARRAY */     //2
//     struct redisReply **element; /* elements vector for REDIS_REPLY_ARRAY */         //2
// } redisReply;

/*--使用了redisGetReply()
[root@bogon hiRedis Test]# g++ 003hiredisTest\ .cpp -o 003 -l hiredis
[root@bogon hiRedis Test]# ./003 

[root@bogon hiRedis Test]# ./003 
测试1.1、string
REDIS_REPLY_STATUS：OK
REDIS_REPLY_STRING：zhang3
REDIS_REPLY_INTEGER：1
测试1.2、string的二进制
REDIS_REPLY_STATUS：OK
REDIS_REPLY_STRING：zhang3-----123456789-----test--Binary secure transmission
REDIS_REPLY_INTEGER：1
测试2、hash
REDIS_REPLY_STATUS：OK
---REDIS_REPLY_ARRAY---
REDIS_REPLY_STRING：name
REDIS_REPLY_STRING：zhang3
REDIS_REPLY_STRING：age
REDIS_REPLY_STRING：24
REDIS_REPLY_STRING：sex
REDIS_REPLY_STRING：man
REDIS_REPLY_STRING：passwd
REDIS_REPLY_STRING：123456
REDIS_REPLY_INTEGER：1
测试3、set
REDIS_REPLY_INTEGER：4
---REDIS_REPLY_ARRAY---
REDIS_REPLY_STRING：passwd_123456
REDIS_REPLY_STRING：sex_man
REDIS_REPLY_STRING：name_zhang3
REDIS_REPLY_STRING：age_24
REDIS_REPLY_INTEGER：1
测试4、zset
REDIS_REPLY_INTEGER：4
---REDIS_REPLY_ARRAY---
REDIS_REPLY_STRING：name_zhang3
REDIS_REPLY_STRING：1
REDIS_REPLY_STRING：age_24
REDIS_REPLY_STRING：2
REDIS_REPLY_STRING：sex_man
REDIS_REPLY_STRING：3
REDIS_REPLY_STRING：passwd_123456
REDIS_REPLY_STRING：4
REDIS_REPLY_INTEGER：1
测试5、set get 把struct写入redis
REDIS_REPLY_STATUS：OK
------------InfoStruct_get 等待进入------------
------------InfoStruct_get 已进入------------
temp --> uint32_t a =  100
temp --> uint32_t b =  0
temp --> uint32_t c =  2000
temp --> string str1 =  hello world
REDIS_REPLY_INTEGER：0
测试6、zzset zget 把struct写入redis
REDIS_REPLY_INTEGER：0
------------InfoStruct_Zget 等待进入------------
------------InfoStruct_Zget 已进入------------
temp --> uint32_t a =  100
temp --> uint32_t b =  0
temp --> uint32_t c =  2000
temp --> string str1 =  hello world
REDIS_REPLY_INTEGER：0
测试7、hiredis处理zscan和hscan的reply
member：redis1
score：1
member：redis2
score：2
member：redis3
score：3
member：redis4
score：4
--------cmd--------zscan  USER  %lld count 10zscan  USER  %lld count 10
*/
/*--没使用redisGetReply()

*/