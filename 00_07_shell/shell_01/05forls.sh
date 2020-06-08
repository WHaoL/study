#!/bin/bash

for file in $(ls)
do 
    if [ -f "$file" ]
    then 
        echo "$file is a file"
    elif [-d "$file"]
    then
        echo "$file is a direction"
    fi
done
