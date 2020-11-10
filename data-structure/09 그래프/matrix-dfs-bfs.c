#include <stdio.h>
#include <string.h>
#define MAX_VERTICES 5
#define MAX_QUEUE_SIZE 100

void error(const char* string) {
	printf(string);
}

typedef int element;
typedef struct QueueType {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;
void init(QueueType* q) {
	q->front = q->rear = 0;
}
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
int is_full(QueueType* q) {
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}
void enqueue(QueueType* q, int item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->queue[q->rear] = item;
	}
}
int dequeue(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->queue[q->front];
	}
}



// ���� ���
typedef struct GraphType {
	int n; // ������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;
int visited[MAX_VERTICES];

// ���� ��ķ� ǥ���� �׷����� ���� ���̿켱 Ž��
void dfs_mat(GraphType* g, int v) {
	int w;
	printf("%d ", v); // ���� v�� �湮�ϰ� ���
	visited[v] = 1; // ���� v�� �湮 ǥ��
	for (w = 0; w < g->n; w++) // ���� ���� Ž��
		if (g->adj_mat[v][w] && !visited[w]) dfs_mat(g, w);
	//���� w���� DFS ���� ����
}

// ���� ��ķ� ǥ���� �׷����� ���� �ʺ�켱 Ž��
void bfs_mat(GraphType* g, int v) {
	int w;
	QueueType q;
	init(&q); // ť �ʱ�ȭ
	printf("%d ", v); // ���� v�� �湮�ϰ� ���
	visited[v] = 1; // ���� v�� �湮 ǥ��
	enqueue(&q, v); // ���� ������ ť�� ����
	while (!is_empty(&q)) {
		v = dequeue(&q); // ť���� ���� ����
		for (w = 0; w < g->n; w++) // ���� ���� Ž��
			if (g->adj_mat[v][w] && !visited[w]) {
				printf("%d ", w); // ���� �湮 �� ���
				visited[w] = 1; // ���� w�� �湮 ǥ��
				enqueue(&q, w); // �湮�� ������ ť�� ����
			}
	}
}

void main() {
	GraphType g;
	g.n = 5;
	int matrix[MAX_VERTICES][MAX_VERTICES] = { {0,1,1,0,1}, {1,0,1,0,0}, {1,1,0,1,1}, {0,0,1,0,1}, {1,0,1,1,0} };
	memcpy(g.adj_mat, matrix, sizeof(matrix));
	
	memset(visited, 0, sizeof(int) * 5);
	printf("dfs: ");
	dfs_mat(&g, 0);
	printf("\n");
	
	memset(visited, 0, sizeof(int) * 5);
	printf("bfs: ");
	bfs_mat(&g, 0);
	printf("\n");
	return;
}