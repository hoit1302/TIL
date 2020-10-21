#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct QueueType {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

int is_empty(QueueType* q) {
    return (q->front == q->rear);
}
int is_full(QueueType* q) {
    return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}
// 새로운 원소를 q에 삽입
void enqueue(QueueType* q, int item) {
    if (is_full(q))
        error("큐가 포화상태입니다");
    else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // 항상 증가 주의
        q->queue[q->rear] = item;
    }
}
// 비어있지 않으면 q에서 원소를 삭제하고 반환
int dequeue(QueueType* q) {
    if (is_empty(q))
        error("큐가 공백상태입니다");
    else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE; // 항상 증가 주의
        return q->queue[q->front];
    }
}
int number_of_element(QueueType* q) {
    return (MAX_QUEUE_SIZE - q->front + q->rear) % MAX_QUEUE_SIZE;
}
int main() {
    return 0;
}