#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node* createRandomList(int num) {
    node* head = NULL;
    for (int i = 0; i < num; i++) {
        node* new = malloc(sizeof(node));
        new -> val = rand() % 10 + 1;
        new -> next = head;
        head = new;
    }
    return head;
}

void printList(node* head) {
    node* curr = head;
    while (curr != NULL) {
        printf("[%2d] ", curr -> val);
        for (int i = 0; i < curr -> val; i++) {
            printf("|");
        }
        printf("\n");
        curr = curr -> next;
    }
}

void freeList(node* head) {
    node* curr = head;
    while (curr != NULL) {
        node* temporary = curr;
        curr = curr -> next;
        free(temporary);
    }
}
