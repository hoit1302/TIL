#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct QueueType {
    int count;
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

int is_empty(QueueType* q) {
    return (q->count == 0);
}

int is_full(QueueType* q) {
    return (q->count == MAX_QUEUE_SIZE);
}
// ���ο� ���Ҹ� q�� ����
void enqueue(QueueType* q, int item) {
    if (is_full(q))
        error("ť�� ��ȭ�����Դϴ�");
    else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->queue[q->rear] = item;
        q->count++;
    }
}
// ������� ������ q���� ���Ҹ� �����ϰ� ��ȯ
int dequeue(QueueType* q) {
    if (is_empty(q))
        error("ť�� ��������Դϴ�");
    else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        q->count--;
        return q->queue[q->front];
    }
}

int main() {


	return 0;
}