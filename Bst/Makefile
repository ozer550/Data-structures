#This is makefile
.PHONY: clean 
testbst: testbst.o bst.o
	gcc -g -Wall bst.o testbst.o -o testbst

bst.o: bst.c bst.h
	gcc -g -Wall -c bst.c

testbst.o: testbst.c bst.h
	gcc -g -Wall -c testbst.c

clean:
	rm  testbst bst.o  testbst.o

