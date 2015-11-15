#!/bin/bash
#program2 for tput
#
bell=`tput bel`
s_uline=`tput smul`
e_uline=`tput rmul`
tput clear
tput cup 10 40
echo $bell $s_uline
echo "Computer Department"
echo $e_uline
