#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int V[SIZE];
    int n;
} ArrayList;

void init(ArrayList* L) {
    L->n = 0;
}

void traverse(ArrayList* L) {
    for (int i = 0; i < L->n; i++)
        printf("[%d] ", L->V[i]);
    printf("\n");
}

void add(ArrayList* L, int pos, int item) {
    if (L->n == SIZE) {
        printf("fullListException...\n");
        exit(1);
    }
    //invalidPosException..... Q@<= pos <= L->n
    for (int i = L->n - 1; i >= pos; i--)
        L->V[i + 1] = L->V[i];
    L->V[pos] = item;
    L->n++;
}

void main() {
    ArrayList list;
    init(&list);

    add(&list, 0, 10); traverse(&list);
    add(&list, 0, 20); traverse(&list);
    add(&list, 1, 30); traverse(&list);
    add(&list, 1, 40); traverse(&list);
    add(&list, 3, 50); traverse(&list);
}
