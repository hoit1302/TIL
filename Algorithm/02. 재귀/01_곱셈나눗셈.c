#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// output: a * b
int product(int a, int b) {
    if (b == 1)
        return a;
    else
        return a + product(a, b - 1);
}

// output: a % b
int modulo(int a, int b) {
    if (a < b)
        return a;
    else
        return modulo(a - b, b);
}

// output: a / b
int quotient(int a, int b) {
    if (a < b)
        return 0;
    else
        return 1 + quotient(a - b, b);
}

int main() {
    srand(time(NULL));
    int a = rand() % 10 + 1;
    int b = rand() % 10 + 1;
    printf("%d * %d = %d\n", a, b, product(a, b));
    printf("%d %% %d = %d\n", a, b, modulo(a, b));
    printf("%d / %d = %d\n", a, b, quotient(a, b));
}
