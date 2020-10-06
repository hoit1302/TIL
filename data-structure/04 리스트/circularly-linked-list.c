#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Circularly linked list
// ������ ����� ��ũ�� ù��° ��带 ����Ű�� ����Ʈ
// �� ��忡�� �ٸ� ��� ���� ������ ����
// ��� �����Ͱ� ������ ��带 ����Ű�Բ� ���� -> ó���� ������ ��� ���� �� �� ����

typedef int element;
typedef struct _ListNode {
	element data;
	struct _ListNode* link;
} ListNode;


// phead : ����Ʈ�� ��� �������� ������
// node : ���Ե� ���
void insert_first(ListNode** phead, ListNode* node)
{
	if (*phead == NULL) { // �������. �� ���� ���� ����.
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