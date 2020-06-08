#!/bin/bash

echo "Is it morning ? Plz answer [yes/no]"

#从标准输入中读取字符串存储到变量中
read YES_OR_NO

if [ "$YES_OR_NO" = "yes" ] ;then
    echo "Good morning!"
elif [ "$YES_OR_NO" = "no" ] ;then
    echo "Good afternoon!"
else
    echo "$YES_OR_NO not recgonized , plz answer yes or no"
fi


a=10
b=30

if [ $a -eq 10 ] && [ $b -eq 20 ]
then
    echo "Yes"
fi

