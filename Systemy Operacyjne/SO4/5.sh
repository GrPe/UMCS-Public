#!/bin/bash
numOne=0
numTwo=1

case "$1" in
"1") echo 0 ;;
"2") echo 1 ;;
*)
    for ((i=1;i<$1;i++))
    do
        temp=$numOne
        numOne=$numTwo
        numTwo=$((numOne + temp))
    done
    echo $numTwo ;;
esac