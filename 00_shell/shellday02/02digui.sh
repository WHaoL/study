#!/bin/bash 

function digui
{
    local directiii="$1"
    for file in $( ls $directiii)
    do
        if [ -f $directiii/$file ];then
            echo "$directiii/$file 是普通文件"
        elif [ -d $directiii/$file ];then
            echo "$directiii/$file 是目录"
            digui "$directiii/$file"
        fi
    done

}
digui .
