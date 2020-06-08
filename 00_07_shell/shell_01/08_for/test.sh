#!/bin/bash

#for fruit in apple banana pear
#do
#    echo "I like $fruit"
#done

#需求，遍历当前目录，输出每个文件是 file 还是 directory
#for f in $(ls)
#do
#    if [ -f "$f" ]
#    then
#        echo "$f is a file"
#    elif [ -d "$f" ]
#    then
#        echo "$f is a directory"
#    fi
#done


sum=0
for i in {1..100}
do
    sum=$[$sum+$i]
done
echo $sum
