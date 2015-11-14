#!/usr/bin/python
val = input("Please input temperature:")
if val[-1] in ['C','c']:
	f=1.8 * float(val[0:-1]) + 32
	printf("The temperatures convert later is :%.2fF"%f)
elif val[-1] in ['F','f']:
	c = (float(val[0:-1])-32)/1.8
	print("The temperatures convert later is :%.2fC"%c)
else:
	print("Input error!")
