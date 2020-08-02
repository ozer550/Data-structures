/*    
 Made By prathamesh desai
 interface file for stack adt
 
 Date-30/jul/20

 ALL RIGHTS RESERVED
 */
#ifndef STACK_H
#define STACK_H

#define TRUE 1
#define FALSE 0

typedef struct stack *Stack;

//Creates new stack and returns pointer to struct
Stack newStack(void);

//Pushes a char in the stack
void push(char brac, Stack stack);

//Pops element from stack and return it
char pop(Stack stack);

//Returns true if stack is empty and false if not
int isEmpty(Stack stack);

//prints all the elements os stack
char printStack(Stack stack);

//frees the heap
void freeStack(Stack stack);

#endif
