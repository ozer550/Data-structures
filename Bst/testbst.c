/*
   
 Made By prathamesh desai 
 test  file for bst
 
 Date-2/aug/20

 ALL RIGHTS RESERVED

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bst.h"

int main()
{
	testinsert();
	printf("All test passed\n");
	return 0;
}

void testinsert()
{
	printf("testing testinsert function\n");
	Bst sample = Bmaketree();
	Binsert(sample, 3);
	assert(BisEmpty(sample) == 0);
	assert(Bsize(sample) == 1);
	Binsert(sample, 2);
	Binsert(sample, 4);
	Binsert(sample, 3);
	assert(Bsize(sample) == 4);
	printf("test passed\n");
}
