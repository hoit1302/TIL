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
// ���� �ȵ� ���� �� �ּ� dist[v] ���� ���� ������ ��ȯ
int get_min_vertex(int n) {
	// �ʱ�ȭ
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

	for (u = 0; u < n; u++) { // �ʱ�ȭ
		dist[u] = INF; selected[u] = FALSE;
	}
	
	dist[s] = 0; // start vertex
	for (i = 0; i < n; i++) { // ���õ� �������տ��� ���õ��� ����
		u = get_min_vertex(n); // ���� �������� ���� ���� dist�� ����
		selected[u] = TRUE; // ���� ã�� (u ã��)
		if (dist[u] == INF) return;	// ��� ������ ����Ǿ� ���� ����.
		printf("%d ", u);
		
		// �������� u�κ��� ���� �ȵ� ������ dist ����
		for (v = 0; v < n; v++) 
			if (weight[u][v] != INF) // ������ �Ǿ� �ְ�
				if (!selected[v] && weight[u][v] < dist[v]) // �湮���� �ʾ����� v������ ���̰� �� ª����
					dist[v] = weight[u][v]; // dist �ٲ��ֱ�
	}
}

void main() {
	prim(0, MAX_VERTICES);
}