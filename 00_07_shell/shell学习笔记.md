@[TOC](目录)



# 一、为什么要学习shell

> shell比较适合一些运维性质的工作
>
> 一些简单的工作就不要动高级编程语言 C/C++ 
>
> 分析日志，将其中的404错误打印出来，统计出错最多的URL
>
> shell是有现成很多命令，可以直接得到结果
>
> 
>
> > 硬件资源、硬盘、内存、网卡...
> >
> > 系统内核
> >
> > 系统调用API (read/write...)
> >
> > 图形界面 或者 shell  (将用户的操作指令转化为系统调用)
> >
> > ------------------------------上面的各项(自上而下)：是从内到外 依次被包含---------------------------------------

# 二、 shell基础

## 2.1 确定当前用户的shell

>确定当前用户的shell
>    法一：查看环境变量
>    	[root@lwh ~]# echo $SHELL
>		/bin/bash
>    法二：查看/etc/passwd
>        找到对应用户那一行的最后一列
>
>修改当前用户使用的shell
>    chsh命令

## 2.2 shell的内建命令

>shell的内建命令，是不会启动一个新的进程的
>    cd、umask、alias、exit...
>	
>which 命令找不到的的命令都认为是内建命令
>	
>通过 man bash-builtins 查看有哪些内建命令

## 2.3 shell的执行

### test.sh 01

```shell
# !/bin/bash # 第一行使用 #做注释 后面跟上!+解析器的位置，指定使用哪个解析器 ，如果没有默认用sh
             # ./test.sh执行时,会直接使用这个解析器来解析下面的程序
echo Hello world
cd ..
tree
```

```shell
# 直接执行报错，因为没有可执行权限
[root@lwh testShell]# ./test.sh
-bash: ./test.sh: Permission denied
[root@lwh testShell]# ll test.sh 
-rw-r--r--. 1 root root 41 Jun 15 18:06 test.sh 

# 给予可执行权限之后，就可以执行这个sh文件了
[root@lwh testShell]# chmod a+x test.sh 
[root@lwh testShell]# ll test.sh 
-rwxr-xr-x. 1 root root 41 Jun 15 18:06 test.sh
```

```shell
# 执行sh文件


# 第一种执行方式:
    chmod a+x test.sh # 添加可执行权限
    ./test.sh         # 直接./执行
[root@lwh testShell]# ./test.sh 
Hello world
.
├── Makefile
├── test.c
└── testShell
    └── test.sh

1 directory, 3 files
[root@lwh testShell]# 

#第二种执行方式:
    sh test.sh                  
    #这种执行方式不需要test.sh 有可执行权限，但是必须有可读权限
    #该脚本是作为一个参数传到 sh命令中，该sh命令就会读取这个文件
[root@lwh testShell]# sh test.sh 
Hello world
.
├── Makefile
├── test.c
└── testShell
    └── test.sh

1 directory, 3 files
[root@lwh testShell]# 


# 以上两种，正常应该使用第一种来执行脚本，因为调用者不需要关注该脚本是什么解析器
# 除非没有办法添加可执行权限，就使用第二种  


#第三种执行方式：
    (cd .. ; ls)
#   小括号括起多条命令，命令之间使用分号分隔开来



# 以上三种方法都是开启一个子进程去执行命令



#第四种执行方法：
	#将脚本中的每一条指令都加载到当前shell里边去执行，不会开启子进程去执行
    source test.sh  # source与. 在此处时一样的
    . test.sh       # source与. 在此处时一样的
[root@lwh testShell]# source ./test.sh 
Hello world
.
├── Makefile
├── test.c
└── testShell
    └── test.sh

1 directory, 3 files
[root@lwh test]# 
#会发现当前目录已经变了，因为这个不开启子进程，而是在当前进程中执行
[root@lwh testShell]#  . ./test.sh 
Hello world
.
├── Makefile
├── test.c
└── testShell
    └── test.sh

1 directory, 3 files
[root@lwh test]# 
#会发现当前目录已经变了，因为这个不开启子进程，而是在当前进程中执行

    

source #经常用于加载一些环境配置
	source /etc/profile
	source ~/.bashrc
	..
```

# 三、 shell 基础语法

## 3.1 变量   

### 1.变量的定义 

> shell中的变量默认都是字符串
>
> varname=value
>     等号两边不能留空格
>     变量定义就是声明
>     定义和声明的同时要赋初值
>
> 
>
> 变量取值
>
> ​    $varname
> ​    ${varname}

### 2.删除变量

> 删除变量
>     unset 变量名
>     直接删除某个变量，不管是普通的shell内变量还是环境变量都可以通过这种方式来删除

## 3.2 变量的分类

### 1. shell内变量：全局变量、局部变量


    shell内变量
    
        全局变量
            只要在shell脚本中没有任何修饰符修饰的变量都是全局的
            生命周期，从该行脚本执行开始一直到脚本结束
        局部变量
            只能声明在函数中，以local作为修饰符，
            生命周期，就从该行脚本执行开始一直到函数结束
            
    shell内变量仅限于在当前shell进程中去使用，不能跨进程

### 2. 环境变量

```shell
环境变量
    操作系统提供给进程的一些环境参数，这些参数可以被修改，任何进程都会有的变量
    能够从父进程传递给子进程，单向传递，不能从子进程传递给父进程
    其实每个进程启动的时候都会从父进程拷贝一份环境变量，
    对环境变量的修改仅限于当前进程以及子进程

    export varname=value
    或者
    varname=value
    export varname
```

#### test.sh 02 

```shell
################test.sh 文件内容如下################
#!/bin/bash
a="Hello"
aa="world"

#取值时，推荐给变量加上 {},便于编译器区分，也便于我们阅读
echo ${a}a

#################
function testfun
{
        #此处的b是全局变量
        b="123"

        #此处的c是局部变量      
        local c="456"
}

#执行testfun函数
testfun

echo b:$b
echo c:$c

##################
#法一：调用子脚本，创建子进程来执行新的sh文件
# shell内变量仅限于在当前shell进程中去使用，不能跨进程
# 所以子进程是拿不到父进程的全局变量的
#./test_sub.sh

#法二：加载子脚本，把test_sub.sh的代码加载到当前进程去执行，这样执行就不会开新的子线程了
#这样test_sub.sh是能取到test.sh的全局变量的
#source ./test_sub.sh

export env_var="这是一个环境变量"
#调用子脚本
./test_sub.sh
#再次输出环境变量
echo "parentscript 输出 env_var:"$env_var
```

#### test_sub.sh 02 

```shell
################test_sub.sh 文件内容如下################
#!/bin/bash
#子脚本
#输出父脚本的全局变量
echo "subscript a:"$a

echo "subscript 输出 env_var:"$env_var

#子进程修改环境变量
export env_var="子进程修改了的环境变量"
```

```shell
##执行
[root@lwh testShell]# ./test.sh 
Helloa
b:123
c:
subscript a:
subscript 输出 env_var:这是一个环境变量
parentscript 输出 env_var:这是一个环境变量
[root@lwh testShell]# 
```

## 3.3 文件名代换

```shell
# * 匹配0个或多个任意字符
	rm *.txt

# ? 匹配一个任意字符
	rm 02?.txt

# [若干字符] 匹配方括号中任意一个字符的一次出现
	rm 0[34]?.txt
    # [34]匹配3或者4
    # ？匹配一个任意字符
```


```shell
# 参数扩展
# 参数展开    
    
    touch {a,b,c}.txt
    # 等同于  touch a.txt b.txt c.txt
    # 将花括号中的名字扩展开来
	
	touch {01..10}.txt
        # 就会产生 01.txt 02.txt ... 10.txt  10个文件
    
    touch {1..3}_{4..6}.txt
        #最后是9个文件
    	[root@lwh test]# touch {1,2,3}_{4,5,6}.txt
		[root@lwh test]# ls
        1_4.txt  1_5.txt  1_6.txt  
        2_4.txt  2_5.txt  2_6.txt  
        3_4.txt  3_5.txt  3_6.txt

	mkdir day{01..05}
		# 产生day01 ... day05 5个文件夹
	
	mkdir -p day{01..05}/0{1_doc,2_code,3_resource,4_note}
	    # 产生day01 ... day05 5个文件夹
	    # 并在5个文件夹下产生01_doc,02_code,03_resource,04_note4个子文件夹
    	[root@lwh test]# mkdir -p day{01..05}/0{1_doc,2_code,3_resource,4_note}
        [root@lwh test]# tree
        .
        ├── day01
        │   ├── 01_doc
        │   ├── 02_code
        │   ├── 03_resource
        │   └── 04_note
        ├── day02
        │   ├── 01_doc
        │   ├── 02_code
        │   ├── 03_resource
        │   └── 04_note
        ├── day03
        │   ├── 01_doc
        │   ├── 02_code
        │   ├── 03_resource
        │   └── 04_note
        ├── day04
        │   ├── 01_doc
        │   ├── 02_code
        │   ├── 03_resource
        │   └── 04_note
        └── day05
            ├── 01_doc
            ├── 02_code
            ├── 03_resource
            └── 04_note
```

```shell

# 以上的参数代换其实是发生在命令执行之前的
# 如
    touch {1,2,3}.txt
    rm *.txt # rm 收到的参数是 1.txt 2.txt 3.txt  
# 我们写个测试程序：打印参数
```

### main.c 03

```c
#include <stdio.h>
int main(int argc, char **argv)
{
    int i = 0;
    for (i = 0; i < argc; ++i)
    {
        printf("argv[%d]:%s\n", i, argv[i]);
    }
    return 0;
}
```

```shell
[root@lwh testshell]# ls *.txt
0_10.txt  0_11.txt  1_10.txt  1_11.txt

[root@lwh testShell]# gcc test_argc.c -o exe 

[root@lwh testShell]# ./exe *.txt
argv[0]:./main
argv[1]:0_10.txt
argv[2]:0_11.txt
argv[3]:1_10.txt
argv[4]:1_11.txt
[root@lwh testShell]# 
```



## 3.4 命令代换
    反引号 ` 
    	ESC下面那个，用反引号扩起来的也是一条命令
    	开启一个进程去执行命令，将命令的标准输出 替换到当前的位置
    
    `date`	等价于	$(date)
    ` `和 $( ) 作用一样
    
    用处：
    	需要将某个命令的标准输出存起来，就要想到命令代换 ``  
    	把输出的内容存到变量里

### test.sh 04

```shell
#!/bin/bash
begintime=$(date) # 执行date，并把值存入变量begintime
sleep 3           # 等待3s
endtime=`date`    # 执行date，并把值存入变量endtime
echo ${begintime} 
echo ${endtime}

[root@lwh testShell]# ./test.sh 
Tue Jun 16 19:12:32 CST 2020 
Tue Jun 16 19:12:35 CST 2020
```

### curPath.sh 04 


```shell
#题目：
#    1.脚本运行的时候会依赖当前的目录：将当前脚本所在目录(路径)计算出来
#    2.通过ls 的方式列出当前脚本所在目录的所有文件
    
    ls curPath=$(dirname $0) 
    # $0 相当于C语言main函数的argv[0]
```

版本1：计算出的是相对路径

```shell
 #!/bin/bash
 curPath=$(dirname  $0)
 echo "curPath:" ${curPath}
 ls ${curPath}


[root@lwh testShell]# ./test.sh 
curPath: .
test.sh
```

版本2：计算出的是绝对路径

```shell
#!/bin/bash
curPath=$(cd `dirname $0`;pwd)
echo "curPath:" ${curPath}
ls ${curPath}

[root@lwh testShell]# ./test.sh 
curPath: /home/lwh/Desktop/study/test/testShell
test.sh
```



## 3.5 算数代换

> shell中的变量默认都是字符串
>
> 使用$(( )) 用于算术计算
>
> ​	$(( ))中的shell变量取值，将(默认是字符串)转换成整数，同样含义的$[]等价
>
> ​	只能用于整数简单计算+-*/

### test.sh 05

```shell
#!/bin/bash
var=45
echo $((var+3))  
echo $(($var-3)) # 最里面的$加不加都可以，没影响
echo $[var/3]
echo $[$var*3]
echo $[$var%10]

# 进制转换
# 以8进制来解析10   最后是10进制的8  ： 结果是10进制的19
echo $[8#10+11]
```

## 3.6 转义字符
```shell
#在shell中都是使用 \ 作为转义字符

#两层含义
#    普通的字符转特殊字符
        \r \n \t
#    特殊的字符转普通字符
        \$SHELL
        
[root@lwh testShell]# echo \$SHELL
$SHELL
[root@lwh testShell]# echo \\
\

[root@lwh testShell]# echo "abc\tABC"
abc\tABC
[root@lwh testShell]# echo -e "abc\tABC" # 加上-e就会转义了
abc	ABC
```

## 3.7 引号
```shell
# 单引号和双引号都是为了保持字符串的字面值
# 区别在于：双引号允许 变量扩展

echo 'hello $SHELL' #作为字面值
echo "hello $SHELL" #允许取变量的值

[root@lwh testShell]# echo 'hello $SHELL'
hello $SHELL
[root@lwh testShell]# echo "hello $SHELL"
hello /bin/bash
```


```shell
# 如果变量是作为一个单一参数来使用：使用变量的时候加上双引号！！！
# 预防这些空格导致其他错误的操作
    var="a b"
    touch $var  
    touch "$var"
    rm $var
```

```shell
#!/bin/bash
var="G A"
touch ${var}.txt # 不加""时，直接替换过来，创建了两个文件，分别是A.txt和G
curPath=$(cd `dirname $0`;pwd)
ls ${curPath}

 
[root@lwh testShell]# ./test.sh 
A.txt  G  test.sh

```

```shell
#!/bin/bash
var="G A"
touch "${var}".txt # 加""时，创建了一个文件 G A.txt 
                   # 文件的名字中间有一个空格，规范做法是名字中不要有空格
curPath=$(cd `dirname $0`;pwd)
ls ${curPath}


[root@lwh testShell]# ./test.sh 
G A.txt  test.sh
```

# 四、shell脚本语法    

## 1.条件测试

### 1.1 真假

    shell中如何表示真假
    
    shell里以命令的返回结果来判断真假
        	成功返回0                真
        	失败返回非0              假
    		
    		跟C语言数值判断相反

```
如何获取一条命令的返回值 ，使用一个特殊变量 $? ，会动态存储上一条指令的退出状态(返回值) 
	echo $?
```

### 1.2 条件测试

```
条件测试
    1、test  用来测试条件真假  ， 以退出状态返回
    	Shell中的 test 命令用于检查某个条件是否成立，它可以进行数值、字符和文件三个方面的测试。
    2、[ ]   中括号跟 test 一致  ( /usr/bin/[ )
        使用[ 的测试需要以 ] 结束
        注意，以中括号来进行测试的时候 中括号后要留空格
        	[ 3 -gt 2 ]
        	echo $?
```

- man test 可以查看到以下的内容

| 表达式/参数                | 说明                                                         |
| -------------------------- | ------------------------------------------------------------ |
| ( EXPRESSION )             | 判断 expression 真假                                         |
| ! EXPRESSION               | 判断 expression 为假   ，跟C一样，取反                       |
| EXPRESSION1 -a EXPRESSION2 | 逻辑与，两个条件都为真,才为真  <br />相当于：&&              |
| EXPRESSION1 -o EXPRESSION2 | 逻辑或 ， 两个表达式至少有一个为真 <br /> 相当于：\|\|       |
| -n STRING                  | 判断字符串：不为空串 <br />    为空串，返回非零值，即为假<br />    不是空串，返回0，即为真 |
| -z STRING                  | 判断字符串：为空串<br />    跟 -n 相反                       |
| STRING1 = STRING2          | 判断两个字符串相等                                           |
| STRING1 != STRING2         | 判断两个字符串不等                                           |
| INTEGER1 -eq INTEGER2      | 判断两个整数相等                                             |
| INTEGER1 -ge INTEGER2      | INTEGER1 >= INTEGER2                                         |
| INTEGER1 -gt INTEGER2      | INTEGER1 > INTEGER2                                          |
| INTEGER1 -le INTEGER2      | INTEGER1 <= INTEGER2                                         |
| INTEGER1 -lt INTEGER2      | INTEGER1 < INTEGER2                                          |
| INTEGER1 -ne INTEGER2      | INTEGER1 != INTEGER2                                         |
| 文件判断                   |                                                              |
| FILE1 -nt FILE2            | FILE1 is newer (modification date) than FILE2<br/>文件1 修改时间 比文件2修改时间要新 |
| FILE1 -ot FILE2            | FILE1 is older than FILE2<br/>跟 -nt 相反                    |
| -b FILE                    | FILE exists and is block special<br/>判断文件是不是一个：块设备 |
| -c FILE                    | FILE exists and is character special<br/>判断文件是不是一个：字符设备 |
| -d FILE                    | FILE exists and is a directory<br/>判断文件是不是一个：目录  |
| -e FILE                    | FILE exists<br/>判断文件：是否存在，不管文件是什么类型       |
| -f FILE                    | FILE exists and is a regular file<br/>判断文件：是一个普通的文件 |
| -g FILE                    | FILE exists and is set-group-ID<br />判断文件：是否被设置了组ID |
| -h FILE                    | FILE exists and is a symbolic link (same as -L)              |
| -L FILE                    | FILE exists and is a symbolic link (same as -h)<br/> 判断文件是一个符号链接 |
| -k FILE                    | FILE exists and has its sticky bit set<br/>判断文件设置了黏着位 |
| -p FILE                    | FILE exists and is a named pipe<br/>命名管道                 |
| -r FILE                    | FILE exists and read permission is granted<br/>文件是否相对于当前用户有读权限 |
| -w FILE                    | FILE exists and write permission is granted<br/>文件是否相对于当前用户有写权限 |
| -x FILE                    | FILE exists and execute (or search) permission is granted<br/>文件是否相对于当前用户有执行权限 |
| -s FILE                    | FILE exists and has a size greater than zero<br/>判断文件不为空 ，文件大小大于0 |
| -S FILE                    | FILE exists and is a socket<br/>判断是否是一个socket文件     |

## 2.分支结构

### 2.1 if/then/elif/then/else/fi

    if 命令|条件测试
    then
        ...... #条件为真的时候执行的语句
        
    elif 命令2|条件测试2  ; then      #if和then写在同一行时要加分号
        .......
    else                            #else不需要加then
        ......
    fi

#### Demo1 test.sh

```shell
#!/bin/bash
if test 3 -gt 2
then 
    echo "3>2"
else
    echo "3<=2"
fi
```

```shell
[root@lwh testshell]# ./test.sh 
3>2
```

#### Demo2 test.sh

特殊的常量命令

```
特殊的常量命令
    :     空指令，返回结果总是真
    true  返回结果总是真，不做任何事情 
    false 返回结果总是假,不做任何事情
```

```shell
#!/bin/bash
target=/home

#if [ -d "$target" ]
if test -d "$target"
then
    echo "$target is a directory"
else 
    echo "$target is not a directory"
fi

if :
then
    echo ": Always true"
else
    echo ": Always false"
fi

if false
then
    echo "false Always true"
else
    echo "false Always false"
fi
```

```shell
[root@lwh testshell]# ./test.sh 
/home is a file
: Always true
false Always false
```

#### Demo3 read.sh

- 从标准输入读取内容

```
shell中：从标准输入读取内容 ，存储到变量中
	read 变量名 

&& 类似C语言中的&& ，表示并且的意思
	[ $a -eq 10 ] && [ $b -eq 20 ] 
	可以多个条件测试表示逻辑与，同时具备短路特性

	短路特性的应用：
		第一条语句执行结果为真，才去执行第二条语句
    	make && sudo make install

|| 类似C语言的|| ，表示多条语句的逻辑或，也具备短路特性
	rm 1.txt || echo "error"
	# rm 1.txt   执行成功就不会 输出error；执行失败 就会输出error
```



```shell
#!/bin/bash

echo "Is it morning? please answer [yes/no]"

read YES_OR_NO #从标准输入中读取字符串存储到变量中

if [ "$YES_OR_NO" = "yes" ]
then
    echo "Good morning!"
elif [ "$YES_OR_NO" = "no" ]
then 
    echo "Good afternoon!"
else
    echo "$YES_OR_NO not recognize,please answer yes or no"
fi



a=10
b=301

if [ $a -eq 10 ] && [ $b -eq 30 ]
then    
    echo "皆相等"
else    
    echo "不等"
fi
```

```shell
[root@lwh testshell]# ./testshell.sh 
Is it morning? please answer [yes/no]
yes
Good morning!
不等
[root@lwh testshell]# 
```



### 2.2 case/esac 


```c
// C语言中的 switch 语句
switch(expression)
{
    case val1:
        ....
        break;
    case val2:
        ....
        break;
    default:
        .....
        break;
}
```


    case 表达式 in
        值1|模式1..)
            匹配后的动作.....
            ;;              #两个分号类似C中的break
        值2|模式2..)
            匹配后的动作....
            ;;
        *)                  # * 能匹配任意字符，所以作为最后的匹配模式表示default
            .....
            ;;
    esac

#### Demo1 test.sh

```shell
#!/bin/bash
echo "Is it morning? please answer [yes/no]"
read YES_OR_NO #从标准输入中读取字符串存储到变量中

case "$YES_OR_NO" in
    [Yy] | [Yy][Ee][Ss])
        echo "Good morning!"
        ;;
    [Nn] | [Nn][Oo])
        echo "Good afternoon!"
        ;;
    *)
        echo "$YES_OR_NO not recognize,please answer yes or no"
        ;;
esac
```

```shell
[root@lwh testshell]# ./test.sh 
Is it morning? please answer [yes/no]
YeS
Good morning!
```

## 3. 循环

### 3.1 for/do/done

```shell
# 语法
for 变量名 in 参数1 参数2 .... # 相当于对集合中的元素进行遍历
do     # 如果do跟for写在同一行，要添加;
    .. # 每次循环  对应的变量的值是不一样的
done
```


```shell
# 遍历目录
for f in $(ls) ....

# 固定次数的循环遍历
for i in {1..100}  ....
```

#### Demo1 test.sh

```shell
#!/bin/bash

for fruit in apple banana pear
do
    echo "I like $fruit"
done

for f in `ls`
do 
    if [ -f "$f" ]
    then 
        echo "$f is a regular file"
    elif [ -d "$f" ]
    then 
        echo "$f is a directory"
    fi
done 

sum=0
for i in {1..100}
do  
    sum=$(($sum+$i)) # sum=$[$sum+$i]
done 
echo $sum

```

```shell
[root@lwh testshell]# ./testshell.sh 
I like apple
I like banana
I like pear
main.c is a regular file
testshell.sh is a regular file
5050
```

### 3.2 while/do

    while 命令|条件测试
    do
        ........
    done


​    
​    break 和 continue 
​        也跟c语言中的 break 和 continue 一致

#### Demo1 test.sh

```shell
#!/bin/bash
echo "Input password"
read Input
count=1
while [ "$Input" != "secret" ]
do  
    if [ "$count" -gt 4 ]
    then
        echo "Fail $count times , exit "
    fi 

    echo "Please try again"
    read Input
    count=$[$count+1]
done
```

```shell
[root@lwh testshell]# ./testshell.sh 
Input password
a
Please try again
b
Please try again
c
Please try again
d
Please try again
f
Fail 5 times , exit 
Please try again
secret
```

## 4. 位置参数和特殊变量

```
$0          相当于C语言main函数的argv[0]
$1、$2...    这些称为位置参数（Positional Parameter），相当于C语言main函数的argv[1]、argv[2]...
$#          相当于C语言main函数的argc-1(即实际参数的个数)，注意这里的#后面不表示注释
$@          表示参数列表"$1" "$2" ...，例如可以用在for循环中的in后面。
$*          表示参数列表"$1" "$2" ...，同上
$?          上一条命令的Exit Status
$$          当前进程号

参数左移 shift n # 把参数列表左移n

./test.sh 1 2 3 4 5 6

shift 之后 参数的排列等同于 ，最左边的参数被移走
./test.sh 2 3 4 5 6

shift 对于操作不定参数比较常见

例子：写一个脚本 add.sh  加法计算器，将参数中所有整数都相加
```

#### Demo1 test.sh

```shell
#!/bin/bash

echo "============================"
echo '$0:'$0
echo '$1:'$1
echo '$2:'$2
echo '$3:'$3
echo '$4:'$4
echo '$5:'$5
echo '$6:'$6
echo '$#:'$#
echo '$@:'$@
echo '$*:'$*
echo '$$:'$$
echo "============================"
shift
echo '$0:'$0
echo '$1:'$1
echo '$2:'$2
echo '$3:'$3
echo '$4:'$4
echo '$5:'$5
echo '$6:'$6
echo '$#:'$#
echo '$@:'$@
echo '$*:'$*
echo '$$:'$$
echo "============================"
```

```shell
[root@lwh testshell]# ./test.sh  1 2 3 4 5 6 7 8 9 10 11
============================
$0:./testshell.sh
$1:1
$2:2
$3:3
$4:4
$5:5
$6:6
$#:11
$@:1 2 3 4 5 6 7 8 9 10 11
$*:1 2 3 4 5 6 7 8 9 10 11
$$:52522
============================
$0:./testshell.sh
$1:2
$2:3
$3:4
$4:5
$5:6
$6:7
$#:10
$@:2 3 4 5 6 7 8 9 10 11
$*:2 3 4 5 6 7 8 9 10 11
$$:52522
============================
[root@lwh testshell]# 
```

#### Demo2 add.sh

```shell
#!/bin/bash
sum=0
# for i in $@
# do 
#     sum=$[$sum+$i]
# done
# echo $sum

while [ -n "$1" ]
do
    sum=$(( $sum + $1 ))
    echo $@
    shift 1
done
echo $sum
```

```shell
[root@lwh testshell]# ./add.sh  1 2 3
1 2 3
2 3
3
6
```

## 5. 输入输出

### 1. echo、printf

```
输入：read

输出1：echo [option] string
    -e 解析转义字符
    -n 不回车换行。默认情况echo回显的内容后面跟一个回车换行。
    echo "hello\n\n"
    echo -e "hello\n\n"
    echo "hello"

printf 格式字符串  参数1 参数2 ..
    跟C语言的printf一致
```

#### Demo test.sh

```shell
#!/bin/bash

echo -n "abc" # 不换行
echo  "123"   # 换行
echo "def"    # 换行
echo "123"    # 换行

echo -n -e "abc\tdef\n" # -e 转义

printf "hijklmn%sopq%drst\n" "AAAAAAAA" 123123123123
```

```shell
[root@lwh testshell]# ./test.sh 
abc123
def
123
abc     def
hijklmnAAAAAAAAopq123123123123rst
```

### 2. 管道 

#### 1. \|

    pipe
    	命令1 | 命令2 ....
    
    竖线的作用
    	将前面进程的标准输出重定向到后面进程的标准输入
    	注意：正常情况下，标准错误输出是不会重定向的


    more
        提供对文本的滚动操作
        回车单行滚动，空格翻页
    
    	# cat /var/log/anaconda/syslog | more

```shell
less 命令
	也跟more差不多，支持更多类似于vim的操作：能够进行查找，回滚...
	# cat /var/log/anaconda/syslog | less
```

##### Demo main.c

```c
//从标准输入读取内容，转化为大写再输出

#include <stdio.h>
#include <ctype.h>
int main()
{
    int c = getchar();
    while (c != EOF)
    {
        putchar(toupper(c));
        c = getchar();
    }

    return 0;
}

/*

[root@lwh testcpp]# ./out 
asdfgasdgadsfg
ASDFGASDGADSFG
skjshfdgsadkjfhgkjsahdg
SKJSHFDGSADKJFHGKJSAHDG
^C
[root@lwh testcpp]# 

*/
```

#### 2. sort

```shell
从标准输入中读取数据然后按照字符串内容进行排序
	-f 忽略字符大小写
	-n 比较数值大小
	-t 指定分割符，默认是空格或者tab
	-k 指定分割后进行比较字段
	-u 重复的行只显示一次
	-r 反向排序
	-R 打乱顺序
```

```shell
cat test.txt | sort	默认是升序
sort < test.txt		默认是升序
 
sort -k2 < test.txt 	根据第二列进行排序，默认是当成字符串
sort -n -k2 < test.txt 	根据第二列进行排序，如果第二列是数字，要指定按照数字大小进行排序

sort -u -n -k2 < test.txt	重复的行只显示一次

sort -r -n -k2 < test.txt	降序排序

sort -R < test.txt	打乱顺序(洗牌)
```

```shell
sort -t: -n -k3 < /etc/passwd	指定分隔符是: 按第三列的数字进行排序   
```

#### 3. uniq

```shell
去除重复的行,前提是重复的行连续
	-c 显示每行重复的次数
    -d 仅显示重复过的行
    -u 仅显示不曾重复的行
     
cat test.txt | sort | uniq
cat test.txt | sort | uniq -c	并在每行，显示重复的次数
	
sort < test.txt | uniq
```

#### 4. wc

```shell
wc：word countter 
    -l 统计行数
	-c 统计字节数
	-w 统计单词数

wc -l < test.txt	计算代码行数
wc -w < test.txt	统计单词数，以空格作为分隔
wc -c < test.txt	统计字节数
wc < test.txt		相当于指定了 -l -w -c 

wc -l *.c *.h *.cpp	统计写了多少行代码
```



### 3. tee命令

    命令 | tee [-a] 文件名
    
    读取标准输入的内容，也原样输出到标准输出，同时存一份到文件
    
        ex: 运行游戏服务器，日志一下就刷屏，使用tee命令，来进行跟踪，同时将日志存到一个文件里边，如果
        错过了什么重要的日志可以查看文件
    
        -a 
            以追加的方式来打开文件，默认是直接覆盖

```bash
# 利用 2 管道编程Demo main.c  的out 测试tee
[root@lwh testcpp]# cat test4.cpp | ./out | tee testToUpper.c 
#INCLUDE <STDIO.H>
#INCLUDE <CTYPE.H>
INT MAIN()
{
    INT C = GETCHAR();
    WHILE (C != EOF)
    {
        PUTCHAR(TOUPPER(C));
        C = GETCHAR();
    }

    RETURN 0;
}[root@lwh testcpp]# 
[root@lwh testcpp]# cat testToUpper.c 
#INCLUDE <STDIO.H>
#INCLUDE <CTYPE.H>
INT MAIN()
{
    INT C = GETCHAR();
    WHILE (C != EOF)
    {
        PUTCHAR(TOUPPER(C));
        C = GETCHAR();
    }

    RETURN 0;
[root@lwh testcpp]# 
```



### 4. 文件重定向



    cmd > file          把标准输出重定向到新文件中
    cmd >> file         追加
    cmd >file 2>file2	标准输出重定向到file 标准错误输出重定向到file2
    	0 标准输入
        1 标准输出
        2 标准错误输出
        
    cmd > file 2>&1     标准输出重定向到file 标准出错也重定向到1所指向的file里
        2>&1  
        	文件描述符2也重定向到文件描述符1的位置
            标准错误输出也重定向到标准输出的位置
    cmd >> file 2>&1
    cmd < file1         输入重定向到文件里
        将file1 读取处理扔到命令的标准输入
        
    cmd < &fd           把文件描述符fd作为标准输入
        很少用
        
    cmd > &fd           把文件描述符fd作为标准输出
    
    cmd < &-            关闭标准输入

```c
#include <stdio.h>
int main()
{
    fprintf(stdout, "this is stdout\n");
    fprintf(stderr, "this is stderr\n");
    return 0;
}

/*
[root@lwh testcpp]# ./out > stdout.txt
this is stderr
[root@lwh testcpp]# cat stdout.txt 
this is stdout
[root@lwh testcpp]# 
    
[root@lwh testcpp]# ./out > stdout.txt 2>stderr.txt
[root@lwh testcpp]# cat stdout.txt 
this is stdout
[root@lwh testcpp]# cat stderr.txt 
this is stderr
[root@lwh testcpp]# 
*/
```



## 6. 函数

```shell
function 函数名()    #括号中没有形参列表
{
    xxxxxxx
    local var=xxx   #局部变量
    return 0
}

函数的定义中，function 或者小括号 可以省略，但最多只能省一个

在function中使用 local 定义局部变量

return 只能返回整数，作为该函数的退出状态 
    如果没有return语句，函数默认的退出状态就是最后一条命令执行的退出状态
    
    如果想返回字符串，
    	函数内部使用echo输出字符串
    	调用函数时使用命令代换(` `)的形式来获取字符串  

函数的调用，当做一个普通命令来调用
    函数名  参数1 参数2 参数3 ....
    函数中通过$1 $2.. 来获取函数的参数

```

```shell
#!/bin/bash

function testfunc1
{
    local var=111
    echo "$1 $2 $3"
    echo "局部变量 $var"
    echo "这是一个返回值"
    return 100
}

testfunc1 1 2 3
echo $? # 函数返回值
echo 


# 拿到 函数返回的字符串
function testfunc2
{
    local var=111
    echo "这是一个返回值"
    return 100
}
ret=`testfunc2 1 2 3`
echo "函数返回值：$ret"
echo $?



[root@lwh testcpp]# ./shell.sh 
1 2 3
局部变量 111
这是一个返回值
100

函数返回值：这是一个返回值
0
[root@lwh testcpp]# 
```




    作业：
        需求：遍历当前目录的所有文件，还要同时遍历子目录中的文件
        注意：函数支持递归
        		是普通文件就 xxx is a file
                是目录 就输出 xxx is a directory
           

```shell
#!/bin/bash
#遍历当前目录，包括子目录

function visit
{
    local dir="$1" 
    for f in $(ls "$dir")
    do
        if [ -f "$dir/$f" ]
        then
            echo "$dir/$f is a file"
        elif [ -d "$dir/$f" ]
        then
            echo "$dir/$f is a directory"
            visit "$dir/$f"
        else
            echo "$dir/$f not recognized"
        fi
    done
}

visit .
```

# 五、shell脚本的调试方法

```shell
-n 读一遍脚本，但是不执行，只是查看是否有语法错误

-v 一边执行一遍输出读到的脚本

-x 最常用的 ，执行的过程中输出执行的语句，包括变量的值也会输出出来
    输出的信息 
    + 表示当前进程的调试信息，
    如果有多个++ 表示开启了子进程

启动调试的方法
    1 bash -x test.sh

    2 在脚本的第一句话开启  #!/bin/bash -x

    3 在脚本中
        set -x   #开启调试
            .....  一段代码
        set +x   #关闭调试
```

# 六、正则表达式

## 1. 基础练习(14题)
```shell
1 以S开头的字符串

    使用^表示字符串的开头匹配
    ^S
```

```shell
2 以数字结尾的字符串

    匹配一个数字
        [0123456789]    将所有数字枚举出来，使用中括号括起来表示匹配其中字符的一次出现
        [0-9]           同上，是一个区间的形式
        \d              同上
    
    匹配字符串结束 $

    [0-9]$
```

```shell
3 匹配空字符串(没有任何字符)
    
    ^$
```

```shell
4 字符串只包含三个数字
    
    ^\d\d\d$

    ^[0-9]{3}$
        {n} 表示前面的单元重复n次
```

```shell
5 字符串只有3到5个字母
    
    {m,n}   m表示前面单元最少重复次数，n表示最多重复次数

    匹配字母
    [a-zA-Z]    多个区间之间不要留空格

    ^[a-zA-Z]{3,5}$
```

```shell
6 匹配不是a-z的任意字符
    
    [^a-z]   中括号中第一个字符是^，表示区间取反
```


```shell
7 字符串有0到1个数字或者字母或者下划线
    
    [0-9a-zA-Z_]	数字或者字母或者下划线
    \w           	同上
    
    ^\w{0,1}$	{0,1}表示前面的单元重复 0-1次
    ^\w?$		? 表示前面的单元重复 0-1次 等同于 {0,1}
```


```shell
8 字符串有1个或多个空白符号(\t\n\r等)
    
    \s   		代替这些空白字符 
    ^\s{1,}$	{1,}  表示前面的单元重复1-n次
    ^\s+$		+ 等同于 {1,}  表示前面的单元重复1-n次
```


```shell
9 字符串有0个或者若干个任意字符(除了\n)
    
    .   表示除了\n 的任意字符
    ^.*$
        * 表示前面的单元重复0-n次

```


```shell
        ?    0-1
    	+    1-n
    	*    0-n
```


```shell
10 匹配0或任意多组ABC，比如ABC，ABCABCABC

    将ABC组合成为一个单元,使用小括号
    ^(ABC)*$
```


```shell
11 字符串要么是ABC，要么是123

    选择关系使用 | ，表示左右两边的正则做选择，要么匹配

    ^ABC|123$
        这样写是错的，这样写就会变成要么ABC开头，要么123结束

    ^ABC$|^123$
    ^(ABC|123)$   小括号能够限制竖线选择范围
```


```shell
12 字符串只有一个点号
    
    ^.$   错误，因为.表示除了\n 的任意字符
    .号是特殊字符，要考虑转义 , 使用\

    ^\.$
```

```shell
13 匹配十进制3位整数
    100-999

    ^[1-9][0-9][0-9]$
    
        0-999       排除011这类
        分段
            1位数
                ^[0-9]$
            2位数
                10-99
                ^[1-9][0-9]$
       	 	将以上3段连在一起，做选择
        		^([0-9]|[1-9][0-9]{1,2})$
```


```shell
14 匹配0-255的整数
    常用于匹配用户输入的ip地址
    分段
        1位数
            ^[0-9]$
        2位数
            10-99
            ^[1-9][0-9]$
        3位数
            100-255

            继续分段
                100-199
                    1[0-9]{2}

                200-249
                    2[0-4][0-9]

                250-255
                    25[0-5]

    匹配端口号 0-65535
    	
```



## 2. 正则的分类


    基础正则 basic
        ?+{}|()   是普通字符，要表示特殊含义时需要加\
    
    扩展的正则 extended
        ?+{}|()   是特殊字符,使用时直接使用即可表示特殊含义
    
    perl正则 
        目前我们学习的，也是编程中最常用
        建立在扩展正则之上，添加了一堆特殊字符
            \s \d \w ....



# 七、grep

```shell
grep：global regular expression print 全局正则表达式打印
egrep = grep -E
fgrep = grep -F
rgrep = grep -r

-c 只输出匹配行的计数
-i 不区分大小写
-H 文件名显示
-n 显示行号
-s 不显示不存在或无匹配文本的错误信息
-v 显示不包含匹配文本的所有行，这个参数经常用于过滤不想显示的行
    反选
-E 使用扩展的正则表达(grep正常情况下是使用basic正则)

-P 使用perl的正则表达式

-F 固定字符串匹配，不会将字符串当做正则表达式来解析

-r 递归、同时搜索目录

cat nginxAccess.log | grep 404	
cat nginxAccess.log | grep 404 -n 显示行号
cat nginxAccess.log | grep 404 -n --color 显示颜色
cat nginxAccess.log | grep 404 -c 统计行数

cat nginxAccess.log | grep -P "group\d/M\d{2}" -n --color	使用正则表达式，匹配字符串

grep -r -H -n "function" .	当前目录下哪些文件的第几行调用了这个函数


```



# 八、find
```shell
find pathname -options [-print -exec -ok ...]
	ex: find . -name "aaa"
```

```shell
    pathname: find命令所查找的目录路径。
    	例如用.来表示当前目录，
    	用/来表示系统根目录，递归查找。
```

```shell
	-options
		
		-name 按照文件名查找文件。
			find . -name "*.cpp"
			
        -perm 按照文件权限来查找文件。
            find . -perm 777
        
        -user 按照文件属主来查找文件。
        -group 按照文件所属的组来查找文件。
        
        -mtime -n +n 按照文件的更改时间来查找文件，
        	-n表示文件更改时间距现在n天以内，
            +n表示文件更改时间距现在n天以前。
            find命令还有-atime和-ctime 选项，但它们都和-m time选项。

        -nogroup 查找无有效所属组的文件，即该文件所属的组在/etc/groups中不存在。
        -nouser 查找无有效属主的文件，即该文件的属主在/etc/passwd中不存在。
        -newer file1 ! file2 查找更改时间比文件file1新但比文件file2旧的文件。
        
        -type 查找某一类型的文件，诸如 ：
            b - 块设备文件。
            d - 目录。
            c - 字符设备文件。
            p - 管道文件。
            l - 符号链接文件。
            f - 普通文件。
            s - socket 文件
            find . -type d
            find . -type s

        -size n：[c] 查找文件长度为n块的文件，带有c时表示文件长度以字节计。
        	find . -size 91c 文件大小为91字节
        	
        -depth 在查找文件时，首先查找当前目录中的文件，然后再在其子目录中查找。
        -fstype 查找位于某一类型文件系统中的文件，这些文件系统类型通常可以在配置文件/etc/fstab中找到，该配置文件中包含了本系统中有关文件系统的信息。
        -mount 在查找文件时不跨越文件系统mount点。
        -follow 如果find命令遇到符号链接文件，就跟踪至链接所指向的文件。
```

```shell
    -print： find命令将匹配的文件输出到标准输出。
```

```shell
    -exec： find命令对匹配的文件执行该参数所给出的shell命令。相应命令的形式为'command' {} \;
        注意{}内部无空格，和\；之间含有一个空格分隔符。

        find . -name "*.txt" -exec mv {} {}.png \;
            查找当前目录的txt文件，然后将txt文件添加一个后缀.png
            (1.txt-->1.txt.png)

        -exec 就是每次找到文件之后要执行什么命令
            mv {} {}.png        
            	这里的花括号是会被找到的文件名替换的
           	 	如：mv 6.txt 6.txt.png    
            \; 表示该命令的结束 反斜杠不能省略
            
        find . -name "*.png" -exec rm{} \;
        	删除当前目录下的.png文件
            
    -ok： 和-exec的作用相同，
           只不过以一种更为安全的模式来执行该参数所给出的shell命令，
           在执行每一个命令之前，都会给出提示，让用户来确定是否执行。
           只有用户明确输入y才会执行后边的语句
```



## xargs

```shell
主要作用就是将标准输入读取到的参数排成一行
主要是配合其他命令来使用
    test.txt 里边有 aa bb
	cat test.txt | xargs touch 
    	最终xargs会将 aa bb 两个参数排成一行，跟到touch后面
        	touch aa bb
    cat test.txt | xargs rm
    	删除文件
    	
        docker ps -aq | xargs docker rm -f 
        	docker ps -aq 显示所有容器ID
        	删除所有的docker容器

    xargs 可以指定替换字符串
    find . -name "*.txt" | xargs -I{} mv {} b 把当前目录下的txt移动到b/
        -I{}  表示指定替换字符串是{}，之前标准输入的内容的参数将会替换后面命令的{}  
        {} 是替换后的字符串(此处是txt文件)    
```



# 九、sed(流编辑器)

```shell
sed(流编辑器)

文件内容 ->  sed + 脚本  ->  文件内容2 

sed option 'script' file1 file2 ...             
	sed 参数  `脚本(/pattern/action)` 待处理文件
sed option -f scriptfile file1 file2 ...        
	sed 参数 –f `脚本文件` 待处理文件
	
    p,  print           打印
    a,  append          追加
    i,  insert          插入
    d,  delete          删除
    s,  substitution    替换
    
        sed '' test.txt			原样输出
        sed -n '2p' test.txt 	输出第二行（-n关闭正常输出）
        sed '2d' test.txt		删除第二行的内容
        sed '2,5d' test.txt
	
    /pattern/action    符合某个模式就执行什么动作
    	sed  '/123/p' test.txt   只要该行有123的就输出
    	sed  '/123/d' test.txt   只要该行有123的就删除
    	sed  '/123/i aaa' test.txt 	遇到123，就在前面插入一行aaa
    	sed  's/123/999/g' test.txt	遇到123就替换为999
		sed -i 's/123/999/g' test.txt 遇到123就替换为999，并修改源文件（慎用）
		
    sed 's/<[a-zA-Z/]*>//g' testfile 
        将html内容中的标签全部干掉
```



# 十、awk
```shell
awk是一个命令，也是一个脚本语言

    awk option 'script' file1 file2 ...
    awk option -f scriptfile file1 file2 ...
    
    	cat /etc/passwd | awk -F: '{print $1}'	
    	awk -F: '{print $1}'   /etc/passwd
   	 		提取passwd文件的第一列 ，以:作为分隔符   
   	 		注意：其中脚本要使用单引号（因为双引号还支持变量扩展）

awk脚本的语法内容
    {actions}
        每一行文本都无条件的执行某些动作
    /pattern/{actions}
        该行文本匹配了模式，就执行某些动作
    condition{actions}
        只要满足某个条件就执行某些动作
        有两个特殊条件

        BEGIN{actions} 在遍历文本第一行之前会执行的动
        END{actions}   在遍历文本最后一行之后会执行的动作   	 
```



***


```shell
awk '$2<75{print $1,$2}' testfile
	testfile文件内容如下
		ProductA 30
        ProductB 76
        ProductC 55
```

test.awk

```shell
如果库存量少于75 提示要重新订货
    $2<75 {
        print $1,$2,"reorder";
    }
    $2>=75 {
        print $1,$2;
    }
```

调用： awk -f test.awk testfile

***



```shell
使用BEGIN 和 END，
	实现：
		输出列名: 产品名 + 库存量，
		输出结果要显示库存总量

test.awk

    BEGIN{
        #输出表头
        printf("产品名\t库存\n");

        #定义一个变量，存储库存总量
        sum=0;
    }
    $2<75 {
        print $1,$2,"reorder";
    }
    $2>=75 {
        print $1,$2;
    }
    {
        sum+=$2;
    }
    END{
        printf("库存总量:%d\n",sum);
    }

awk -f test.awk testfile

awk是比较强大的工具，能够做一些数理统计等操作....
```



# 十一、C程序中使用正则表达式

C语言中一般不建议使用正则表达式

C语言中，即使用正则表达式也是使用pcre正则表达式

以下代码使用的是扩展正则表达式

```c
/*
regcomp	编译
regexec	执行
regfree 释放
*/
    
#include <sys/types.h>
#include <regex.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
    if (argc != 3) {
        printf("Usage: %s RegexString Text\n", argv[0]);
        return 1;
    }
    const char * pregexstr = argv[1]; // 正则表达式
    const char * ptext = argv[2];	  // 待匹配的文本
    
    regex_t oregex;	//创建一个正则表达式结构体变量
    int nerrcode = 0;
    char szerrmsg[1024] = {0};
    size_t unerrmsglen = 0;
    
    // REG_EXTENDED 使用的是扩展的正则表达式
    if ((nerrcode = regcomp(&oregex, pregexstr, REG_EXTENDED|REG_NOSUB)) == 0) 
    {
        if ((nerrcode = regexec(&oregex, ptext, 0, NULL, 0)) == 0)//匹配成功返回0
        {
            printf("%s matches %s\n", ptext, pregexstr);
            regfree(&oregex);
            return 0;
        }
    }
    
    //出错了的话：报错、并释放
    unerrmsglen = regerror(nerrcode, &oregex, szerrmsg, sizeof(szerrmsg));
    unerrmsglen = unerrmsglen < sizeof(szerrmsg) ? unerrmsglen : sizeof(szerrmsg)- 1;
    szerrmsg[unerrmsglen] = '\0';
    printf("ErrMsg: %s\n", szerrmsg);
    regfree(&oregex);

    return 1;
}
```