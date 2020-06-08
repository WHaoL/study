#!/bin/bash
sum=0
#for i in $@
#do
#    sum=$[$sum+$i]
#done

while [ -n "$1" ]
do
    sum=$[$sum+$1]
    echo "$@"
    shift
done
echo $sum
