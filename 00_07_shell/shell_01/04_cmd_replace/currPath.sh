#!/bin/bash

#推算脚本所在目录
#$0   main函数的argv[0]
#echo $0

#curPath=$(dirname $0)
curPath=$(cd `dirname $0` ; pwd )

echo "curPath:"$curPath

#通过ls 的方式列出当前脚本所在目录的所有文件
ls  $curPath
