#include <stdio.h>
#include <unistd.h>
#include "list.h"
#include "sort.h"

#define DELAY 200000

node* mergeSort(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node *firstHalf, *secondHalf;
    split(head, &firstHalf, &secondHalf);
    printf("\nSplitting----------------\n\n");
    printf("\nFirst half:\n\n");
    printList(firstHalf);
    printf("\nSecond half:\n\n");
    printList(secondHalf);
    usleep(DELAY);
    firstHalf = mergeSort(firstHalf);
    secondHalf = mergeSort(secondHalf);
    printf("\nMerging----------------\n\n");
    printf("\nFirst half:\n\n");
    printList(firstHalf);
    printf("\nSecond half:\n\n");
    printList(secondHalf);
    usleep(DELAY);
    node* merged = sorted(firstHalf, secondHalf);
    printf("\nResult of merge:\n\n");
    printList(merged);
    usleep(DELAY);
    return merged;
}

void split(node* block, node** firstHalf, node** secondHalf) {
    node* mid = block;
    node* end = block -> next;
    while (end) {
        end = end -> next;
        if (end) {
            mid = mid -> next;
            end = end -> next;
        }
    }
    *firstHalf = block;
    *secondHalf = mid -> next;
    mid -> next = NULL;
}

node* sorted(node* firstHalf, node* secondHalf) {
    if (firstHalf == NULL) {
        return secondHalf;
    } else if (secondHalf == NULL) {
        return firstHalf;
    } 
    node* result = NULL;
    if (firstHalf -> val <= secondHalf -> val) {
        result = firstHalf;
        result -> next = sorted(firstHalf -> next, secondHalf);
    } else {
        result = secondHalf;
        result -> next = sorted(firstHalf, secondHalf -> next);
    }
    return result;
}