#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10

int sorted[MAX_SIZE]; // �߰� ������ �ʿ�
// i�� ���ĵ� ���ʸ���Ʈ�� ���� �ε���
// j�� ���ĵ� �����ʸ���Ʈ�� ���� �ε���
// k�� ���ĵ� ����Ʈ�� ���� �ε���
void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left; j = mid + 1; k = left;
    // ���� ���ĵ� list�� �պ�
    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    // ���� �ִ� ���ڵ��� �ϰ� ����
    if (i > mid) // ���ʸ���Ʈ�� �̹� �� ���� ���
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    else // �����ʸ���Ʈ�� �̹� �� ���� ���
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];

    // �迭 sorted[]�� ����Ʈ�� �迭 list[]�� ����
    for (l = left; l <= right; l++) list[l] = sorted[l];
}
void merge_sort(int list[], int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2; // ����Ʈ�� �յ����
        merge_sort(list, left, mid); // �κи���Ʈ ����
        merge_sort(list, mid + 1, right);//�κи���Ʈ ����
        merge(list, left, mid, right); // �պ�
    }
}


int main() {
    int temp_list[8] = { 7, 3, 5, 2, 8, 6, 4, 1 };
    merge_sort(temp_list, 0, 7);
	return 0;
}