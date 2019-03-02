#!/bin/bash
max=0
filename='liczby'
filedata=`cat $filename`
for num in $filedata;
do
	if [ $max -lt $num ];
	then
		 max=$num
	fi
done
echo $max	
