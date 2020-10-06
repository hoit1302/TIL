#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ���� ���� ����Ʈ Doubly linked list

// �ܼ� ���� ����Ʈ�� ������: ���� ��带 ã�Ⱑ ��ƴ�.
// � ��带 �����ϰų� ���ʿ� ���� �ÿ��� �ݵ�� �����尡 �ʿ�.

// ��ũ�� ������̹Ƿ� ��������� �˻��� ����
// ������ ������ ���� �����ϰ� �ڵ尡 ��������� ����
// ���� ���Ǵ� �Ϲ����� ���� ���� ����Ʈ�� ���´�
// "�����" + ���߿��Ḯ��Ʈ + ȯ�����Ḯ��Ʈ

// ��� ���: �����ʹ� ������� �ʰ� ���� ����, ���� ������ �����ϰ� �� �������� ������� Ư���� ���.
// ���� ���¿����� ��� ��常 ����. ��� �����Ϳʹ� ���� �ǹ̰� �ٸ�.
typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
} DlistNode;

// new_node�� ��� before�� �����ʿ� ����
void dinsert_node_before(DlistNode* before, DlistNode* new_node) {
	new_node->llink = before;
	new_node->rlink = before->rlink;
	before->rlink->llink = new_node;
	before->rlink = new_node;
}

// new_node�� ��� before�� �����ʿ� ���� (����)
void dinsert_node_after(DlistNode* after, DlistNode* new_node) {
	new_node->llink = after->llink;
	new_node->rlink = after;
	after->llink->rlink = new_node;
	after->llink = new_node;
}

// ��� removed�� �����Ѵ�.
void dremove_node(DlistNode* phead_node, DlistNode* removed)
{
	if (removed == phead_node) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}
