#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "list.h"
#include "sort.h"

#define SIZE 5
#define DELAY 200000

int main() {
    srand(time(NULL));
    node* list = createRandomList(SIZE);
    printf("\nStarting List:\n");
    printList(list);
    usleep(4 * DELAY);
    list = mergeSort(list);
    printf("\nSorted List:\n");
    printList(list);
    freeList(list);
}
