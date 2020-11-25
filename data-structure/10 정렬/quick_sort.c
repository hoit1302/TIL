#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;
	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++; // �ǹ����� ������ ��� �̵�
		while (low <= right && list[low] < pivot);
		do
			high--; // �ǹ����� ũ�� ��� �̵�
		while (high >= left && list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);
	SWAP(list[left], list[high], temp); // list[left]: list[high]:���ʹ迭�� ���� ������ ��
	return high; // �ప�� ��ġ ��ȯ
}

void quick_sort(int list[], int left, int right) {
	if (left < right) { // ������ ������ 2�� �̻��� �������̸�
		// 1. partition �Լ� ȣ��� �ప�� �������� 2���� ����Ʈ�� ���� (partition �Լ��� ��ȯ ���� �ప�� ��ġ)
		int q = partition(list, left, right);
		// 2. left���� �ప �ٷ� �ձ����� ������� ��� ȣ��(�ప ����)
		quick_sort(list, left, q - 1);
		// 3. �ప �ٷ� �������� right������ ������� ��� ȣ��(�ప ����)
		quick_sort(list, q + 1, right);
	}
}
int main() {
	int list[8] = { 7, 3, 5, 2, 8, 6, 4, 1 };
	quick_sort(list, 0, 7);
	return 0;
}