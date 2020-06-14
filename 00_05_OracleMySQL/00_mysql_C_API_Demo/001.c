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

int main()
{
	//1、初始化
	MYSQL *mysql = mysql_init(NULL);
	if (mysql == NULL)
	{ //报错
		fprintf(stderr, "Error in mysql_init()\n");
		exit(-1);
	}

	//2、建立连接
	if (mysql_real_connect(
			mysql,
			DB_HOST,
			DB_USER,
			DB_PASSWD,
			DB_NAME,
			DB_PORT,
			NULL,
			0) == NULL)
	{ //报错
		fprintf(stderr, "Error in mysql_real_connect():%s\n", mysql_error(mysql));
		exit(-1);
	}
	else
	{ //执行成功
		printf("mysql_real_connect() -- 执行成功\n");
	}

	//3.1.1、执行sql: 插入一条记录
 	const char sql_insert[] = "insert into dept(deptno,dname,loc) values(40,'OPERATIONS','BOSTON')";
	if (0 == mysql_query(mysql, sql_insert))
	{ //执行成功
		printf("Execute succees: insert 执行成功\n");
	}
	else
	{ //执行失败
		fprintf(stderr, "Error in mysql_query() insert :%s\n", mysql_error(mysql));
		exit(-1);
	} 
	//3.1.2、执行sql: 删除一条记录
	const char sql_delete[] = "delete from dept where deptno = 40";
	if (0 == mysql_query(mysql, sql_delete))
	{ //执行成功
		printf("Execute succees: delete 执行成功\n");
	}
	else
	{ //执行失败
		fprintf(stderr, "Error in mysql_query() delete :%s\n", mysql_error(mysql));
		exit(-1);
	}


	//4、垃圾回收
	mysql_close(mysql);
	return 0;
}