#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackNode {
    element data;
    struct StackNode* link;
} StackNode;
typedef struct {
    StackNode* top;
} LinkedStackType;

void init(LinkedStackType* s) {
    s->top = NULL;
}
int is_empty(LinkedStackType* s) {
    if (s->top == NULL)   return 1;
    return 0;
}
// 삽입 함수
void push(LinkedStackType* s, element item) {
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    if (temp == NULL) {
        fprintf(stderr, "메모리 할당에러\n");
        return;
    }
    else {
        temp->data = item;
        temp->link = s->top; // (1)
        s->top = temp; // (2)
    }
}
// 삭제 함수
element pop(LinkedStackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        StackNode* temp = s->top; // (1)
        int item = temp->data; // (2)
        s->top = s->top->link; // (3)
        free(temp); // (4)
        return item;
    }
}
element peek(LinkedStackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else
        return s->top->data;
}

void main() {

    LinkedStackType s;
    init(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    pop(&s);
    printf("%d\n", peek(&s));
    push(&s, 5);
    printf("%d\n", peek(&s));

    return;
}