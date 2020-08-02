
#This is makefile
.PHONY: clean 
testStack: testStack.o stack.o
	gcc -g -Wall stack.o testStack.o -o testStack

stack.o: stack.c stack.h
	gcc -g -Wall -c stack.c

testStack.o: testStack.c stack.h
	gcc -g -Wall -c testStack.c

clean:
	rm  testStack stack.o  testStack.o

