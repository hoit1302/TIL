#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

// ��������: O(n^2), ������ ����Ʈ���� �ּҰ��� '����'�Ͽ� ������ ����Ʈ�� ù��° ���� ��ȯ
void selection_sort(int list[], int n) {
    int i, j, least, temp = 0;
    for (i = 0; i < n - 1; i++) {
        least = i; // least: ������ ����Ʈ������ �ּڰ��� ����Ű�� �ε���
        for (j = i + 1; j < n; j++)
            if (list[j] < list[least]) least = j; // �� Ƚ�� (n-1)+(n-2)+...+(1)= n(n-1)/2
        SWAP(list[i], list[least], temp); // �̵� Ƚ�� 3(n-1)
    }
}

// ���� ����: O(n^2), ���ĵǾ� �ִ� �� �κп� ���ο� ���ڵ带 '�ùٸ� ��ġ�� ����'�ϴ� ���� �ݺ�
// �̹� ���� �� ��� n-1�� ��. �ι�° for loop���� �� ����!
void insertion_sort(int list[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = list[i]; // ���� �� ī��
        for (j = i - 1; j >= 0 && list[j] > key; j--) // �� Ƚ��
            list[j + 1] = list[j]; // ���ڵ��� ������ �̵�
        list[j + 1] = key; // ���ڸ� Ȥ�� ���� �ڸ��� �� �ֱ�
    }
}

// ���� ���� O(n^2), ������ 2���� ���ڵ��� Ű�� ���Ͽ� ������� �Ǿ� ���� ������ ���� ��ȯ
void bubble_sort(int list[], int n) {
    int i, j, temp = 0;
    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) // �յ��� ���ڵ带 ���� �� ��ȯ
            if (list[j] > list[j + 1])
                SWAP(list[j], list[j + 1], temp);
    }
}

// ������ ���� ���� O(n^2), �� ���� swap�� ���� �ʾ��� ��� ��� ��ȯ
// �ּ��� ��� O(n)
// �迭�� �޺κк��� ������ ���Ҹ� ���Ͽ� ���� ���Ҹ� ������ ������ ������ ���� ���� �˰���
void improved_bubble_sort(int list[], int n) {
    int i, j, temp = 0, flag = TRUE;
    j = 0;
    while ((j < n - 1) && flag) {
        flag = FALSE;
        for (i = n - 1; i > j; i--) 
            if (list[i - 1] > list[i]) {
                SWAP(list[i], list[i - 1], temp);
                flag = TRUE;
            }
        j++;
    }
}

// ������ ���� ���� O(n^2), �� ���� swap�� ���� �ʾ��� ��� ��� ��ȯ
// �ּ��� ��� O(n)
// �迭�� �պκк��� ������ ���Ҹ� ���Ͽ� ū ���Ҹ� �ڷ� ������ ������ ���� ���� �˰���
void improved_bubble_sort2(int list[], int n) {
    int i, j, temp = 0, flag = TRUE;
    j = n - 1;
    while ((0 < j) && flag) {
        flag = FALSE;
        for (i = 0; i < j; i++)
            if (list[i + 1] < list[i]) {
                SWAP(list[i], list[i + 1], temp);
                flag = TRUE;
            }
        j--;
    }
}


int main() {
    int list1[6] = { 7,3,5,2,6,1 };
    selection_sort(list1, 6);

    int list2[6] = { 7,3,5,2,6,1 };
    insertion_sort(list2, 6);

    int list3[6] = { 7,3,5,2,6,1 };
    bubble_sort(list3, 6);

    int list4[6] = { 7,3,5,2,6,1 };
    improved_bubble_sort(list4, 6);

    int list5[6] = { 7,3,5,2,6,1 };
    improved_bubble_sort2(list5, 6);

    return 0;
}