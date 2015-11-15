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

BINARY1 = read_mutex
BINARY2 = write_mutex 

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


#OBJ= ${patsubst %.c, %.o, ${wildcard *.c}}
OBJ1 = sem_com.o shm_read.o
OBJ2 = sem_com.o shm_write.o		
all:$(BINARY1) $(BINARY2)

$(BINARY1):$(OBJ1)
	$(CC) $(CFLAGS) -o $(BINARY1) $(OBJ1) $(LIBS)

$(BINARY2):$(OBJ2)
	$(CC) $(CFLAGS) -o $(BINARY2) $(OBJ2) $(LIBS)

	
#%.o : %.c	
#	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: install uninstall clean dis

install: $(BINARY1) $(BINARY2)
	$(INSTALL) -s -m 755 -g root -o root $(BINARY1) $(BINARY2) $(BIN_PATH) 

uninstall :
ifdef CROSS_COMPILE
	cd  $(BIN_PATH) && rm -f $(PROGS)
endif

clean : uninstall
	- rm -f $(BINARY1) $(BINARY2) *.o core *.gz

dist: clean
	tar czf ../farsight_ipc_sem_shm_mutex_demo_v1.0.tar.gz ../sem_shm_mutex

