#include <stdio.h>
#include <stdlib.h>

int* A;

void buildList(int* A, int n) {
    for (int r = 0; r < n; r++)
        A[r] = r + 1;
}

void remove_candle(int r, int n) {
    for (int i = r; i < n - 1; i++) 
        A[i] = A[i + 1];
}
int runSimulation(int* A, int n, int k) {
    int r = 0;
    while (n > 1) {
        r = (r + k) % n;
        remove_candle(r, n);
        n--;
    }
    return A[0];
}

int candle(int n, int k) {
    buildList(A, n);
    return runSimulation(A, n, k);
}

void main() {
    int n, k;
    scanf("%d %d", &n, &k);
    A = (int*)malloc(sizeof(int) * n);
    printf("%d\n", candle(n, k));
    free(A);
}
