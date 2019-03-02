#!/bin/bash
for FILE in `ls /home`
do
	if [ -n "$grep '$FILE' $FILE" ];
	then 
		echo "$FILE"
	fi
done
