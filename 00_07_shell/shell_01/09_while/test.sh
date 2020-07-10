#!/bin/bash
echo "Input password"
read Input
count=1
while [ "$Input" != "secret" ]
do  
    if [ "$count" -gt 4 ]
    then
        echo "Fail $count times , exit "
    fi 

    echo "Please try again"
    read Input
    count=$[$count+1]
done