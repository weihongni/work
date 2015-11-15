#!/bin/bash
#unload Program to backup and remove files
#syntax: unload directory
#check arguments

if [ $# -ne 1 ]
then
	echo "usage: $0 <directory>"
	exit
fi
#check for valid directory name
if [ ! -d "$1" ]
then
	echo "$1 is not a directory"
	exit
fi

cd $1
ls -a | cpio -o > ./null
if [ $? -eq 0 ]
then
	rm -rf *
else
	echo "A problem has occured in creating backup"
	echo "The directory will not be ereased"
	echo "Please check the backup device"
	exit 3
fi
#end of unload
