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