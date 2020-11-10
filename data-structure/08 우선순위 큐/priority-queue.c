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

// �ʱ�ȭ �Լ�
init(HeapType* h) {
	h->heap_size = 0;
}
// ���� ���α׷� - upheap O(lgN)
// ���� ������ ������ heap_size�� �� h�� item�� �����Ѵ�.
void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	// ���� �Ž��� �ö󰡸鼭 key�� ���ϴ� ����
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // ���ο� ��带 ����
}
// ���� ���α׷� - downheap O(lgN)
element delete_max_heap(HeapType* h) {
	int parent, child; element item, temp;
	item = h->heap[1]; // return�� root ��
	temp = h->heap[(h->heap_size)--]; // ������ ��带 ��Ʈ��
	parent = 1; child = 2;
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ�� �߿��� �� ū �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break; // ��ġ ã��
		// �Ѵܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

// �켱 ���� ť�� ���� �̿��� ����
void heap_sort(element a[], int n) {
	int i;
	HeapType h;
	init(&h);

	// step1 ���� (������, on-line) - O(NlgN)
	for (i = 0; i < n; i++)
		insert_max_heap(&h, a[i]);
	// step2 ���� - downheap O(NlgN)
	for (i = (n - 1); i >= 0; i--)
		a[i] = delete_max_heap(&h);

}
int main() {
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	
	HeapType heap; // �� ����
	
	init(&heap); // �ʱ�ȭ
	

	// ���� ����
	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	insert_max_heap(&heap, e3);
	// print_heap(&heap);
	
	// ���� ����
	e4 = delete_max_heap(&heap);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(&heap);
	printf("< %d > ", e5.key);
	e6 = delete_max_heap(&heap);
	printf("< %d > ", e6.key);
	
	return 0;
}