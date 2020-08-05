/*    
 Made By prathamesh desai
 main fxn file for Bst adt
 
 Date-2/Aug/20

 ALL RIGHTS RESERVED
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <sysexits.h>

#include "bst.h"

#define TRUE 1
#define FALSE 0

typedef struct node *Node;

struct bst
{
	Node head;
	int size;
};

struct node
{
	Node left;
	Node right;
	int value;

} node;

////function to create a new node with item value
//fxn is private to this ADT
static Node newnode(int val)
{
	Node new = malloc(sizeof *new);
	if (new == NULL)
	{
		err(EX_OSERR, "couldn't allocate Node");
	}
	new->left = NULL;
	new->right = NULL;
	new->value = val;
	return new;
}

//Creates a tree
Bst Bmaketree()
{
	Bst newtree = malloc(sizeof *newtree);
	if (newtree == NULL)
	{
		err(EX_OSERR, "couldn't allocate tree");
	}
	newtree->head = NULL;
	newtree->size = 0;
	return newtree;
}

//Returns size of tree
int Bsize(Bst tree)
{
	assert(tree != NULL);
	return tree->size;
}

//Returns true if empty else false
int BisEmpty(Bst tree)
{
	assert(tree != NULL);
	if (tree->size == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//main node insertion
static void insert_node(Node node, Node head)
{
	Node curr = head;
	if (curr->value > node->value)
	{
		if (curr->right == NULL)
		{
			curr->right = node;
		}
		else
		{
			insert_node(node, curr->right);
		}
	}
	else
	{
		if (curr->left == NULL)
		{
			curr->left = node;
		}
		else
		{
			insert_node(node, curr->left);
		}
	}
}

//Add node to tree
void Binsert(Bst tree, int val)
{
	assert(tree != NULL);
	Node new = newnode(val);
	if (tree->size == 0)
	{

		tree->head = new;
		tree->size++;
	}
	else
	{
		insert_node(new, tree->head);
		tree->size++;
	}
}
