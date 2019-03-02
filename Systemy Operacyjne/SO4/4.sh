#!/bin/bash
sum=0
file='liczby'
while read num
do
    sum=$((sum + num))
done <$file
echo $sum