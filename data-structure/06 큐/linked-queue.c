#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int element;
typedef struct QueueNode {
    element item;
    QueueNode* link;
}QueueNode;
typedef struct QueueType {
    QueueNode* front, * rear;
} QueueType;

void enqueue(QueueType* q, element item) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    if (temp == NULL)
        error("�޸� �Ҵ� ����");
    else {
        temp->item = item;
        temp->link = NULL;
        if (is_empty(q))
            q->front = q->rear = temp;
        else {
            q->rear->link = temp;
            q->rear = temp;
        }
    }
}

element dequeue(QueueType* q) {
    QueueNode* temp = q->front;
    element item;
    if (is_empty(q))
        error("ť�� ���������");
    else {
        item = temp->item;
        q->front = q->front->link;
        if (q->front == NULL) // ��尡 �ϳ��� ť������ ����
            q->rear = NULL;
        free(temp);
        return item;
    }
}