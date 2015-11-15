CC = gcc
CFLAGS = -Wall -g -O0

test:test.c btree.c linkqueue.c seqstack.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) test .*.sw?
