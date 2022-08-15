#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include "ringbuffer.h"

/* In the begining ,we define a node structure like we did with linded list*/
typedef struct btnode{
	struct btnode* left = NULL;
	struct btnode* right = NULL;
	int data;
}btnode;

/*
 *
 *		Basical actions like create,insert,delete,and easy-way traverse,etc.
 *
 */

/* create a binary tree,return a pointer pointing to root's address */
btnode* PlantBi(void){
	btnode *root = (btnode *)malloc(sizeof(btnode));
	return root;
}

/* Preorder traverse */
void PreOrderTraverse(btnode* root){
	if(root==NULL)	        return;
	    printf("%d", root ->data);		/* output first */
	    PreOrderTraverse(root ->left);	/* traverse left */
	    PreOrderTraverse(root ->right);	/* then the rigt */
}
/* Inorder traverse */
void InOrderTraverse(btnode *root){
	if(root==NULL)	        return;
	    InOrderTraverse(root ->left);     	/* traverse left first */
	    printf("%d", root ->data);	    	/* output */
	    InOrderTraverse(root ->right);     	/* then the right*/
}
/* Postoder traverse */
void PostOrderTraverse(btnode *root){
	if(root==NULL)		 return;
	    PostOrderTraverse(root ->left);	/* traverser left first */
	    PostOrderTraverse(root ->right);	/* then the right */
	    printf("%d", root ->data);		/* output */
}

void LevelorderTraverse(btnode *root){
	ringbuffer* queue = (ringbuffer*)malloc(sizeof(ringbuffer));
	writebuffer(queue,&root);
	while(root!=NULL){
		if(root->left!=NULL)	
	}
}

/* add a element */
void BTGrowup(btnode *root,int data){
	btnode *newleaf = (btnode *)malloc(sizeof(btnode));
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
	if(){

	}	
}

