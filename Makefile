all: main.o bst.o
	gcc main.o bst.o -o hw3

main.o: main.c
	gcc -g -c main.c

bst.o: bst.c bst.h
	gcc -g -c bst.c

clean:
	rm bst.o main.o
