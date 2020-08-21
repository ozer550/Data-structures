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
#include "queue.h"

int main()
{
	//testinsert();
	//testdfs();
	//testBpreOrder();
	//testBpostOrder();
	//testBinOrder();
	testBlevelorder();
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

void testdfs()
{
	printf("testing dfstest function\n");
	Bst sample = Bmaketree();
	Binsert(sample, 8);
	assert(Bdfs(sample, 8) != NULL);
	assert(Bdfs(sample, 4) == NULL);
	Binsert(sample, 3);
	Binsert(sample, 10);
	Binsert(sample, 1);
	Binsert(sample, 6);
	Binsert(sample, 14);

	assert(Bdfs(sample, 3) != NULL);
	assert(Bdfs(sample, 10) != NULL);
	assert(Bdfs(sample, 1) != NULL);
	assert(Bdfs(sample, 6) != NULL);
	assert(Bdfs(sample, 14) != NULL);
	assert(Bdfs(sample, 100) == NULL);

	printf("test passed\n");
}

void testBsum()
{
	printf("testing dfsSumfxn function\n");
	Bst sample = Bmaketree();
	Binsert(sample, 8);
	Binsert(sample, 3);
	Binsert(sample, 10);
	Binsert(sample, 1);
	Binsert(sample, 6);
	Binsert(sample, 14);
	assert(Bsum(sample) == 33);
	printf("test passed\n");
}

void testBpreOrder()
{
	printf("testing Bpreorder function\n");
	Bst sample = Bmaketree();
	Binsert(sample, 8);
	Binsert(sample, 3);
	Binsert(sample, 10);
	Binsert(sample, 1);
	Binsert(sample, 6);
	Binsert(sample, 14);
	Btraverse(sample, 'p');
	printf("test passed\n");
}

void testBpostOrder()
{
	printf("testing Bpreorder function\n");
	Bst sample = Bmaketree();
	Binsert(sample, 8);
	Binsert(sample, 3);
	Binsert(sample, 10);
	Binsert(sample, 1);
	Binsert(sample, 6);
	Binsert(sample, 14);
	Btraverse(sample, 'P');
	printf("test passed\n");
}

void testBinOrder()
{
	printf("testing Bpreorder function\n");
	Bst sample = Bmaketree();
	Binsert(sample, 8);
	Binsert(sample, 3);
	Binsert(sample, 10);
	Binsert(sample, 1);
	Binsert(sample, 6);
	Binsert(sample, 14);
	Btraverse(sample, 'i');
	printf("test passed\n");
}

void testBlevelorder()
{
	printf("testing levelorderfxn function\n");
	Bst sample = Bmaketree();
	Binsert(sample, 8);
	Binsert(sample, 3);
	Binsert(sample, 10);
	Binsert(sample, 1);
	Binsert(sample, 6);
	Binsert(sample, 14);
	Btraverse(sample, 'l');
	printf("test passed\n");
}
