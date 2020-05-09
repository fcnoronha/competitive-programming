#!/bin/bash

# The first argument used when calling this script will be the number of files
# created

# Generate copies of the template with the associeted chars

alfabeto="abcdefghijklmnopqrstuv"
for ((T=0, C='a'; T<$1; T=T+1))
do
    cp template.cpp ToDo/"${alfabeto:$T:1}.cpp"
done
