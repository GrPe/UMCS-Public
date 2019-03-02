#!/bin/bash
min=125000000
filename='liczby'
while read num;
do
    if [ $num -lt $min ];
    then
        min=$num
    fi
done <$filename
echo $min