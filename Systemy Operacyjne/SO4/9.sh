#!/bin/bash
if [ $# -ne 1 ]
then
    echo "Invalid number of arguments"
    exit
fi

ls $1 | sort -r