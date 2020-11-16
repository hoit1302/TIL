#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 6
#define INF 1000L

int dist[MAX_VERTICES], selected[MAX_VERTICES];
int weight[MAX_VERTICES][MAX_VERTICES] =
{
	{0 ,13, 8, 1, INF, INF},
	{13, 0, 15, INF, INF, INF},
	{8, 15, 0 ,5, 3, INF},
	{1, INF, 5, 0, 4, 5},
	{INF, INF, 3, 4, 0, 2},
	{INF, INF, INF, 5, 2, 0}
};
// 선택 안된 정점 중 최소 dist[v] 값을 갖는 정점을 반환
int get_min_vertex(int n) {
	// 초기화
	int min_vertex;
	for (int i = 0; i < n; i++)
		if (!selected[i]) { min_vertex = i; break; }

	for (int i = 0; i < n; i++)
		if (!selected[i] && dist[i] < dist[min_vertex]) min_vertex = i;
	return min_vertex;
}
// O(n^2)
void prim(int s, int n) {
	int i, u, v;

	for (u = 0; u < n; u++) { // 초기화
		dist[u] = INF; selected[u] = FALSE;
	}
	
	dist[s] = 0; // start vertex
	for (i = 0; i < n; i++) { // 선택된 정점집합에서 선택되지 않은
		u = get_min_vertex(n); // 정점 집합으로 가는 가장 dist가 적은
		selected[u] = TRUE; // 정점 찾기 (u 찾기)
		if (dist[u] == INF) return;	// 모든 정점이 연결되어 있지 않음.
		printf("%d ", u);
		
		// 선택정점 u로부터 선택 안된 정점의 dist 재계산
		for (v = 0; v < n; v++) 
			if (weight[u][v] != INF) // 연결이 되어 있고
				if (!selected[v] && weight[u][v] < dist[v]) // 방문하지 않았으며 v까지의 길이가 더 짧으면
					dist[v] = weight[u][v]; // dist 바꿔주기
	}
}

void main() {
	prim(0, MAX_VERTICES);
}