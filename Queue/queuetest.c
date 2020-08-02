/*
   
 Made By prathamesh desai 
 test  file for queue
 
 Date-2/aug/20

 ALL RIGHTS RESERVED

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"

int main()
{
	testenq();
	testisempty();
	testdeq();
	printf("ALL TESTS PASSED U R AWESOME !!!!!!!!\n");
	return 0;
}

void testenq()
{
	printf("testing queue_enq fxn \n");
	Queue tstque = queue_crt();
	queue_enq(tstque, 1);
	assert(queue_front(tstque) == 1);
	queue_enq(tstque, 6);
	queue_show(tstque);
	queue_free(tstque);
	printf("test passed \n");
}

void testisempty()
{
	printf("testing isempty \n");
	Queue tstque = queue_crt();
	assert(queue_isempty(tstque) == 1);
	queue_enq(tstque, 1);
	assert(queue_isempty(tstque) == 0);
	queue_free(tstque);
	printf("test passed \n");
}

void testdeq()
{
	printf("testing deque \n");
	Queue tstque = queue_crt();
	queue_enq(tstque, 1);
	queue_deq(tstque);
	assert(queue_isempty(tstque) == 1);
	queue_enq(tstque, 2);
	queue_enq(tstque, 3);
	queue_show(tstque);
	queue_deq(tstque);
	queue_show(tstque);
	assert(queue_size(tstque) == 1);
	queue_enq(tstque, 6);
	queue_enq(tstque, 3);
	queue_enq(tstque, 2);
	queue_enq(tstque, 1);
	queue_show(tstque);
	queue_deq(tstque);
	queue_show(tstque);
	printf("test passed \n");
	queue_free(tstque);
}
