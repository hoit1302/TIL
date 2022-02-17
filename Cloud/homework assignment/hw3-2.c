/*
 * find the problems
*/

/*
int foo(int N, int *a, int *b, int *c, int *d) {
    double tmp, total = 0;
    #pragma omp parallel
    {
        #pragma omp sections
        {
             #pragma omp for
             for (int i = 0; i < N; i++) {
                 a[b[i]] += b[i];
                 total += b[i];
             }
         }
        #pragma omp section
        {
            #pragma omp for
            for (int i = 0; i < N; i++) {
                tmp = c[i];
                c[i] = d[i];
                d[i] = tmp;
                total += c[i];
            }
            #pragma omp for
            for (int i = 0; i < N; i++) {
                total += d[i];
            }
        }
    }
    return total;
}

*/

// 찾은 문제점을 서술하고 고쳐서 제출

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

// #pragma omp section directive는 단독으로 사용될 수 없다. #pragma omp sections의 영역 안에 있어야 한다.
// #pragma omp section 부분에는 thread 하나가 할당되어 #pragma omp for directive를 통한 병렬처리를 수행할 수 없기에 해당 부분은 삭제하였다.
int foo(int N, int *a, int *b, int *c, int *d) {
    double tmp, total = 0;
    #pragma omp parallel shared(N, a, b, c, d)
    {
        #pragma omp sections
        {
            #pragma omp section
            for (int i = 0; i < N; i++) {
                a[b[i]] += b[i];
                total += b[i];
            }
            #pragma omp section
            {
                for (int i = 0; i < N; i++) {
                    tmp = c[i];
                    c[i] = d[i];
                    d[i] = tmp;
                    total += c[i];
                }
                for (int i = 0; i < N; i++) {
                    total += d[i];
                }
            }
        }
    }
    return total;
}

void print_vector(char letter, int *a, int N) {
    printf("%c: [", letter);
    for (int i = 0; i < N - 1; i++)
        printf("%d, ", a[i]);
    printf("%d]\n", a[N - 1]);
}

int main(int argc, char *argv[]) {
    int N = 1e1;         // vector size: N
    int *a, *b, *c, *d;  // create vector
    a = (int *)malloc(sizeof(int) * N);
    b = (int *)malloc(sizeof(int) * N);
    c = (int *)malloc(sizeof(int) * N);
    d = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) a[i] = 0;
    for (int i = 0; i < N; i++) b[i] = 1;
    for (int i = 0; i < N; i++) c[i] = 2;
    for (int i = 0; i < N; i++) d[i] = 3;

    printf("total: %d\n", foo(N, a, b, c, d));

    print_vector('a', a, N);  // a[1] = 10
    print_vector('b', b, N);  // 모두 1 (변화없음)
    print_vector('c', c, N);  // 모두 3
    print_vector('d', d, N);  // 모두 2

    return 0;
}
