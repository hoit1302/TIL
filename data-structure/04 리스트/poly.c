#include <stdio.h>
#include <stdlib.h>
void error(const char* string) {
	printf(string);
}
// 연결 리스트의 노드의 구조
typedef struct ListNode {
	int coef;
	int exp;
	struct ListNode* link;
} ListNode;

// 연결 리스트 헤더
typedef struct ListHeader {
	int length;
	ListNode* head;
	ListNode* tail;
} ListHeader;

// 초기화 함수
void init(ListHeader* plist) {
	plist->length = 0;
	plist->head = plist->tail = NULL;
}

// plist는 연결 리스트의 헤더를 가리키는 포인터, coef는 계수, exp는 지수
void insert_node_last(ListHeader* plist, int coef, int exp) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
	else {
		temp->coef = coef;
		temp->exp = exp;
		temp->link = NULL;
		if (plist->tail == NULL) {
			plist->head = plist->tail = temp;
		}
		else {
			plist->tail->link = temp;
			plist->tail = temp;
		}
		plist->length++;
	}
}

// list3 = list1 + list2
void poly_add(ListHeader* plist1, ListHeader* plist2, ListHeader* plist3)
{
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;
	while (a && b) {
		if (a->exp == b->exp) { // a의 차수 > b의 차수
			sum = a->coef + b->coef;
			if (sum != 0) insert_node_last(plist3, sum, a->exp);
			a = a->link; b = b->link;
		}
		else if (a->exp > b->exp) { // a의 차수 == b의 차수
			insert_node_last(plist3, a->coef, a->exp);
			a = a->link;
		}
		else { // a의 차수 < b의 차수
			insert_node_last(plist3, b->coef, b->exp);
			b = b->link;
		}
	}

	// a나 b 중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두 결과 다항식으로 복사
	for (; a != NULL; a = a->link)
		insert_node_last(plist3, a->coef, a->exp);
	for (; b != NULL; b = b->link)
		insert_node_last(plist3, b->coef, b->exp);
}

//
void poly_print(ListHeader* plist)
{
	ListNode* p = plist->head;
	for (; p; p = p->link) {
		printf("%d %d\n", p->coef, p->exp);
	}
}

//
void main() {
	ListHeader list1, list2, list3;
	// 연결 리스트의 초기화
	init(&list1);
	init(&list2);
	init(&list3);
	// 다항식 1을 생성
	insert_node_last(&list1, 3, 12);
	insert_node_last(&list1, 2, 8);
	insert_node_last(&list1, 1, 0);
	// 다항식 2를 생성
	insert_node_last(&list2, 8, 12);
	insert_node_last(&list2, -3, 10);
	insert_node_last(&list2, 10, 6);
	// 다항식 3 = 다항식 1 + 다항식 2
	poly_add(&list1, &list2, &list3);
	poly_print(&list3);
}