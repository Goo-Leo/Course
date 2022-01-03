#include <stdio.h>
#include <stdlib.h>

/* In the begining ,we define a node like the other ADTs */
typedef struct btnode {
	struct btnode * left;
	struct btnode * right;
	int data;
}btnode;
/*
 *
 *	Basical actions like create,insert,delete,and easy-way traverse,etc.
 *
 */

/* create a binary tree() */
btnode* PlantBi(void){
	btnode *root = (btnode *)malloc(sizeof(btnode));
	return root;
}
/* add some elements */
void BTGrowup(btnode *root,int data){
	btnode * newleaf = (btnode *)malloc(sizeof(btnode));
	newleaf ->data = data;
	if(root ->left = NULL){
		root ->left = newleaf;
	}
	if(root ->right = NULL){
		root ->right = newleaf;
	}else
		BTGrowup(node ->left,data);
		BTGrowup(node ->right,data);
	return 0;
}
/* Preordertraverse */
void PreOrderTraverse(btnode *root){
	if(root==NULL)	        return;
	    printf("%d", root ->data);		/* output first */
	    PreOrderTraverse(root ->left);	/* traverse left */
	    PreOrderTraverse(root ->right);	/* then the rigt */
}
/* Inordertraverse */
void InOrderTraverse(btnode *root){
	if(root==NULL)	        return;
	    InOrderTraverse(root ->left);     	/* traverse left first */
	    printf("%d", root ->data);	    	/* output */
	    InOrderTraverse(root ->right);     	/* then the right*/
}
/* Postodertraverse */
void PostOrderTraverse(btnode *root){
	if(root==NULL)		 return;
	    PostOrderTraverse(root ->left);	/* traverser left first */
	    PostOrderTraverse(root ->right);	/* then the right */
	    printf("%d", root ->data);		/* output */
}
/* counting */
int Countdeep(BTnode* head) {
	return head == NULL ? 0 : (tier(head->left)> tier(head->right)? tier(head->left) : tier(head->right)) + 1;
}
int CountLeaf(BTnode* r) {
	int ll, rr;
	if (!r) return 0;
	else{
		ll = CountLeafBtnode(r->left);
		rr = CountLeafBtnode(r->right);
	}
	return ll + rr + (!r->left&&!r->right);
}

/* Find node using a given keyword */
btnode * BTFind(int key,btnode *root){
	if()	
}

