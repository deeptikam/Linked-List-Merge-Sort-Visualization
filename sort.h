#ifndef SORT_H
#define SORT_H
#include "list.h"

node* mergeSort(node* head);
node* sorted(node* firstHalf, node* secondHalf);
void split(node* block, node** firstHalf, node** secondHalf);

#endif