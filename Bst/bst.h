/*    
 Made By prathamesh desai
 interface file for bst adt
 
 Date-2/Aug/20

 ALL RIGHTS RESERVED
 */

#ifndef BST_H
#define BST_H

typedef struct bst *Bst;
typedef struct node *Node;

//Creates a tree
Bst Bmaketree();

//Add node to tree
void Binsert(Bst tree, int val);

//delete node from tree
int Bdelete(Bst tree, int val);

//Returns size of tree
int Bsize(Bst tree);

//Free all elements of tree
void Bfree(Bst tree);

//Returns true if empty else false
int BisEmpty(Bst tree);

//Depth-first-search for bst
Node Bdfs(Bst tree, int val);

//Returns sum of all the elements of the tree
int Bsum(Bst tree);

//all types of traversals
void Btraverse(Bst tree, char c);

//Delete a node <finally>
void BdeleteNode(Bst tree,int val);
#endif
