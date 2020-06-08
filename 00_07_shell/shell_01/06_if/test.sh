#!/bin/bash
target=/home

#if [ -f "$target" ]
if test -f "$target"
then
    echo "$target is a file"
else
    echo "$target is not a file"
fi


if false
then
    echo "Always true"
else
    echo "Always false"
fi
