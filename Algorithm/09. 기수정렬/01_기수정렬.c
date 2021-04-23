#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 15
#define BUCKETS 10
#define DIGITS 2

// 원형 큐 구현
typedef int element;
typedef struct {
    element data[MAX_SIZE];
    int front, rear;
} QueueType;

void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}
int is_empty(QueueType* q) {
    return q->front == q->rear;
}
int is_full(QueueType* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}
void enqueue(QueueType* q, element item) {
    if (is_full(q)) exit(1);

    q->rear = (q->rear + 1) % MAX_SIZE; // 끝을 하나 증가시키고
    q->data[q->rear] = item; // 거기에 아이템 넣기
}
element dequeue(QueueType* q) {
    if (is_empty(q)) exit(1);

    q->front = (q->front + 1) % MAX_SIZE; // 앞을 하나 증가시키고 
    return q->data[q->front]; // 맨 앞의 친구를 주기
}
void queue_print(QueueType* q) {
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % MAX_SIZE;
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}
void print_buckets(QueueType queues[]) {
    printf("\n===============================\n");
    for (int b = 0; b < BUCKETS; b++) {
        printf("[%d] -> ", b);
        queue_print(&queues[b]);
    }
    printf("\n===============================\n");
}

void radix_sort(int list[], int n) {
    int i, b, d, factor = 1;
    QueueType queues[BUCKETS];

    // 큐 배열 초기화
    for (b = 0; b < BUCKETS; b++) init_queue(&queues[b]);
    for (d = 0; d < DIGITS; d++) {
        // 1, 10, ... 10^n의 자리에 맞추어 버킷에 추가
        for (i = 0; i < n; i++)
            enqueue(&queues[(list[i] / factor) % 10], list[i]);

        print_buckets(queues);
        // 순서대로!!! 빼내오기
        for (b = i = 0; b < BUCKETS; b++)
            while (!is_empty(&queues[b]))
                list[i++] = dequeue(&queues[b]);
        factor += 10; // factor 기준 자리수 바꿔주기
    }
}

void main() {
    int list[MAX_SIZE];
    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE; i++)
        list[i] = rand() % 100;

    for (int i = 0; i < MAX_SIZE; i++)
        printf("[%d] ", list[i]);
    printf("\n");
    getchar();

    radix_sort(list, MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++)
        printf("[%d] ", list[i]);
    printf("\n");
}
