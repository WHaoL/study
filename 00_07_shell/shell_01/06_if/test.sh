#!/bin/bash
target=/home

#if [ -d "$target" ]
if test -d "$target"
then
    echo "$target is a directory"
else 
    echo "$target is not a directory"
fi


if false
then
    echo "Always true"
else
    echo "Always false"
fi
