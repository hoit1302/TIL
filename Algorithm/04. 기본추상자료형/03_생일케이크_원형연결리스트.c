#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int elem;
    struct Node* next;
}Node;
Node* L;

Node* getNode() {
    Node* node = malloc(sizeof(Node));
    return node;
}

void putNode(Node* pNext) {
    free(pNext);
}

Node* buildList(int n) {
    Node* p = getNode();
    L = p;
    p->elem = 1;
    for (int i = 2; i <= n; i++) {
        p->next = getNode();
        p = p->next;
        p->elem = i;
    }
    p->next = L;
    return L;
}

int runSimulation(Node* L, int n, int k) {
    Node* p = L;
    while (p != p->next) {
        for (int i = 1; i < k; i++) {
            p = p->next;
        }
        Node* pNext = p->next;
        p->next = p->next->next;
        putNode(pNext);
        p = p->next;
    }
    return p->elem;
}

int candle(int n, int k) {
    L = buildList(n);
    return runSimulation(L, n, k);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", candle(n, k));
    return 0;
}