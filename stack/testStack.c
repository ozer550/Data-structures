/*
   
 Made By prathamesh desai 
 test  file for stack 
 
 Date-30/jul/20

 ALL RIGHTS RESERVED

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

int main()
{

	testNewStack();
	testPush();
	testpop();
	testIsEmpty();
	printf("ALL TESTS PASSED U R AWESOME !!!!!!!!\n");
}

void testNewStack()
{
	printf("testing newStack()\n");
	Stack new = newStack();
	assert(new != NULL);
	printf("test passed\n");
	free(new);
}

void testPush()
{
	printf("testing testPush()\n");
	Stack mystack = newStack();
	push('{', mystack);
	assert(printStack(mystack) == '{');
	push('}', mystack);
	assert(printStack(mystack) == '}');
	printf("test passed \n");
}

void testIsEmpty()
{
	//case 1 when empty
	printf("testing isEmpty()\n");
	Stack mystack3 = newStack();
	assert(isEmpty(mystack3) == 1);
	//case 2 not empty
	push('{', mystack3);
	assert(isEmpty(mystack3) != 1);
	push('{', mystack3);
	assert(isEmpty(mystack3) != 1);
	pop(mystack3);
	pop(mystack3);
	assert(isEmpty(mystack3) == 1);
	printf("test-passed\n");
	free(mystack3);
}

void testpop()
{
	printf("testing testPop()\n");
	Stack mystack2 = newStack();
	push('{', mystack2);
	push('}', mystack2);
	pop(mystack2);
	assert(printStack(mystack2) == '{');
	printf("test passed \n");
	free(mystack2);
}
