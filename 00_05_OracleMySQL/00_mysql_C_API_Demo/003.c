#include <mysql.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

#define _HOST_ "127.0.0.1"
#define _PORT_ 3306
#define _USER_ "root"
#define _PASSWD_ "root123"
#define _DB_ ""

#define MAX(a, b) ((a) > (b) ? (a) : (b))
MYSQL mysql;

//1 每次等待用户输入
//2 将用户输入进行查询，并将结果显示出来
//3 如果用户输入的是exit或者quit，就退出

void displayResultSet(MYSQL_RES *result)
{
	//1 计算每一列的最大宽度
	//	该列每行数据（包括表头）长度作比较，取最大值
	//	这时候就要使用一个数组记录最大长度，同时因为要遍历每一行，所以
	//	也选用哦一个额外的数组来保存每一行每一列的数据免得重复遍历
	//2 输出表格，列与列之间用|分隔，每一格数据补空格使其和最长值相等
	//3 竖线与横线交叉的位置用+表示
	//格式样例
	/*
	+------+----------+--------+
	|deptno|dname     |loc     |
	+------+----------+--------+
	|10    |ACCOUNTING|NEW YORK|
	|20    |RESEARCH  |DALLAS  |
	|30    |SALES     |CHICAGO |
	|40    |OPERATIONS|BOSTON  |
	+------+----------+--------+
	*/

	assert(result);

	//列坐标
	int colIndex = 0;
	//行坐标
	int rowIndex = 0;
	//获取列数
	const unsigned int colCount = mysql_field_count(&mysql);
	//获取行数
	const unsigned int rowCount = mysql_num_rows(result);

	int i;

	//计算每列的最大长度，并用动态数组记录好
	int *colMaxLength = (int *)malloc(sizeof(int) * colCount);
	//用一个动态数组记录结果集的每一个字符串
	char **resultStrArray = (char **)malloc(sizeof(char *) * colCount * rowCount);
	assert(colMaxLength);
	assert(resultStrArray);
	memset(colMaxLength, 0, sizeof(int) * colCount);
	memset(resultStrArray, 0, sizeof(char *) * colCount * rowCount);

	//遍历结果集每一行每一列，记录每个字符串，同时记住每列最长长度
	MYSQL_ROW row = NULL;
	for (rowIndex = 0; (row = mysql_fetch_row(result)); ++rowIndex)
	{
		unsigned long *lengths = mysql_fetch_lengths(result);
		for (colIndex = 0; colIndex < colCount; ++colIndex)
		{
			colMaxLength[colIndex] = MAX(colMaxLength[colIndex], lengths[colIndex]);
			resultStrArray[rowIndex * colCount + colIndex] = row[colIndex];
		}
	}

	//获取列信息，用来计算表头每列的长度
	MYSQL_FIELD *fields = mysql_fetch_fields(result);
	for (colIndex = 0; colIndex < colCount; ++colIndex)
	{
		colMaxLength[colIndex] = MAX(strlen(fields[colIndex].name), colMaxLength[colIndex]);
	}

	//画横线，横线和竖线交叉部分用+号
	for (colIndex = 0; colIndex < colCount; ++colIndex)
	{
		printf("+");
		for (i = 0; i < colMaxLength[colIndex]; ++i)
		{
			printf("-");
		}
	}
	printf("+\n");

	//显示表头
	for (colIndex = 0; colIndex < colCount; ++colIndex)
	{
		printf("|");
		int colLength = colMaxLength[colIndex];
		printf("%s", fields[colIndex].name);
		for (i = 0; i < colLength - strlen(fields[colIndex].name); ++i)
		{
			printf(" ");
		}
		//printf("%s\t" ,row[i]);
	}
	printf("|\n");

	//划横线
	for (colIndex = 0; colIndex < colCount; ++colIndex)
	{
		printf("+");
		for (i = 0; i < colMaxLength[colIndex]; ++i)
		{
			printf("-");
		}
	}
	printf("+\n");

	//显示结果集数据
	for (rowIndex = 0; rowIndex < rowCount; ++rowIndex)
	{
		for (colIndex = 0; colIndex < colCount; ++colIndex)
		{
			printf("|");
			int colLength = colMaxLength[colIndex];
			int index = rowIndex * colCount + colIndex;
			const char *str = resultStrArray[index] ? resultStrArray[index] : "";
			int padding = colLength - strlen(str);
			printf("%s", str);
			//每一个格子的数据都要用空格补全，使其长度刚好登录该列最长长度，达到对齐效果
			for (i = 0; i < padding; ++i)
			{
				printf(" ");
			}
		}
		printf("|\n");
	}

	//画最后一行横线
	for (colIndex = 0; colIndex < colCount; ++colIndex)
	{
		printf("+");
		for (i = 0; i < colMaxLength[colIndex]; ++i)
		{
			printf("-");
		}
	}

	printf("+\n");
	//释放动态数组
	free(colMaxLength);
	free(resultStrArray);
}

void displayAffactRows()
{
	my_ulonglong rowCount = mysql_affected_rows(&mysql);
	printf("%lld rows affected! \n", rowCount);
}

int main()
{
	//初始化Mysql
	if (!mysql_init(&mysql))
	{
		//如果返回值是NULL，那么初始化失败
		printf("mysql init error\n");
		exit(1);
	}
	//建立连接
	if (!mysql_real_connect(
			&mysql,
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
	//修改字符集为UTF8
	if (mysql_set_character_set(&mysql, "UTF8"))
	{
		printf("Mysql set character set error\n");
		exit(1);
	}

	printf("Welcome to MySQL\n");

	char sql[1024]={0};
	while (1)
	{
		memset(sql, 0, sizeof(sql));

		//输出提示
		write(STDOUT_FILENO, "MySQL> ", 7);

		//等待用户输入
		int ret = read(STDIN_FILENO, sql, sizeof(sql));

		//判断用户是否要退出
		if (ret == 0 || strcmp(sql, "exit\n") == 0 || strcmp(sql, "quit\n") == 0)
		{
			//quit the client
			printf("\n");
			break;
		}

		if (mysql_query(&mysql, sql))
		{
			printf("Query error: %s \n", mysql_error(&mysql));
			continue;
		}

		//Get result set
		MYSQL_RES *res = mysql_store_result(&mysql);
		if (!res)
		{
			printf("Result is empty\n");
			//no result set , display affact rows
			displayAffactRows();
		}
		else
		{
			displayResultSet(res);
			mysql_free_result(res);
			displayAffactRows();
		}
	}

	//关闭连接
	mysql_close(&mysql);
	return 0;
}
