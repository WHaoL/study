#!/bin/bash

echo "Input password"
read input
counter=1
while [ "$input" != "secret" ]
do
    if [ "$counter" -gt 4 ]
    then
        echo "Fails 5 times ,exit"
        break
    fi

    echo "Pease try again"
    read input
    counter=$[counter+1]
done
