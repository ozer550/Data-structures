#This is makefile
.PHONY: clean 
testbst: testbst.o bst.o queue.o
	gcc -g -Wall bst.o queue.o testbst.o -o testbst

testbst.o: testbst.c bst.h queue.h
	gcc -g -Wall -c testbst.c

bst.o: bst.c bst.h queue.h
	gcc -g -Wall -c bst.c

queue.o: queue.c queue.h 
	gcc -g -Wall -c queue.c

clean:
	rm  testbst bst.o  testbst.o

