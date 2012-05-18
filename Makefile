HEADERS = linkedlist.h vector.h
OBJS = linkedlist.o vector.o
CC = gcc
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
LDFLAGS=-L. -llwcl

liblwcl.a: $(OBJS)
	ar rcs liblwcl.a $(OBJS)

linkedlisttest: liblwcl.a
	$(CC) $(OPTS) linkedlisttest.c $(LDFLAGS) -o linkedlisttest
	
vectortest: liblwcl.a
	$(CC) $(OPTS) vectortest.c $(LDFLAGS) -o vectortest

linkedlist.o: linkedlist.h linkedlist.c
	$(CC) $(OPTS) -c linkedlist.c
	
vector.o: vector.h vector.c
	$(CC) $(OPTS) -c vector.c

clean:
	rm -f *test *.o *.a