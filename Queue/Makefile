#This is makefile
.PHONY: clean 
testqueue: queuetest.o queue.o
	gcc -g -Wall  -fsanitize=address -fno-omit-frame-pointer queue.o queuetest.o -o queuetest

queue.o: queue.c queue.h
	gcc -g -Wall -c queue.c

queuetest.o: queuetest.c queue.h
	gcc -g -Wall -c queuetest.c

clean:
	rm  queuetest queue.o  queuetest.o

