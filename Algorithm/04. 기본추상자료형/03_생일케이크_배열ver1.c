#include <stdio.h>
#include <stdlib.h>

int* A;

void buildList(int* A, int n) {
    for (int r = 0; r < n; r++)
        A[r] = r + 1;
}

int runSimulation(int* A, int n, int k) {
    int N = n;
    int r = 0;
    while (n > 1) {
        int i = 0;
        while (i < k) {
            r = (r + 1) % N;
            if (A[r] != 0)
                i++;
        }
        A[r] = 0;
        n--;
        while (A[r] == 0)
            r = (r + 1) % N;
    }
    return A[r];
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
