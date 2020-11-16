#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 7
#define INF 1000L

int selected[MAX_VERTICES];
int dist[MAX_VERTICES]; // 선택된 정점 집합으로부터 선택 안된 정점들로의 거리
typedef struct graph {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
} graph;


int get_min_vertex(int n) {
	int v, i;
	for (i = 0; i < n; i++)
		if (!selected[i]) { v = i; break; }
	for (i = 0; i < n; i++)
		if (!selected[i] && (dist[i] < dist[v])) v = i;
	return (v);
}

void prim(graph* G, int s) {
	int i, u, v;
	for (u = 0; u < G->n; u++) { // 초기화
		dist[u] = INF; selected[u] = FALSE;
	}
	dist[s] = 0;

	for (i = 0; i < G->n; i++) { // 선택된 정점집합에서 선택되지 않은
		u = get_min_vertex(G->n); // 정점 집합으로 가는 가장 dist가 적은
		selected[u] = TRUE; // 정점 찾기 (u 찾기)
		if (dist[u] == INF) return;
		printf("%d ", u);
		for (v = 0; v < G->n; v++) // 선택정점 u로부터 선택 안된 정점의
			if (G->weight[u][v] != INF) // dist 재계산
				if (!selected[v] && G->weight[u][v] < dist[v])
					dist[v] = G->weight[u][v] ;
	}
}

main() {
	int weight[MAX_VERTICES][MAX_VERTICES] =
	{
		{ 0, 29, INF, INF, INF, 10, INF },
		{ 29, 0, 16, INF, INF, INF, 15 },
		{ INF, 16, 0, 12, INF, INF, INF },
		{ INF, INF, 12, 0, 22, INF, 18 },
		{ INF, INF, INF, 22, 0, 27, 25 },
		{ 10, INF, INF, INF, 27, 0, INF },
		{ INF, 15, INF, 18, 25, INF, 0 }
	};

	graph g;
	g.n = MAX_VERTICES;
	memcpy(g.weight, weight, sizeof(weight));
	prim(&g, 0);
}