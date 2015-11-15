#!/bin/bash

for i in `ls`
	do
	if [ -f $i ]
	then
		echo "$i is a file"
	elif [ -d $i ] 
	then
		echo "$i is a directory"
	fi
done
