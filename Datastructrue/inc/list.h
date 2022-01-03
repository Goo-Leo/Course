#ifndef LIST_H
#define LIST_H

#include "stdlib.h"
#include "stdio.h"

typedef struct Node{
	int Data;
	struct Node *Next;
} Node;


Node* Makelist(void);				//create a list ,return header
Node* FindElem(Node *head , int key);		//find element,return pointer
void InsertElem(Node *head , int data);		//insert a new node(in the ending)	
void DelElem(Node* head ,data);

Node* Makelist(void){

	Node *head;	
	head = (Node *)malloc(sizeof(Node));
	head ->Next = NULL;
 
	return head;
}

Node* FindElem(Node *head , int key){
        Node *ptr = head;       
	while((ptr ->Next) && (ptr ->Data != key))
		ptr = ptr ->Next;       
	return ptr;
}

Node* FindElemrecurse(Node *head,key){
	Node *get;
	if(head ->Next != key){
		head = head ->Next;
		get = FindElemrecurse(head,key);
	}
	return get;
}

void EndInsert(Node *head , int data){
	
	Node* ptr = head;
	Node* newone = malloc(sizeof(Node)); 	
        while(ptr ->Next != NULL)
		ptr = ptr ->Next;
	ptr ->Next = newone;
	newone ->Data = data;
	newone ->Next = NULL;

}

void DelElem(Node *head , int key){
	Node* del = FindElemrecurse(head,key);
	
	free(ptr);
}



#endif

