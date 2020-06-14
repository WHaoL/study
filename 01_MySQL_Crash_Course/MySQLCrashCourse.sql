--创建数据库(本书使用的)
create database MySQLCrashCourse;
--使用数据库
use MySQLCrashCourse;
------------------------------------------------
-- Create customers table
------------------------------------------------
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
----------------------------------------------------
-- Populate customers table
----------------------------------------------------
INSERT INTO customers(cust_id, cust_name, cust_address, cust_city, cust_state, cust_zip, cust_country, cust_contact, cust_email)
VALUES(10001, 'Coyote Inc.', '200 Maple Lane', 'Detroit', 'MI', '44444', 'USA', 'Y Lee', 'ylee@coyote.com');
INSERT INTO customers(cust_id, cust_name, cust_address, cust_city, cust_state, cust_zip, cust_country, cust_contact)
VALUES(10002, 'Mouse House', '333 Fromage Lane', 'Columbus', 'OH', '43333', 'USA', 'Jerry Mouse');
INSERT INTO customers(cust_id, cust_name, cust_address, cust_city, cust_state, cust_zip, cust_country, cust_contact, cust_email)
VALUES(10003, 'Wascals', '1 Sunny Place', 'Muncie', 'IN', '42222', 'USA', 'Jim Jones', 'rabbit@wascally.com');
INSERT INTO customers(cust_id, cust_name, cust_address, cust_city, cust_state, cust_zip, cust_country, cust_contact, cust_email)
VALUES(10004, 'Yosemite Place', '829 Riverside Drive', 'Phoenix', 'AZ', '88888', 'USA', 'Y Sam', 'sam@yosemite.com');
INSERT INTO customers(cust_id, cust_name, cust_address, cust_city, cust_state, cust_zip, cust_country, cust_contact)
VALUES(10005, 'E Fudd', '4545 53rd Street', 'Chicago', 'IL', '54545', 'USA', 'E Fudd');

----------------------------------------------
-- Create products table
----------------------------------------------
CREATE TABLE products
(
  prod_id    char(10)      NOT NULL,
  vend_id    int           NOT NULL ,
  prod_name  char(255)     NOT NULL ,
  prod_price decimal(8,2)  NOT NULL ,
  prod_desc  text          NULL ,
  PRIMARY KEY(prod_id)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8;
--------------------------------------------------
-- Populate products table
--------------------------------------------------
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('ANV01', 1001, '.5 ton anvil', 5.99, '.5 ton anvil, black, complete with handy hook');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('ANV02', 1001, '1 ton anvil', 9.99, '1 ton anvil, black, complete with handy hook and carrying case');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('ANV03', 1001, '2 ton anvil', 14.99, '2 ton anvil, black, complete with handy hook and carrying case');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('OL1', 1002, 'Oil can', 8.99, 'Oil can, red');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('FU1', 1002, 'Fuses', 3.42, '1 dozen, extra long');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('SLING', 1003, 'Sling', 4.49, 'Sling, one size fits all');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('TNT1', 1003, 'TNT (1 stick)', 2.50, 'TNT, red, single stick');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('TNT2', 1003, 'TNT (5 sticks)', 10, 'TNT, red, pack of 10 sticks');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('FB', 1003, 'Bird seed', 10, 'Large bag (suitable for road runners)');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('FC', 1003, 'Carrots', 2.50, 'Carrots (rabbit hunting season only)');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('SAFE', 1003, 'Safe', 50, 'Safe with combination lock');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('DTNTR', 1003, 'Detonator', 13, 'Detonator (plunger powered), fuses not included');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('JP1000', 1005, 'JetPack 1000', 35, 'JetPack 1000, intended for single use');
INSERT INTO products(prod_id, vend_id, prod_name, prod_price, prod_desc)
VALUES('JP2000', 1005, 'JetPack 2000', 55, 'JetPack 2000, multi-use');

--------------------------------------------
-- Create vendors table
--------------------------------------------
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
------------------------------------------------
-- Populate vendors table
------------------------------------------------
INSERT INTO vendors(vend_id, vend_name, vend_address, vend_city, vend_state, vend_zip, vend_country)
VALUES(1001,'Anvils R Us','123 Main Street','Southfield','MI','48075', 'USA');
INSERT INTO vendors(vend_id, vend_name, vend_address, vend_city, vend_state, vend_zip, vend_country)
VALUES(1002,'LT Supplies','500 Park Street','Anytown','OH','44333', 'USA');
INSERT INTO vendors(vend_id, vend_name, vend_address, vend_city, vend_state, vend_zip, vend_country)
VALUES(1003,'ACME','555 High Street','Los Angeles','CA','90046', 'USA');
INSERT INTO vendors(vend_id, vend_name, vend_address, vend_city, vend_state, vend_zip, vend_country)
VALUES(1004,'Furball Inc.','1000 5th Avenue','New York','NY','11111', 'USA');
INSERT INTO vendors(vend_id, vend_name, vend_address, vend_city, vend_state, vend_zip, vend_country)
VALUES(1005,'Jet Set','42 Galaxy Road','London', NULL,'N16 6PS', 'England');
INSERT INTO vendors(vend_id, vend_name, vend_address, vend_city, vend_state, vend_zip, vend_country)
VALUES(1006,'Jouets Et Ours','1 Rue Amusement','Paris', NULL,'45678', 'France');

--------------------------------------------------
-- Create orderitems table
-- 表：订单
--------------------------------------------------
CREATE TABLE orderitems
(
  order_num  int          NOT NULL ,
  order_item int          NOT NULL ,
  prod_id    char(10)     NOT NULL ,
  quantity   int          NOT NULL ,
  item_price decimal(8,2) NOT NULL ,
  PRIMARY KEY (order_num, order_item)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8;
------------------------------------------------------
-- Populate orderitems table
------------------------------------------------------
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20005, 1, 'ANV01', 10, 5.99);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20005, 2, 'ANV02', 3, 9.99);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20005, 3, 'TNT2', 5, 10);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20005, 4, 'FB', 1, 10);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20006, 1, 'JP2000', 1, 55);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20007, 1, 'TNT2', 100, 10);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20008, 1, 'FC', 50, 2.50);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20009, 1, 'FB', 1, 10);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20009, 2, 'OL1', 1, 8.99);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20009, 3, 'SLING', 1, 4.49);
INSERT INTO orderitems(order_num, order_item, prod_id, quantity, item_price)
VALUES(20009, 4, 'ANV03', 1, 14.99);

------------------------------------------
-- Create orders table
------------------------------------------
CREATE TABLE orders
(
  order_num  int      NOT NULL AUTO_INCREMENT,
  order_date datetime NOT NULL ,
  cust_id    int      NOT NULL ,
  PRIMARY KEY (order_num)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8;

----------------------------------------------
-- Populate orders table
----------------------------------------------
INSERT INTO orders(order_num, order_date, cust_id)
VALUES(20005, '2005-09-01', 10001);
INSERT INTO orders(order_num, order_date, cust_id)
VALUES(20006, '2005-09-12', 10003);
INSERT INTO orders(order_num, order_date, cust_id)
VALUES(20007, '2005-09-30', 10004);
INSERT INTO orders(order_num, order_date, cust_id)
VALUES(20008, '2005-10-03', 10005);
INSERT INTO orders(order_num, order_date, cust_id)
VALUES(20009, '2005-10-08', 10001);







--------------------------------------------------
-- 第9章
--------------------------------------------------
--9.2.1基本字符匹配
--输入
select prod_name 
from products 
where prod_name regexp '1000' 
order by prod_name;
--输出
+--------------+
| prod_name    |
+--------------+
| JetPack 1000 |
+--------------+
1 row in set (0.00 sec)
--regexp 它告诉MySQL: regexp后跟的东西作为正则表达式处理
--注意：regexp 在列值内进行匹配如果被匹配的文字在列值中出现，regexp将会找到它，相应的行将被返回

--输入
select prod_name 
from products 
where prod_name like '1000' 
order by prod_name;
--输出
Empty set (0.01 sec)
--注意：like匹配整个列，如果被匹配的文本在列值中出现，like将不会找到它，相应的行也不会被返回（除非使用通配符）

--注意


--输入
select prod_name 
from products 
where prod_name regexp '.000' 
order by prod_name;
--输出
+--------------+
| prod_name    |
+--------------+
| JetPack 1000 |
| JetPack 2000 |
+--------------+
2 rows in set (0.00 sec)
--这里使用了正则表达式 .000  .是正则表达式语言中一个特殊的字符，它表示匹配任意一个字符

--9.2.2 进行or匹配
--输入
select prod_name 
from products 
where prod_name regexp '1000|2000' 
order by prod_name;
--输出
+--------------+
| JetPack 1000 |
| JetPack 2000 |
+--------------+
2 rows in set (0.00 sec)
-- | 为正则表达式的or，类似于select语句中使用的or语句，多个or条件可并入单个正则表达式
-- | 表示都匹配并返回

--9.2.3 匹配特定的字符
--[ ] 括起来来完成，匹配[ ]中出现的字符
--输入
select prod_name
from products
where prod_name regexp '[123] Ton'
order by prod_name;
--输出
+-------------+
| 1 ton anvil |
| 2 ton anvil |
+-------------+
2 rows in set (0.01 sec)
--[123]表示匹配1或2或3,
--正则表达式[123] Ton为[1|2|3] Ton的缩写，也可以使用后者

-- ^ 否定 ， 在集合的开始处，放置^,将匹配指定字符之外的任何东西

--9.2.4 匹配范围
--输入
select prod_name
from products
where prod_name regexp '[1-5] Ton'
order by prod_name;
--输出
+--------------+
| prod_name    |
+--------------+
| .5 ton anvil |
| 1 ton anvil  |
| 2 ton anvil  |
+--------------+
3 rows in set (0.00 sec)
--   - 用来定义一个范围
--   [1-9]  匹配1至9
--   [a-z]  匹配字母 a至z

--9.2.5 匹配特殊字符
--为了匹配特殊字符，必须用\\为前。
--  \\-表示查找- , \\.表示查找.
-- 这种处理就是所谓的转义
-- 正则表达式内具有特殊意义的所有字符都必须以这种方式转义
-- 为了匹配\，需要使用\\\
-- 注意 MySQL要求两个反斜杠(MySQL自己解释一个，正则表达式解释另一个)
--输入
select vend_id,vend_name  from vendors where vend_name regexp '\\.' order by vend_name;
--输出
+---------+--------------+
| vend_id | vend_name    |
+---------+--------------+
|    1004 | Furball Inc. |
+---------+--------------+
1 row in set (0.00 sec)

--9.2.7 匹配多个实现
select prod_name
from products
where prod_name regexp '\\([0-9] sticks?\\)'
order by prod_name;
--
+----------------+
| prod_name      |
+----------------+
| TNT (1 stick)  |
| TNT (5 sticks) |
+----------------+
2 rows in set (0.00 sec)
-- \\(      匹配(
-- [0-9]    匹配任意数字
-- sticks?  s后的?使得s可选， 因为?匹配它前面的任何字符的0次或1次出现
-- \\)      匹配)

select prod_name
from products
where prod_name regexp '[0-9][0-9][0-9][0-9]'
order by prod_name;
+--------------+
| prod_name    |
+--------------+
| JetPack 1000 |
| JetPack 2000 |
+--------------+
2 rows in set (0.00 sec)

--9.2.8 定位符
-- 匹配特定位置的文本
select prod_name 
from products
where prod_name regexp '^[0-9\\.]'
order by prod_name;
--
+--------------+
| prod_name    |
+--------------+
| .5 ton anvil |
| 1 ton anvil  |
| 2 ton anvil  |
+--------------+
3 rows in set (0.00 sec)  

--------------------------------------------------
-- 第10章 创建计算字段
--------------------------------------------------
--10.2 拼接字段    
--concat()拼接串
select concat(vend_name,' (',vend_country,')')
from  vendors
order by vend_name;
--
+-----------------------------------------+
| concat(vend_name,' (',vend_country,')') |
+-----------------------------------------+
| ACME (USA)                              |
| Anvils R Us (USA)                       |
| Furball Inc. (USA)                      |
| Jet Set (England)                       |
| Jouets Et Ours (France)                 |
| LT Supplies (USA)                       |
+-----------------------------------------+
6 rows in set (0.02 sec)

--rtrim()去掉值右边的所有空格
--ltrim()去掉左边的所有空格
select concat( rtrim(vend_name), ' (', rtrim(vend_country), ')' ) 
from vendors
order by vend_name;
--+------------------------------------------------------------+
| concat( rtrim(vend_name), ' (', rtrim(vend_country), ')' ) |
+------------------------------------------------------------+
| ACME (USA)                                                 |
| Anvils R Us (USA)                                          |
| Furball Inc. (USA)                                         |
| Jet Set (England)                                          |
| Jouets Et Ours (France)                                    |
| LT Supplies (USA)                                          |
+------------------------------------------------------------+
-- as 使用别名
select concat(rtrim(vend_name),' (',rtrim(vend_country),')') as vend_tile
from vendors
order by vend_name;
--
+-------------------------+
| vend_tile               |
+-------------------------+
| ACME (USA)              |
| Anvils R Us (USA)       |
| Furball Inc. (USA)      |
| Jet Set (England)       |
| Jouets Et Ours (France) |
| LT Supplies (USA)       |
+-------------------------+
6 rows in set (0.01 sec)

--10.3 执行算术计算
select order_num,prod_id,quantity,item_price,quantity*item_price as expanded_price
from orderitems
where order_num = 20005;
--
+-----------+---------+----------+------------+----------------+
| order_num | prod_id | quantity | item_price | expanded_price |
+-----------+---------+----------+------------+----------------+
|     20005 | ANV01   |       10 |       5.99 |          59.90 |
|     20005 | ANV02   |        3 |       9.99 |          29.97 |
|     20005 | TNT2    |        5 |      10.00 |          50.00 |
|     20005 | FB      |        1 |      10.00 |          10.00 |
+-----------+---------+----------+------------+----------------+
4 rows in set (0.00 sec)

--去掉左边多余的空格
--
select '   abc';
+--------+
| abc    |
+--------+
|    abc |
+--------+
1 row in set (0.00 sec)
--输入
select ltrim('   abc'); 
--输出
+-----------------+
| ltrim('   abc') |
+-----------------+
| abc             |
+-----------------+
1 row in set (0.00 sec)
--输入
select trim('   abc');
--输出
+----------------+
| trim('   abc') |
+----------------+
| abc            |
+----------------+
1 row in set (0.00 sec)

--upper()将文本转换为大写
select vend_name,upper(vend_name) as vend_name_upcase
from vendors
order by  vend_name;
--
+----------------+------------------+
| vend_name      | vend_name_upcase |
+----------------+------------------+
| ACME           | ACME             |
| Anvils R Us    | ANVILS R US      |
| Furball Inc.   | FURBALL INC.     |
| Jet Set        | JET SET          |
| Jouets Et Ours | JOUETS ET OURS   |
| LT Supplies    | LT SUPPLIES      |
+----------------+------------------+
6 rows in set (0.01 sec)

--length()返回串的长度
select vend_name,length(vend_name) as vend_name_length
from vendors
order by  vend_name;

--
select cust_name,cust_contact 
from customers
where cust_contact = 'Y Lie';
--
Empty set (0.00 sec)
--soundex()函数，按读音查找
select cust_name,cust_contact
from customers
where soundex(cust_contact)  = soundex('Y Lie');
--+-------------+--------------+
| cust_name   | cust_contact |
+-------------+--------------+
| Coyote Inc. | Y Lee        |
+-------------+--------------+
1 row in set (0.04 sec)

--11.2.2 时间和日期处理函数
--
select cust_id,order_num,order_date
from orders
where date(order_date) = '2005-09-01';
--
+---------+-----------+---------------------+
| cust_id | order_num | order_date          |
+---------+-----------+---------------------+
|   10001 |     20005 | 2005-09-01 00:00:00 |
+---------+-----------+---------------------+
--检索出2005年9月份下的所有订单
select cust_id,order_num,order_date
from orders
where year(order_date)=2005 and month(order_date)=9;
+---------+-----------+---------------------+
| cust_id | order_num | order_date          |
+---------+-----------+---------------------+
|   10001 |     20005 | 2005-09-01 00:00:00 |
|   10003 |     20006 | 2005-09-12 00:00:00 |
|   10004 |     20007 | 2005-09-30 00:00:00 |
+---------+-----------+---------------------+

--------------------------------------------------
-- 第12章 汇总数据
--------------------------------------------------
--12.1 聚集函数
--12.1.1 avg()函数
--avg()计算所有列或特定列的平均值
-- 如果列里 某行的值为NULL，则被avg()忽略
select avg(prod_price) as avg_price
from products;
+-----------+
| avg_price |
+-----------+
| 16.133571 |
+-----------+
1 row in set (0.07 sec)
--
select avg(prod_price) as avg_price
from products
where vend_id=1003;
+-----------+
| avg_price |
+-----------+
| 13.212857 |
+-----------+
1 row in set (0.00 sec)

--12.1.2 count()函数
--count()计算行的数目，或符合条件的行的数目
-- count()里指定列名，如果列里 某行的值为NULL，则被count()忽略
-- count()用*，则不忽略
select count(*) as num_cust
from customers;
+----------+
| num_cust |
+----------+
|        5 |
+----------+
1 row in set (0.67 sec)
--
select count(cust_email) as num_cust
from customers;
+----------+
| num_cust |
+----------+
|        3 |
+----------+
1 row in set (0.00 sec)

--12.1.3 max()函数
-- 找出最大的数值或日期值或文本串列里的最大的串
-- 如果列里 某行的值为NULL，则被max()忽略
select max(prod_price) as max_price
from products;
+-----------+
| max_price |
+-----------+
|     55.00 |
+-----------+
1 row in set (0.16 sec)

--12.1.4 min()函数
-- 如果列里 某行的值为NULL，则被min()忽略
select min(prod_price)  as min_price
from products;
+-----------+
| min_price |
+-----------+
|      2.50 |
+-----------+
1 row in set (0.00 sec)

--12.1.5 sum()函数
-- 返回指定列值的和
select sum(quantity) as items_ordered
from orderitems
where order_num=20005;
+---------------+
| items_ordered |
+---------------+
|            19 |
+---------------+
1 row in set (0.00 sec)
--
select sum(item_price*quantity) as total_price
from orderitems
where order_num = 20005;
+-------------+
| total_price |
+-------------+
|      149.87 |
+-------------+
1 row in set (0.00 sec)

--12.2 聚集不同值
-- all     ：为默认，不需要指定，不指定distinct则假定为all
-- distinct：只包含不同的值,后必须跟列名，不能用于计算或表达式
select avg(distinct prod_price) as avg_price
from products
where vend_id = 1003;
+-----------+
| avg_price |
+-----------+
| 15.998000 |
+-----------+
1 row in set (0.00 sec)
