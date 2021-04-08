#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

void makeArray(int A[]) {
    for (int i = 0; i < SIZE; i++)
        A[i] = rand() % 50 + 50;
}

void printArray(int A[]) {
    for (int i = 0; i < SIZE; i++)
        printf("[%d] ", A[i]);
    printf("\n");
}

// O(N^2)
void prefixAvg1(int A[]) {
    int X[SIZE];
    int sum;
    for (int i = 0; i < SIZE; i++) {
        sum = 0;
        for (int j = 0; j <= i; j++)
            sum += A[j];
        X[i] = sum / (i + 1);
    }
    printArray(X);
}

// O(N)
void prefixAvg2(int A[]) {
    int X[SIZE];
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += A[i];
        X[i] = sum / (i + 1);
    }
    printArray(X);
}

int main() {
    int A[SIZE];
    srand(time(NULL));
    makeArray(A);
    printArray(A);
    getchar();

    prefixAvg1(A);
    prefixAvg2(A);
    return 0;
}