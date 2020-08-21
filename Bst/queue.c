/*    
 Made By prathamesh desai
 main fxn file for queue adt
 
 Date-2/Aug/20

 ALL RIGHTS RESERVED
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <sysexits.h>

#include "queue.h"

#define TRUE 1
#define FALSE 0

typedef struct queue_node Nodeq;

//data structure representing queue
struct queue_node
{
	int item;	 //value of item
	Nodeq *next; // pointer to next node
};

struct queue
{
	Nodeq *first;
	Nodeq *last;
	int size;
};

//function to create a new node with item value
//fxn is private to this ADT
static Nodeq *newNode(int val)
{
	Nodeq *new = malloc(sizeof *new);
	if (new == NULL)
	{
		err(EX_OSERR, "couldn't allocate Nodeq");
	}
	new->item = val;
	new->next = NULL;
	return new;
}

//Creates a queue
Queue queue_crt(void)
{
	Queue newq = malloc(sizeof *newq);
	if (newq == NULL)
	{
		err(EX_OSERR, "couldn't allocate queue");
	}
	newq->first = NULL;
	newq->last = NULL;
	newq->size = 0;
	return newq;
}

//Returns true if empty else false
int queue_isempty(Queue queue)
{
	assert(queue != NULL);
	if (queue->size == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//Add item at end of the queue
void queue_enq(Queue queue, int item)
{
	assert(queue != NULL);
	//case-1:when queue is empty
	if (queue_isempty(queue))
	{
		Nodeq *head = newNode(item);
		queue->first = head;
		queue->last = head;
		queue->size++;
	} //when not empty
	else
	{
		Nodeq *temp = newNode(item);
		queue->last->next = temp;
		queue->last = temp;
		queue->size++;
	}
}

//Prints and returns first elemnt of queue
int queue_front(Queue queue)
{
	assert(queue != NULL);

	return queue->first->item;
}

//Returns and prints size of queue
int queue_size(Queue queue)
{
	assert(queue != NULL);
	printf("size of que is %d\n", queue->size);
	return queue->size;
}

//Prints elements of queue sequentially
void queue_show(Queue queue)
{
	Nodeq *curr = queue->first;
	while (curr != NULL)
	{
		printf("%d ", curr->item);
		curr = curr->next;
	}
	printf("\n");
}

//Remove element from front of queue
int queue_deq(Queue queue)
{
	assert(queue != NULL);
	assert(queue->size != 0);
	if (queue->size == 1)
	{
		int value = queue->first->item;
		queue->first = NULL;
		queue->last = NULL;
		queue->size--;
		return value;
	}
	else
	{
		int value = queue->first->item;
		Nodeq *curr = queue->first;
		queue->first = queue->first->next;
		free(curr);
		queue->size--;
		return value;
	}
}

//Frees the dynamically allocated memory
void queue_free(Queue queue)
{
	if (queue == NULL)
	{
		return;
	}
	for (Nodeq *curr = queue->first; curr != NULL; curr = curr->next)
	{
		free(curr);
	}
}
