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



// 인접 행렬
typedef struct GraphType {
	int n; // 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;
int visited[MAX_VERTICES];

// 인접 행렬로 표현된 그래프에 대한 깊이우선 탐색
void dfs_mat(GraphType* g, int v) {
	int w;
	printf("%d ", v); // 정점 v를 방문하고 출력
	visited[v] = 1; // 정점 v의 방문 표시
	for (w = 0; w < g->n; w++) // 인접 정점 탐색
		if (g->adj_mat[v][w] && !visited[w]) dfs_mat(g, w);
	//정점 w에서 DFS 새로 시작
}

// 인접 행렬로 표현된 그래프에 대한 너비우선 탐색
void bfs_mat(GraphType* g, int v) {
	int w;
	QueueType q;
	init(&q); // 큐 초기화
	printf("%d ", v); // 정점 v를 방문하고 출력
	visited[v] = 1; // 정점 v의 방문 표시
	enqueue(&q, v); // 시작 정점을 큐에 저장
	while (!is_empty(&q)) {
		v = dequeue(&q); // 큐에서 정점 제거
		for (w = 0; w < g->n; w++) // 인접 정점 탐색
			if (g->adj_mat[v][w] && !visited[w]) {
				printf("%d ", w); // 정점 방문 및 출력
				visited[w] = 1; // 정점 w의 방문 표시
				enqueue(&q, w); // 방문한 정점을 큐에 저장
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