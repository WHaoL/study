#!/bin/bash
#遍历当前目录，包括子目录

function visit
{
    local dir="$1" 
    for f in $(ls "$dir")
    do
        if [ -f "$dir/$f" ]
        then
            echo "$dir/$f is a file"
        elif [ -d "$dir/$f" ]
        then
            echo "$dir/$f is a directory"
            visit "$dir/$f"
        else
            echo "$dir/$f not recognized"
        fi
    done
}

visit .
