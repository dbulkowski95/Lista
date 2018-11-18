CC = gcc
CFLAGS = -c -Wall -Wextra 

all: List

List: list.o ListTest.o
	$(CC) ListTest.o list.o -o MyList -lcriterion

ListTest.o: ListTest.c 
	$(CC) $(CFLAGS) ListTest.c -lcriterion

list.o: list.c 
	$(CC) $(CFLAGS) list.c

clean:
	rm -f *.out *o MyList
