#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100

typedef struct {
    int heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

void init(HeapType *h) {
    h->heap_size = 0;
}

void upHeap(HeapType *h) {
    int i = h->heap_size;
    int key = h->heap[i];
    while ((i != 1) && (key < h->heap[i / 2])) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = key;
}

void insertItem(HeapType *h, int key) {
    h->heap_size += 1;
    h->heap[h->heap_size] = key;
    upHeap(h);
}

void downHeap(HeapType *h) {
    int temp = h->heap[1];
    int parent = 1, child = 2;
    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child] > h->heap[child + 1]))
            child++; // child 중 더 작은 값을 가진 노드를 child로 설정하기. 근데  child가 2개 있는 거 확인하고.
        if (temp <= h->heap[child])
            break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
     h->heap[parent] = temp;
}

int removeMin(HeapType *h) {
    int key = h->heap[1];
    h->heap[1] = h->heap[h->heap_size];
    h->heap_size -= 1;
    downHeap(h);
    return key;
}

void printHeap(HeapType *h) {
    for (int i = 1; i <= h->heap_size; i++) {
        printf("[%d] ", h->heap[i]);
    }
    printf("\n");
}

void main() {
    // (완전이진트리)
    HeapType heap;
    init(&heap);
    insertItem(&heap, 5);
    insertItem(&heap, 3);
    insertItem(&heap, 7);
    insertItem(&heap, 4);
    insertItem(&heap, 1);  // 1 3 7 5 4
    insertItem(&heap, 4);
    insertItem(&heap, 8);
    insertItem(&heap, 2);
    printHeap(&heap);  // 1 2 4 3 4 7 8 5

    printf("deleted key: %d\n", removeMin(&heap));
    printf("deleted key: %d\n", removeMin(&heap));
    printf("deleted key: %d\n", removeMin(&heap));
    printf("deleted key: %d\n", removeMin(&heap));
    printf("deleted key: %d\n", removeMin(&heap));
    printf("deleted key: %d\n", removeMin(&heap));
    printf("deleted key: %d\n", removeMin(&heap));
    printf("deleted key: %d\n", removeMin(&heap));
}
