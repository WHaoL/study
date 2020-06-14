@[TOC](目录)

# 书本源码

书本源码：https://forta.com/books/0672327120/

[mysql_scripts.zip](https://forta.com/wp-content/uploads/books/0672327120/mysql_scripts.zip) contains two files, create.sql and populate.sql.

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
> > like 是谓词，而不是操作符 

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



























































































