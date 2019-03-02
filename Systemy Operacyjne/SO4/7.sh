#!/bin/bash
if [ "$#" -ne 1 ]
then
    echo "Invalid number of arguments"
    exit
fi

env | grep "^$1" | sort -r | tee "zmienne.txt"
