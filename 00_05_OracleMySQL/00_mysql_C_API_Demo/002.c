#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASSWD "root123"
#define DB_NAME "lwh_scott"
#define DB_PORT 3306

// 1、初始化 连接mysql 设置当前连接的字符集
void mysql_init_connect_setCharacter(MYSQL *mysql)
{
	// 1.1、初始化
	if ((mysql_init(mysql)) == NULL)
	{
		fprintf(stderr, "Error in mysql_init()\n");
		exit(-1);
	}

	// 1.2、建立连接
	if (mysql_real_connect(
			mysql,
			DB_HOST,
			DB_USER,
			DB_PASSWD,
			DB_NAME,
			DB_PORT,
			NULL,
			0) == NULL)
	{
		fprintf(stderr, "Error in mysql_real_connect():%s\n", mysql_error(mysql));
		exit(-1);
	}
	else
	{
		printf("mysql_real_connect() -- 执行成功\n");
	}

	// 1.3、设置UTF8编码：因为有些时候显示乱码，所以需要设置
	if (mysql_set_character_set(mysql, "utf8") != 0)
	{
		fprintf(stderr, "Error in mysql_set_character_set():%s\n", mysql_error(mysql));
		//exit(-1);
	}
	else
	{
		printf("mysql_set_character_set() utf8 -- 执行成功\n");
	}
}

// 3、打印结果集
void printResultSet(MYSQL_RES *res)
{

	// 获得列数
	unsigned int num_fields = mysql_num_fields(res);

	//获得表头：各列的名字
	MYSQL_FIELD *fields = mysql_fetch_field(res);

	//输出表头：各列的名字
	unsigned int i = 0;
	for (i = 0; i < num_fields; ++i)
	{
		printf("%s\t", fields[i].name);
	}
	printf("\n-----------------------------------------------------------------\n");

	//输出表头下面的：各行数据
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res))) // != NULL
	{

		for (i = 0; i < num_fields; ++i)
		{

			printf("%s\t", row[i]);
		}
		printf("\n");
	}
}

// 2、获取用户输入并执行sql
// 调用 3、打印结果集
void getUserInputAndExecute(MYSQL *mysql, char sql[], unsigned int NUM)
{
	while (1)
	{
		memset(sql, 0, NUM);

		// 2.1打印提示符
		write(STDOUT_FILENO, "MySQL> ", 7);

		// 2.2 获得用户输入
		int ret = read(STDIN_FILENO, sql, NUM);
		// read读取失败
		if (ret < 0)
		{
			perror("read");
			break;
		}
		// 按了ctrl+d ，接受了EOF，read就会返回0
		else if (ret == 0)
		{
			printf("Byebye!\n");
			break;
		}

		// 如果输入的是quit 或者 exit 直接退出
		if ((strcmp(sql, "quit\n") == 0) || (strcmp(sql, "exit\n") == 0))
		{
			printf("Byebye!\n");
			break;
		}

		// 2.3 执行sql语句，获得结果集
		if (mysql_query(mysql, sql) == 0)
		{
			//printf("Execute mysql_query() succeed\n");
			MYSQL_RES *res = mysql_store_result(mysql);
			if (res != NULL)
			{
				// 3、打印结果集
				printResultSet(res);

				//结果集中有多少行数据
				printf("%lld rows in set \n", mysql_affected_rows(mysql));

				// 释放结果集
				mysql_free_result(res);
			}
			else
			{
				//有多少行数据被affected
				printf("%lld row affected \n", mysql_affected_rows(mysql));
			}
		}
		else
		{
			//执行失败
			fprintf(stderr, "Error in mysql_query:%s\n", mysql_error(mysql));
		}
	}
}

int main()
{
	MYSQL mysql;
	char sql[1024] = {0};

	// 1、初始化 连接mysql 设置当前连接的字符集
	memset(&mysql, 0, sizeof(mysql));
	mysql_init_connect_setCharacter(&mysql);

	// 2、获取用户输入并执行sql
	// 调用 3、打印结果集
	getUserInputAndExecute(&mysql, sql, sizeof(sql));

	//4、垃圾回收
	mysql_close(&mysql);
	return 0;
}