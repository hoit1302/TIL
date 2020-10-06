#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 이중 연결 리스트 Doubly linked list

// 단순 연결 리스트의 문제점: 선행 노드를 찾기가 어렵다.
// 어떤 노드를 삭제하거나 앞쪽에 삽입 시에는 반드시 선행노드가 필요.

// 링크가 양방향이므로 양방향으로 검색이 가능
// 단점은 공간을 많이 차지하고 코드가 상대적으로 복잡
// 실제 사용되는 일반적인 이중 연결 리스트의 형태는
// "헤드노드" + 이중연결리스트 + 환형연결리스트

// 헤드 노드: 데이터는 저장되지 않고 단지 삽입, 삭제 연산을 간단하게 할 목적으로 만들어진 특별한 노드.
// 공백 상태에서는 헤드 노드만 존재. 헤드 포인터와는 서로 의미가 다름.
typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
} DlistNode;

// new_node를 노드 before의 오른쪽에 삽입
void dinsert_node_before(DlistNode* before, DlistNode* new_node) {
	new_node->llink = before;
	new_node->rlink = before->rlink;
	before->rlink->llink = new_node;
	before->rlink = new_node;
}

// new_node를 노드 before의 오른쪽에 삽입 (퀴즈)
void dinsert_node_after(DlistNode* after, DlistNode* new_node) {
	new_node->llink = after->llink;
	new_node->rlink = after;
	after->llink->rlink = new_node;
	after->llink = new_node;
}

// 노드 removed를 삭제한다.
void dremove_node(DlistNode* phead_node, DlistNode* removed)
{
	if (removed == phead_node) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}
