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