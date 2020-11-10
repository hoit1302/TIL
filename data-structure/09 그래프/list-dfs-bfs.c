#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTICES 100
#define MAX_QUEUE_SIZE 10

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

// ���� ����Ʈ
typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
} GraphNode;
typedef struct GraphType {
	int n; // ������ ����
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;
int visited[MAX_VERTICES];

// ���� ����Ʈ�� ǥ���� �׷����� ���� ���̿켱 Ž��
void dfs_list(GraphType* g, int v) {
	GraphNode* w;
	printf("%d ", v); // ���� v�� �湮�ϰ� ���
	visited[v] = 1; // ���� v�� �湮 ǥ��
	for (w = g->adj_list[v]; w; w = w->link) // ���� ���� Ž��
		if (!visited[w->vertex]) dfs_list(g, w->vertex);
	//���� w->vertex���� DFS ���� ����
}

void bfs_list(GraphType* g, int v) {
	GraphNode* w;
	QueueType q;
	init(&q); // ť �ʱ�ȭ
	printf("%d ", v); // ���� v�� �湮�ϰ� ���
	visited[v] = 1; // ���� v�� �湮 ǥ��
	enqueue(&q, v); // ���� ������ ť�� ����
	while (!is_empty(&q)) {
		v = dequeue(&q); // ť���� ���� ����
		for (w = g->adj_list[v]; w; w = w->link) // ���� ���� Ž��
			if (!visited[w->vertex]) { // �̹湮 ���� Ž��
				printf("%d ", w->vertex); // ���� �湮 �� ���
				visited[w->vertex] = 1; // �湮 ǥ��
				enqueue(&q, w->vertex); // �湮�� ������ ť�� ����
			}
	}
}


int main() {

	GraphType g;
	g.n = 5;

	GraphNode g04 = { 4, NULL };
	GraphNode g02 = { 2, &g04 };
	GraphNode g01 = { 1, &g02 };
	GraphNode g0 = { 0, &g01 };

	GraphNode g12 = { 2, NULL };
	GraphNode g10 = { 0, &g12 };
	GraphNode g1 = { 1, &g10 };

	GraphNode g23 = { 3, NULL };
	GraphNode g21 = { 1, &g23 };
	GraphNode g20 = { 0, &g21 };
	GraphNode g2 = { 2, &g20 };

	GraphNode g34 = { 4, NULL };
	GraphNode g32 = { 2, &g34 };
	GraphNode g3 = { 3, &g32 };

	GraphNode g43 = { 3, NULL };
	GraphNode g42 = { 2, &g43 };
	GraphNode g40 = { 0, &g42 };
	GraphNode g4 = { 4, &g40 };

	//g.adj_list[0] = &g0;
	//g.adj_list[1] = &g1;
	//g.adj_list[2] = &g2;
	//g.adj_list[3] = &g3;
	//g.adj_list[4] = &g4;

	GraphNode* adj_list[MAX_VERTICES] = { &g0, &g1, &g2, &g3, &g4 };
	memcpy(g.adj_list, adj_list, sizeof(adj_list));

	memset(visited, 0, sizeof(int) * 5);
	dfs_list(&g, 0);
	printf("\n");

	memset(visited, 0, sizeof(int) * 5);
	bfs_list(&g, 0);
	printf("\n");
	return 0;
}