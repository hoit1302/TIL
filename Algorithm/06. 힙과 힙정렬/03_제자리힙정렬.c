#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
            child++;  // child 중 더 작은 값을 가진 노드를 child로 설정하기. 근데  child가 2개 있는 거 확인하고.
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

void inPlaceHeapSort(HeapType *h) {
    int size = h->heap_size;
    int key;
    for (int i = 0; i < size; i++) {
        key = removeMin(h);
        h->heap[h->heap_size + 1] = key;
    }
}

void main() {
    // (완전이진트리)
    HeapType heap;
    srand(time(NULL));
    init(&heap);
    for (int i = 0; i < 15; i++)
        insertItem(&heap, rand() % 100);
    printHeap(&heap);

    // 힙 자체에 정렬하기, 하나씩 삭제하는 방식이기 때문에 그냥 printHeap 호출하면 X
    // (재귀적상향식힙생성) 이랑 다른거지?
    getchar();
    inPlaceHeapSort(&heap);
    for (int i = 1; heap.heap[i] > 0; i++)
        printf("[%d] ", heap.heap[i]);
    printf("\n");

}