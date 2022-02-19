#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 100

int main(int argc, char *argv) {
    omp_set_num_threads(1);  //set number of threads here
    int i, j, k;
    double sum;
    double start, end;  // used for timing
    double A[N][N], B[N][N], C[N][N];
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = j * 1;
            B[i][j] = i * j + 2;
            C[i][j] = j - i * 2;
        }
    }
    
    start = omp_get_wtime();  //start time measurement
    #pragma omp parallel for shared(A, B, C) private(i, j, k) 
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            C[i][j] = 0;
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    end = omp_get_wtime();  //end time measurement
    printf("Time of computation: %f seconds\n", end - start);
    return (0);
}

/*
각 thread 개수 별 실행했을 때 걸린 시간의 평균 값
thread 1	thread 2	thread 4	thread 8
0.006570	0.004268	0.003728	0.004991


세부적으로 실험한 결과값은 아래와 같습니다.
	thread 1	thread 2	thread 4	thread 8

1st	0.006676	0.003704	0.002911	0.006582
2nd	0.006490	0.005872	0.003085	0.004629
3rd	0.006552	0.003507	0.004445	0.004705
4th	0.006528	0.003771	0.003863	0.005204
5th	0.006603	0.004485	0.004335	0.003834

avg	0.006570	0.004268	0.003728	0.004991
*/