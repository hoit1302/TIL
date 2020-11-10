#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// 초기화 함수
init(HeapType* h) {
	h->heap_size = 0;
}
// 삽입 프로그램 - upheap O(lgN)
// 현재 원소의 개수가 heap_size인 힙 h에 item을 삽입한다.
void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	// 힙을 거슬러 올라가면서 key값 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // 새로운 노드를 삽입
}
// 삭제 프로그램 - downheap O(lgN)
element delete_max_heap(HeapType* h) {
	int parent, child; element item, temp;
	item = h->heap[1]; // return할 root 값
	temp = h->heap[(h->heap_size)--]; // 마지막 노드를 루트로
	parent = 1; child = 2;
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중에서 더 큰 자식노드를 찾는다.
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break; // 위치 찾음
		// 한단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

// 우선 순위 큐인 힙을 이용한 정렬
void heap_sort(element a[], int n) {
	int i;
	HeapType h;
	init(&h);

	// step1 구성 (연속적, on-line) - O(NlgN)
	for (i = 0; i < n; i++)
		insert_max_heap(&h, a[i]);
	// step2 삭제 - downheap O(NlgN)
	for (i = (n - 1); i >= 0; i--)
		a[i] = delete_max_heap(&h);

}
int main() {
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	
	HeapType heap; // 힙 생성
	
	init(&heap); // 초기화
	

	// 삽입 연산
	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	insert_max_heap(&heap, e3);
	// print_heap(&heap);
	
	// 삭제 연산
	e4 = delete_max_heap(&heap);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(&heap);
	printf("< %d > ", e5.key);
	e6 = delete_max_heap(&heap);
	printf("< %d > ", e6.key);
	
	return 0;
}