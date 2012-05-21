HEADERS = linkedlist.h vector.h tree.h
OBJS = linkedlist.o vector.o tree.o
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

treetest: liblwcl.a
	$(CC) $(OPTS) treetest.c $(LDFLAGS) -o treetest

linkedlist.o: linkedlist.h linkedlist.c
	$(CC) $(OPTS) -c linkedlist.c
	
vector.o: vector.h vector.c
	$(CC) $(OPTS) -c vector.c
	
tree.o: tree.h tree.c
	$(CC) $(OPTS) -c tree.c

clean:
	rm -f *test *.o *.a