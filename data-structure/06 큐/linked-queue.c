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
        error("메모리 할당 에러");
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
        error("큐가 공백상태임");
    else {
        item = temp->item;
        q->front = q->front->link;
        if (q->front == NULL) // 노드가 하나인 큐에서의 삭제
            q->rear = NULL;
        free(temp);
        return item;
    }
}