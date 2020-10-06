#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackNode {
    element data;
    struct StackNode* link;
} StackNode;

typedef struct {
    StackNode* stack_ptr;
} LinkedStackType;



void push(LinkedStackType* s, int item) {
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    if (temp == NULL) {
        fprint(stderr, "memory allocation error \n");
        return;
    }
    else {
        temp->data = item;
        temp->link = s->stack_ptr->link;
        s->stack_ptr->link = temp;
    }
}
int pop(LinkedStackType* s) {
    if (is_empty(s)) {
        fprint(stderr, "The stack is empty \n");
        return;
    }
    else {
        StackNode* temp = s->stack_ptr->link;
        int item = temp->data;
        s->stack_ptr->link = temp->link;
        free(temp);
        return item;
    }
}