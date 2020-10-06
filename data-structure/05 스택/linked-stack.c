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



// ���� �Լ�
void push(LinkedStackType* s, element item) {
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    if (temp == NULL) {
        fprintf(stderr, "�޸� �Ҵ翡��\n");
        return;
    }
    else {
        temp->data = item;
        temp->link = s->top; // (1)
        s->top = temp; // (2)
    }
}

// ���� �Լ�
element pop(LinkedStackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "������ �������\n");
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
