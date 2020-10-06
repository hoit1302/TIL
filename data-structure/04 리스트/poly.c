#include <stdio.h>
#include <stdlib.h>
void error(const char* string) {
	printf(string);
}
// ���� ����Ʈ�� ����� ����
typedef struct ListNode {
	int coef;
	int exp;
	struct ListNode* link;
} ListNode;

// ���� ����Ʈ ���
typedef struct ListHeader {
	int length;
	ListNode* head;
	ListNode* tail;
} ListHeader;

// �ʱ�ȭ �Լ�
void init(ListHeader* plist) {
	plist->length = 0;
	plist->head = plist->tail = NULL;
}

// plist�� ���� ����Ʈ�� ����� ����Ű�� ������, coef�� ���, exp�� ����
void insert_node_last(ListHeader* plist, int coef, int exp) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("�޸� �Ҵ� ����");
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
		if (a->exp == b->exp) { // a�� ���� > b�� ����
			sum = a->coef + b->coef;
			if (sum != 0) insert_node_last(plist3, sum, a->exp);
			a = a->link; b = b->link;
		}
		else if (a->exp > b->exp) { // a�� ���� == b�� ����
			insert_node_last(plist3, a->coef, a->exp);
			a = a->link;
		}
		else { // a�� ���� < b�� ����
			insert_node_last(plist3, b->coef, b->exp);
			b = b->link;
		}
	}

	// a�� b ���� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵��� ��� ��� ���׽����� ����
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
	// ���� ����Ʈ�� �ʱ�ȭ
	init(&list1);
	init(&list2);
	init(&list3);
	// ���׽� 1�� ����
	insert_node_last(&list1, 3, 12);
	insert_node_last(&list1, 2, 8);
	insert_node_last(&list1, 1, 0);
	// ���׽� 2�� ����
	insert_node_last(&list2, 8, 12);
	insert_node_last(&list2, -3, 10);
	insert_node_last(&list2, 10, 6);
	// ���׽� 3 = ���׽� 1 + ���׽� 2
	poly_add(&list1, &list2, &list3);
	poly_print(&list3);
}