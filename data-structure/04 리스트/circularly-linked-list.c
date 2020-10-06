#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Circularly linked list
// 마지막 노드의 링크가 첫번째 노드를 가리키는 리스트
// 한 노드에서 다른 모든 노드로 접근이 가능
// 헤드 포인터가 마지막 노드를 가리키게끔 구성 -> 처음과 마지막 모두 쉽게 알 수 있음

typedef int element;
typedef struct _ListNode {
	element data;
	struct _ListNode* link;
} ListNode;


// phead : 리스트의 헤드 포인터의 포인터
// node : 삽입될 노드
void insert_first(ListNode** phead, ListNode* node)
{
	if (*phead == NULL) { // 비어있음. 한 개를 새로 삽입.
		*phead = node;
		node->link = node;
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node;
	}
}

void insert_last(ListNode** phead, ListNode* node)
{
	if (*phead == NULL) {
		*phead = node;
		node->link = node;
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node;
		*phead = node;
	}
}