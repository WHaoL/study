@[TOC](目录)

# 书本源码

书本源码：

​		https://forta.com/books/0672327120/

​		[mysql_scripts.zip](https://forta.com/wp-content/uploads/books/0672327120/mysql_scripts.zip) contains two files, create.sql and populate.sql.

我把它们放在了博客里 方便大家查看：

​		https://blog.csdn.net/liangwenhao1108/article/details/105667242



# 第1章 了解SQL

## 1.1 数据库基础

- 数据库基础
> 学习的良好切入点就是给出一张最重要的数据库术语清单，并加以说明。
> 理解数据库是掌握MySQL的一个重要组成部分，如果有必要的话，你应该参阅一些有关数据库基础知识的书籍。
> > 《数据库系统：面向应用的方法》Kifer、Bernstein和Lewis合著  人民邮电出版社
> > 《数据库系统基础》 Elmasri和Navathe合著

### 1.1.1 什么是数据库

- 数据库
> 数据库（database）：保存有组织的数据的容器
> 数据库软件（数据库管理系统）：DBMS
> 数据库是通过DBMS创建和操纵的容器
> 数据库是什么并不重要，因为你并不直接访问数据库；你使用的是DBMS，它替你访问数据库。

### 1.1.2 表

- 表
> 表（table）：某种特定类型数据的结构化清单。
> 注意：存储在表中的数据是一种类型的数据或一个清单。
> 数据库中的每个表都有一个名字，用来标识自己，此名字是唯一的。（不同的数据库中可以使用相同的表名）

- 模式
> 模式（schema）：关于数据库和表的布局及特性的信息。
> > 表的特性，如：数据在表中如何存储，可以存储什么样的数据，数据如何分解，各部分信息如何命名，等等
> > 有时，模式用作数据库的同义词。

### 1.1.3 列和数据类型

- 列
>  列（column）：表中的一个字段。所有表都是有一个或多个列组成的。
>  正确地将数据分解为多个列极为重要。
>  数据库中每个列都有相应的数据类型。
- 数据类型
> 数据类型（data type）：限制（或容许）列中存储的数据种类。
### 1.1.4 行

- 行
> 行（row）：表中的一个记录。
> > 垂直的列为表列，水平行为表行。
>
> 有人喜欢把行（row）称为数据库记录（record）
>
>  > 数据是按行存储的，每个记录存储在自己的行内。
### 1.1.5 主键

- 主键
> 主键（primary key）：一列（或一组列），其值能够唯一区分表中的每个行。
> > 应该总是定义主键
> > 表中每一行都应该有可以唯一标识自己的一列（或一组列）
>
> 主键满足以下条件：
>  > 任意两行 都不具有相同的主键值；
>  > 每个行都必须具有一个主键值（主键列不允许NULL值）。
>
> MySQL的主键值规则
> > 主键通常定义在表的一列上，也可以一起使用多个列作为主键；
> > 在使用多了作为主键时，所有列值的组合必须是唯一的（此时单个列的值可以不唯一）。（复合主键）
>
> 应该坚持的几个普遍认可的：主键的最好习惯为：
> > 不更新主键列中的值；
> > 不重用主键列中的值；
> > 不在主键列中使用可能会更改的值.
>
> 还有一种非常重要的键，称为外键，在15章介绍。
## 1.2 什么是SQL

- SQL
> SQL（Structured Query Language）：是一种专门用来与数据库通信的语言。
>
> > 本书讲授的SQL是专门针对MySQL的
## 1.3 动手实践

> 你需要MySQL，作者强烈建议读者实验每个例子。



# 第2章 MySQL简介

## 2.1 什么是MySQL 

> MySQL是一种DBMS，即它是一种数据库软件。
### 2.1.1 client-server软件

> MySQL是基于client-server的DBMS。
> > 服务器部分：负责所有数据访问和处理的一个软件。这个软件运行在称为数据库服务器的计算机上。
>
> 客户机是与用户打交道的软件
> > 客户机软件 通过网络提交请求给服务器软件；
> > 服务器软件处理这个请求，根据需要过滤、丢弃和排序数据；
> > 然后把结果送回到你的客户机软件。
>
> 服务器软件为MySQL DBMS。
## 2.2 MySQL工具

> MySQL是一个Client-Server DBMS，因此为了使用MySQL，需要有一个客户机
> 即用来与MySQL打交道的一个应用。
### 2.2.1 mysql命令行实用程序

> 每个MySQL安装都有一个名为mysql的简单命令行实用程序。
> > mysql -uUserName -pPassword
> >
> > mysql -u user -p -h myserver -P 9999
>
> > 命令输入在mysql>之后
> >
> > 命令用；或\g结束，换句话说，仅按Enter不执行命令
> >
> > 输入help 或\h获得帮助；输入help select获得使用select语句的帮助
> >
> > 输入quit或exit退出命令行实用程序
>
> mysql命令行实用程序
>
> > mysql命令行实用程序是使用的最多的实用程序之一
> > 对于快速测试和执行脚本非常有价值
> > 本书中使用的所有输出例子都是从mysql命令行输出中抓取的



# 第3章 使用MySQL (登录mysql、use、show、desc)

## 3.1 连接

> 使用 MySQL的Client连接到MySQL DBMS
> 即 执行命令之前需要先登录到DBMS
> 登录之后，就可以访问你的登录名能够访问的任意数据库和表了
>  > 登录本地MySQL：mysql -u root -p
>  > 回显后：输入你的mysql 设置的root密码即可登录
>
>   > 登录本地MySQL：mysql -u root -p密码
>   > 同一行直接输入mysql的root密码登录
>
> > 登录远端的mysql：mysql -h [hostIP] -u [username] -p[password]
>
> 注意： -u username 之间可以不用加空格，其它几个也一样（-p 和 password之间最好不要有空格，经验所得）

```sql
[root@lwh study]# mysql -u root -proot123
mysql>

[root@lwh study]# mysql -uroot -p 
Enter password: 

mysql> quit
Bye
[root@lwh study]# 
```

## 3.2 选择数据库

> 在刚连接到MySQL时，是没有任何数据库打开供你使用的
> 必须先使用 use 打开数据库，才能读取其中的数据
> > use databaseName
> > use语句并不返回任何结果，依赖于使用的客户机显示某种形式的通知
> > mysql命令行实用程序一般回显：Database changed

```sql
-- 查看当前有哪些数据库
show databases；
```

```sql
--创建数据库(本书使用的)
create database MySQLCrashCourse;
--删除数据库
drop database MySQLCrashCourse;
```

```sql
--使用数据库
use MySQLCrashCourse;
```

## 3.3 了解数据库和表

```sql
-- 返回可用数据库的一个列表
show databases; 
```
```sql
-- 返回当前选择的数据库内 可用表的列表
show tables; 
```
> 自动增量
> > 如果需要它，则必须在使用 create 语句创建表时把它作为表定义的组成 部分
> > 如 字段 cust_id 的 auto_increment
```sql
-- show也可以用来显示表列
-- 显示 表的行列 结构
show columns from customers;
```

>describe语句
>>下面三条语句是等价的
>>desc customers; 
>>describe customers; 
>>show columns from customers;
>
>总结：MySQL支持用describe作为show columns from 的一种快捷方式

```sql
mysql> desc products;
+------------+--------------+------+-----+---------+-------+
| Field      | Type         | Null | Key | Default | Extra |
+------------+--------------+------+-----+---------+-------+
| prod_id    | char(10)     | NO   | PRI | NULL    |       |
| vend_id    | int          | NO   | MUL | NULL    |       |
| prod_name  | char(255)    | NO   |     | NULL    |       |
| prod_price | decimal(8,2) | NO   |     | NULL    |       |
| prod_desc  | text         | YES  |     | NULL    |       |
+------------+--------------+------+-----+---------+-------+
5 rows in set (0.01 sec)

mysql> describe products;
+------------+--------------+------+-----+---------+-------+
| Field      | Type         | Null | Key | Default | Extra |
+------------+--------------+------+-----+---------+-------+
| prod_id    | char(10)     | NO   | PRI | NULL    |       |
| vend_id    | int          | NO   | MUL | NULL    |       |
| prod_name  | char(255)    | NO   |     | NULL    |       |
| prod_price | decimal(8,2) | NO   |     | NULL    |       |
| prod_desc  | text         | YES  |     | NULL    |       |
+------------+--------------+------+-----+---------+-------+
5 rows in set (0.09 sec)

mysql> show columns from products;
+------------+--------------+------+-----+---------+-------+
| Field      | Type         | Null | Key | Default | Extra |
+------------+--------------+------+-----+---------+-------+
| prod_id    | char(10)     | NO   | PRI | NULL    |       |
| vend_id    | int          | NO   | MUL | NULL    |       |
| prod_name  | char(255)    | NO   |     | NULL    |       |
| prod_price | decimal(8,2) | NO   |     | NULL    |       |
| prod_desc  | text         | YES  |     | NULL    |       |
+------------+--------------+------+-----+---------+-------+
5 rows in set (0.01 sec)
```

>其他的 show 语句还有
>show status； -- 显示广泛的服务器状态信息
>show create database MySQLCrashCourse; -- 显示创建特定数据库的MySQL语句
>show create table customers; -- 显示创建特定表的MySQL语句
>mysql> show errors; -- 显示服务器错误
>mysql> show warnings; -- 显示警告信息
>进一步了解 show ： help show;
## 3.4 小结

> 1. 连接和登录MySQL
> 2. use选择数据库
> 3. show查看数据库、表、内部信息



# 第4章 检索数据(select、limit)

## 简介

> 如何使用 select 语句从表中检索一个或多个数据列
## 4.1 select 语句

>使用 select语句检索表数据，必须给出两条信息
>>想选择什么
>>从什么地方选择
## 4.2 检索单个列

```sql
mysql> select prod_name
    -> from products;
+----------------+
| prod_name      |
+----------------+
| .5 ton anvil   |
| 1 ton anvil    |
| 2 ton anvil    |
| Detonator      |
| Bird seed      |
| Carrots        |
| Fuses          |
| JetPack 1000   |
| JetPack 2000   |
| Oil can        |
| Safe           |
| Sling          |
| TNT (1 stick)  |
| TNT (5 sticks) |
+----------------+
14 rows in set (0.03 sec)
```
> 列名在 select 关键字之后给出
> 表名在 from   关键字之后给出 

> 如果没有明确排序查询结果，则返回的数据的顺序没有特殊意义

> 使用 ; 来结束SQL语句
> 多条SQL语句必须以 ; 分隔

> SQL语句不区分大小写
> 对SQL关键字使用大写，对所有列和表名使用小写，这样做使代码更易于阅读和调试
> 最佳方式是：按照大小写的惯例，且使用时保持一致。
## 4.3 检索多个列

> select 关键字之后给出多个列名，列名之间以逗号分隔，最后一个列名之后不需要加逗号。

```sql
mysql> select prod_id,prod_name,prod_price from products;
+---------+----------------+------------+
| prod_id | prod_name      | prod_price |
+---------+----------------+------------+
| ANV01   | .5 ton anvil   |       5.99 |
| ANV02   | 1 ton anvil    |       9.99 |
| ANV03   | 2 ton anvil    |      14.99 |
| DTNTR   | Detonator      |      13.00 |
| FB      | Bird seed      |      10.00 |
| FC      | Carrots        |       2.50 |
| FU1     | Fuses          |       3.42 |
| JP1000  | JetPack 1000   |      35.00 |
| JP2000  | JetPack 2000   |      55.00 |
| OL1     | Oil can        |       8.99 |
| SAFE    | Safe           |      50.00 |
| SLING   | Sling          |       4.49 |
| TNT1    | TNT (1 stick)  |       2.50 |
| TNT2    | TNT (5 sticks) |      10.00 |
+---------+----------------+------------+
14 rows in set (0.00 sec)
```

> SQL语句一般返回原始的、无格式的数据。
> 数据的格式是一个表示问题，而不是一个检索问题。
## 4.4 检索所有的列

> 检索所有的列
> 实际列名的位置使用星号 * 通配符 来达到

```sql
mysql> select * from products;
+---------+---------+----------------+------------+----------------------------------------------------------------+
| prod_id | vend_id | prod_name      | prod_price | prod_desc                                                      |
+---------+---------+----------------+------------+----------------------------------------------------------------+
| ANV01   |    1001 | .5 ton anvil   |       5.99 | .5 ton anvil, black, complete with handy hook                  |
| ANV02   |    1001 | 1 ton anvil    |       9.99 | 1 ton anvil, black, complete with handy hook and carrying case |
| ANV03   |    1001 | 2 ton anvil    |      14.99 | 2 ton anvil, black, complete with handy hook and carrying case |
| DTNTR   |    1003 | Detonator      |      13.00 | Detonator (plunger powered), fuses not included                |
| FB      |    1003 | Bird seed      |      10.00 | Large bag (suitable for road runners)                          |
| FC      |    1003 | Carrots        |       2.50 | Carrots (rabbit hunting season only)                           |
| FU1     |    1002 | Fuses          |       3.42 | 1 dozen, extra long                                            |
| JP1000  |    1005 | JetPack 1000   |      35.00 | JetPack 1000, intended for single use                          |
| JP2000  |    1005 | JetPack 2000   |      55.00 | JetPack 2000, multi-use                                        |
| OL1     |    1002 | Oil can        |       8.99 | Oil can, red                                                   |
| SAFE    |    1003 | Safe           |      50.00 | Safe with combination lock                                     |
| SLING   |    1003 | Sling          |       4.49 | Sling, one size fits all                                       |
| TNT1    |    1003 | TNT (1 stick)  |       2.50 | TNT, red, single stick                                         |
| TNT2    |    1003 | TNT (5 sticks) |      10.00 | TNT, red, pack of 10 sticks                                    |
+---------+---------+----------------+------------+----------------------------------------------------------------+
14 rows in set (0.00 sec)
```
> 除非你确定需要表中的每个列，否则最好别使用 * 通配符
> 检索不需要的列通常会降低检索和应用程序的性能

> 使用通配符有一个大的优点。由于不明确指定列名，所以能检索出名字未知的列
## 4.5 检索不同的行

> select返回所有匹配的行（重复的值不做处理，一并返回）
```sql
mysql> select vend_id from products;
+---------+
| vend_id |
+---------+
|    1001 |
|    1001 |
|    1001 |
|    1002 |
|    1002 |
|    1003 |
|    1003 |
|    1003 |
|    1003 |
|    1003 |
|    1003 |
|    1003 |
|    1005 |
|    1005 |
+---------+
14 rows in set (0.00 sec)
```

> distinct 关键字，指示MySQL只返回不同的(唯一的)值 / 行
> distinct 关键字，它必须直接放在列名的前面
> distinct 关键字，应用于所有列而不仅是前置它的列
```sql
mysql> select distinct vend_id from products;
+---------+
| vend_id |
+---------+
|    1001 |
|    1002 |
|    1003 |
|    1005 |
+---------+
4 rows in set (0.00 sec)
```
>若两列里的两个对应值重复，distinct会过滤掉重复的
>多列时，亦然。
```sql
mysql> select distinct vend_id,prod_price from products;
+---------+------------+
| vend_id | prod_price |
+---------+------------+
|    1001 |       5.99 |
|    1001 |       9.99 |
|    1001 |      14.99 |
|    1003 |      13.00 |
|    1003 |      10.00 |
|    1003 |       2.50 |
|    1002 |       3.42 |
|    1005 |      35.00 |
|    1005 |      55.00 |
|    1002 |       8.99 |
|    1003 |      50.00 |
|    1003 |       4.49 |
+---------+------------+
12 rows in set (0.00 sec)
```
## 4.6 限制结果

> limit 子句：限制返回的行数
> limit 5 指示MySQL返回不多于5行。
```sql
mysql> select prod_name 
    -> from products
    -> limit 5;
+--------------+
| prod_name    |
+--------------+
| .5 ton anvil |
| 1 ton anvil  |
| 2 ton anvil  |
| Detonator    |
| Bird seed    |
+--------------+
5 rows in set (0.00 sec)

mysql> 
```

> 限制返回的 起始行 和 行数
> limit 5,5 指示MySQL返回：从行5开始的，接下来的5行 （从行5开始，取5行）
> 第一个数 为开始位置，第二个数为要检索的行数

```sql
mysql> select prod_name
    -> from products
    -> limit 5,5;
+--------------+
| prod_name    |
+--------------+
| Carrots      |
| Fuses        |
| JetPack 1000 |
| JetPack 2000 |
| Oil can      |
+--------------+
5 rows in set (0.00 sec)

mysql> 
```

> 行 0
> > 检索出的第一行为行 0 而不是行 1
> > 因此 limit 1 , 1 将检索出第二行而不是第一行
```sql
mysql> select prod_name from products limit 1,1;
+-------------+
| prod_name   |
+-------------+
| 1 ton anvil |
+-------------+
1 row in set (0.00 sec)
```

> 没有足够的行，将只返回它能返回的那么多行

> limit 3 ,4  等价于 limit 4 offset 3
> 表示：从行3开始取4行

## 4.7 使用完全限定的表名

> 完全限定的列名
```sql
mysql> select products.prod_name 
    -> from products;
+----------------+
| prod_name      |
+----------------+
| .5 ton anvil   |
| 1 ton anvil    |
| 2 ton anvil    |
| Detonator      |
| Bird seed      |
| Carrots        |
| Fuses          |
| JetPack 1000   |
| JetPack 2000   |
| Oil can        |
| Safe           |
| Sling          |
| TNT (1 stick)  |
| TNT (5 sticks) |
+----------------+
14 rows in set (0.00 sec)
```

> 完全限定的列名 、 表名
```sql
mysql> select products.prod_name
    -> from MySQLCrashCourse.products;
+----------------+
| prod_name      |
+----------------+
| .5 ton anvil   |
| 1 ton anvil    |
| 2 ton anvil    |
| Detonator      |
| Bird seed      |
| Carrots        |
| Fuses          |
| JetPack 1000   |
| JetPack 2000   |
| Oil can        |
| Safe           |
| Sling          |
| TNT (1 stick)  |
| TNT (5 sticks) |
+----------------+
14 rows in set (0.00 sec)
```
## 4.8 小结

> 1. 使用SQL的 select 语句来检索单个列
> 1. 使用SQL的 select 语句来检索多个列
> 1. 使用SQL的 select 语句来检索所有列



# 第5章 排序检索数据(select语句的order by字句、desc)

## 简介

> 使用 select 语句的 order by 字句
> 根据需要排序检索出的数据

## 5.1 排序数据

> 关系数据库
> 如果不明确规定排序顺序，则不应该假设 检索出的 数据的顺序 有意义

> order by 字句
> 对select语句检索出的数据进行明确的排序
> 取一个或多个列的名字，据此对输出进行排序

```sql
mysql> select prod_name
    -> from products
    -> order by prod_name;
+----------------+
| prod_name      |
+----------------+
| .5 ton anvil   |
| 1 ton anvil    |
| 2 ton anvil    |
| Bird seed      |
| Carrots        |
| Detonator      |
| Fuses          |
| JetPack 1000   |
| JetPack 2000   |
| Oil can        |
| Safe           |
| Sling          |
| TNT (1 stick)  |
| TNT (5 sticks) |
+----------------+
14 rows in set (0.00 sec)

mysql> 
```

## 5.2 按多个列排序

> 按 多个列进行排序，只要指定列名，列名之间用逗号分开即可
> 先按 第一个列值进行排序，第一个列值相同的情况下 按照第二个列值进行排序，.....
> > 重要的是理解按多个列进行排序时，排序完全按所规定的顺序进行。
> > 对于下面的例子，仅在多个行具有相同的prod_price值时，才对产品按prod_name进行排序。
> > 如果prod_price列中所有的值都是唯一的，则不会按prod_name排序。

```sql
mysql> select prod_id,prod_price,prod_name
    -> from products
    -> order by prod_price,prod_name;
+---------+------------+----------------+
| prod_id | prod_price | prod_name      |
+---------+------------+----------------+
| FC      |       2.50 | Carrots        |
| TNT1    |       2.50 | TNT (1 stick)  |
| FU1     |       3.42 | Fuses          |
| SLING   |       4.49 | Sling          |
| ANV01   |       5.99 | .5 ton anvil   |
| OL1     |       8.99 | Oil can        |
| ANV02   |       9.99 | 1 ton anvil    |
| FB      |      10.00 | Bird seed      |
| TNT2    |      10.00 | TNT (5 sticks) |
| DTNTR   |      13.00 | Detonator      |
| ANV03   |      14.99 | 2 ton anvil    |
| JP1000  |      35.00 | JetPack 1000   |
| SAFE    |      50.00 | Safe           |
| JP2000  |      55.00 | JetPack 2000   |
+---------+------------+----------------+
14 rows in set (0.01 sec)
```
## 5.3 指定排序方向

> order by
> > 升序排序（A到Z），指定 asc   关键字，可以不指定，因为升序是默认的
> > 降序排序（Z到A），指定 desc 关键字
```sql
mysql> select prod_id,prod_price,prod_name
    -> from products
    -> order by prod_price desc,prod_name;
+---------+------------+----------------+
| prod_id | prod_price | prod_name      |
+---------+------------+----------------+
| JP2000  |      55.00 | JetPack 2000   |
| SAFE    |      50.00 | Safe           |
| JP1000  |      35.00 | JetPack 1000   |
| ANV03   |      14.99 | 2 ton anvil    |
| DTNTR   |      13.00 | Detonator      |
| FB      |      10.00 | Bird seed      |
| TNT2    |      10.00 | TNT (5 sticks) |
| ANV02   |       9.99 | 1 ton anvil    |
| OL1     |       8.99 | Oil can        |
| ANV01   |       5.99 | .5 ton anvil   |
| SLING   |       4.49 | Sling          |
| FU1     |       3.42 | Fuses          |
| FC      |       2.50 | Carrots        |
| TNT1    |       2.50 | TNT (1 stick)  |
+---------+------------+----------------+
14 rows in set (0.00 sec)

mysql> 
```
> desc 关键字 只应用到位于其前面的列名
> 如果想在多个列上进行降序排序，必须对每个列指定 desc 关键字

> order by 和 limit 的组合
> > order by 子句位于 from 子句之后
> > limit 子句，位于 order by 子句之后

```sql
--找出一个列中 最高或者最低的值

mysql> select prod_price 
    -> from products
    -> order by prod_price desc 
    -> limit 1;
+------------+
| prod_price |
+------------+
|      55.00 |
+------------+
1 row in set (0.00 sec)

mysql> 
```
## 5.4 小结

> 1. 使用 select 语句的 order by 子句对检索出的数据进行排序
> 2. 这个子句是 select 语句中的最后一条子句（limit 子句，位于其后）
> 3. 使用 desc 、asc 限定 order by 排序的方向
> 4. 可根据需要，在一个或多个列上对数据进行排序



# 第6章 过滤数据(select语句的where子句)

## 简介

> 使用 select语句 的where子句 指定搜索条件
## 6.1 使用where子句

> 只检索所需数据，需要指定搜索条件
> 搜索条件也称为过滤条件（filter condition）

> select语句中，数据根据 where子句 中指定的搜索条件进行过滤
> where子句 在表名（from 子句） 之后给出
```sql
mysql> select prod_name,prod_price
    -> from products
    -> where prod_price=2.50;
+---------------+------------+
| prod_name     | prod_price |
+---------------+------------+
| Carrots       |       2.50 |
| TNT (1 stick) |       2.50 |
+---------------+------------+
2 rows in set (0.00 sec)

mysql> 
```
> 同时使用 order by子句 和 where子句 时，
> 应该让 order by子句 位于 where子句 之后

```sql
mysql> select prod_id,prod_name,prod_price
    -> from products
    -> where prod_price=2.50
    -> order by prod_price;
+---------+---------------+------------+
| prod_id | prod_name     | prod_price |
+---------+---------------+------------+
| FC      | Carrots       |       2.50 |
| TNT1    | TNT (1 stick) |       2.50 |
+---------+---------------+------------+
2 rows in set (0.00 sec)
```

## 6.2 where子句操作符

> where子句，它确定一个列是否包含特定的值

```sql
=				--等于
<>				--不等于
!=				--不等于
<				--小于
<=				--小于等于
>				--大于
>=				--大于等于
between			--在指定的两个值之间
```
### 6.2.1 检查单个值

> 单引号用来限定字符串
> > 如果将值与'串类型'的列进行比较，则需要限定引号
> > 如果将值与'数值类型'的列进行比较，则不需要限定引号
>
>  > MySQL在执行匹配时默认不区分大小写

```sql
mysql> select prod_name,prod_price
    -> from products
    -> where prod_name = 'fuses';
+-----------+------------+
| prod_name | prod_price |
+-----------+------------+
| Fuses     |       3.42 |
+-----------+------------+
1 row in set (0.01 sec)

mysql> 
```


```sql
mysql> select prod_name,prod_price
    -> from products
    -> where prod_price <= 10
    -> order by prod_price;
+----------------+------------+
| prod_name      | prod_price |
+----------------+------------+
| Carrots        |       2.50 |
| TNT (1 stick)  |       2.50 |
| Fuses          |       3.42 |
| Sling          |       4.49 |
| .5 ton anvil   |       5.99 |
| Oil can        |       8.99 |
| 1 ton anvil    |       9.99 |
| Bird seed      |      10.00 |
| TNT (5 sticks) |      10.00 |
+----------------+------------+
9 rows in set (0.00 sec)

mysql> 
```
### 6.2.2 不匹配检查

```sql
mysql> select vend_id,prod_name
    -> from products
    -> where vend_id <> 1003
    -> order by vend_id;
+---------+--------------+
| vend_id | prod_name    |
+---------+--------------+
|    1001 | .5 ton anvil |
|    1001 | 1 ton anvil  |
|    1001 | 2 ton anvil  |
|    1002 | Fuses        |
|    1002 | Oil can      |
|    1005 | JetPack 1000 |
|    1005 | JetPack 2000 |
+---------+--------------+
7 rows in set (0.05 sec)

mysql> 
```

```sql
mysql> select vend_id,prod_name
    -> from products
    -> where vend_id != 1003 
    -> order by vend_id;
+---------+--------------+
| vend_id | prod_name    |
+---------+--------------+
|    1001 | .5 ton anvil |
|    1001 | 1 ton anvil  |
|    1001 | 2 ton anvil  |
|    1002 | Fuses        |
|    1002 | Oil can      |
|    1005 | JetPack 1000 |
|    1005 | JetPack 2000 |
+---------+--------------+
7 rows in set (0.00 sec)

mysql> 
```
### 6.2.3 范围值检查

> between 操作符： 检查某个范围的值 （闭区间）
> 它需要两个值，范围的开始值、结束值
```sql
mysql> select prod_name,prod_price
    -> from products
    -> where prod_price between 5 and 10
    -> order by prod_price;
+----------------+------------+
| prod_name      | prod_price |
+----------------+------------+
| .5 ton anvil   |       5.99 |
| Oil can        |       8.99 |
| 1 ton anvil    |       9.99 |
| Bird seed      |      10.00 |
| TNT (5 sticks) |      10.00 |
+----------------+------------+
5 rows in set (0.00 sec)

mysql> 
```

### 6.2.4 空值检查

> 一个列不包含值时，称其包含空值NULL
>
> > NULL  无值（no value），它与字段包含0、空字符串、仅仅包含空格 不同

> select语句有一个特殊的where子句，用来检查具有NULL值的列
> 这个where子句就是 is null 子句

```sql
mysql> select prod_name,prod_price
    -> from products
    -> where prod_price is null;
Empty set (0.00 sec)

mysql> 
```

```sql
mysql> select cust_id,cust_email
    -> from customers
    -> where cust_email is null;
+---------+------------+
| cust_id | cust_email |
+---------+------------+
|   10002 | NULL       |
|   10005 | NULL       |
+---------+------------+
2 rows in set (0.00 sec)

mysql> 
```
## 6.3 小结

> 1. 使用select语句的where子句过滤返回的数据
> 2. 我们学习了 相等、不相等、大于、小于、值的范围、以及NULL值 等进行测试



# 第7章 数据过滤(select语句的where子句，的 and、or、in、not操作符)

## 简介

> 组合where子句 以建立功能更强的更高级的搜索条件
> 学习使用 not 和 in 操作符
> 操作符：用来联结或改变where子句中的子句的关键字。也称为逻辑操作符（logical operator ）
## 7.1 组合where子句

> where子句中的多个过滤条件，
> 通过组合使用 and子句、or子句 达到
### 7.1.1 and 操作符

> and
> > 用在where子句中的关键字
> > 用来指示：索引'满足所有给定条件'的行
>
>  > 只包含一个 and关键字 的语句，把两个过滤条件组合在一起
>  > 添加多个过滤条件，每添加一条就要使用一个 and 
```sql
mysql> select prod_id,prod_price,prod_name
    -> from products
    -> where vend_id = 1003 and prod_price <= 10;
+---------+------------+----------------+
| prod_id | prod_price | prod_name      |
+---------+------------+----------------+
| FB      |      10.00 | Bird seed      |
| FC      |       2.50 | Carrots        |
| SLING   |       4.49 | Sling          |
| TNT1    |       2.50 | TNT (1 stick)  |
| TNT2    |      10.00 | TNT (5 sticks) |
+---------+------------+----------------+
5 rows in set (0.00 sec)

mysql> 
```
### 7.1.2 or 操作符

> or
>
> > where子句中使用的关键字
> > 用来检索'匹配任一给定条件'的行

```sql
mysql> select prod_id,prod_name,prod_price,vend_id
    -> from products
    -> where vend_id = 1002 or vend_id = 1003;
+---------+----------------+------------+---------+
| prod_id | prod_name      | prod_price | vend_id |
+---------+----------------+------------+---------+
| FU1     | Fuses          |       3.42 |    1002 |
| OL1     | Oil can        |       8.99 |    1002 |
| DTNTR   | Detonator      |      13.00 |    1003 |
| FB      | Bird seed      |      10.00 |    1003 |
| FC      | Carrots        |       2.50 |    1003 |
| SAFE    | Safe           |      50.00 |    1003 |
| SLING   | Sling          |       4.49 |    1003 |
| TNT1    | TNT (1 stick)  |       2.50 |    1003 |
| TNT2    | TNT (5 sticks) |      10.00 |    1003 |
+---------+----------------+------------+---------+
9 rows in set (0.02 sec)

mysql> 
```
### 7.1.3 计算次序

> where子句 中允许组合使用多个and 和 or操作符
> > and 比 or 的优先级高
> > ( ) 比and or 优先级高
> > 使用具有and or操作符的where子句，都应该使用圆括号 明确地分组操作符
```sql
mysql> select prod_name,prod_price,vend_id
    -> from products
    -> where (vend_id = 1002 or vend_id = 1003) and prod_price >= 10
    -> order by prod_price;
+----------------+------------+---------+
| prod_name      | prod_price | vend_id |
+----------------+------------+---------+
| Bird seed      |      10.00 |    1003 |
| TNT (5 sticks) |      10.00 |    1003 |
| Detonator      |      13.00 |    1003 |
| Safe           |      50.00 |    1003 |
+----------------+------------+---------+
4 rows in set (0.00 sec)

mysql> 
```
## 7.2 in 操作符

> in 操作符
> > 用在where子句中
> > 用来指定条件范围（用来指定要匹配值的清单）
> > 完成与 or 相同的功能
>
> in 相比 or 的优点
> > 语法更清楚 直观，易于管理
> > 一般情况下 比  or操作符清单  执行更快
> > 最大的优点是，可以包含其他select语句，使得能够更动态的建立where子句，在14章详细介绍
```sql
mysql> select prod_name,prod_price,vend_id
    -> from products
    -> where vend_id in (1002,1003)
    -> order by prod_price,prod_name;
+----------------+------------+---------+
| prod_name      | prod_price | vend_id |
+----------------+------------+---------+
| Carrots        |       2.50 |    1003 |
| TNT (1 stick)  |       2.50 |    1003 |
| Fuses          |       3.42 |    1002 |
| Sling          |       4.49 |    1003 |
| Oil can        |       8.99 |    1002 |
| Bird seed      |      10.00 |    1003 |
| TNT (5 sticks) |      10.00 |    1003 |
| Detonator      |      13.00 |    1003 |
| Safe           |      50.00 |    1003 |
+----------------+------------+---------+
9 rows in set (0.00 sec)

mysql> 
```
## 7.3 not 操作符

> not
>
> > 用在where子句中
> > 否定跟在它之后所有的任何条件（用来否定后跟条件）
>
> > MySQL支持使用 not 对 in 、between、exists 子句取反

> 对于复杂的where子句，not 是非常有用的
> 例如，在与 in 操作符联合使用时，not使找出与条件不匹配的行非常简单

```sql
mysql> select prod_name,prod_price,vend_id
    -> from products
    -> where vend_id not in (1002,1003)
    -> order by vend_id,prod_name;
+--------------+------------+---------+
| prod_name    | prod_price | vend_id |
+--------------+------------+---------+
| .5 ton anvil |       5.99 |    1001 |
| 1 ton anvil  |       9.99 |    1001 |
| 2 ton anvil  |      14.99 |    1001 |
| JetPack 1000 |      35.00 |    1005 |
| JetPack 2000 |      55.00 |    1005 |
+--------------+------------+---------+
5 rows in set (0.01 sec)

mysql> 
```

## 7.4 小结

> 1. 在where子句中组合使用 and、or 操作符
> 2. 在where子句中使用 in 操作符
> 3. 在where子句中使用 not 操作符



# 第8章 用通配符进行过滤(select语句的where子句，的 like 操作符 和 %、_ 通配符)

## 简介

> 什么是通配符
> 如何组合使用 like操作符 和 通配符，进行通配搜索，以便对数据进行复杂过滤
## 8.1 like 操作符

> 通配符（wildcard）
> > 用来匹配值的一部分的特殊字符
> > 通配符本身实际就是 SQL的where子句中，有特殊含义的字符
>
> 利用通配符可创建比较特定数据的搜索模式

> 搜索模式（search pattern）
> > 由字面值、通配符或两者组合成的搜索条件
>
> 在搜索子句中使用通配符，必须使用like操作符
> like指示MySQL，后跟的搜索模式 利用通配符匹配而不是直接相等匹配进行比较。
>
> > 从技术上说：like 是谓词，而不是操作符 

> 搜索是否区分大小写
> > 搜索  默认是不区分大小写的
> > 如果需要区分大小写的话，要加其它关键字 

### 8.1.1 百分号（%）通配符

> %
>
> > 表示任何字符出现任意次数

```sql
mysql> select prod_id,prod_name
    -> from products
    -> where prod_name like 'jet%' ;
+---------+--------------+
| prod_id | prod_name    |
+---------+--------------+
| JP1000  | JetPack 1000 |
| JP2000  | JetPack 2000 |
+---------+--------------+
2 rows in set (0.01 sec)

mysql> 
```


 >  > 通配符可以在搜索模式中任意位置使用
 >  > 并且可以使用多个通配符
```sql
mysql> select prod_id,prod_name
    -> from products
    -> where prod_name like '%anvil%';
+---------+--------------+
| prod_id | prod_name    |
+---------+--------------+
| ANV01   | .5 ton anvil |
| ANV02   | 1 ton anvil  |
| ANV03   | 2 ton anvil  |
+---------+--------------+
3 rows in set (0.00 sec)

mysql> 

```
> >通配符也可以出现在搜索模式的中间位置
> >比如，找出以s起头以e结尾的所有产品

```sql
mysql> select prod_id,prod_name
    -> from products
    -> where prod_name like 's%e';
+---------+-----------+
| prod_id | prod_name |
+---------+-----------+
| SAFE    | Safe      |
+---------+-----------+
1 row in set (0.00 sec)

mysql> 
```
>> 注意，%还能匹配0个字符
>> % 代表搜索模式中给定位置的0个、1个或多个字符
>
> >注意尾空格
> >‘%   ’ 最后有多余的空格字符，将会被忽略
> >如果想匹配它们，最简单的办法是：在搜索模式的最后附加一个%，如 '%   %' 
> >更好的办法是：使用函数去掉首尾空格（11章 介绍）
>
>> 注意NULL
>> '%' 不能匹配NULL

### 8.1.2 下划线（_）通配符

> ' - '
> 只匹配单个字符
> 总是匹配一个字符，不能多也不能少

```sql
mysql> select prod_id,prod_name
    -> from products
    -> where prod_name like '_ ton anvil';
+---------+-------------+
| prod_id | prod_name   |
+---------+-------------+
| ANV02   | 1 ton anvil |
| ANV03   | 2 ton anvil |
+---------+-------------+
2 rows in set (0.00 sec)

mysql> 
```

```sql
mysql> select prod_id,prod_name 
    -> from products
    -> where prod_name like '% ton anvil';
+---------+--------------+
| prod_id | prod_name    |
+---------+--------------+
| ANV01   | .5 ton anvil |
| ANV02   | 1 ton anvil  |
| ANV03   | 2 ton anvil  |
+---------+--------------+
3 rows in set (0.00 sec)

mysql> 
```

## 8.2 使用通配符的技巧

> 通配符很有用，但通配符搜索的处理一般要比前面讨论的其他搜索花费的时间更长
> 这里给出一些使用通配符要记住的技巧
>
> > 1. 不要过度使用通配符。如果其他操作符可以达到相同目的，应该使用其他操作符
> > 2. 在确实需要使用通配符时，除非绝对有必要，否则不要把它们用在搜索模式的开始处。把通配符置于搜索模式的开始处，搜索起来是最慢的
> > 3. 仔细注意通配符的位置。
> > 总之，通配符是一种极重要和有用的搜索工具

## 8.3 小结

> 1. 什么是通配符
> 2. 如何在where子句中使用SQL通配符
> 3. 通配符应该细心使用，不要过度使用



# 第9章 用正则表达式进行搜索(select语句的where子句中使用正则表达式 来更好地控制数据过滤)

## 简介

> 学习，在 select语句的where子句中使用正则表达式 来更好地控制数据过滤
## 9.1 正则表达式介绍

> 正则表达式：是用来匹配文本的特殊的串（字符集合）
> > 从一个文本文件中提取电话号码
> > 查找名字中间有数字的所有文件
> > 在一个文本中找到所有重复的单词
> > 替换一个页面中的所有URL为这些URL的实际HTML链接
## 9.2 使用MySQL正则表达式

> 正则表达式的作用：
> > 匹配文本
> > 将一个模式（正则表达式）与一个文本串进行比较

### 9.2.1 基本字符匹配

> MySQL的正则表达式中：where子句中的like关键字，被 regexp 替代
> regexp 
>
> > 它告诉MySQL：regexp后跟的东西为正则表达式

> 点 '' .'' 
> 是正则表达式语言中一个特殊的字符，它表示匹配任意一个字符

```sql
mysql> select prod_name
    -> from products
    -> where prod_name regexp '.000'
    -> order by prod_name;
+--------------+
| prod_name    |
+--------------+
| JetPack 1000 |
| JetPack 2000 |
+--------------+
2 rows in set (0.00 sec)

```
> like 和 regexp  有一个重要的差别 （看下面两个代码段）
> > like 匹配整个列，如果被匹配的文本在列值中出现，like将不会找到它，相应的行也不被返回（除非使用通配符）
> > regexp 在列值内进行匹配，如果被匹配的文本在列值中出现，regexp将会找到它，相应的行将被返回
```sql
mysql> select prod_name 
    -> from products
    -> where prod_name like '1000'
    -> order by prod_name;
Empty set (0.00 sec)

mysql> 
```
```sql
mysql> select prod_name
    -> from products
    -> where prod_name regexp '1000'
    -> order by prod_name;
+--------------+
| prod_name    |
+--------------+
| JetPack 1000 |
+--------------+
1 row in set (0.04 sec)

mysql> 
```
>> regexp 能用来匹配整个列值（从而起到与like 相同的作用）：使用 ^ 和 $ 定位符

>MySQL的正则表达式匹配不区分大小写
>>为区分大小写，可使用 binary 关键字
>>如：

```sql
mysql> select prod_name
    -> from products
    -> where prod_name regexp binary 'JetPack .000';
+--------------+
| prod_name    |
+--------------+
| JetPack 1000 |
| JetPack 2000 |
+--------------+
2 rows in set (0.01 sec)

mysql> 
```
### 9.22 进行 or 匹配

> '|'
> > 为正则表达式的 or 操作符
> > 它表示，匹配其中之一
>
>  > 想达到两个以上的 or条件 效果
>  > 可以给出两个以上的 or 条件
>  > 如： '1000|2000|3000'
```sql
mysql> select prod_name 
    -> from products
    -> where prod_name regexp '1000|2000'
    -> order by prod_name;
+--------------+
| prod_name    |
+--------------+
| JetPack 1000 |
| JetPack 2000 |
+--------------+
2 rows in set (0.00 sec)

mysql> 
```
### 9.2.3 匹配几个字符之一

> 只匹配特定的字符
> 通过  [ ] 指定一组括起来的字符，来实现

```sql
mysql> select prod_name 
    -> from products
    -> where prod_name regexp '[123] Ton'
    -> order by prod_name;
+-------------+
| prod_name   |
+-------------+
| 1 ton anvil |
| 2 ton anvil |
+-------------+
2 rows in set (0.00 sec)

mysql> 
```
> [123] 
> 定义一组字符，表示匹配1 或2 或3 
> >  [ ] 是另一种形式的 or 语句，
> >  所以，事实上 [123] 是[1 | 2 | 3] 的缩写

> 字符集也可以被否定
> 匹配指定字符集以外的任何东西
>
> > 在字符集的开始处放置一个 ^ 即可

```sql
mysql> select prod_name 
    -> from products 
    -> where prod_name regexp '[^123] ton anvil' 
    -> order by prod_name;
+--------------+
| prod_name    |
+--------------+
| .5 ton anvil |
+--------------+
1 row in set (0.01 sec)

mysql> 
```
```sql
mysql> select prod_name 
    -> from products 
    -> where prod_name regexp '[123] ton anvil' 
    -> order by prod_name;
+-------------+
| prod_name   |
+-------------+
| 1 ton anvil |
| 2 ton anvil |
+-------------+
2 rows in set (0.00 sec)

mysql> 
```
### 9.2.4 匹配范围

> 集合可以用来定义要匹配的一个或多个字符
> > 匹配数字0到9：[0-9] （等价于 [0123456789] ）
> > 匹配任意字母字符： [a-zA-Z]
> >
> > > 使用 - 来定义一个范围

```sql
mysql> select prod_name 
    -> from products
    -> where prod_name regexp '[1-5] Ton'
    -> order by prod_name;
+--------------+
| prod_name    |
+--------------+
| .5 ton anvil |
| 1 ton anvil  |
| 2 ton anvil  |
+--------------+
3 rows in set (0.00 sec)

mysql> 
```

### 9.2.5 匹配特殊字符

> 为匹配特殊字符，必须使用 \\ 为前导，
> 这就是所谓的转义

```sql
 \\- 		表示查找 - 
 \\. 		表示查找 .
 \\[ 		表示查找 [
 \\] 		表示查找 ]
 \\| 		表示查找 |
```


```sql
mysql> select vend_name 
    -> from vendors
    -> where vend_name regexp '\\.' -- \\. 匹配 .
    -> order by vend_name;
+--------------+
| vend_name    |
+--------------+
| Furball Inc. |
+--------------+
1 row in set (0.05 sec)

mysql> 
```
> \\ 也可以用来引用元字符（具有特殊含义的字符）

```sql
\\f		换页
\\n		换行
\\r		回车
\\t		制表
\\v		纵向制表
```
```sql
匹配 \ 
	需要使用  \\\
```

> 正则表达式中 一个  \  实现转义特殊字符
> MySQL正则表达式中 两个  \\  实现转义特殊字符
>
> > MySQL自己解释一个，正则表达式库解释另一个

### 9.2.6 匹配字符类

> 预定义的字符集，称为字符类
```sql
[:alnum:]		任意字母和数字（同[a-zA-Z0-9]）
[:alpha:]		任意字符（同[a-zA-Z]）
[:blank:]		空格和制表（同[\\t]）
[:cntr1：]		ASCⅡ控制字符（ASCII 0到31和127）
[:digit:]		任意数字（同[0-9]）
[:graph:]		与[：print:]相同，但不包括空格
[:1ower:]		任意小写字母（同[a-z]）
[:print:]		任意可打印字符
[:punct:]		既不在[：alnum:]又不在[：cntr1：]中的任意字符
[:space:]		包括空格在内的任意空白字符（同[\\f\\n\\rl\t\\v]）
[:upper:]		任意大写字母（同[A-Z]）
[:xdigit:]		任意十六进制数字（同[a-fA-F0-9]）
```
### 9.2.7 匹配多个实例

> 目前为止，前面的所有正则表达式都试图匹配单次出现
>
> > 有时需要对匹配的数目进行更强的控制

```sql
		重复元字符
元字符				说明
*				0个或多个匹配
+				1个或多个匹配（等于{1,}）
?				0个或1个匹配（等于{0,1}）
{n}				指定数目的匹配
{n,}				不少于指定数目的匹配
{n,m}				匹配数目的范围（m不超过255）
```

```sql
mysql> select prod_name
    -> from products
    -> where prod_name regexp '\\([0-9] sticks?\\)'
    -> order by prod_name;
+----------------+
| prod_name      |
+----------------+
| TNT (1 stick)  |
| TNT (5 sticks) |
+----------------+
2 rows in set (0.01 sec)

mysql> 
```
```
正则表达式： \\([0-9] sticks?\\)
```

```sql
正则表达式 \\([0-9] sticks?\\)
\\(				匹配 (
[0-9] 			匹配任意数字
sticks?			匹配stick和sticks（s后的?，使s可选）（因为 ? 匹配它前面的任何字符的0次或一次出现）
\\) 			匹配 )
```

```sql
mysql> select prod_name
    -> from products
    -> where prod_name regexp '[[:digit:]]{4}' -- 匹配连在一起的4位数字
    -> order by prod_name;
+--------------+
| prod_name    |
+--------------+
| JetPack 1000 |
| JetPack 2000 |
+--------------+
2 rows in set (0.00 sec)

mysql> 
```

```sql
mysql> select prod_name
    -> from products
    -> where prod_name regexp '[0-9][0-9][0-9][0-9]'  -- 匹配连在一起的4位数字
    -> order by prod_name;
+--------------+
| prod_name    |
+--------------+
| JetPack 1000 |
| JetPack 2000 |
+--------------+
2 rows in set (0.00 sec)

mysql> 
```
### 9.2.8 定位符

>目前为止的所有例子，都是匹配一个串中任意位置的文本 

> 为了匹配特定位置的文本，需要使用定位符

```
	    定位元字符
元字符				说明
^				文本的开始
$				文本的结尾
[[:<:]]			词的开始
[[:>:]]			词的结尾
```
> 问题：找出以一个数（包括以小数点开始的数）开始的所有产品
>
> > ^ 定位符：匹配串的开始
```sql
mysql> select prod_name 
    -> from products
    -> where prod_name regexp '^[0-9\\.]' -- 只在 . 或任意数字为串中第一个字符时才匹配它们
    -> order by prod_name;
+--------------+
| prod_name    |
+--------------+
| .5 ton anvil |
| 1 ton anvil  |
| 2 ton anvil  |
+--------------+
3 rows in set (0.00 sec)

mysql> 
```
> ^的双重用途
> >在集合的开始位置：用来否定集合中的字符   （ 放在 [ ] 中的第一个位置）[^]
> >指串的开始处  （  放在 [ ] 前）^[]

> 使 regexp 起类似 like 的作用
> > like匹配整个串
> > regexp 匹配子串
>
> > 利用定位符 
> > 用 ^ 开始每个表达式
> > 用 $ 结束每个表达式
> > 可以使 regexp 的作用 与  like 一样


> 在MySQL中，简单的正则表达式测试
> > 可以在不使用数据库表的情况下用 select 来测试正则表达式。
> > regexp 检查总是返回0(没有匹配)、或1(匹配)
>
> 可以用带文子串的 regexp 来测正则表达式
> 如下所示，这个列子显然将返回0，（因为文本hello中没有数字）
```sql
mysql> select 'hello' regexp '[0-9]';
+------------------------+
| 'hello' regexp '[0-9]' |
+------------------------+
|                      0 |
+------------------------+
1 row in set (0.00 sec)

mysql> 
```
## 9.3 小结

> 1. MySQL 中正则表达式的基础知识
> 2. 在MySQL的 select 语句中 通过 regexp 关键字使用它们



# 第10章 创建计算字段(MySQL的select语句中的计算字段)

## 简介

> 什么是计算字段
> 如何创建计算字段
> 怎样从应用程序中使用别名引用它们
## 10.1 计算字段

> 计算字段：是运行时在select语句内创建的

> 字段（field）
> > 基本与列（column）意思相同
> > 数据库列：一般称为列
> > 术语字段：通常用在计算字段的连接上
## 10.2 拼接字段

> 拼接（concatenate）：将值联结到一起构成单个值
> > select语句中，可以使用 Concat()  函数来拼接两个列
>
> Concat() 拼接串，各个串之间用逗号分隔

```sql
mysql> select Concat(vend_name, ' (',vend_country,')')
    -> from vendors
    -> order by vend_name;
+------------------------------------------+
| Concat(vend_name, ' (',vend_country,')') |
+------------------------------------------+
| ACME (USA)                               |
| Anvils R Us (USA)                        |
| Furball Inc. (USA)                       |
| Jet Set (England)                        |
| Jouets Et Ours (France)                  |
| LT Supplies (USA)                        |
+------------------------------------------+
6 rows in set (0.00 sec)

mysql> 
```
> Trim函数
> RTrim() 去掉串右侧的空格
> LTrim() 去掉串左侧的空格
> Trim()   去掉串左右两侧的空格

```sql
mysql> select Concat(RTrim(vend_name),' (',vend_country,')')
    -> from vendors
    -> order by vend_name;
+------------------------------------------------+
| Concat(RTrim(vend_name),' (',vend_country,')') |
+------------------------------------------------+
| ACME (USA)                                     |
| Anvils R Us (USA)                              |
| Furball Inc. (USA)                             |
| Jet Set (England)                              |
| Jouets Et Ours (France)                        |
| LT Supplies (USA)                              |
+------------------------------------------------+
6 rows in set (0.00 sec)

mysql> 
```
> 别名（alias）：是一个字段或值的替换名
> >使用 AS 关键字赋予
> >起了别名之后，任何客户机应用，都可以按名引用这个列，就像它是表中一个实际的列一样

```sql
mysql> select Concat(RTrim(vend_name),' (',vend_country,')')  as vend_title
    -> from vendors
    -> order by vend_name;
+-------------------------+
| vend_title              |
+-------------------------+
| ACME (USA)              |
| Anvils R Us (USA)       |
| Furball Inc. (USA)      |
| Jet Set (England)       |
| Jouets Et Ours (France) |
| LT Supplies (USA)       |
+-------------------------+
6 rows in set (0.00 sec)

mysql> 
```
> 别名的其他用途
> 在列名含混或容易误解时：重命名它

>别名，有时也称为 导出列（derived column）
## 10.3 执行算术计算

> 计算字段的另一个常见用途是对检索出的数据进行算术计算

```sql
mysql> select prod_id,  quantity,  item_price,  quantity*item_price as expanded_price
    -> from orderitems
    -> where order_num = 20005;
+---------+----------+------------+----------------+
| prod_id | quantity | item_price | expanded_price |
+---------+----------+------------+----------------+
| ANV01   |       10 |       5.99 |          59.90 |
| ANV02   |        3 |       9.99 |          29.97 |
| TNT2    |        5 |      10.00 |          50.00 |
| FB      |        1 |      10.00 |          10.00 |
+---------+----------+------------+----------------+
4 rows in set (0.03 sec)

mysql> 
```
> 执行算术计算时，需要用到基本的操作符
> ( ) 圆括号 可用来区分优先顺序

```sql
MySQL算术操作符
+			加
-			减
*			乘
/			除
```
> 如何测试计算
>
> > 可以省略from子句，以便简单地访问和处理表达式

```sql
mysql> select 3*2; -- 返回6
+-----+
| 3*2 |
+-----+
|   6 |
+-----+
1 row in set (0.00 sec)

mysql> 
```

```sql
mysql> select Trim('   abc   '); --返回abc
+-------------------+
| Trim('   abc   ') |
+-------------------+
| abc               |
+-------------------+
1 row in set (0.00 sec)

mysql> 
```

```sql
mysql> select Now(); --返回当前日期和时间
+---------------------+
| Now()               |
+---------------------+
| 2020-04-24 14:37:38 |
+---------------------+
1 row in set (0.00 sec)

mysql> 
```
## 10.4 小结

> 1. 计算字段，如何创建计算字段
> 2. 计算字段拼接、执行算术运算
> 3. 创建、使用别名，以便应用程序能引用计算字段





# 第11章 使用数据处理函数(MySQL的数据处理函数：日期和时间处理函数、文本处理函数、数值处理函数)

## 11.1 函数

> SQL 支持利用函数来处理数据，给数据的转换和处理提供了方便
> 多数SQL语句是可移植的
> 而SQL函数的可移植性却不强
> 所以，如果你决定使用函数，应该保证做好代码注释
## 11.2 使用函数

> 文本函数：用于处理文本串（如删除或填充值，转换值为大写或小写）的文本函数。
> 数值函数：用于在数值数据上进行算术操作（如返回绝对值，进行代数运算）的数值函数。
> 日期时间函数：用于处理日期和时间值并从这些值中提取特定成分（例如，返回两个日期之差，检查日期有效性等）的日期和时间函数。
> 系统函数：返回DBMS正使用的特殊信息（如返回用户登录信息，检查版本细节）的系统函数。
### 11.2.1 文本处理函数

> Trim函数
> RTrim() 去掉串右侧的空格
> LTrim() 去掉串左侧的空格
> Trim()   去掉串左右两侧的空格

> Upper() 函数：将文本转换为大写

> 拼接（concatenate）：将值联结到一起构成单个值
> > select语句中，可以使用 Concat()  函数来拼接两个列
>
> Concat() 拼接串，各个串之间用逗号分隔

```sql
常用的文本处理函数
函数				说明
Left()		返回串左边的字符
Length()	返回串的长度
Locate()	找出串的一个子串
Lower()		将串转换为小写
LTrim()		去掉串左边的空格
Right()		返回串右边的字符

RTrim()		去掉串右边的空格
Soundex()	返回串的SOUNDEX值
SubString()	返回子串的字符
Upper()		将串转换为大写
```

```sql
mysql>select vend_name,upper(vend_name) as vend_name_UpperCase -- upper()
    -> from vendors
    -> order by vend_name;
+----------------+---------------------+
| vend_name      | vend_name_UpperCase |
+----------------+---------------------+
| ACME           | ACME                |
| Anvils R Us    | ANVILS R US         |
| Furball Inc.   | FURBALL INC.        |
| Jet Set        | JET SET             |
| Jouets Et Ours | JOUETS ET OURS      |
| LT Supplies    | LT SUPPLIES         |
+----------------+---------------------+
6 rows in set (0.00 sec)

mysql> 
```
> Soundex() 函数
>
> > 能对串进行发音比较

```sql
mysql> select cust_name,cust_contact
    -> from customers
    -> where Soundex(cust_contact) = Soundex('Y Lie'); --使用 Soundex转换列值，然后Soundex值匹配时...
+-------------+--------------+
| cust_name   | cust_contact |
+-------------+--------------+
| Coyote Inc. | Y Lee        |
+-------------+--------------+
1 row in set (0.04 sec)

mysql> 
```
### 11.2.2 日期和时间处理函数

```sql
常用日期和时间处理函数
函数					说明
AddDate（）		增加一个日期（天、周等）
AddTime（）		增加一个时间（时、分等）

CurDate（）		返回当前日期
CurTime（）		返回当前时间
Now（）			返回当前日期和时间

DateDiff（）		计算两个日期之差
Date_Add（）		高度灵活的日期运算函数
Date_Format（）	返回一个格式化的日期或时间串

DayofWeek（）	对于一个日期，返回对应的星期几

Date（）			返回一个日期时间的-日期部分
Time（）			返回一个日期时间的-时间部分

--日期部分
Hour（）			返回一个时间的-小时部分
Minute（）		返回一个时间的-分钟部分
Second（）		返回一个时间的-秒部分

--时间部分
Hour（）			返回一个时间的-小时部分
Minute（）		返回一个时间的-分钟部分
Second（）		返回一个时间的-秒部分
```
> 数据经常用日期进行过滤
> > 不管是插入、更新表还是用where子句进行过滤
> > 日期的格式必须为：yyyy-mm-dd
>
> > 应该总是使用4位数字的年份，4位数字年份更可靠

```sql
mysql> select order_date
    -> from orders;
+---------------------+
| order_date          |
+---------------------+
| 2005-09-01 00:00:00 |
| 2005-09-12 00:00:00 |
| 2005-09-30 00:00:00 |
| 2005-10-03 00:00:00 |
| 2005-10-08 00:00:00 |
+---------------------+
5 rows in set (0.00 sec)

mysql> 
```
>> 如果要的仅是日期，请使用Date()
```sql
mysql> select date(order_date)	-- Date（）			返回一个日期时间的-日期部分
    -> from orders;
+------------------+
| date(order_date) |
+------------------+
| 2005-09-01       |
| 2005-09-12       |
| 2005-09-30       |
| 2005-10-03       |
| 2005-10-08       |
+------------------+
5 rows in set (0.00 sec)

mysql> 
```
>>  如果要的仅是时间，请使用Time()
```sql
mysql> select time(order_date) -- Time（）			返回一个日期时间的-时间部分
    -> from orders;
+------------------+
| time(order_date) |
+------------------+
| 00:00:00         |
| 00:00:00         |
| 00:00:00         |
| 00:00:00         |
| 00:00:00         |
+------------------+
5 rows in set (0.00 sec)

mysql> 
```
> 对时间进行相等测试检索操作时，尽量使用这些时间函数，这样检索更精准
```sql
mysql> select cust_id,order_num,order_date
    -> from orders
    -> where Date(order_date) = '2005-09-01';
+---------+-----------+---------------------+
| cust_id | order_num | order_date          |
+---------+-----------+---------------------+
|   10001 |     20005 | 2005-09-01 00:00:00 |
+---------+-----------+---------------------+
1 row in set (0.00 sec)

mysql> 
```

检索某一时间范围：比如9月下的所有订单

```sql
mysql> select cust_id,order_num,order_date
    -> from orders
    -> where Date(order_date) between '2005-09-01' and '2005-09-30';
+---------+-----------+---------------------+
| cust_id | order_num | order_date          |
+---------+-----------+---------------------+
|   10001 |     20005 | 2005-09-01 00:00:00 |
|   10003 |     20006 | 2005-09-12 00:00:00 |
|   10004 |     20007 | 2005-09-30 00:00:00 |
+---------+-----------+---------------------+
3 rows in set (0.00 sec)

mysql> 
```

```sql
mysql> select cust_id,order_num,order_date
    -> from orders
    -> where Year(order_date)=2005 and Month(order_date)=9;
+---------+-----------+---------------------+
| cust_id | order_num | order_date          |
+---------+-----------+---------------------+
|   10001 |     20005 | 2005-09-01 00:00:00 |
|   10003 |     20006 | 2005-09-12 00:00:00 |
|   10004 |     20007 | 2005-09-30 00:00:00 |
+---------+-----------+---------------------+
3 rows in set (0.00 sec)

mysql> 
```
### 11.2.3 数值处理函数

>仅处理数值数据
>一般主要用于 代数、三角、几何运算等


```sql
	常用数值处理函数
函数				说明
Abs（）		返回一个数的绝对值
Cos（）		返回一个角度的余弦
Exp（）		返回一个数的指数值
Mod（）		返回除操作的余数
Pi（）		返回圆周率
Rand（）		返回一个随机数
Sin（）		返回一个角度的正弦
Sqrt（）		返回一个数的平方根
Tan（）		返回一个角度的正切
```
## 11.3 小结

> 1. 如何使用SQL的数据处理函数
> 2. 着重介绍了日期处理函数



# 第12章 汇总数据(avg、count、max、min、sum函数)

## 简介

> 什么是SQL的聚集函数
> 使用它们汇总表的数据
## 12.1 聚集函数

> 汇总数据
> > 确定表中行数（或者满足某个条件或包含某个特定值的行数）。
> > 获得表中行组的和。
> > 找出表列（或所有行或某些特定的行）的最大值、最小值和平均值。

> MySQL给了5个聚集函数
> 聚集函数（aggregate function）：运行在行组上，计算和返回单个值的函数

```sql
	   SQL聚集函数
函数					说明
AVG（）			返回某列的平均值
COUNT（）		返回某列的行数
MAX（）			返回某列的最大值
MIN（）			返回某列的最小值
SUM（）			返回某列值之和
```
### 12.1.1 avg() 函数

> AVG() 通过对表中行数计数并计算特定列值之和，求得该列的平均值。
> AVG() 可用来返回所有列的平均值，也可以用来返回特定列或行的平均值。

> 返回所有特定列的所有行的平均值

```sql
mysql> select avg(prod_price) as avg_price -- 返回所有产品的平均价格
    -> from products;
+-----------+
| avg_price |
+-----------+
| 16.133571 |
+-----------+
1 row in set (0.01 sec)
```
> 返回特定列的特定行的平均值
```sql
mysql> select avg(prod_price) as avg_price
    -> from products
    -> where vend_id = 1003; -- 返回特定供应商的产品的平均价格
+-----------+
| avg_price |
+-----------+
| 13.212857 |
+-----------+
1 row in set (0.00 sec)
```
> 只用于单个列
> > AVG（）只能用来确定特定数值列的平均值，而且列名必须作为函数参数给出。
> > 为了获得多个列的平均值，必须使用多个AVG（）函数。

>  NULL值
>
>  > AVG（）函数忽略列值为NULL的行。

### 12.1.2 count() 函数

> count()函数
> > 确定表中行的数目或符合特定条件的行的数目
>
> COUNT（）函数有两种使用方式。
> >使用COUNT（*）对表中行的数目进行计数，不管表列中包含的是空值（NULL）还是非空值。
> >使用COUNT（column）对特定列中具有有效值的行进行计数，忽略NULL值。


```sql
-- 返回customers表中客户的总数
--在此例子中，利用COUNT（*）对所有行计数，不管行中各列有什么值。计数值在num_cust中返回。
mysql> select count(*) as num_cust 
    -> from customers;
+----------+
| num_cust |
+----------+
|        5 |
+----------+
1 row in set (0.05 sec)
```

```sql
--这条SELECT语句使用COUNT（cust_email）对cust_email列中有值的行进行计数。
mysql> select count(cust_email) as num_cust 
    -> from customers;
+----------+
| num_cust |
+----------+
|        3 |
+----------+
1 row in set (0.00 sec)
```
> NULL值
> > 如果指定列名，则指定列的值为空的行被COUNT（）函数忽略，
> > 但如果COUNT（）函数中用的是星号（*），则不忽略。
### 12.1.3 max() 函数

> max() 
> > 返回指定列中的最大值
> > 要求指定列名，作为参数

```sql
mysql> select max(prod_price) as max_price
    -> from products;
+-----------+
| max_price |
+-----------+
|     55.00 |
+-----------+
1 row in set (0.00 sec)
```
> 对非数值数据使用MAX（）
> > 虽然MAX（）一般用来找出最大的数值或日期值，
> > 但MySQL允许将它用来返回任意列中的最大值，包括返回文本列中的最大值。
> > 在用于'文本数据'时，如果数据按相应的列排序，则MAX（）返回最后一行。
>
> NULL值
>
>  > MAX（）函数忽略列值为NULL的行。
### 12.1.4 min() 函数

> MIN（）返回指定列的最小值
> 要求指定列名，作为参数
```sql
mysql> select min(prod_price) as min_price
    -> from products;
+-----------+
| min_price |
+-----------+
|      2.50 |
+-----------+
1 row in set (0.00 sec)
```
> 对非数值数据使用MIN（）
> > MIN（）函数与MAX（）函数类似，
> > MySQL允许将它用来返回任意列中的最小值，包括返回文本列中的最小值。
> > 在用于文本数据时，如果数据按相应的列排序，则MIN（）返回最前面的行。
>
> NULL值
>
>  > MIN（）函数忽略列值为NULL的行。
### 12.1.5 sum() 函数

> sum()
>
> >用来返回指定列值的和（总计）
```sql
mysql> select sum(quantity) as items_ordered
    -> from orderitems
    -> where order_num = 20005;
+---------------+
| items_ordered |
+---------------+
|            19 |
+---------------+
1 row in set (0.00 sec)
```
> 在多个列上进行计算
>
> >如本例所示，利用标准的算术操作符，所有聚集函数都可用来执行多个列上的计算。
```sql
mysql> select sum(item_price*quantity) as items_ordered 
    -> from orderitems 
    -> where order_num = 20005;
+---------------+
| items_ordered |
+---------------+
|        149.87 |
+---------------+
1 row in set (0.00 sec)
```
>NULL值
>
>>SUM（）函数忽略列值为NULL的行。

## 12.2 聚集不同值

> 以上5个聚集函数
> > 指定 distinct 参数：只包含不同的值
> > 对所有的行执行计算，指定 all 参数或不给参数（all参数不需要指定，因为它是默认行为，如果不指定 distinct，则假定为 all） 

```sql
mysql> select avg(distinct prod_price) as avg_price
    -> from products
    -> where vend_id = 1003;
+-----------+
| avg_price |
+-----------+
| 15.998000 |
+-----------+
```
> 注意：
> >如果指定列名，则DISTINCT只能用于COUNT（）。
> >DISTINCT不能用于COUNT（*），因此不允许使用COUNT（DISTINCT），否则会产生错误。
> >类似地，DISTINCT必须使用列名，不能用于计算或表达式。
>
> > 将DISTINCT用于MIN()和MAX()，对结果没有任何影响，所以这样做实际上没有价值。

## 12.3 组合聚集函数

> select 语句可根据需要包含多个聚集函数

```sql
mysql> select count(*) as num_items,
    -> min(prod_price) as price_min,
    -> max(prod_price) as price_max,
    -> avg(prod_price) as price_avg
    -> from products;
+-----------+-----------+-----------+-----------+
| num_items | price_min | price_max | price_avg |
+-----------+-----------+-----------+-----------+
|        14 |      2.50 |     55.00 | 16.133571 |
+-----------+-----------+-----------+-----------+
```

> 取别名
>
> > 在指定别名以包含某个聚集函数的结果时，不应该使用表中实际的列名。
## 12.4 小结

> 聚集函数用来汇总数据。
> MySQL支持一系列聚集函数，可以用多种方法使用它们以返回所需的结果。
> 这些函数是高效设计的，它们返回结果一般比你在自己的客户机应用程序中计算要快得多。



# 第13章 分组数据(select语句的group by子句、having子句、select各子句的顺序)

## 简介

> 分组数据，以便能汇总表内容的子集
> select语句的group by子句、having子句
## 13.1 数据分组

> 分组允许把数据分为多个逻辑组，以便能对每个组进行聚集计算
## 13.2 创建分组

> 分组是在 select语句 的group by子句中建立的
>
> > 用 group by 分组数据

```sql
mysql> select vend_id,count(*) as num_prods
    -> from products
    -> group by vend_id;
+---------+-----------+
| vend_id | num_prods |
+---------+-----------+
|    1001 |         3 |
|    1002 |         2 |
|    1003 |         7 |
|    1005 |         2 |
+---------+-----------+
```
> group by 子句，指示MySQL分组数据，然后对每个组而不是整个结果集进行聚集

> 关于group by子句的一些重要规定
> > GROUP BY子句可以包含任意数目的列。这使得能对分组进行嵌套，为数据分组提供更细致的控制。
> > 如果在GROUPBY子句中嵌套了分组，数据将在最后规定的分组上进行汇总。换句话说，在建立分组时，指定的所有列都一起计算（所以不能从个别的列取回数据）。
> > GROUPBY子句中列出的每个列都必须是检索列或有效的表达式（但不能是聚集函数）。如果在SELECT中使用表达式，则必须在GROUP BY子句中指定相同的表达式。不能使用别名。
> > 除聚集计算语句外，SELECT语句中的每个列都必须在GROUP BY子句中给出。
> > 如果分组列中具有NULL值，则NULL将作为一个分组返回。如果列中有多行NULL值，它们将分为一组。
> > GROUP BY子句必须出现在WHERE子句之后，ORDER BY子句之前。

```sql
select 。。。
from 。。。
where 。。。
group by 。。。
order by。。。
```

> 使用ROLLUP 
> > 使用WITH ROLLUP关键字，可以得到每个分组以及每个分组汇总级别（针对每个分组）的值，
> > 如下所示：
```sql
mysql> select vend_id,count(*) as num_prods
    -> from products
    -> group by vend_id with rollup;
+---------+-----------+
| vend_id | num_prods |
+---------+-----------+
|    1001 |         3 |
|    1002 |         2 |
|    1003 |         7 |
|    1005 |         2 |
|    NULL |        14 |
+---------+-----------+
```
## 13.3 过滤分组

> >group by 分组数据（把原来的行数据，分为若干组）
> >having 过滤分组（规定包括哪些分组，排除哪些分组）
>
> > where子句过滤：指的是过滤行，而不是过滤分组（where没有分组的概念）
>
> > having子句，类似于where，目前为止所学过的所有类型的where子句都可以使用having子句进行替代
> > 唯一的差别是：where过滤行、having过滤分组
>
> > having 支持所有的where操作符
> > 所学过的有关where的所有这些技术、选项、通配符、操作符 都适用于having
> > 它们的句法是相同的，只是关键字有差别
>
>  > having子句过滤
>  > 过滤是基于分组聚集值
>  > 而不是特定行值
```sql
mysql> select cust_id,count(*) as num_orders
    -> from orders
    -> group by cust_id      -- 分组
    -> having count(*) >= 2; -- 过滤分组
+---------+------------+
| cust_id | num_orders |
+---------+------------+
|   10001 |          2 |
+---------+------------+
1 row in set (0.05 sec)
```
>having 和where的差别
>> where 在数据分组前进行过滤
>> having在数据分组后进行过滤

举个同时使用where和having的例子，如下：
```sql
mysql> select vend_id,count(*) as num_prods
    -> from products
    -> where prod_price >= 10 -- 先对行进行过滤
    -> group by vend_id       -- 再对过滤后的行进行分组
    -> having count(*) >= 2;  -- 最后对分组后的 各个分组进行过滤

+---------+-----------+
| vend_id | num_prods |
+---------+-----------+
|    1003 |         4 |
|    1005 |         2 |
+---------+-----------+
2 rows in set (0.00 sec)
```

```sql
mysql> select vend_id,count(*) as num_prods
    -> from products
    -> group by vend_id     -- 先对行数据 进行分组
    -> having count(*) >= 2;-- 再对分组后的各组进行过滤
+---------+-----------+
| vend_id | num_prods |
+---------+-----------+
|    1001 |         3 |
|    1002 |         2 |
|    1003 |         7 |
|    1005 |         2 |
+---------+-----------+
4 rows in set (0.01 sec)
```
## 13.4 分组和排序

```sql
ORDER BY            与                   GROUP BY 
ORDER BY                                 GROUP BY
排序产生的输出                              分组行。但输出可能不是分组的顺序
任意列都可以使用（甚至非选择的列也可以使用）      只可能使用选择列或表达式列，而且必须使用每个选择列表达式
不一定需要                                  如果与聚集函数一起使用列（或表达式），则必须使用
```
> 不要忘记order by
> >一般在使用group by 子句时，应该也给出 order  by 子句
> >这是保证数据正确排序的唯一的方法。千万不要依赖 group by 自身排序数据

没使用 order by 时
```sql
mysql> select order_num, sum(quantity * item_price) as order_total
    -> from orderitems
    -> group by order_num                      --按订单编号进行排序
    -> having sum(quantity * item_price) >= 50;--对分组后的数据，进行sum聚集运算，然后过滤掉不符合的分组
+-----------+-------------+
| order_num | order_total |
+-----------+-------------+
|     20005 |      149.87 |
|     20006 |       55.00 |
|     20007 |     1000.00 |
|     20008 |      125.00 |
+-----------+-------------+
4 rows in set (0.04 sec)
```
使用 order by 后
```sql
mysql> select order_num, sum(quantity * item_price) as order_total
    -> from orderitems
    -> group by order_num                      --按订单编号进行排序
    -> having sum(quantity * item_price) >= 50;--对分组后的数据，进行sum聚集运算，然后过滤掉不符合的分组
    -> order by order_total;
+-----------+-------------+
| order_num | order_total |
+-----------+-------------+
|     20006 |       55.00 |
|     20008 |      125.00 |
|     20005 |      149.87 |
|     20007 |     1000.00 |
+-----------+-------------+
4 rows in set (0.00 sec)
```

## 13.5 select 子句顺序

> 回顾一下select语句中子句的顺序

```sql
				SELECT子句及其顺序
子句                说明                是否必须使用
SELECT 			要返回的列或表达式        是
FROM			从中检索数据的表          仅在从表选择数据时使用
WHERE			行级过滤                 否
GROUP BY		分组说明                 仅在按组计算聚集时使用
HAVING			组级过滤                 否
ORDER BY		输出排序顺序              否
LIMIT			要检索的行数              否
```
## 13.6 小结

> 1. 使用 group by子句 对分组后的数据组进行汇总计算，返回每个组的计算结果
> 2. 使用 having子句  过滤特定的组
> 3. group by 一般会搭配 order by
> 4. having 和where之间的差异



# 第14章 使用子查询(where子句的in操作符中使用子查询、以及用子查询来填充计算列)

## 简介

>  什么是子查询
>  如何使用它们
## 14.1 子查询

> 子查询（subquary）
>
> > 嵌套在其他查询中的查询

## 14.2 利用子查询进行过滤

> 根据 （产品id）prod_id = 'TNT2' ，在 orderitems 表中，查找 （订单号）order_num
> 根据（订单号）order_num，在orders表中，查找 （客户的id）cust_id
> 根据（客户的id）cust_id，在 customers表中，查找 （客户的姓名）cust_name和（客户的联系名）cust_contact
```sql
mysql> select cust_name,cust_contact 
    -> from customers
    -> where cust_id in ( select cust_id
    ->                    from orders
    ->                    where order_num in ( select order_num
    ->                                         from orderitems
    ->                                         where prod_id = 'TNT2' ) ) ;
+----------------+--------------+
| cust_name      | cust_contact |
+----------------+--------------+
| Coyote Inc.    | Y Lee        |
| Yosemite Place | Y Sam        |
+----------------+--------------+
2 rows in set (0.00 sec)
```
> 虽然子查询一般与 in操作符 结合使用，但也可以用于测试等于（=）、不等于（<>）等

> 虽然对能嵌套的子查询的数目没有限制，
> 不过在实际使用时由于性能的限制，不能嵌套太多的子查询

> 子查询和性能
> 使用子查询并不总是  执行这种类型的数据检索的  最有效的方法，更多的论述，请参阅15章

## 14.3 作为计算字段使用子查询

> 显示customers表中每个客户的订单总数
> >1. 从customers表中检索客户列表（找到客户ID）
> >2. 对于检索出的每个客户，统计其在orders表中的订单数目（根据客户ID，统计此客户ID的订单总数）

```sql
--对客户ID为10001，的订单数量进行计数
-- （对特定客户ID的订单进行计数）
mysql> select count(*) as orders
    -> from orders
    -> where cust_id = 10001;
+--------+
| orders |
+--------+
|      2 |
+--------+
1 row in set (0.06 sec)
```

```sql
-- 为了对每个客户执行 count(*)计算，应该将count(*)作为一个子查询
-- （检索出每个客户ID，根据客户ID使用子查询，统计每个客户的订单数量）
mysql> select cust_name,
    ->        cust_state,
    ->        ( select count(*)
    ->          from orders
    ->          where customers.cust_id = orders.cust_id ) as orders
    -> from customers
    -> order by cust_name;
+----------------+------------+--------+
| cust_name      | cust_state | orders |
+----------------+------------+--------+
| Coyote Inc.    | MI         |      2 |
| E Fudd         | IL         |      1 |
| Mouse House    | OH         |      0 |
| Wascals        | IN         |      1 |
| Yosemite Place | AZ         |      1 |
+----------------+------------+--------+
5 rows in set (0.03 sec)
```

> 相关子查询（correlated subquary）：涉及外部查询的子查询
>
> > 任何时候，只要列名可能有多义性，就必须使用这种语法（完全限定列名）（表名和列名由一个句点分隔）

> 它 并不是解决这种数据检索的最有效的方法，后面章节会讲解的

>逐渐增加子查询来建立查询
>> 用子查询建立查询、调试查询的最有效的方法是逐渐进行，
>> > 首先，建立和测试最内层的查询，
>> > 然后，用硬编码数据建立和测试外层查询
>> > 并且 ，仅在确认它正常后才嵌入子查询。
>> > 这时，再次测试它。对于要增加的每个查询，重复这些步骤。
## 14.4 小结

> 1. 什么是子查询
> 2.  如何使用子查询
> 3. 子查询最常见的使用是在：where子句的in操作符中、以及用来填充计算列



# 第15章 联结表(主键、外键、内部联结)

## 简介

> 什么是联结
> 为什么要使用联结
> 如何编写使用联结的select语句
## 15.1 联结

>SQL最强大的功能之一，就是能在检索查询的执行中联结（join）表
### 15.1.1 关系表

> 相同的数据出现多次绝不是一件好事 
> 关系表的设计就是要保证把信息分解成多个表，一类数据一个表。
> 各表通过某些常用的值（即关系设计中的关系（relation））相关联

> 外键（foreign key）
> > 外键为某个表中的一列。它包含另一个表的主键值，定义了两个表之间的关系
>
> 好处
> > 信息不重复，从而不浪费时间和空间
> > 如果信息变动，可以只更新单个记录，相关表中的数据不用改变
> > 由于数据无重复，显然数据是一致的，这使得处理数据更简单
>
> > 总之，关系数据库的可伸展性远比非关系型数据库更好

> 可伸展性（scale）
> > 能够适应不断增加的工作量而不失败。
> > 设计良好的数据库或应用程序称之为可伸缩性好（scale well）
### 15.1.2 为什么要使用联结

> 分解数据为多个表能更有效地存储，更方便地处理，并且具有更大的可伸缩性
> 但是这些好处是有代价的

> 联结是一种机制，用来在一条select语句中关联表，因此称之为联结。

>维护完整性
>> 联结不是物理实体，它在实际的数据库表中不存在。
>> 联结由MySQL根据需要建立，它存在于查询的执行中。
>
>> 使用关系表时，仅在关系列中插入合法的数据非常重要
>
>> 为了防止插入不合法的数据，从而维护引用完整性
>> 是通过在表的定义中指定主键和外键来实现的。

## 15.2 创建联结

```sql
mysql> select v.vend_name, p.prod_name, p.prod_price
    -> from vendors v , products p
    -> where v.vend_id = p.vend_id
    -> order by v.vend_name , p.prod_name;
+-------------+----------------+------------+
| vend_name   | prod_name      | prod_price |
+-------------+----------------+------------+
| ACME        | Bird seed      |      10.00 |
| ACME        | Carrots        |       2.50 |
| ACME        | Detonator      |      13.00 |
| ACME        | Safe           |      50.00 |
| ACME        | Sling          |       4.49 |
| ACME        | TNT (1 stick)  |       2.50 |
| ACME        | TNT (5 sticks) |      10.00 |
| Anvils R Us | .5 ton anvil   |       5.99 |
| Anvils R Us | 1 ton anvil    |       9.99 |
| Anvils R Us | 2 ton anvil    |      14.99 |
| Jet Set     | JetPack 1000   |      35.00 |
| Jet Set     | JetPack 2000   |      55.00 |
| LT Supplies | Fuses          |       3.42 |
| LT Supplies | Oil can        |       8.99 |
+-------------+----------------+------------+
14 rows in set (0.00 sec)
```
> 上面的例子
> >这两个表用 where子句 联结
> >where子句指示MySQL匹配vendors表中的vend_id和products表中的vend_id
>
> 完全限定列名
> >在引用的列可能出现二义性时，必须使用完全限定列名
> >用一个点分隔表名和列名

### 15.2.1 where子句 的重要性

>>在一条select语句中联结几个表时，相应的关系是在运行在构造的
>
>>在联结两个表时，你实际上做的是将第一个表中的每一行与第二个表中的每一行配对。
>>where子句的过滤条件，它只包含那些匹配给定条件（这里是联结条件）的行
>
>笛卡尔积（cartesian product）
>>由没有联结条件的表关系返回的结果为笛卡尔积。
>>检索出的行数目：第一个表中的行数 乘以 第二个表中的行数
>>检索出的列数目：第一个表中的列数 加上 第二个表中的列数
>
>> 笛卡尔积举例如下
>> 可以看出，有很多匹配不正确的数据
>> 所以要利用where子句过滤笛卡尔积，拿到正确匹配的数据

```sql
mysql> select v.vend_name, p.prod_name, p.prod_price
    -> from vendors v , products p
    -> order  by v.vend_name, p.prod_name;
+----------------+----------------+------------+
| vend_name      | prod_name      | prod_price |
+----------------+----------------+------------+
| ACME           | .5 ton anvil   |       5.99 |
| ACME           | 1 ton anvil    |       9.99 |
| ACME           | 2 ton anvil    |      14.99 |
| ACME           | Bird seed      |      10.00 |
| ACME           | Carrots        |       2.50 |
| ACME           | Detonator      |      13.00 |
| ACME           | Fuses          |       3.42 |
| ACME           | JetPack 1000   |      35.00 |
| ACME           | JetPack 2000   |      55.00 |
| ACME           | Oil can        |       8.99 |
| ACME           | Safe           |      50.00 |
| ACME           | Sling          |       4.49 |
| ACME           | TNT (1 stick)  |       2.50 |
| ACME           | TNT (5 sticks) |      10.00 |
| Anvils R Us    | .5 ton anvil   |       5.99 |
| Anvils R Us    | 1 ton anvil    |       9.99 |
| Anvils R Us    | 2 ton anvil    |      14.99 |
| Anvils R Us    | Bird seed      |      10.00 |
| Anvils R Us    | Carrots        |       2.50 |
| Anvils R Us    | Detonator      |      13.00 |
| Anvils R Us    | Fuses          |       3.42 |
| Anvils R Us    | JetPack 1000   |      35.00 |
| Anvils R Us    | JetPack 2000   |      55.00 |
| Anvils R Us    | Oil can        |       8.99 |
| Anvils R Us    | Safe           |      50.00 |
| Anvils R Us    | Sling          |       4.49 |
| Anvils R Us    | TNT (1 stick)  |       2.50 |
| Anvils R Us    | TNT (5 sticks) |      10.00 |
| Furball Inc.   | .5 ton anvil   |       5.99 |
| Furball Inc.   | 1 ton anvil    |       9.99 |
| Furball Inc.   | 2 ton anvil    |      14.99 |
| Furball Inc.   | Bird seed      |      10.00 |
| Furball Inc.   | Carrots        |       2.50 |
| Furball Inc.   | Detonator      |      13.00 |
| Furball Inc.   | Fuses          |       3.42 |
| Furball Inc.   | JetPack 1000   |      35.00 |
| Furball Inc.   | JetPack 2000   |      55.00 |
| Furball Inc.   | Oil can        |       8.99 |
| Furball Inc.   | Safe           |      50.00 |
| Furball Inc.   | Sling          |       4.49 |
| Furball Inc.   | TNT (1 stick)  |       2.50 |
| Furball Inc.   | TNT (5 sticks) |      10.00 |
| Jet Set        | .5 ton anvil   |       5.99 |
| Jet Set        | 1 ton anvil    |       9.99 |
| Jet Set        | 2 ton anvil    |      14.99 |
| Jet Set        | Bird seed      |      10.00 |
| Jet Set        | Carrots        |       2.50 |
| Jet Set        | Detonator      |      13.00 |
| Jet Set        | Fuses          |       3.42 |
| Jet Set        | JetPack 1000   |      35.00 |
| Jet Set        | JetPack 2000   |      55.00 |
| Jet Set        | Oil can        |       8.99 |
| Jet Set        | Safe           |      50.00 |
| Jet Set        | Sling          |       4.49 |
| Jet Set        | TNT (1 stick)  |       2.50 |
| Jet Set        | TNT (5 sticks) |      10.00 |
| Jouets Et Ours | .5 ton anvil   |       5.99 |
| Jouets Et Ours | 1 ton anvil    |       9.99 |
| Jouets Et Ours | 2 ton anvil    |      14.99 |
| Jouets Et Ours | Bird seed      |      10.00 |
| Jouets Et Ours | Carrots        |       2.50 |
| Jouets Et Ours | Detonator      |      13.00 |
| Jouets Et Ours | Fuses          |       3.42 |
| Jouets Et Ours | JetPack 1000   |      35.00 |
| Jouets Et Ours | JetPack 2000   |      55.00 |
| Jouets Et Ours | Oil can        |       8.99 |
| Jouets Et Ours | Safe           |      50.00 |
| Jouets Et Ours | Sling          |       4.49 |
| Jouets Et Ours | TNT (1 stick)  |       2.50 |
| Jouets Et Ours | TNT (5 sticks) |      10.00 |
| LT Supplies    | .5 ton anvil   |       5.99 |
| LT Supplies    | 1 ton anvil    |       9.99 |
| LT Supplies    | 2 ton anvil    |      14.99 |
| LT Supplies    | Bird seed      |      10.00 |
| LT Supplies    | Carrots        |       2.50 |
| LT Supplies    | Detonator      |      13.00 |
| LT Supplies    | Fuses          |       3.42 |
| LT Supplies    | JetPack 1000   |      35.00 |
| LT Supplies    | JetPack 2000   |      55.00 |
| LT Supplies    | Oil can        |       8.99 |
| LT Supplies    | Safe           |      50.00 |
| LT Supplies    | Sling          |       4.49 |
| LT Supplies    | TNT (1 stick)  |       2.50 |
| LT Supplies    | TNT (5 sticks) |      10.00 |
+----------------+----------------+------------+
84 rows in set (0.00 sec)
```
>不要忘了where子句（在多表联结时）
>
>> 应该保证所有联结都有where子句，而且where子句必须正确

### 15.2.2 内部联结

> 上面所讲的联结称为等值联结（equi join），也称为内部联结
> 它基于两个表之间的相等测试

```sql
mysql> select v.vend_name,p.prod_name,p.prod_price
    -> from vendors v inner join products p
    -> on v.vend_id = p.vend_id;
+-------------+----------------+------------+
| vend_name   | prod_name      | prod_price |
+-------------+----------------+------------+
| Anvils R Us | .5 ton anvil   |       5.99 |
| Anvils R Us | 1 ton anvil    |       9.99 |
| Anvils R Us | 2 ton anvil    |      14.99 |
| LT Supplies | Fuses          |       3.42 |
| LT Supplies | Oil can        |       8.99 |
| ACME        | Detonator      |      13.00 |
| ACME        | Bird seed      |      10.00 |
| ACME        | Carrots        |       2.50 |
| ACME        | Safe           |      50.00 |
| ACME        | Sling          |       4.49 |
| ACME        | TNT (1 stick)  |       2.50 |
| ACME        | TNT (5 sticks) |      10.00 |
| Jet Set     | JetPack 1000   |      35.00 |
| Jet Set     | JetPack 2000   |      55.00 |
+-------------+----------------+------------+
14 rows in set (0.00 sec)
```
>> 在from子句中，用 inner  join 指定两表之间的关系（书写上，可以认为是，inner join 代替了表之间的逗号）
>> 联结条件 / 过滤条件：用特定的 on子句（书写上，可以认为是，on代替了where）
>> 传递给 on 的实际条件 与传递给 where的相同


> SQL 规范首选 inner join 语法
>
> > 使用明确的联结语法能够确保不会忘记联结条件，有时候这样做也能影响性能
### 15.2.3 联结多个表

> SQL对一条select语句中可以联结的表的数目没有限制，
> 创建规则也基本相同
> 首先列出所有的表，然后定义表之间的关系

```sql
--在orderitems表中 根据订单号 order_num = 20005，找到产品ID prod_id
--然后根据产品ID，在products表中，筛选并找到供应商ID vend_id
--根据供应商ID，在vendors表中，筛选并找到 select 选择的列值
mysql> select prod_name,vend_name,prod_price,quantity
    -> from orderitems,products,vendors
    -> where products.vend_id = vendors.vend_id
    ->   and orderitems.prod_id = products.prod_id
    ->   and order_num = 20005;
+----------------+-------------+------------+----------+
| prod_name      | vend_name   | prod_price | quantity |
+----------------+-------------+------------+----------+
| .5 ton anvil   | Anvils R Us |       5.99 |       10 |
| 1 ton anvil    | Anvils R Us |       9.99 |        3 |
| TNT (5 sticks) | ACME        |      10.00 |        5 |
| Bird seed      | ACME        |      10.00 |        1 |
+----------------+-------------+------------+----------+
4 rows in set (0.01 sec)
```
> 不要联结不必要的表
> 联结的表越多，性能下降越厉害


> 再看一遍，第十四章的，根据子查询进行过滤
> >根据 （产品id）prod_id = 'TNT2' ，在 orderitems 表中，查找 （订单号）order_num
> >根据（订单号）order_num，在orders表中，查找 （客户的id）cust_id
> >根据（客户的id）cust_id，在 customers表中，查找 （客户的姓名）cust_name和（客户的练习名）cust_contact
```sql
mysql> select cust_name,cust_contact 
    -> from customers
    -> where cust_id in ( select cust_id
    ->                    from orders
    ->                    where order_num in ( select order_num
    ->                                         from orderitems
    ->                                         where prod_id = 'TNT2' ) ) ;
+----------------+--------------+
| cust_name      | cust_contact |
+----------------+--------------+
| Coyote Inc.    | Y Lee        |
| Yosemite Place | Y Sam        |
+----------------+--------------+
2 rows in set (0.00 sec)
```
> 使用联结查询，完成上面的例子
>
> > 其中含有三个where子句条件，前两个关联联结中的表，最后一个过滤产品TNT2的数据
```sql
mysql> select cust_name,cust_contact
    -> from customers,orders,orderitems
    -> where customers.cust_id = orders.cust_id
    ->   and orders.order_num  = orderitems.order_num
    ->   and prod_id = 'TNT2';
+----------------+--------------+
| cust_name      | cust_contact |
+----------------+--------------+
| Coyote Inc.    | Y Lee        |
| Yosemite Place | Y Sam        |
+----------------+--------------+
2 rows in set (0.05 sec)
```




> 多做实验
> >为执行一给定的SQL操作， 一般存在不止一种方法，很少有绝对正确或绝对错误的方法
> >性能可能受操作类型、表汇总数据量、是否存在索引或键以及其他一些条件的影响
> >因此，有必要对不同的选择机制进行实验，以找出最合适具体情况的方法

## 15.3 小结

> 联结
> 等值联结（内部联结），最经常使用的联结形式



# 第16章 创建高级联结(联结中使用表别名、和 聚集函数；自联结、外部联结)

## 简介

> 一些联结类型
> 对被联结的表使用表别名和聚集函数
## 16.1 使用表别名

>别名
>>前面学过：别名可以用于列名和计算字段
>
>还可以给表起别名
>> 缩短SQL语句
>> 允许在单条select语句中多次使用相同的表
>
>注意：别名只在查询执行中使用，表别名不返回到客户机（列别名会返回到客户机）

```sql
mysql> select c.cust_name,c.cust_contact
    -> from customers as c , orders as o , orderitems as oi
    -> where c.cust_id = o.cust_id
    ->   and o.order_num = oi.order_num
    ->   and prod_id = 'TNT2';
+----------------+--------------+
| cust_name      | cust_contact |
+----------------+--------------+
| Coyote Inc.    | Y Lee        |
| Yosemite Place | Y Sam        |
+----------------+--------------+
2 rows in set (0.00 sec)
```
## 16.2 使用不同类型的联结

> 前面学习了：内部联结（等值联结）
> 下面学
> >自联结
> >自然联结
> >外部联结
### 16.2.1 自联结

>例子
>> 根据产品id  DTNTR 找到供应商id
>> 根据供应商id ，找到此供应商生产的所有产品

>法一：子查询（可以看出两次均是对同一张表进行操作）
```sql
mysql> select prod_id,prod_name
    -> from products
    -> where vend_id = ( select vend_id
    ->                   from products
    ->                   where prod_id = 'DTNTR' ) ;
+---------+----------------+
| prod_id | prod_name      |
+---------+----------------+
| DTNTR   | Detonator      |
| FB      | Bird seed      |
| FC      | Carrots        |
| SAFE    | Safe           |
| SLING   | Sling          |
| TNT1    | TNT (1 stick)  |
| TNT2    | TNT (5 sticks) |
+---------+----------------+
7 rows in set (0.00 sec)
```
>法二：自联结（可以看出：需要的两个表，其实是同一张表）
>>where首先联结两个表
>>然后，按照第二个表中的prod_id过滤数据，返回所需的数据

```sql
mysql> select p1.prod_id,p1.prod_name
    -> from products as p1 , products as p2
    -> where p1.vend_id = p2.vend_id -- where首先联结两个表
    ->   and p2.prod_id = 'DTNTR';   -- 然后，按照第二个表中的prod_id过滤数据，返回所需的数据
+---------+----------------+
| prod_id | prod_name      |
+---------+----------------+
| DTNTR   | Detonator      |
| FB      | Bird seed      |
| FC      | Carrots        |
| SAFE    | Safe           |
| SLING   | Sling          |
| TNT1    | TNT (1 stick)  |
| TNT2    | TNT (5 sticks) |
+---------+----------------+
7 rows in set (0.00 sec)
```
>用自联结而不用子查询
>>1. 自联结通常作为外部语句用来替代从相同表中检索数据时使用的子查询语句。
>>2. 虽然最终的结果是相同的，但有时候处理联结远比处理子查询快得多。
>
>应该试一下两种方法，以确定哪一种的性能更好。

### 16.2.2 自然联结

> 使用联结的前提：
> > 至少有一个列出现在不止一个表中（被联结的列）
>
> 标准的联结（比如内部联结）： 
> >返回所有数据，甚至相同的列多次出现
>
> 自然联结
> >排除多次出现，使每个列只返回一次
> >只能选择那些唯一的列
> >通过对表使用通配符（select *），对所有其他表的列使用明确的子集

```sql
mysql> select c.* , o.order_num,o.order_date,oi.prod_id,oi.quantity,oi.item_price
    -> from customers c,orders o,orderitems oi
    -> where c.cust_id = o.cust_id
    ->   and o.order_num = oi.order_num
    ->   and prod_id = 'FB';
+---------+-------------+----------------+-----------+------------+----------+--------------+--------------+-----------------+-----------+---------------------+---------+----------+------------+
| cust_id | cust_name   | cust_address   | cust_city | cust_state | cust_zip | cust_country | cust_contact | cust_email      | order_num | order_date          | prod_id | quantity | item_price |
+---------+-------------+----------------+-----------+------------+----------+--------------+--------------+-----------------+-----------+---------------------+---------+----------+------------+
|   10001 | Coyote Inc. | 200 Maple Lane | Detroit   | MI         | 44444    | USA          | Y Lee        | ylee@coyote.com |     20005 | 2005-09-01 00:00:00 | FB      |        1 |      10.00 |
|   10001 | Coyote Inc. | 200 Maple Lane | Detroit   | MI         | 44444    | USA          | Y Lee        | ylee@coyote.com |     20009 | 2005-10-08 00:00:00 | FB      |        1 |      10.00 |
+---------+-------------+----------------+-----------+------------+----------+--------------+--------------+-----------------+-----------+---------------------+---------+----------+------------+
2 rows in set (0.04 sec)
```
> 这个例子中，通配符只对第一个表使用
> 所有其他列明确列出，所以没有重复的列被检索出来 

>迄今为止，我们建立的每个内部联结都是自然联结，
>很可能我们永远都不会用到不是自然联结的内部联结。
### 16.2.3 外部联结 

>>许多联结将一个表中的行与另一个表中的行相关联。（联结产生笛卡尔积，然后过滤笛卡尔积得出我们需要的结果）
>>但有时候会需要包含没有关联行的那些行。（一个表中有这条数据，另一个表中没有这条数据，此时过滤笛卡尔积，这条数据会被过滤掉）
>
>例如，可能需要使用联结来完成以下工作：
>>对每个客户下了多少订单进行计数，包括那些至今尚未下订单的客户；
>>列出所有产品以及订购数量，包括没有人订购的产品；
>>计算平均销售规模，包括那些至今尚未下订单的客户。
>
>在上述例子中，联结包含了那些在相关表中没有关联行的行。这种类型的联结称为外部联结。

> 例子：内部联结，检索所有客户及其订单
> > select ...
> > from .. inner join ..
> > on ...
```sql
mysql> select c.cust_id,o.order_num
    -> from customers c inner join orders o
    -> on c.cust_id = o.cust_id;
+---------+-----------+
| cust_id | order_num |
+---------+-----------+
|   10001 |     20005 |
|   10001 |     20009 |
|   10003 |     20006 |
|   10004 |     20007 |
|   10005 |     20008 |
+---------+-----------+
5 rows in set (0.00 sec)
```
>例子：外部联结，检索所有的客户，包括那些没有订单的客户
>> select ...
>> from ... left / right outer join
>> on ...
```sql
mysql> select c.cust_id,o.order_num
    -> from customers c left outer join orders o
    -> on c.cust_id = o.cust_id;
+---------+-----------+
| cust_id | order_num |
+---------+-----------+
|   10001 |     20005 |
|   10001 |     20009 |
|   10002 |      NULL |
|   10003 |     20006 |
|   10004 |     20007 |
|   10005 |     20008 |
+---------+-----------+
6 rows in set (0.01 sec)
```

```sql
mysql> select c.cust_id as c_cust_id , o.cust_id as o_cust_id,o.order_num
    -> from customers c left outer join orders o
    -> on c.cust_id = o.cust_id;
+-----------+-----------+-----------+
| c_cust_id | o_cust_id | order_num |
+-----------+-----------+-----------+
|     10001 |     10001 |     20005 |
|     10001 |     10001 |     20009 |
|     10002 |      NULL |      NULL |
|     10003 |     10003 |     20006 |
|     10004 |     10004 |     20007 |
|     10005 |     10005 |     20008 |
+-----------+-----------+-----------+
6 rows in set (0.00 sec)
```
>关键字OUTER JOIN来指定联结的类型（而不是在WHERE子句中指定）。
>但是，与内部联结关联两个表中的行不同的是，外部联结还包括没有关联行的行。
>在使用OUTER JOIN语法时，必须使用RIGHT或LEFT关键字指定包括其所有行的表
>> RIGHT指出的是OUTER JOIN右边的表，
>> LEFT指出的是OUTER JOIN左边的表。
>
>上面的例子使用LEFT OUTER JOIN从FROM子句的左边表（customers表）中选择所有行。
>为了从右边的表中选择所有行，应该使用RIGHT OUTER JOIN，如下所示：

```sql
mysql> select c.cust_id,o.order_num 
	-> from customers c right outer join orders o 
	-> on c.cust_id = o.cust_id;
+---------+-----------+
| cust_id | order_num |
+---------+-----------+
|   10001 |     20005 |
|   10001 |     20009 |
|   10003 |     20006 |
|   10004 |     20007 |
|   10005 |     20008 |
+---------+-----------+
5 rows in set (0.00 sec)

mysql> select c.cust_id as c_cust_id , o.cust_id as o_cust_id,o.order_num 
	-> from customers c right outer join orders o 
	-> on c.cust_id = o.cust_id;
+-----------+-----------+-----------+
| c_cust_id | o_cust_id | order_num |
+-----------+-----------+-----------+
|     10001 |     10001 |     20005 |
|     10001 |     10001 |     20009 |
|     10003 |     10003 |     20006 |
|     10004 |     10004 |     20007 |
|     10005 |     10005 |     20008 |
+-----------+-----------+-----------+
5 rows in set (0.00 sec)
```

>注意： MySQL不支持简化字符，如 *= 、=*

> 外部联结的类型
> > 存在两种基本的外部联结形式：左外部联结和右外部联结。
> > 它们之间的唯一差别是所关联的表的顺序不同。
> > 换句话说，左外部联结可通过颠倒FROM或WHERE子句中表的顺序转换为右外部联结。
> > 因此，两种类型的外部联结可互换使用，而究竟使用哪一种纯粹是根据方便而定。

## 16.3 使用带聚集函数的联结

```sql
mysql> select * 
    -> from customers c inner join orders o
    -> on c.cust_id = o.cust_id;
+---------+----------------+---------------------+-----------+------------+----------+--------------+--------------+---------------------+-----------+---------------------+---------+
| cust_id | cust_name      | cust_address        | cust_city | cust_state | cust_zip | cust_country | cust_contact | cust_email          | order_num | order_date          | cust_id |
+---------+----------------+---------------------+-----------+------------+----------+--------------+--------------+---------------------+-----------+---------------------+---------+
|   10001 | Coyote Inc.    | 200 Maple Lane      | Detroit   | MI         | 44444    | USA          | Y Lee        | ylee@coyote.com     |     20005 | 2005-09-01 00:00:00 |   10001 |
|   10003 | Wascals        | 1 Sunny Place       | Muncie    | IN         | 42222    | USA          | Jim Jones    | rabbit@wascally.com |     20006 | 2005-09-12 00:00:00 |   10003 |
|   10004 | Yosemite Place | 829 Riverside Drive | Phoenix   | AZ         | 88888    | USA          | Y Sam        | sam@yosemite.com    |     20007 | 2005-09-30 00:00:00 |   10004 |
|   10005 | E Fudd         | 4545 53rd Street    | Chicago   | IL         | 54545    | USA          | E Fudd       | NULL                |     20008 | 2005-10-03 00:00:00 |   10005 |
|   10001 | Coyote Inc.    | 200 Maple Lane      | Detroit   | MI         | 44444    | USA          | Y Lee        | ylee@coyote.com     |     20009 | 2005-10-08 00:00:00 |   10001 |
+---------+----------------+---------------------+-----------+------------+----------+--------------+--------------+---------------------+-----------+---------------------+---------+
5 rows in set (0.00 sec)
```
> 如下例子，使用内部联结，搭配使用了聚合函数
> 检索所有客户及每个客户所下的订单数
```sql
mysql> select c.cust_name , c.cust_id , count(o.order_num) as num_order
    -> from customers c inner join orders o
    -> on c.cust_id = o.cust_id
    -> group by cust_id;
+----------------+---------+-----------+
| cust_name      | cust_id | num_order |
+----------------+---------+-----------+
| Coyote Inc.    |   10001 |         2 |
| Wascals        |   10003 |         1 |
| Yosemite Place |   10004 |         1 |
| E Fudd         |   10005 |         1 |
+----------------+---------+-----------+
4 rows in set (0.06 sec)
```
>分析
>此SELECT语句使用INNER JOIN将customers和orders表互相关联。
>GROUPBY子句按客户分组数据，因此，函数调用COUNT（orders.order_num）对分组后的每个客户的订单计数，将它作为num_ord返回。

> 如下例子，使用左外部联结，搭配使用了聚合函数
> 检索所有客户及每个客户所下的订单数（甚至包含那些没有下任何订单的客户）

```sql
mysql> select c.cust_name , c.cust_id , count(o.order_num) as num_order
    -> from customers c left outer join orders o
    -> on c.cust_id = o.cust_id
    -> group by cust_id;
+----------------+---------+-----------+
| cust_name      | cust_id | num_order |
+----------------+---------+-----------+
| Coyote Inc.    |   10001 |         2 |
| Mouse House    |   10002 |         0 |
| Wascals        |   10003 |         1 |
| Yosemite Place |   10004 |         1 |
| E Fudd         |   10005 |         1 |
+----------------+---------+-----------+
5 rows in set (0.00 sec)
```

```sql
mysql> select c.cust_name , c.cust_id , count(o.order_num) as num_order
    -> from customers c left outer join orders o
    -> on c.cust_id = o.cust_id
    -> group by cust_id
	-> order by cust_id desc;
+----------------+---------+-----------+
| cust_name      | cust_id | num_order |
+----------------+---------+-----------+
| E Fudd         |   10005 |         1 |
| Yosemite Place |   10004 |         1 |
| Wascals        |   10003 |         1 |
| Mouse House    |   10002 |         0 |
| Coyote Inc.    |   10001 |         2 |
+----------------+---------+-----------+
5 rows in set (0.00 sec)
```
## 16.4 使用联结和联结条件

> 关于联结及其使用的某些要点
> >1. 联结类型：一般使用内部联结，但外部联结也是有效的。
> >2. 正确的联结条件，否则将返回不正确的数据。
> >3. 必须提供联结条件，否则会得出笛卡儿积。
> >4. 在一个联结中可以包含多个表，甚至对于每个联结可以采用不同的联结类型。应该在一起测试它们前，分别测试每个/种联结。这将使故障排除更为简单。
## 16.5 小结

> 1. 表的别名
> 2. 自联结、自然联结
> 3. 外部联结
> 4. 带聚集函数的联结
> 5. 联结条件



# 第17章 组合查询（union操作符）

## 简介

>用UNION操作符将多条SELECT语句组合成一个结果集
## 17.1 组合查询

>组合查询：通常称为并（union）或复合查询（compound query）
>>执行多个查询（多条SELECT语句），并将结果作为单个查询结果集返回。
>
>有两种基本情况，其中需要使用组合查询：
>>在单个查询中从不同的表返回类似结构的数据；
>>对单个表执行多个查询，按单个查询返回数据。
>
>组合查询和多个WHERE条件
>
>>具有多个WHERE子句的SELECT语句都可以作为一个组合查询给出
## 17.2 创建组合查询

>用UNION操作符来组合数条SQL查询
>
>>利用UNION，可给出多条SELECT语句，将它们的结果组合成单个结果集。
### 17.2.1 使用union

>UNION的使用很简单。
>
>>所需做的只是给出每条SELECT语句，在各条语句之间放上关键字UNION。

> 例子：价格小于等于5的所有物品的一个列表
```sql
select  vend_id,prod_id,prod_price
from products
where prod_price <= 5;

mysql> source /home/lwh/Desktop/study/db_MySQL/db_MSQLCrashCourse/execute.sql
+---------+---------+------------+
| vend_id | prod_id | prod_price |
+---------+---------+------------+
|    1003 | FC      |       2.50 |
|    1002 | FU1     |       3.42 |
|    1003 | SLING   |       4.49 |
|    1003 | TNT1    |       2.50 |
+---------+---------+------------+
4 rows in set (0.00 sec)

Query OK, 0 rows affected (0.00 sec)
```
> 例子：供应商1001 1002生产的所有物品的一个列表
```sql
select  vend_id,prod_id,prod_price
from products
where vend_id in (1001,1002);

mysql> source /home/lwh/Desktop/study/db_MySQL/db_MSQLCrashCourse/execute.sql
+---------+---------+------------+
| vend_id | prod_id | prod_price |
+---------+---------+------------+
|    1001 | ANV01   |       5.99 |
|    1001 | ANV02   |       9.99 |
|    1001 | ANV03   |      14.99 |
|    1002 | FU1     |       3.42 |
|    1002 | OL1     |       8.99 |
+---------+---------+------------+
5 rows in set (0.00 sec)

Query OK, 0 rows affected (0.00 sec)
```
> 例子：求上面两个例子的并集
> >union关键字
> >指示MySQL执行两条SELECT语句，并把输出组合成单个查询结果集。
```sql
select  vend_id,prod_id,prod_price
from products
where prod_price <= 5

union

select  vend_id,prod_id,prod_price
from products
where vend_id in (1001,1002);


mysql> source /home/lwh/Desktop/study/db_MySQL/db_MSQLCrashCourse/execute.sql
+---------+---------+------------+
| vend_id | prod_id | prod_price |
+---------+---------+------------+
|    1003 | FC      |       2.50 |
|    1002 | FU1     |       3.42 |
|    1003 | SLING   |       4.49 |
|    1003 | TNT1    |       2.50 |
|    1001 | ANV01   |       5.99 |
|    1001 | ANV02   |       9.99 |
|    1001 | ANV03   |      14.99 |
|    1002 | OL1     |       8.99 |
+---------+---------+------------+
8 rows in set (0.02 sec)

Query OK, 0 rows affected (0.00 sec)
```
> 使用多条where子句完成上述例子
```sql
select  vend_id,prod_id,prod_price
from products
where prod_price <= 5
or vend_id in (1001,1002);

mysql> mysql> source /home/lwh/Desktop/study/db_MySQL/db_MSQLCrashCourse/execute.sql
+---------+---------+------------+
| vend_id | prod_id | prod_price |
+---------+---------+------------+
|    1001 | ANV01   |       5.99 |
|    1001 | ANV02   |       9.99 |
|    1001 | ANV03   |      14.99 |
|    1003 | FC      |       2.50 |
|    1002 | FU1     |       3.42 |
|    1002 | OL1     |       8.99 |
|    1003 | SLING   |       4.49 |
|    1003 | TNT1    |       2.50 |
+---------+---------+------------+
8 rows in set (0.00 sec)

Query OK, 0 rows affected (0.00 sec)
```
>在这个简单的例子中，使用UNION可能比使用WHERE子句更为复杂。
>
>>但对于更复杂的过滤条件，或者从多个表（而不是单个表）中检索数据的情形，使用UNION可能会使处理更简单。

### 17.2.2 union规则

> union求并时的几条规则
> >1. UNION必须由两条或两条以上的SELECT语句组成，语句之间用关键字UNION分隔
> >2. UNION中的每个查询必须包含相同的列、表达式或聚集函数
> >3. 列数据类型必须兼容：类型不必完全相同，但必须是DBMS可以隐含地转换的类型

### 17.2.3 包含或取消重的行

> UNION从查询结果集中自动去除了重复的行
> （换句话说，它的行为与单条SELECT语句中使用多个WHERE子句条件一样）

>使用UNIONALL，MySQL不取消重复的行。

>UNION与WHERE
>>1. UNION几乎总是完成与多个WHERE条件相同的工作。
>>2. UNION ALL为UNION的一种形式，它完成WHERE子句完成不了的工作。如果确实需要每个条件的匹配行全部出现（包括重复行），则必须使用UNIONALL而不是WHERE。
```sql
select  vend_id,prod_id,prod_price
from products
where prod_price <= 5

union all

select  vend_id,prod_id,prod_price
from products
where vend_id in (1001,1002);

mysql> source /home/lwh/Desktop/study/db_MySQL/db_MSQLCrashCourse/execute.sql
+---------+---------+------------+
| vend_id | prod_id | prod_price |
+---------+---------+------------+
|    1003 | FC      |       2.50 |
|    1002 | FU1     |       3.42 |
|    1003 | SLING   |       4.49 |
|    1003 | TNT1    |       2.50 |
|    1001 | ANV01   |       5.99 |
|    1001 | ANV02   |       9.99 |
|    1001 | ANV03   |      14.99 |
|    1002 | FU1     |       3.42 |
|    1002 | OL1     |       8.99 |
+---------+---------+------------+
9 rows in set (0.01 sec)

Query OK, 0 rows affected (0.00 sec)
```

### 17.2.4 对组合查询结果排序

> SELECT语句的输出用ORDER BY子句排序。
>
> > 在用UNION组合查询时，只能使用一条ORDER BY子句，
> > 它必须出现在最后一条SELECT语句之后。 
>
> >虽然ORDER BY子句似子只是最后一条SELEC语句的组成部分，
> >但实际上MySQL将用它来排序所有SELECT语句返回的所有结果。
```sql
select  vend_id,prod_id,prod_price
from products
where prod_price <= 5

union

select  vend_id,prod_id,prod_price
from products
where vend_id in (1001,1002)

order by vend_id,prod_price;

mysql> source /home/lwh/Desktop/study/db_MySQL/db_MSQLCrashCourse/execute.sql
+---------+---------+------------+
| vend_id | prod_id | prod_price |
+---------+---------+------------+
|    1001 | ANV01   |       5.99 |
|    1001 | ANV02   |       9.99 |
|    1001 | ANV03   |      14.99 |
|    1002 | FU1     |       3.42 |
|    1002 | OL1     |       8.99 |
|    1003 | FC      |       2.50 |
|    1003 | TNT1    |       2.50 |
|    1003 | SLING   |       4.49 |
+---------+---------+------------+
8 rows in set (0.00 sec)

Query OK, 0 rows affected (0.00 sec)
```
>组合不同的表
>>为使表述比较简单，本章例子中的组合查询使用的均是相同的表。
>>但是其中使用UNION的组合查询可以应用不同的表。
## 17.3 小结

> 1.用UNION操作符来组合SELECT语句。
> 利用UNION，可把多条查询的结果作为一条组合查询返回，不管它们的结果中包含还是不包含重复。
> 使用UNION可极大地简化复杂的WHERE子句，简化从多个表中检索数据的工作。



# 第18章 全文本搜索（match()、against()、查询扩展、布尔方式）

## 简介

>使用MySQL的全文本搜索功能进行高级的数据查询和选择

## 18.1 理解全文本搜索

>> MySQL两个最常使用的引擎为MyISAM和InnoDB，前者支持全文本搜索，而后者不支持。
>
>> 第8章：LIKE关键字，它利用通配操作符匹配文本（和部分文本）。
>> 使用LIKE，能够查找包含特殊值或部分值的行（不管这些值位于列内什么位置）。
>
>> 在第9章：正则表达式，用基于文本的搜索作为正则表达式匹配列值的更进一步的介绍。
>> 使用正则表达式，可以编写查找所需行的非常复杂的匹配模式。
>
>虽然这些搜索机制非常有用，但存在几个重要的限制。
>> 性能：通配符和正则表达式（匹配表中所有的行）随着搜索行数不断增加，会非常耗时
>> 明确控制：很难明确控制匹配什么和不匹配什么
>> 智能化选择结果：不能提供一种智能化的选择结果的方法
>
>所有这些限制以及更多的限制都可以用全文本搜索来解决。
>>在使用全文本搜索时，MySQL不需要分别查看每个行，不需要分别分析和处理每个词。
>>MySQL创建指定列中各词的一个索引，搜索可以针对这些词进行。
>>这样，MySQL可以快速有效地决定哪些词匹配（哪些行包含它们），哪些词不匹配，它们匹配的频率，等等。

## 18.2 使用全文本搜索

> 必须索引被搜索的列
>
> > match()、against()一起使用以实现全文本搜索
### 18.2.1 启用全文本搜索支持

>一般在创建表时启用全文本搜索。
>>CREATE TABLE语句 接受FULLTEXT子句，
>>它给出被索引列的一个逗号分隔的列表。
>>如下：
```sql
------------------------------------------------------
-- Create productnotes table
------------------------------------------------------
CREATE TABLE productnotes
(
  note_id    int           NOT NULL AUTO_INCREMENT,
  prod_id    char(10)      NOT NULL,
  note_date datetime       NOT NULL,
  note_text  text          NULL ,
  PRIMARY KEY(note_id),
  FULLTEXT(note_text)  -- FULLTEXT子句
) ENGINE=MyISAM DEFAULT CHARSET=UTF8;
```
>MySQL根据子句FULLTEXT（note_text）的指示对  列 note_text  进行索引。
>这里的FULLTEXT索引单个列，如果需要也可以指定多个列。

>在定义之后，MySQL自动维护该索引。在增加、更新或删除行时，索引随之自动更新。

>可以在创建表时指定FULLTEXT，或者在稍后指定（在这种情况下所有已有数据必须立即索引）

>不要在导入数据时使用FULLTEXT 
>>应该首先导入所有数据，然后再修改表，定义FULLTEXT。
>>这样有助于更快地导入数据

### 18.2.2 进行全文本搜索

>在索引之后，使用两个函数Match（）和 Against（）执行全文本搜索，
>>Match（）指定被搜索的列，
>>Against（）指定要使用的搜索表达式。
```sql
select note_text
from productnotes
where match(note_text)  against('rabbit');


mysql> source /home/lwh/Desktop/study/db_MySQL/db_MSQLCrashCourse/execute.sql
+----------------------------------------------------------------------------------------------------------------------+
| note_text                                                                                                            |
+----------------------------------------------------------------------------------------------------------------------+
| Customer complaint: rabbit has been able to detect trap, food apparently less effective now.                         |
| Quantity varies, sold by the sack load.
All guaranteed to be bright and orange, and suitable for use as rabbit bait. |
+----------------------------------------------------------------------------------------------------------------------+
2 rows in set (0.00 sec)

Query OK, 0 rows affected (0.01 sec)
```
>分析
>此SELECT语句检索单个列note_text。
>由于WHERE子句，一个全文本搜索被执行。
>>Match（notetext）指示MySQL针对指定的列进行搜索，
>>Against（'rabbit）指定词rabbit作为搜索文本。
>
>由于有两行包含词rabbit，这两个行被返回。

>使用完整的Match（）说明
>>传递给Match（）的值必须与FULLTEXT（）定义中的相同。
>>如果指定多个列，则必须列出它们（而且次序正确）。
>
>搜索不区分大小写
>
>>除非使用BINARY方式（本章中没有介绍），否则全文本搜索不区分大小写。

>事实是刚才的搜索可以简单地用LIKE子句完成，如下所示：
```sql
select note_text
from productnotes
where note_text like '%rabbit%';


mysql> mysql> source /home/lwh/Desktop/study/db_MySQL/db_MSQLCrashCourse/execute.sql
+----------------------------------------------------------------------------------------------------------------------+
| note_text                                                                                                            |
+----------------------------------------------------------------------------------------------------------------------+
| Quantity varies, sold by the sack load.
All guaranteed to be bright and orange, and suitable for use as rabbit bait. |
| Customer complaint: rabbit has been able to detect trap, food apparently less effective now.                         |
+----------------------------------------------------------------------------------------------------------------------+
2 rows in set (0.01 sec)

Query OK, 0 rows affected (0.00 sec)
```
> like
> > 返回的数据的顺序没有经过排序
>
> 全文本搜索
> >会对结果进行排序
> >具有较高等级的行先返回
>
> 演示排序工作如下
```sql
select
    note_text,
    match(note_text) against('rabbit') as rankrank
from
    productnotes;



mysql> mysql> source /home/lwh/Desktop/study/db_MySQL/db_MSQLCrashCourse/execute.sql
+-----------------------------------------------------------------------------------------------------------------------------------------------------------+--------------------+
| note_text                                                                                                                                                 | rankrank           |
+-----------------------------------------------------------------------------------------------------------------------------------------------------------+--------------------+
| Customer complaint:
Sticks not individually wrapped, too easy to mistakenly detonate all at once.
Recommend individual wrapping.                          |                  0 |
| Can shipped full, refills not available.
Need to order new can if refill needed.                                                                          |                  0 |
| Safe is combination locked, combination not provided with safe.
This is rarely a problem as safes are typically blown up or dropped by customers.         |                  0 |
| Quantity varies, sold by the sack load.
All guaranteed to be bright and orange, and suitable for use as rabbit bait.                                      | 1.5905543565750122 |
| Included fuses are short and have been known to detonate too quickly for some customers.
Longer fuses are available (item FU1) and should be recommended. |                  0 |
| Matches not included, recommend purchase of matches or detonator (item DTNTR).                                                                            |                  0 |
| Please note that no returns will be accepted if safe opened using explosives.                                                                             |                  0 |
| Multiple customer returns, anvils failing to drop fast enough or falling backwards on purchaser. Recommend that customer considers using heavier anvils.  |                  0 |
| Item is extremely heavy. Designed for dropping, not recommended for use with slings, ropes, pulleys, or tightropes.                                       |                  0 |
| Customer complaint: rabbit has been able to detect trap, food apparently less effective now.                                                              | 1.6408053636550903 |
| Shipped unassembled, requires common tools (including oversized hammer).                                                                                  |                  0 |
| Customer complaint:
Circular hole in safe floor can apparently be easily cut with handsaw.                                                                |                  0 |
| Customer complaint:
Not heavy enough to generate flying stars around head of victim. If being purchased for dropping, recommend ANV02 or ANV03 instead.   |                  0 |
| Call from individual trapped in safe plummeting to the ground, suggests an escape hatch be added.
Comment forwarded to vendor.                            |                  0 |
+-----------------------------------------------------------------------------------------------------------------------------------------------------------+--------------------+
14 rows in set (0.00 sec)

Query OK, 0 rows affected (0.00 sec)
```
>分析：
>>在SELECT而不是WHERE子句中使用Match（）和Against（）。
>>这使所有行都被返回（因为没有WHERE子句）。
>
>>Match（）和Against（）用来建立一个计算列（别名为rank），此列包含全文本搜索计算出的等级值。
>>等级由MySQL根据行中词的数目、唯一词的数目、整个索引中词的总数以及包含该词的行的数目计算出来。
>>正如所见，不包含词rabbit的行等级为0（因此不被前一例子中的WHERE子句选择）。
>>确实包含词rabbit的两个行每行都有一个等级值，文本中词靠前的行的等级值比词靠后的行的等级值高。
>
>>这个例子有助于说明全文本搜索如何排除行（排除那些等级为0的行），如何排序结果（按等级以降序排序）。
>
>排序多个搜索项
>>如果指定多个搜索项，则包含多数匹配词的那些行将具有比包含较少词（或仅有一个匹配）的那些行高的等级值。
>
>>正如所见，全文本搜索提供了简单LIKE搜索不能提供的功能。
>>而且，由于数据是索引的，全文本搜索还相当快。

### 18.2.3 使用查询扩展

>查询扩展
>>用来设法放宽所返回的全文本搜索结果的范围
>>简言之：找出可能与你的搜索有关的所有其他行
>>
>>>使用关键字：with query expansion

>扩展查询的搜索步骤：对数据和索引进行两遍扫描完成搜索
>>首先，进行一个基本的全文本搜索，找出与搜索条件匹配的所有行；
>>其次，MySQL检查这些匹配行并选择所有有用的词（MySQL将断定什么有用，什么无用）。
>>再其次，MySQL再次进行全文本搜索，这次不仅使用原来的条件，而且还使用所有有用的词。
>
>利用查询扩展，能找出可能相关的结果，即使它们并不精确包含所查找的词。


>首先进行一个简单的全文本搜索

```sql
select
    note_text
from
    productnotes
where
    match(note_text) against('rabbit');


mysql> source /home/lwh/Desktop/study/db_MySQL/db_MSQLCrashCourse/execute.sql
+----------------------------------------------------------------------------------------------------------------------+
| note_text                                                                                                            |
+----------------------------------------------------------------------------------------------------------------------+
| Customer complaint: rabbit has been able to detect trap, food apparently less effective now.                         |
| Quantity varies, sold by the sack load.
All guaranteed to be bright and orange, and suitable for use as rabbit bait. |
+----------------------------------------------------------------------------------------------------------------------+
2 rows in set (0.01 sec)

Query OK, 0 rows affected (0.00 sec)
```


>这次试用扩展查询 进行全文本搜索

```sql
select
    note_text
from
    productnotes
where
    match(note_text) against('anvils' with query expansion);


mysql> source /home/lwh/Desktop/study/db_MySQL/db_MSQLCrashCourse/execute.sql
+----------------------------------------------------------------------------------------------------------------------------------
------------------------+
| note_text                                                                                                                        
                        |
+----------------------------------------------------------------------------------------------------------------------------------
------------------------+
| Multiple customer returns, anvils failing to drop fast enough or falling backwards on purchaser. Recommend that customer consider
s using heavier anvils. |
| Customer complaint:
Sticks not individually wrapped, too easy to mistakenly detonate all at once.
Recommend individual wrapping.                         |
| Customer complaint:
Not heavy enough to generate flying stars around head of victim. If being purchased for dropping, recommend ANV02 or ANV03 instead.
  |
| Please note that no returns will be accepted if safe opened using explosives.                                                    
                        |
| Customer complaint: rabbit has been able to detect trap, food apparently less effective now.                                     
                        |
| Customer complaint:
Circular hole in safe floor can apparently be easily cut with handsaw.                                                             
  |
| Matches not included, recommend purchase of matches or detonator (item DTNTR).                                                   
                        |
+----------------------------------------------------------------------------------------------------------------------------------
------------------------+
7 rows in set (0.00 sec)

Query OK, 0 rows affected (0.00 sec)
```
>查询扩展极大地增加了返回的行数，但这样做也增加了你实际上并不想要的行的数目。


>行越多越好
>>表中的行越多（这些行中的文本就越多），
>>使用查询扩展返回的结果越好。
### 18.2.4 布尔方式进行全文本搜索

> 全文本搜索的另外一种形式：称为布尔方式（boolean mode）。
>
> >使用关键字： in boolean mode

>布尔方式 的 全文本搜索，提供了更精确的搜索控制
>>1. 要匹配的词；
>>2. 要排斥的词（如果某行包含这个词，则不返回该行，即使它包含其他指定的词也是如此）；
>>3. 排列提示（指定某些词比其他词更重要，更重要的词等级更高）；
>>4. 表达式分组；
>>5. 另外一些内容。

>即使没有FULLTEXT索引也可以使用
>>即使没有定义FULLTEXT索引，也可以使用它。
>>但这是一种非常缓慢的操作（其性能将随着数据量的增加而降低）。

```sql
select
    note_text
from
    productnotes
where
    match(note_text) against('heavy' in boolean mode);


mysql> mysql> source /home/lwh/Desktop/study/db_MySQL/db_MSQLCrashCourse/execute.sql
+---------------------------------------------------------------------------------------------------------------------------------------------------------+
| note_text                                                                                                                                               |
+---------------------------------------------------------------------------------------------------------------------------------------------------------+
| Item is extremely heavy. Designed for dropping, not recommended for use with slings, ropes, pulleys, or tightropes.                                     |
| Customer complaint:
Not heavy enough to generate flying stars around head of victim. If being purchased for dropping, recommend ANV02 or ANV03 instead. |
+---------------------------------------------------------------------------------------------------------------------------------------------------------+
2 rows in set (0.00 sec)

Query OK, 0 rows affected (0.00 sec)
```
>因为没有指定布尔操作符
>其结果与没有指定布尔方式的结果相同


>例子：使用带布尔操作符的 布尔 全文本搜索
>>其中用到了两个全文本搜索布尔操作符
>>“-” 排除一个词
>>“*” 截断操作符（可想象为，用于词尾的一个通配符）
```sql
select
    note_text
from
    productnotes
where
    match(note_text) against('heavy -rope*' in boolean mode);
-- 仍然匹配词 heavy
-- -rope*  ： 排除包含rope*的行（任何rope开始的词，也包括rope本身）



mysql> source /home/lwh/Desktop/study/db_MySQL/db_MSQLCrashCourse/execute.sql
+---------------------------------------------------------------------------------------------------------------------------------------------------------+
| note_text                                                                                                                                               |
+---------------------------------------------------------------------------------------------------------------------------------------------------------+
| Customer complaint:
Not heavy enough to generate flying stars around head of victim. If being purchased for dropping, recommend ANV02 or ANV03 instead. |
+---------------------------------------------------------------------------------------------------------------------------------------------------------+
1 row in set (0.00 sec)

Query OK, 0 rows affected (0.00 sec)
```
- 全文本布尔操作符 如下：

```sql
布尔操作符    		说明
  +				包含，词必须存在
  -				排除，词必须不出现
  >				包含，而且增加等级值
  <				包含，且减少等级值
  ()			把词组成子表达式（允许这些子表达式作为一个组被包含、排除、排列等）
  ~				取消一个词的排序值
  *				词尾的通配符
  ""			定义一个短语（与单个词的列表不一样，它匹配整个短语以便包含或排除这个短语）
```
>举几个例子

```sql
-------------------- 搜索匹配：包含词 rabbit和bait的行
select
    note_text
from
    productnotes
where
    match(note_text) against('+rabbit +bait' in boolean mode);

mysql> source /home/lwh/Desktop/study/db_MySQL/db_MSQLCrashCourse/execute.sql
+----------------------------------------------------------------------------------------------------------------------+
| note_text                                                                                                            |
+----------------------------------------------------------------------------------------------------------------------+
| Quantity varies, sold by the sack load.
All guaranteed to be bright and orange, and suitable for use as rabbit bait. |
+----------------------------------------------------------------------------------------------------------------------+
1 row in set (0.00 sec)

Query OK, 0 rows affected (0.00 sec)
```

```sql
-------------------- 搜索匹配：包含 词rabbit和词bait 中的，至少一个的行
select
    note_text
from
    productnotes
where
    match(note_text) against('rabbit bait' in boolean mode);

mysql> source /home/lwh/Desktop/study/db_MySQL/db_MSQLCrashCourse/execute.sql
+----------------------------------------------------------------------------------------------------------------------+
| note_text                                                                                                            |
+----------------------------------------------------------------------------------------------------------------------+
| Quantity varies, sold by the sack load.
All guaranteed to be bright and orange, and suitable for use as rabbit bait. |
| Customer complaint: rabbit has been able to detect trap, food apparently less effective now.                         |
+----------------------------------------------------------------------------------------------------------------------+
2 rows in set (0.00 sec)

Query OK, 0 rows affected (0.00 sec)
```

```sql
-------------------- 搜索匹配：包含短语 rabbit bait，而不是匹配两个词rabbit和bait 
select
    note_text
from
    productnotes
where
    match(note_text) against('"rabbit bait"' in boolean mode);

mysql> source /home/lwh/Desktop/study/db_MySQL/db_MSQLCrashCourse/execute.sql
+----------------------------------------------------------------------------------------------------------------------+
| note_text                                                                                                            |
+----------------------------------------------------------------------------------------------------------------------+
| Quantity varies, sold by the sack load.
All guaranteed to be bright and orange, and suitable for use as rabbit bait. |
+----------------------------------------------------------------------------------------------------------------------+
1 row in set (0.00 sec)

Query OK, 0 rows affected (0.00 sec)
```

```sql
-------------------- 搜索匹配：包含 词rabbit和词carrot 中的，至少一个的行，并增加前者的等级，降低后者的等级
select
    note_text
from
    productnotes
where
    match(note_text) against('>rabbit <carrot' in boolean mode);


mysql> source /home/lwh/Desktop/study/db_MySQL/db_MSQLCrashCourse/execute.sql
+----------------------------------------------------------------------------------------------------------------------+
| note_text                                                                                                            |
+----------------------------------------------------------------------------------------------------------------------+
| Quantity varies, sold by the sack load.
All guaranteed to be bright and orange, and suitable for use as rabbit bait. |
| Customer complaint: rabbit has been able to detect trap, food apparently less effective now.                         |
+----------------------------------------------------------------------------------------------------------------------+
2 rows in set (0.00 sec)

Query OK, 0 rows affected (0.00 sec)
```

```sql
-------------------- 搜索匹配：词safe和词combination中的，至少一个的行，并降低后者的等级
select
    note_text
from
    productnotes
where
    match(note_text) against('+safe +(<combination)' in boolean mode);

mysql> source /home/lwh/Desktop/study/db_MySQL/db_MSQLCrashCourse/execute.sql
+---------------------------------------------------------------------------------------------------------------------------------------------------+
| note_text                                                                                                                                         |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
| Safe is combination locked, combination not provided with safe.
This is rarely a problem as safes are typically blown up or dropped by customers. |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
1 row in set (0.00 sec)

Query OK, 0 rows affected (0.00 sec)
```
>排列而不排序
>
>>在布尔方式中，不按等级值降序排序返回的行
### 18.2.5 全文本搜索的使用说明

>关于全文本搜索的某些重要说明
>>1. 在索引全文本数据时，短词被忽略且从索引中排除。
>>短词定义为那些具有3个或3个以下字符的词（如果需要，这个数目可以更改）。
>
>>2. MySQL带有一个内建的非用词（stopword）列表，这些词在索引全文本数据时总是被忽略。
>>如果需要，可以覆盖这个列表（请参阅MySQL文档以了解如何完成此工作）。
>
>>3. 许多词出现的频率很高，搜索它们没有用处（返回太多的结果）。
>>因此，MySQL规定了一条50%规则，如果一个词出现在50%以上的行中，则将它作为一个非用词忽略。
>>50%规则不用于IN BOOLEAN MODE。
>
>>4. 如果表中的行数少于3行，则全文本搜索不返回结果（因为每个词或者不出现，或者至少出现在50%的行中）。
>
>>5. 忽略词中的单引号。例如，don't索引为dont。
>
>>6. 不具有词分隔符（包括日语和汉语）的语言不能恰当地返回全文本搜索结果。

> 如前所述，仅在MyISAM数据库引擎中支持全文本搜索。
## 18.3 小结

>1. 为什么使用全文本搜索
>2. 使用 Match() 和 Against() 函数进行全文本搜索
>3. 查询扩展：增加找到相关匹配的机会
>4. 布尔方式进行细致的查找控制



# 第19章 插入数据（insert、insert select ）

## 简介

>使用SQL的insert语句将数据插入表中
## 19.1 数据插入

>INSERT是用来插入（或添加）行到数据库表的。
>>插入完整的行；
>>插入行的一部分；
>>插入多行；
>>插入某些查询的结果。

>插入及系统安全
>
>>可针对每个表或每个用户，利用MySQL的安全机制禁止使用INSERT语句，这将在第28章介绍。
## 19.2 插入完整的行

>指定表名和被插入到新行中的值

```sql
INSERT INTO
    customers
VALUES
    (
        NULL,
        'Pep E.LaPew',
        '100 Main Street',s
        'Los Angeles',
        'CA',
        '90046',
        'USA',
        NULL,
        NULL
    );
```
>没有输出
>>INSERT语句一般不会产生输出
>
>> 这种方式，高度依赖于表中列的定义次序，插入时，值必须按照表中各列的次序一一对应上
>
>>对于自动增量，使用NULL值，MySQL会自动去补全


```sql
INSERT INTO
    customers (
        cust_name,
        cust_address,
        cust_city,
        cust_state,
        cust_zip,
        cust_country,
        cust_contact,
        cust_email
    )
VALUES
    (
        'Pep E.LaPew',
        '100 Main Street',
        'Los Angeles',
        'CA',
        '90046',
        'USA',
        NULL,
        NULL
    );
```
> 这种方式更安全
> > 明确的给出列名，然后，后面的value列表，一一对应上前面的列名即可
> > 这种方式时，可以只给某些列提供值（列名被明确列出），其他列不提供值
>
> 省略列
> >如果表的定义允许，则可以在INSERT操作中省略某些列。
> >>该列定义为允许NULL值（无值或空值）。
> >>在表定义中给出默认值。这表示如果不给出值，将使用默认值。
>
> 提高性能
> > 关键字：insert low_priority into   --- 降低insert语句的优先级
> > 因为insert操作可能很耗时（特别是有很多索引需要更新时），而且它可能降低等待处理的SELECT语句的性能。
>
> 总是使用列的列表
> >使用列的列表能使SQL代码继续发挥作用，即使表结构发生了变化。
>
> 仔细地给出值
> >如果不提供列名，则必须给每个表列提供一个值。
> >如果提供列名，则必须对每个列出的列给出一个值。

>
## 19.3 插入多个行

>需要插入多行数据时

>可以使用多条insert语句，甚至一次提交它们（用分号分隔）

```sql
INSERT INTO
    customers(
        cust_name,
        cust_address,
        cust_city,
        cust_state,
        cust_zip,
        cust_country
    )
VALUES
    (
        'Pep E. LaPew',
        '100Main Street',
        'Los Angeles',
        'CA',
        '90046',
        'USA '
    );

INSERT INTO
    customers(
        cust_name,
        cust_address,
        cust_city,
        cust_state,
        cust_zip,
        cust_country
    )
VALUES
    (
        'M.Martian',
        '142 Galaxy way',
        'New York',
        'NY',
        '11213 ',
        'USA '
    );
```

>或者，组合起来插入数据（列和value，必须都按照次序一一对应）

```sql
INSERT INTO
    customers(
        cust_name,
        cust_address,
        cust_city,
        cust_state,
        cust_zip,
        cust_country
    )
VALUES
    (
        'Pep E. LaPew',
        '100Main Street',
        'Los Angeles',
        'CA',
        '90046',
        'USA '
    ),
VALUES
    (
        'M.Martian',
        '142 Galaxy way',
        'New York',
        'NY',
        '11213 ',
        'USA '
    );
```
>提高INSERT的性能
>
>>用单条INSERT语句处理多个插入比使用多条INSERT语句快
## 19.4 插入检索出的数据

> INSERT
> > 1. 一般用来给表插入一个指定列值的行
> > 2. 还可以将一条SELECT语句的结果插入表中
>
> 这就是所谓的INSERT SELECT，顾名思义，它是由一条INSERT语句和一条SELECT语句组成的
>
> >应用：把从一个表中查询出的数据，合并到另一个表

```sql
INSERT INTO
    customers(
        cust_id,
        cust_contact,
        cust_email,
        cust_name,
        cust_address,
        cust_city,
        cust_state,
        cust_zip,
        cust_country
    )
SELECT
    cust_id,
    cust_contact,
    cust_email,
    cust_name,
    cust_address,
    cust_city,
    cust_state,
    cust_zip,
    cust_country
FROM
    custnew;
```

>这个例子使用INSERT SELECT从custnew中将所有数据导入customers.

>SELECT语句从custnew检索出要插入的值.
>SELECT中列出的每个列对应于customers表名后所跟的列表中的每个列。

>这条语句将插入多少行有赖于custnew表中有多少行。
>如果这个表为空，则没有行被插入（也不产生错误，因为操作仍然是合法的）。
>如果这个表确实含有数据，则所有数据将被插入到customers。

>这个例子导入了cust_id（假设你能够确保cust_id的值不重复）。
>你也可以简单地省略这列（从INSERT和SELECT中），这样MySQL就会生成新值

>> INSERT SELECT中SELECT语句可包含WHERE子句以过滤插入的数据。
## 19.5 小结 

>1. 将行插入到数据库表
>2. insert的几种用法
>3. insert select的用法



# 第20章 更新和删除数据（update、delete）

## 简介

>update语句：更新（修改）表中的数据
>delete语句： 从一个表中删除（去掉）数据
## 20.1 更新数据

>为了更新（修改）表中的数据，可使用UPDATE语句。
>>更新表中特定行；
>>更新表中所有行。

>不要省略WHERE子句
>
>>在使用UPDATE时一定要注意细心，因为稍不注意，就会更新表中所有行。

>UPDATE与安全
>
>>可以限制和控制UPDATE语句的使用，更多内容请参见第28章。

>基本的UPDATE语句由3部分组成，分别是：
>>要更新的表；
>>列名和它们的新值；
>>确定要更新行的过滤条件。

```sql
update
    customers 						-- 要更新的表的名字
set
    cust_email = 'elmer@fudd.com' 	-- 把值赋给，被更新的列
where
    cust_id = 10005; 				-- 更新哪一行
```

```sql
-----------------------------------------更新多个列-----------------------------
update
    customers
set
    cust_email = 'elmer@fudd.com',  --- 列 = 值（逗号分隔）
    cust_name = 'The Fudds'         --- 列 = 值（最后一个列之后不加逗号）
where
    cust_id = 10005;

```
>在UPDATE语句中使用子查询
>>UPDATE语句中可以使用子查询，使得能用SELECT语句检索出的数据更新列数据。
>
>IGNORE关键字
>如果用UPDATE语句更新多行，并且在更新这些行中的一行或多行时出一个现错误，则整个UPDATE操作被取消（错误发生前更新的所有行被恢复到它们原来的值）。
>为即使是发生错误，也继续进行更新，可使用IGNORE关键字，如下所示：
>
>>UPDATE IGNORE customers..

>为了删除某个列的值，可设置它为NULL（假如表定义允许NULL值）。
>如下进行：其中NULL用来去除cust_emai1列中的值。
```sql
UPDATE
    customers
SET
    cust_email = NULL
WHERE
    cust_id = 10005;
```

## 20.2 删除数据

>为了从一个表中删除（去掉）数据，使用DELETE语句。
>>从表中删除特定的行；
>>从表中删除所有行。
>
>不要省略WHERE子句
>>在使用DELETE时一定要注意细心。因为稍不注意，就会错误地删除表中所有行。
>
>DELETE与安全
>
>>可以限制和控制DELETE语句的使用，更多内容请参见第28章。


>UPDATE使用
>下面的语句从customers表中删除一行：

```sql
DELETE FROM
    customers        -- 表名：从哪个表中删除数据
WHERE
    cust_id = 10006; -- 过滤出，要删除的行
```
>DELETE不需要列名或通配符。
>DELETE删除整行而不是删除列。
>为了删除指定的列，请使用UPDATE语句。

>删除表的内容而不是表
>>DELETE语句从表中删除行，甚至是删除表中所有行。但是，DELETE不删除表本身。
>
>更快的删除
>>如果想从表中删除所有行，不要使用DELETE。
>>可使用TRUNCATE TABLE语句，它完成相同的工作，但速度更快
>>（TRUNCATE实际是删除原来的表并重新创建一个表，而不是逐行删除表中的数据）。
## 20.3 更新和删除的指导原则

>update、delete，别忘记where子句

>使用UPDATE或DELETE时所遵循的习惯。
>>1. 除非确实打算更新和删除每一行，否则绝对不要使用不带WHERE子句的UPDATE或DELETE语句。
>
>>2. 保证每个表都有主键（如果忘记这个内容，请参阅第15章），尽可能像WHERE子句那样使用它（可以指定各主键、多个值或值的范围）。
>
>>3. 在对UPDATE或DELETE语句使用WHERE子句前，应该先用SELECT进行测试，保证它过滤的是正确的记录，以防编写的WHERE子句不正确。
>
>>4. 使用强制实施引用完整性的数据库（关于这个内容，请参阅第15章），这样MySQL将不允许删除具有与其他表相关联的数据的行。
>
>小心使用
>
>>MySQL没有撤销（undo）按钮。
## 20.4 小结

> 1. update
> 2. delete
> 3. 使用update和delete时别忘记where子句，这很重要
> 4. 一些指导原则，以保证数据的安全



# 第21章 创建和操纵表（1. create table  2. alter table  3. drop table 4. 备份 5. 数据库引擎 7. 定义主键 8.定义外键）

## 简介

>1. 表的创建
>2. 表的更改
>3. 表的删除

## 21.1 创建表

>1. 直接在mysql命令行里，使用SQL的 create table 语句
>2. 或者使用表创建脚本

### 21.1.1 表创建基础

>为利用CREATE TABLE创建表，必须给出下列信息：
>>1. 新表的名字，在关键字CREATE TABLE之后给出；
>>2. 表列的名字和定义，用逗号分隔。
>
>表的主键
>
>>可以在创建表时用 primary key 关键字指定

```sql
CREATE TABLE customers
(
  cust_id      int       NOT NULL AUTO_INCREMENT,
  cust_name    char(50)  NOT NULL ,
  cust_address char(50)  NULL ,
  cust_city    char(50)  NULL ,
  cust_state   char(5)   NULL ,
  cust_zip     char(10)  NULL ,
  cust_country char(50)  NULL ,
  cust_contact char(50)  NULL ,
  cust_email   char(255) NULL ,
  PRIMARY KEY (cust_id)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8;
```
>创表时，如果表名已经存在，但仍然想创建
>> 应该首先手工删除该表，然后再重建它，而不是简单地用创建表语句覆盖它。
>
>仅在一个表不存在时创建它
>> 在表名后给出：if not exists
>> 它只查看表名是否存在，并且仅在表名不存在时创建它
### 21.1.2 使用NULL值

>NULL值就是没有值或缺值。
>>允许NULL值的列，也允许在插入行时不给出该列的值。
>>不允许NULL值的列，不接受该列没有值的行，换句话说，在插入或更新行时，该列必须有值。

> 每个表列或者是NULL列，或者是NOTNULL列，这种状态在创建时由表的定义规定。
```sql
CREATE TABLE orders
(
  order_num  int      NOT NULL AUTO_INCREMENT,
  order_date datetime NOT NULL ,
  cust_id    int      NOT NULL ,
  PRIMARY KEY (order_num)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8;
```

```sql
CREATE TABLE vendors
(
  vend_id      int      NOT NULL AUTO_INCREMENT,
  vend_name    char(50) NOT NULL ,
  vend_address char(50) NULL ,
  vend_city    char(50) NULL ,
  vend_state   char(5)  NULL ,
  vend_zip     char(10) NULL ,
  vend_country char(50) NULL ,
  PRIMARY KEY (vend_id)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8;
```
>理解NULL
>>不要把NULL值与空串相混淆。
>>NULL值是没有值，它不是空串。空串是一个有效的值，它不是无值。
>>如果指定 '  '（两个单引号，其间没有字符），这在NOT NULL列中是允许的。
>>
>>>NULL值用关键字NULL而不是空串指定。
### 21.1.3 主键再介绍

>主键值必须唯一：即，表中的每个行必须具有唯一的主键值。
>>如果主键使用单个列，则它的值必须唯一。
>>如果使用多个列，则这些列的组合值必须唯一。
>
>迄今为止我们看到的CREATE TABLE例子都是用单个列作为主键。
>其中主键用以下的类似的语句定义：
>PRIMARY KEY（vend_id）

>  为创建由多个列组成的主键，应该以逗号分隔的列表给出各列名，如下所示：

```sql
CREATE TABLE orderitems
(
  order_num  int          NOT NULL ,
  order_item int          NOT NULL ,
  prod_id    char(10)     NOT NULL ,
  quantity   int          NOT NULL ,
  item_price decimal(8,2) NOT NULL ,
  PRIMARY KEY (order_num, order_item)  ----------由多个列组成的主键，应该以逗号分隔
) ENGINE=InnoDB DEFAULT CHARSET=UTF8;
```
>主键可以在创建表时定义，或者在创建表之后定义（本章稍后讨论）

>主键和NULL值
>主键为其值唯一标识表中每个行的列。主键中只能使用不允许NULL值的列。允许NULL值的列不能作为唯一标识。

### 21.1.4 使用 auto_increment

>AUTO_INCREMENT
>>每当增加一行时，对该列自动增量
>>然后MySQL会自动给该列赋予下一个可用的值，这样就可以保证编号唯一，从而该列就可以用作主键

>每个表只允许一个AUTO_INCREMENT列，而且它必须被索引（如，通过使它成为主键）。

>覆盖AUTO_INCREMENT
>>可以简单地在INSERT语句中指定一个值，只要它是唯一的（至今尚未使用过）即可，该值将被用来替代自动生成的值。后续的增量将开始使用该手工插入的值。（相关的例子请参阅本书中使用的表填充脚本。）
>
>确定AUTO_INCREMENT值
>> 让MySQL生成（通过自动增量）主键的一个缺点是你不知道这些值都是谁。
>> 如何在使用AUTOINCREMENT列时获得这个值呢？
>> 可使用last_insert_id（）函数获得这个值，
>> 此语句返回最后一个AUTO_INCREMENT值，然后可以将它用于后续的MySQL语句。
>> 如下所示：
>>
>> >SELECT  last_insert_id()
### 21.1.5 指定默认值

>如果在插入行时没有给出值，此时使用默认值。
>默认值，是CREATE TABLE语句中的DEFAULT关键字指定。

```sql
CREATE TABLE orderitems
(
  order_num  int          NOT NULL ,
  order_item int          NOT NULL ,
  prod_id    char(10)     NOT NULL ,
  quantity   int          NOT NULL 		default 1, ---- 指示，默认值为1
  item_price decimal(8,2) NOT NULL ,
  PRIMARY KEY (order_num, order_item)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8;
```
> 使用默认值而不是NULL值
> 许多数据库开发人员使用默认值而不是NULL列，特别是对用于计算或数据分组的列更是如此
### 21.1.6 引擎类型

>MySQL具有多种引擎
>为不同的任务选择正确的引擎能获得良好的功能和灵活性
>> ENGINE=InnoDB
>> ENGINE=MyISAM

>MySQL的几个引擎的简介
>>1. InnoDB是一个可靠的事务处理引擎（参见第26章），它不支持全文本搜索；
>>2. MEMORY在功能等同于MyISAM，但由于数据存储在内存（不是磁盘）中，速度很快（特别适合于临时表）；
>>3. MyISAM是一个性能极高的引擎，它支持全文本搜索（参见第18章），但不支持事务处理。

>引擎类型可以混用（同一个数据库的不同的表，可以使用不同的引擎）

> 外键不能跨引擎：这是混用引擎的一个大缺陷
> 外键用于强制实施引用完整性，不能跨引擎

>MyISAM由于其性能和特性可能是最受欢迎的引擎
>但如果你需要可靠的事务处理，可以使用其他引擎，如：InnoDB
## 21.2 更新表

>更新表定义 / 更改表结构
>>使用 alter table语句
>
>表的设计需要花大量时间来考虑，以便后期不该对该表进行大的改动
>
>使用alter table更改表结构
>> 1. 在alter table之后给出要更改的表名
>> 2. 所做更该的列

```sql
-----------------------给vendors表增加一个名为vend_phone的列（必须明确其数据类型）
alter table
    vendors
add
    vend_phone CHAR(20);
```
```sql
-----------------------删除刚刚添加的列
alter table
    vendors drop column vend_phone;
```


>> alert table的另一个常见用途是：定义外键
```sql
ALTER TABLE
  orderitems
ADD
  CONSTRAINT fk_orderitems_orders FOREIGN KEY (order_num) REFERENCES orders (order_num);
```

```sql
ALTER TABLE
  orderitems
ADD
  CONSTRAINT fk_orderitems_products FOREIGN KEY (prod_id) REFERENCES products (prod_id);
```

```sql
ALTER TABLE
  orders
ADD
  CONSTRAINT fk_orders_customers FOREIGN KEY (cust_id) REFERENCES customers (cust_id);
```

```sql
ALTER TABLE
  products
ADD
  CONSTRAINT fk_products_vendors FOREIGN KEY (vend_id) REFERENCES vendors (vend_id);
```
>复杂的表结构一般需要手动删除过程
>>1. 用新的列布局创建一个新表；
>>2. 使用INSERT SELECT语句（第19章）从旧表复制数据到新表。如果有必要，可使用转换函数和计算字段；
>>3. 检验包含所需数据的新表；
>>4. 重命名旧表（如果确定，可以删除它）；
>>5. 用旧表原来的名字重命名新表；
>>6. 根据需要，重新创建触发器、存储过程、索引和外键。

>小心使用 alter table
>
>>在进行改动前做一个完整的备份（模式和数据的备份）（因为 MySQL数据库表的更改不能撤销）
## 21.3 删除表

> 删除表（删除整个表 而不是其内容）非常简单，使用DROP TABLE语句即可：
> >DROP TABLE  表名；
> >删除表没有确认，也不能撤销，执行这条语句将永久删除该表。
## 21.4 重命名表

>重命名一个表
>> rename table 表旧名  to  表新名 ;
>
>重命名多个表
>>rename table 1表旧名  to  1表新名,
>>2表旧名  to  2表新名,
>>3表旧名  to  3表新名;
## 21.5 小结

>1. create table 创建新表
>2. alter table 更改表结构
>3. drop table 删除整表
>4. 这些语句必须小心使用，必须在做了备份之后再使用
>5. 数据库引擎
>6. 定义主键
>7. 定义外键



# 第22章 使用视图（）

## 简介

>什么是视图？
>怎样工作？
>如何使用？
## 22.1 视图

### 22.1.1 为什么使用视图

### 22.1.2 视图的规则和限制

## 22.2 使用视图

### 22.2.1 利用视图简化复杂的联结























