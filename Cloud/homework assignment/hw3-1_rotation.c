/*
 * 1. [Rotation] The below code takes a vector and rotates it. That is, it shifts all elements to the
 * left and appends the first element
 */

/*
void rot(int N, double* a) {
    for (int i = 0; i < N – 1; i++) {
         double tmp = a[i];
        a[i] = a[i+1];
        a[i+1] = tmp;
    }
}
*/

// 조건: 
// ① Parallelize the code using OpenMP.
// ② If possible, do not replicate the vector.
// ③ Write a C code for the parallel rotation.

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void rot(int N, double* a) {
    #pragma omp parallel shared(N, a)
    {
        #pragma omp for schedule(static, N)
        for (int i = 0; i < N - 1; i++) {
            double tmp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = tmp;
        }
    }
}

void print_vector(char* letter, double *a, int N) {
    printf("%s: [", letter);
    for (int i = 0; i < N - 1; i++)
        printf("%f, ", a[i]);
    printf("%f]\n", a[N - 1]);
}

int N = 1e1;  // vector size: N
double* a;

int main(int argc, char* argv[]) {
    // create vector
    a = (double*)malloc(sizeof(double) * N);
    for (int i = 0; i < N; i++)
        a[i] = (double)i;
    print_vector("before: a", a, N);

    rot(N, a);

    print_vector("after: a", a, N);
    return 0;
}
