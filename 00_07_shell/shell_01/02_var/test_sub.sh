#!/bin/bash
#子脚本

#输出父脚本的全局变量
echo "subscript a:"$a

echo "subscript env_var:"$env_var

#子进程修改环境变量
export env_var="子进程修改了的环境变量"
