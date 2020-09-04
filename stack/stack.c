/*
   
 Made By prathamesh desai 
 main  file for stack 
 
 Date-30/jul/20

 ALL RIGHTS RESERVED

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

#define MAX_SIZE 100

typedef struct stack
{
	char values[MAX_SIZE];
	int valueCount;

} mystack;

//Creates new stack and returns pointer to struct
Stack newStack(void)
{
	Stack new = malloc(sizeof(mystack));
	assert(new != NULL);
	new->valueCount = 0;
	return new;
}

//Pushes a char in the stack
void push(char brac, Stack stack)
{
	assert(stack != NULL);
	assert(stack->valueCount < MAX_SIZE);
	stack->values[stack->valueCount] = brac;
	stack->valueCount++;
}

//Pops element from stack and return it
char pop(Stack stack)
{
	assert(stack != NULL);
	assert(stack->valueCount != 0);
	assert(!isEmpty(stack));
	stack->valueCount--;
	return stack->values[stack->valueCount];
}

//Returns true if stack is empty and false if not
int isEmpty(Stack stack)
{
	assert(stack != NULL);
	return ((stack->valueCount) == 0);
}

//returns all the elements os stack
char printStack(Stack stack)
{
	assert(stack != NULL);
	return stack->values[stack->valueCount - 1];
}

//frees the heap
void freeStack(Stack stack)
{
	assert(stack != NULL);
	free(stack);
}
