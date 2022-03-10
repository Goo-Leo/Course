//
// Created by 10633 on 2022/3/8.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <iostream>

typedef struct node {
    struct node *next;
    int data;
} node;


class list {
public:
    int length;
    node *head;
    list();        //default construct func
    void lslist();
    ~list();
};


list::list() {
    length = 5;
    head = new node;
    std::cout << "init your 5-node list" << std::endl;
    node *ptr = head;
    for (int i = 0; i < length; i++) {
        node *newnd = new node;
        std::cin >> newnd->data;
        ptr ->next =newnd;
        newnd->next = nullptr;
        ptr = newnd;
    }
}


void list::lslist() {
    node *lsptr = head ->next;
    for (int j = 0; j < length; j++) {
        std::cout << lsptr->data;
        lsptr = lsptr->next;
    }
}

list::~list() {
    std::cout << "goodbye!";
}


#endif //LIST_LIST_H
