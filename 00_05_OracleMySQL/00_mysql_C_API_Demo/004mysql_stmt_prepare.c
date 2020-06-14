// prepare
// 使用 MySQL的预处理语句 编写代码
// 对MySQL数据库的操作，使用预处理API

// 预处理：先解析好你的SQL语句，然后下次客户端直接扔每个字段的值过来，就带入进来
// 优点：
//		对于多次使用的SQL语句(比如插入大量数据时)，不用频繁的解析SQL语句(节省了时间)；
//  	防止SQL注入

//  预处理语句使用方式：
//		1 先创建预处理语句
//      2 先扔给服务器去解析这个语句
//      3 将该填的数据传递给服务器，让服务器去执行

#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_SIZE 50
//删除数据表
#define DROP_SAMPLE_TABLE "DROP TABLE IF EXISTS test_table"
//创建数据表
#define CREATE_SAMPLE_TABLE "CREATE TABLE test_table(\
													col1 INT,\
	                                                col2 VARCHAR(40),\
													col3 SMALLINT,\
													col4 TIMESTAMP)"
//插入数据的SQL语句，以?表示待填入的数据
#define INSERT_SAMPLE "INSERT INTO test_table(col1,col2,col3) VALUES(?,?,?)"

#define _HOST_ "127.0.0.1"
#define _PORT_ 3306
#define _USER_ "root"
#define _PASSWD_ "root123"
#define _DB_ "lwh_scott"

MYSQL mysql_instance;
int main(int argc, char **argv)
{
	MYSQL_STMT *stmt;
	MYSQL_BIND bind[3];
	my_ulonglong affected_rows;
	int param_count;
    
	short small_data;
	int int_data;
	char str_data[STRING_SIZE];
    
	unsigned long str_length;
	bool is_null;

	//初始化Mysql
	MYSQL *mysql = &mysql_instance;
	if (!mysql_init(mysql))
	{
		//如果返回值是NULL，那么初始化失败
		printf("mysql init error\n");
		exit(1);
	}

	//建立连接
	if (!mysql_real_connect(
			mysql,
			_HOST_,
			_USER_,
			_PASSWD_,
			_DB_,
			_PORT_,
			NULL,
			0))
	{
		//如果连接失败，就打印
		printf("Mysql connect error\n");
		exit(1);
	}

	//修改字符集
	if (mysql_set_character_set(mysql, "UTF8"))
	{
		printf("Mysql set character set error\n");
		exit(1);
	}

	//如果表存在删除表
	if (mysql_query(mysql, DROP_SAMPLE_TABLE))
	{
		fprintf(stderr, " DROP TABLE failed\n");
		fprintf(stderr, " %s\n", mysql_error(mysql));
		exit(0);
	}

	//重新创建表
	if (mysql_query(mysql, CREATE_SAMPLE_TABLE))
	{
		fprintf(stderr, " CREATE TABLE failed\n");
		fprintf(stderr, " %s\n", mysql_error(mysql));
		exit(0);
	}

	/* Prepare an INSERT query with 3 parameters */
	/* (the TIMESTAMP column is not named; the server */
	/*  sets it to the current date and time) */
	//初始化一个准备语句
	stmt = mysql_stmt_init(mysql);
	if (!stmt)
	{
		fprintf(stderr, " mysql_stmt_init(), out of memory\n");
		exit(0);
	}
	if (mysql_stmt_prepare(stmt, INSERT_SAMPLE, strlen(INSERT_SAMPLE)))
	{
		fprintf(stderr, " mysql_stmt_prepare(), INSERT failed\n");
		fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
		exit(0);
	}

	fprintf(stdout, " prepare, INSERT successful\n");

	/* Get the parameter count from the statement */
	param_count = mysql_stmt_param_count(stmt);
	fprintf(stdout, " total parameters in INSERT: %d\n", param_count);

	if (param_count != 3) /* validate parameter count */
	{
		fprintf(stderr, " invalid parameter count returned by MySQL\n");
		exit(0);
	}
	/* Bind the data for all 3 parameters */
	memset(bind, 0, sizeof(bind));

	/* INTEGER PARAM */
	/* This is a number type, so there is no need to specify buffer_length */
	bind[0].buffer_type = MYSQL_TYPE_LONG;
	bind[0].buffer = (char *)&int_data;
	bind[0].is_null = 0;
	bind[0].length = 0;

	/* STRING PARAM */
	bind[1].buffer_type = MYSQL_TYPE_STRING;
	bind[1].buffer = (char *)str_data;
	bind[1].buffer_length = STRING_SIZE;
	bind[1].is_null = 0;
	bind[1].length = &str_length;

	/* SMALLINT PARAM */
	bind[2].buffer_type = MYSQL_TYPE_SHORT;
	bind[2].buffer = (char *)&small_data;
	bind[2].is_null = &is_null;
	bind[2].length = 0;

	/* Bind the buffers */
	if (mysql_stmt_bind_param(stmt, bind))
	{
		fprintf(stderr, " mysql_stmt_bind_param() failed\n");
		fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
		exit(0);
	}

	//第一次插入数据
	/* Specify the data values for the first row */
	int_data = 10;							 /* integer */
	strncpy(str_data, "MySQL", STRING_SIZE); /* string  */
	str_length = strlen(str_data);

	/* INSERT SMALLINT data as NULL */
	is_null = 1;

	/* Execute the INSERT statement - 1*/
	if (mysql_stmt_execute(stmt))
	{
		fprintf(stderr, " mysql_stmt_execute(), 1 failed\n");
		fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
		exit(0);
	}

	/* Get the total number of affected rows */
	affected_rows = mysql_stmt_affected_rows(stmt);
	fprintf(stdout, " total affected rows(insert 1): %lu\n",
			(unsigned long)affected_rows);

	//判断数据是否添加成功，只需要判断影响行数是不是1
	if (affected_rows != 1) /* validate affected rows */
	{
		fprintf(stderr, " invalid affected rows by MySQL\n");
		exit(0);
	}

	//第二次插入数据
	/* Specify data values for second row, then re-execute the statement */
	int_data = 1000;
	strncpy(str_data, "The most popular Open Source database", STRING_SIZE);
	str_length = strlen(str_data);
	small_data = 1000; /* smallint */
	is_null = 0;	   /* reset */

	/* Execute the INSERT statement - 2*/
	if (mysql_stmt_execute(stmt))
	{
		fprintf(stderr, " mysql_stmt_execute, 2 failed\n");
		fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
		exit(0);
	}

	/* Get the total rows affected */
	affected_rows = mysql_stmt_affected_rows(stmt);
	fprintf(stdout, " total affected rows(insert 2): %lu\n",
			(unsigned long)affected_rows);

	if (affected_rows != 1) /* validate affected rows */
	{
		fprintf(stderr, " invalid affected rows by MySQL\n");
		exit(0);
	}

	/* Close the statement */
	if (mysql_stmt_close(stmt))
	{
		fprintf(stderr, " failed while closing the statement\n");
		fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
		exit(0);
	}

	//关闭连接
	mysql_close(mysql);
	return 0;
}
