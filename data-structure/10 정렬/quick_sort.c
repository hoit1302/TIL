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
			low++; // 피벗보다 작으면 계속 이동
		while (low <= right && list[low] < pivot);
		do
			high--; // 피벗보다 크면 계속 이동
		while (high >= left && list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);
	SWAP(list[left], list[high], temp); // list[left]: list[high]:왼쪽배열의 가장 오른쪽 값
	return high; // 축값의 위치 반환
}

void quick_sort(int list[], int left, int right) {
	if (left < right) { // 정렬할 범위가 2개 이상의 데이터이면
		// 1. partition 함수 호출로 축값을 기준으로 2개의 리스트로 분할 (partition 함수의 반환 값이 축값의 위치)
		int q = partition(list, left, right);
		// 2. left에서 축값 바로 앞까지를 대상으로 재귀 호출(축값 제외)
		quick_sort(list, left, q - 1);
		// 3. 축값 바로 다음부터 right까지를 대상으로 재귀 호출(축값 제외)
		quick_sort(list, q + 1, right);
	}
}
int main() {
	int list[8] = { 7, 3, 5, 2, 8, 6, 4, 1 };
	quick_sort(list, 0, 7);
	return 0;
}