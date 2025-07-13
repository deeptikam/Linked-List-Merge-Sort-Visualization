#ifndef LIST_H
#define LIST_H

typedef struct node {
    int val;
    struct node* next;
} node;

node* createRandomList(int num);
void printList(node* head);
void freeList(node* head);

#endif