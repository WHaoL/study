#!/bin/bash
for fruit in apple banana pear
do
    echo "I like $fruit"
done

for f in `ls`
do 
    if [ -f "$f" ]
    then 
        echo "$f is a regular file"
    elif [ -d "$f" ]
    then 
        echo "$f is a directory"
    fi
done 

sum=0
for i in {1..100}
do  
    sum=$(($sum+$i)) # sum=$[$sum+$i]
done 
echo $sum
