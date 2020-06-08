#!/bin/bash
#父脚本
a="hello"
aa="world"

echo ${a}a


function testfun
{
    #以下b还是全局变量
    b="123"
    #c是局部变量
    local c="234"
}


#执行函数
testfun

echo b:$b
echo c:$c

export env_var="这是一个环境变量"

#调用子脚本
./test_sub.sh


#再次输出环境变量
echo "parentscript env_var:"$env_var

