#!/bin/bash

function testfunc
{
    local var=111
    #echo "$1 $2 $3"
    #echo "局部变量 $var"
    echo "这是一个返回值"
    return 100
}

testfunc 1 2 3
echo $?

ret=`testfunc 1 2 3`
echo "函数返回值：$ret"
