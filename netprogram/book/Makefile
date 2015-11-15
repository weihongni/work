CC = gcc
CFLAGS = -Wall -g -o
PROGS = ${patsubst %.c,%,${wildcard *.c}}
#从参数3中拿出一个*.c文件匹配参数1中的%.c变成参数2的%

all : $(PROGS)

% : %.c
	$(CC) $(CFLAGS) $@ $<	
clean :
	$(RM) $(PROGS) .*.sw? *.gz
dist : clean
	tar czvf ../network_thread.tar.gz ../book




# $* 不包含扩展名的目标文件
# $? 所有时间戳比目标文件晚的依赖文件，以空格分开
# $^ 所有不重复的目标依赖文件，以空格分开
# $@ 目标文件的完整名称 
# $< 第一个依赖文件名称
# $% 如果目标是归档成员，则表示目标的归档成员名称
# $+ 所有的依赖文件，以空格分开，以出现的先后为顺序，可能有重复
