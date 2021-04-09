#include <stdio.h>

void rprintDigits(int n) {
    if (n < 10)
        printf("%d\n", n);
    else {
        rprintDigits(n / 10); // 몫
        printf("%d\n", n % 10); // 나머지
    }
}

void printDigits() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n < 0)
        printf("Negative!\n");
    else
        rprintDigits(n);
}

int main() {
    printDigits();
}
