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
#include "queue.h"

#define TRUE 1
#define FALSE 0

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

static void BpreOrder(Node head);
static void BpostOrder(Node head);
static void BinOrder(Node head);
static void BlevelOrder(Bst tree, Node head);

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
		if (curr->left == NULL)
		{
			curr->left = node;
		}
		else
		{
			insert_node(node, curr->left);
		}
	}
	else
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

static Node dfs(Node head, int val)
{

	Node otptr = NULL;
	if (head->value == val)
	{

		otptr = head;
		return otptr;
	}
	if (head->left != NULL)
	{
		if (val <= head->value)
		{
			otptr = dfs(head->left, val);
			if (otptr != NULL)
			{
				return otptr;
			}
		}
	}
	if (head->right != NULL)
	{
		if (val > head->value)
		{
			otptr = dfs(head->right, val);
			if (otptr != NULL)
			{
				return otptr;
			}
		}
	}
	else
	{
		return NULL;
	}
}

//Depth-first-search for bst
Node Bdfs(Bst tree, int val)
{
	assert(tree != NULL);
	return dfs(tree->head, val);
}

//main function for summing
sum(Node head)
{
	if (head == NULL)
	{
		return 0;
	}
	int total_sum = head->value;
	if (head->left != NULL)
	{
		total_sum += sum(head->left);
	}
	if (head->right != NULL)
	{

		total_sum += sum(head->right);
	}
	return total_sum;
}

//Returns sum of all the elements of the tree
int Bsum(Bst tree)
{
	assert(tree != NULL);
	int sumtree = sum(tree->head);
	return sumtree;
}

//traversals
void Btraverse(Bst tree, char c)
{
	assert(tree != NULL);
	switch (c)
	{
	case 'p':
		BpreOrder(tree->head);
		break;
	case 'i':
		BinOrder(tree->head);
		break;
	case 'P':
		BpostOrder(tree->head);
		break;
	case 'l':
		BlevelOrder(tree, tree->head);
		break;
	}
}

//preorder-traversal in binary tree
static void BpreOrder(Node head)
{
	if (head == NULL)
	{
		return;
	}
	printf("%d ", head->value);
	if (head->left != NULL)
	{
		BpreOrder(head->left);
	}
	if (head->right != NULL)
	{
		BpreOrder(head->right);
	}
	else
	{
		return;
	}
}

//postorder-traversal in binary tree
static void BpostOrder(Node head)
{
	if (head->left != NULL)
	{
		BpostOrder(head->left);
	}
	if (head->right != NULL)
	{
		BpostOrder(head->right);
	}
	if (head != NULL)
	{
		printf("%d ", head->value);
	}
}

//inorder-traversal in binary tree
static void BinOrder(Node head)
{
	if (head->left != NULL)
	{
		BinOrder(head->left);
	}
	if (head != NULL)
	{
		printf("%d ", head->value);
	}
	if (head->right != NULL)
	{
		BinOrder(head->right);
	}
}

//Level-order traversal
static void BlevelOrder(Bst tree, Node head)
{
	Queue q = queue_crt();
	queue_enq(q, head->value);
	while (queue_isempty(q) != 1)
	{
		if (head->left != NULL)
		{
			queue_enq(q, head->left->value);
		}
		if (head->right != NULL)
		{
			queue_enq(q, head->right->value);
		}
		printf("%d ", head->value);
		queue_deq(q);
		if (queue_isempty(q) != 1)
		{
			head = Bdfs(tree, queue_front(q));
		}
	}
}
