#include <stdio.h>
#include <stdlib.h>
void error(const char* string) {
	printf(string);
}
// singly-linked-list 단순-연결-리스트

//head pointer: 연결 리스트의 대표 노드 (예: 맨 처음 노드)를 가리키는 포인터 변수
//헤드 포인터가 함수 안에서 변경되므로 헤드 포인터의 포인터 필요!
typedef int element;
typedef struct _ListNode {
	element data; // 데이터 필드
	struct _ListNode *link; // 링크 필드
} ListNode;

//삽입 함수의 프로토타입 설명
//phead: 헤드 포인터 head에 대한 포인터
//p: 삽입될 위치의 선행 노드를 가리키는 포인터. 이 노드 다음에 삽입된다.
//new_node: 새로운 노드를 가리키는 포인터
void insert_node(ListNode** phead, ListNode* p, ListNode* new_node) {
	// 삽입의 3가지 경우
	// 1 헤드포인터가 NULL인 경우: 공백 리스트에 삽입
	if (*phead == NULL) { //*phead는 가리키는 곳의 주소 값
		*phead = new_node;
		new_node->link = NULL;
	}
	// 2 p가 NULL일 경우: 리스트의 맨 처음에 삽입
	else if (p == NULL) {
		new_node->link = *phead;
		*phead = new_node;
	}
	// 3 일반적인 경우: 리스트의 중간에 삽입
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
}

//삭제 함수의 프로토타입 설명
//phead: 헤드 포인터 head에 대한 포인터
//p: 삭제될 노드의 선행 위치를 가리키는 포인터
//removed: 삭제될 노드를 가리키는 포인터
void remove_node(ListNode** phead, ListNode* p, ListNode* removed) {
	//삭제의 2가지 경우
	// 1 p가 NULL일 경우: 맨 앞의 노드(첫번째 노드)를 삭제. 헤드포인터 변경
	if (p == NULL)
		*phead = (*phead)->link;
	// 2 p가 NULL이 아닌 경우: p 다음 노드(중간 노드)를 삭제. removed 앞의 노드인 p의 링크가 removed 다음 노드를 가리키도록 변경
	else 
		p->link = removed->link;
	free(removed);
}

// 포인터 p가 가리키는 노드의 다음 노드를 삭제하는 연산(함수)
// 힌트: p가 마지막 노드인 경우를 고려해야 함!
void remove_node(ListNode* L, ListNode* p) {
	ListNode* temp;
	temp = p->link;
	if (temp == NULL)
		error("p의 다음 노드가 없으므로 제거할 수 없음");
	else {
		p->link = temp->link; // p->link = p->link->link; 로 쓸 수 있음.
		free(temp);
	}
}
//방문 연산: 리스트 상의 노드를 순차적으로 방문하여 데이터를 출력함.
//1 반복 기법 O(n)-time, O(1)-space
void visit(ListNode* head) {
	ListNode* p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n");
}
//2 재귀 기법 O(n)-time, O(n)-space
void visit_recur(ListNode* head) {
	ListNode* p = head;
	if (p != NULL) {
		printf("%d->", p->data);
		visit_recur(p->link);
	}
}
// 탐색 연산: 특정한 데이터 값을 갖는 노드를 찾는 연산 (순차 탐색 방법)
ListNode* search(ListNode* head, element x) {
	ListNode* p;
	p = head;
	while (p != NULL) {
		if (p->data == x) return p; // 탐색 성공
		p = p->link;
	}
	return p; // 탐색 실패일 경우 NULL 반환 (p가 NULL임)
}

// 병합 연산: 2개의 리스트를 하나로 합치는 연산
ListNode* concat(ListNode* head1, ListNode* head2) {
	ListNode* p;
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		p = head1;
		// 끝까지 가서 연결하기
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}
// 역순(reverse) 연산: 리스트의 노드들을 역순으로 만드는 연산
ListNode* reverse(ListNode* head) {
	// 포인터로 p, q, r 3개를 사용
	//p: 아직 처리되지 않은 노드
	//q: 현재 역순으로 만들 노드
	//r: 이미 역순으로 변경된 노드
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
	//노드의 생성
	ListNode* p1;
	p1 = (ListNode*)malloc(sizeof(ListNode));
	p1->data = 10;
	p1->link = NULL;

	// 두번째 노드 생성과 첫번째 노드와의 연결
	ListNode* p2;
	p2 = (ListNode*)malloc(sizeof(ListNode));
	p2->data = 20;
	p2->link = NULL;
	p1->link = p2;

}
