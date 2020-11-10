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
		error("큐가 포화상태입니다");
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->queue[q->rear] = item;
	}
}
int dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->queue[q->front];
	}
}

// 인접 리스트
typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
} GraphNode;
typedef struct GraphType {
	int n; // 정점의 개수
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;
int visited[MAX_VERTICES];

// 인접 리스트로 표현된 그래프에 대한 깊이우선 탐색
void dfs_list(GraphType* g, int v) {
	GraphNode* w;
	printf("%d ", v); // 정점 v를 방문하고 출력
	visited[v] = 1; // 정점 v의 방문 표시
	for (w = g->adj_list[v]; w; w = w->link) // 인접 정점 탐색
		if (!visited[w->vertex]) dfs_list(g, w->vertex);
	//정점 w->vertex에서 DFS 새로 시작
}

void bfs_list(GraphType* g, int v) {
	GraphNode* w;
	QueueType q;
	init(&q); // 큐 초기화
	printf("%d ", v); // 정점 v를 방문하고 출력
	visited[v] = 1; // 정점 v의 방문 표시
	enqueue(&q, v); // 시작 정점을 큐에 저장
	while (!is_empty(&q)) {
		v = dequeue(&q); // 큐에서 정점 제거
		for (w = g->adj_list[v]; w; w = w->link) // 인접 정점 탐색
			if (!visited[w->vertex]) { // 미방문 정점 탐색
				printf("%d ", w->vertex); // 정점 방문 및 출력
				visited[w->vertex] = 1; // 방문 표시
				enqueue(&q, w->vertex); // 방문한 정점을 큐에 삽입
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