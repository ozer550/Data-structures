/*    
 Made By prathamesh desai
 interface file for queue adt
 
 Date-2/Aug/20

 ALL RIGHTS RESERVED
 */

#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue *Queue;

//Add item at end of the queue
void queue_enq(Queue queue, int item);

//Remove element from front of queue
int queue_deq(Queue queue);

//Creates a queue
Queue queue_crt(void);

//Frees the dynamically allocated memory
void queue_free(Queue queue);

//Returns true if empty else false
int queue_isempty(Queue queue);

//Prints and returns first elemnt of queue
int queue_front(Queue queue);

//Returns and pritns size of queue
int queue_size(Queue queue);

//Prints elements of queue sequentially
void queue_show(Queue queue);

#endif
