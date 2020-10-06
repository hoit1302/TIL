#include <stdio.h>

typedef int element;
typedef struct _ListNode {
	element data;
	struct _ListNode* link;
} ListNode;


#include <stdio.h>
// 두 개의 단순 연결리스트를 하나로 병합하는 O(n1) - 시간 알고리즘
ListNode* concat(ListNode* head1, ListNode* head2) {
	ListNode* p;
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

// quiz
// 두 개의 환형 연결리스트를 하나로 병합하는 O(1) - 시간 알고리즘
ListNode* concatenate(ListNode* chead1, ListNode* chead2) {
	ListNode* temp;
	if (chead1 == NULL) return chead2;
	else if (chead2 == NULL) return chead1;
	else {
		temp = chead1->link;
		chead1->link = chead2->link;
		chead2->link = temp;
		return chead2;
	}
}