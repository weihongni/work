# Makefile
#

#CROSS_COMPILE = arm-linux-gnu-

CC = $(CROSS_COMPILE)gcc

ifdef CROSS_COMPILE
TARGET = /opt/filesystem
endif


#DEBUG = -g -O0 -Wall
DEBUG = -g -O2
CFLAGS += $(DEBUG)

PROGS = ${patsubst %.c, %, ${wildcard *.c}} 

all : $(PROGS)

install: $(PROGS)
ifdef CROSS_COMPILE
	mkdir $(TARGET)/root/long_term/io -p
	cp $(PROGS) $(TARGET)/root/long_term/io -f
endif
% : %.c
	$(CC)  $(CFLAGS)  $< -o $@ -lpthread

.PHONY: uninstall clean dist

uninstall :
ifdef CROSS_COMPILE
	cd $(TARGET)/root/long_term/io && rm -f $(PROGS)
endif

clean : uninstall
	- rm -f $(PROGS) core *.gz

dist: clean
	tar czf ../farsight_select_demo_v0.2_for_1510.tar.gz ../select_demo
	
