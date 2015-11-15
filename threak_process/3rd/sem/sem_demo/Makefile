##############################
# farsight's Makefile
# Write by StephenYee(StephenYee@farsight.com.cn)
#
##############################

#INSTALLROOT=$(PWD)


#CROSS_COMPILE = arm-linux-gnu-

CC = $(CROSS_COMPILE)gcc

ifdef CROSS_COMPILE
TARGET_FS_PATH = /opt/filesystem
endif

BINARY = sem_demo 

BIN_PATH =$(TARGET_FS_PATH)/root/long_term/ipc

INSTALL=install

#WARNINGS = -Wall \
#           -Wundef -Wpointer-arith -Wbad-function-cast \
#           -Wcast-align -Wwrite-strings -Wstrict-prototypes \
#           -Wmissing-prototypes -Wmissing-declarations \
#           -Wnested-externs -Winline -Wcast-qual -W \
#           -Wno-unused
#           -Wunused

CFLAGS= -O2 -DLINUX $(WARNINGS)

#LIBS= -lpthread


OBJ= ${patsubst %.c, %.o, ${wildcard *.c}}
		
all:$(BINARY)


$(BINARY):$(OBJ)
	$(CC) $(CFLAGS) -o $(BINARY) $(OBJ) $(LIBS)
	
%.o : %.c	
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: install uninstall clean dis

install: $(BINARY)
	$(INSTALL) -s -m 755 -g root -o root $(BINARY) $(BIN_PATH) 

uninstall :
ifdef CROSS_COMPILE
	cd  $(BIN_PATH) && rm -f $(PROGS)
endif

clean : uninstall
	- rm -f $(BINARY) *.o core *.gz

dist: clean
	tar czf farsight_ipc_sem_demo1.1.tar.gz *.h *.c Makefile

