#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_HEAP_SIZE 100

/* [1] stack 구현 */
typedef int element;
typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;
// 스택 초기화 함수
void init_stack(StackType* s) {
    s->top = -1;
}
// 공백상태 검출 함수
int is_empty(StackType* s) {
    return (s->top == -1);
}
// 포화상태 검출 함수
int is_full(StackType* s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입 함수
void push(StackType* s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    } else
        s->stack[++(s->top)] = item;
}
// 삭제 함수
element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    } else
        return s->stack[(s->top)--];
}

/* [2] heap 구현 */
typedef struct {
    int heap[MAX_HEAP_SIZE];
    int heap_size;
} HeapType;

void init_heap(HeapType* h) {
    h->heap_size = 0;
}
// 힙 삽입 시 필요한 up_heap 연산
void up_heap(HeapType* h) {
    int i = h->heap_size;
    int key = h->heap[i];
    while ((i != 1) && (key < h->heap[i / 2])) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = key;
}
// 힙에 원소 삽입
void insert_item(HeapType* h, int key) {
    h->heap_size += 1;
    h->heap[h->heap_size] = key;
    up_heap(h);
}
// 힙 출력
void print_heap(HeapType* h) {
    for (int i = 1; i <= h->heap_size; i++) {
        printf("[%d] ", h->heap[i]);
    }
    printf("\n");
}
/* [3] 핵심 알고리즘 */

// stack에 i를 2진수로 표현한 값을 넣음.
// ex) 10 -> (top) 1 0 1 0 (bottom)
void binary_expansion(int i, StackType* S) {
    while (2 <= i) {
        push(S, i % 2);
        i /= 2;
    }
    push(S, i);
    return;
}
int left_child(int i) {
    return i * 2 + 1;
}
int right_child(int i) {
    return i * 2 + 2;
}
int find_last_node(int v, int n) {
    StackType S;
    init_stack(&S);
    binary_expansion(n, &S);
    pop(&S);  // 최상위 1은 버림.
    while (!is_empty(&S)) {
        int bit = pop(&S);
        if (bit == 0)
            v = left_child(v);
        else
            v = right_child(v);
    }
    return v;
}

void main() {
    HeapType H;
    init_heap(&H);
    insert_item(&H, 2);
    insert_item(&H, 6);
    insert_item(&H, 4);
    insert_item(&H, 14);
    insert_item(&H, 7);
    insert_item(&H, 12);
    insert_item(&H, 8);
    insert_item(&H, 17);
    insert_item(&H, 15);
    insert_item(&H, 9);
    printf("힙: ");
    print_heap(&H);

    printf("해당 힙의 마지막 노드는 [%d]의 값을 가지고 있다.\n", find_last_node(0, H.heap_size));
}