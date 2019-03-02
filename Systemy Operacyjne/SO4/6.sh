#!/bin/bash
mkdir zdjecia
files=`find / -type f -name '*.jpg' -size 5k`
for i in $files
do
    cp $i zdjecia/
done