#include <stdio.h>
#include <stdlib.h>
void error(const char* string) {
	printf(string);
}
// singly-linked-list �ܼ�-����-����Ʈ

//head pointer: ���� ����Ʈ�� ��ǥ ��� (��: �� ó�� ���)�� ����Ű�� ������ ����
//��� �����Ͱ� �Լ� �ȿ��� ����ǹǷ� ��� �������� ������ �ʿ�!
typedef int element;
typedef struct _ListNode {
	element data; // ������ �ʵ�
	struct _ListNode *link; // ��ũ �ʵ�
} ListNode;

//���� �Լ��� ������Ÿ�� ����
//phead: ��� ������ head�� ���� ������
//p: ���Ե� ��ġ�� ���� ��带 ����Ű�� ������. �� ��� ������ ���Եȴ�.
//new_node: ���ο� ��带 ����Ű�� ������
void insert_node(ListNode** phead, ListNode* p, ListNode* new_node) {
	// ������ 3���� ���
	// 1 ��������Ͱ� NULL�� ���: ���� ����Ʈ�� ����
	if (*phead == NULL) { //*phead�� ����Ű�� ���� �ּ� ��
		*phead = new_node;
		new_node->link = NULL;
	}
	// 2 p�� NULL�� ���: ����Ʈ�� �� ó���� ����
	else if (p == NULL) {
		new_node->link = *phead;
		*phead = new_node;
	}
	// 3 �Ϲ����� ���: ����Ʈ�� �߰��� ����
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
}

//���� �Լ��� ������Ÿ�� ����
//phead: ��� ������ head�� ���� ������
//p: ������ ����� ���� ��ġ�� ����Ű�� ������
//removed: ������ ��带 ����Ű�� ������
void remove_node(ListNode** phead, ListNode* p, ListNode* removed) {
	//������ 2���� ���
	// 1 p�� NULL�� ���: �� ���� ���(ù��° ���)�� ����. ��������� ����
	if (p == NULL)
		*phead = (*phead)->link;
	// 2 p�� NULL�� �ƴ� ���: p ���� ���(�߰� ���)�� ����. removed ���� ����� p�� ��ũ�� removed ���� ��带 ����Ű���� ����
	else 
		p->link = removed->link;
	free(removed);
}

// ������ p�� ����Ű�� ����� ���� ��带 �����ϴ� ����(�Լ�)
// ��Ʈ: p�� ������ ����� ��츦 ����ؾ� ��!
void remove_node(ListNode* L, ListNode* p) {
	ListNode* temp;
	temp = p->link;
	if (temp == NULL)
		error("p�� ���� ��尡 �����Ƿ� ������ �� ����");
	else {
		p->link = temp->link; // p->link = p->link->link; �� �� �� ����.
		free(temp);
	}
}
//�湮 ����: ����Ʈ ���� ��带 ���������� �湮�Ͽ� �����͸� �����.
//1 �ݺ� ��� O(n)-time, O(1)-space
void visit(ListNode* head) {
	ListNode* p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n");
}
//2 ��� ��� O(n)-time, O(n)-space
void visit_recur(ListNode* head) {
	ListNode* p = head;
	if (p != NULL) {
		printf("%d->", p->data);
		visit_recur(p->link);
	}
}
// Ž�� ����: Ư���� ������ ���� ���� ��带 ã�� ���� (���� Ž�� ���)
ListNode* search(ListNode* head, element x) {
	ListNode* p;
	p = head;
	while (p != NULL) {
		if (p->data == x) return p; // Ž�� ����
		p = p->link;
	}
	return p; // Ž�� ������ ��� NULL ��ȯ (p�� NULL��)
}

// ���� ����: 2���� ����Ʈ�� �ϳ��� ��ġ�� ����
ListNode* concat(ListNode* head1, ListNode* head2) {
	ListNode* p;
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		p = head1;
		// ������ ���� �����ϱ�
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}
// ����(reverse) ����: ����Ʈ�� ������ �������� ����� ����
ListNode* reverse(ListNode* head) {
	// �����ͷ� p, q, r 3���� ���
	//p: ���� ó������ ���� ���
	//q: ���� �������� ���� ���
	//r: �̹� �������� ����� ���
	ListNode* p, * q, * r;
	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}
void main() {
	//����� ����
	ListNode* p1;
	p1 = (ListNode*)malloc(sizeof(ListNode));
	p1->data = 10;
	p1->link = NULL;

	// �ι�° ��� ������ ù��° ������ ����
	ListNode* p2;
	p2 = (ListNode*)malloc(sizeof(ListNode));
	p2->data = 20;
	p2->link = NULL;
	p1->link = p2;

}
