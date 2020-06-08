#!/bin/bash

var=45
echo $((var+3))
echo $(($var-3))
echo $[var/3]
echo $[$var*3]
echo $[$var%10]

#进制转换
echo $[8#10+11]
