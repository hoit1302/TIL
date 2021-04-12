#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *link;
} ListNode;

typedef struct
{
    ListNode *head;
} LinkedListType;

void init(LinkedListType *L) {
    L->head = NULL;
}

void add(LinkedListType *L, int pos, int item) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    ListNode *before = L->head;
    for (int i = 0; i < pos - 1; i++)
        before = before->link;
    node->data = item;
    node->link = before->link;
    before->link = node;
}

void addFirst(LinkedListType *L, int item) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = item;
    node->link = L->head;
    L->head = node;
}

void addLast(LinkedListType *L, int item) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    ListNode *before = L->head;
    while (before->link != NULL) {
        before = before->link;
    }
    node->data = item;
    node->link = NULL;
    before->link = node;
}

int get(LinkedListType *L, int pos) {
    ListNode *p = L->head;
    for (int i = 1; i < pos; i++)
        p = p->link;
    return p->data;
}

void set(LinkedListType *L, int pos, int item) {
    ListNode *p = L->head;
    for (int i = 1; i < pos; i++)
        p = p->link;
    p->data = item;
}

void Remove(LinkedListType *L, int pos) {
    ListNode *before = L->head;
    for (int i = 1; i < pos; i++)
        before = before->link;
    ListNode *remNode = before->link;
    if (remNode->link == NULL)
        before->link = NULL;
    else
        before->link = remNode->link;
    free(remNode);
}

void RemoveFirst(LinkedListType *L) {
    ListNode *remNode = L->head;
    L->head = remNode->link;
    free(remNode);
}

void RemoveLast(LinkedListType *L) {
    ListNode *before = L->head;
    while (before->link->link != NULL) {
        before = before->link;
    }
    free(before->link);
    before->link = NULL;
}

void printList(LinkedListType *L) {
    for (ListNode *p = L->head; p != NULL; p = p->link)
        printf("[%d] -> ", p->data);
    printf("NULL\n");
}

void main() {
    LinkedListType list;
    init(&list);
    printf("[*] addFirst(15), addFirst(30) \n");
    addFirst(&list, 15);
    printList(&list);
    addFirst(&list, 30);
    printList(&list);
    getchar();
    printf("[*] add(&list,1,40). add(&list,2,50)\n");
    add(&list, 1, 40);
    printList(&list);
    add(&list, 2, 50);
    printList(&list);

    printf("[*] addLast(&list,100) \n");
    addLast(&list, 100);
    printList(&list);

    getchar();

    printf("[*] remove(&list,4) \n");
    Remove(&list, 4);
    printList(&list);

    int pos;
    printf("\nwhich number of nodes to return ? ");
    scanf("%d", &pos);
    printf("%d th node's value is %d\n", pos, get(&list, pos));
    getchar();

    printf("[*] RemoveFirst\n");
    RemoveFirst(&list);
    printList(&list);
    getchar();

    printf("[*] RemoveLast \n");
    RemoveLast(&list);
    printList(&list);
}