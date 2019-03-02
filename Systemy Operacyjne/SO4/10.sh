#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Invalid number of arguments"
    exit
fi

if [ ! -f $1  ]
then
    echo "Invalid file path"
    exit
fi

touch "$1.srtd"
cat $1 | sort | cat -n > "$1.srtd"