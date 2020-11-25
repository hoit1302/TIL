#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

// 선택정렬: O(n^2), 오른쪽 리스트에서 최소값을 '선택'하여 오른쪽 리스트의 첫번째 수와 교환
void selection_sort(int list[], int n) {
    int i, j, least, temp = 0;
    for (i = 0; i < n - 1; i++) {
        least = i; // least: 오른쪽 리스트에서의 최솟값을 가리키는 인덱스
        for (j = i + 1; j < n; j++)
            if (list[j] < list[least]) least = j; // 비교 횟수 (n-1)+(n-2)+...+(1)= n(n-1)/2
        SWAP(list[i], list[least], temp); // 이동 횟수 3(n-1)
    }
}

// 삽입 정렬: O(n^2), 정렬되어 있는 앞 부분에 새로운 레코드를 '올바른 위치에 삽입'하는 과정 반복
// 이미 정렬 된 경우 n-1번 비교. 두번째 for loop에서 한 번씩!
void insertion_sort(int list[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = list[i]; // 내가 쥔 카드
        for (j = i - 1; j >= 0 && list[j] > key; j--) // 비교 횟수
            list[j + 1] = list[j]; // 레코드의 오른쪽 이동
        list[j + 1] = key; // 빈자리 혹은 원래 자리에 잘 넣기
    }
}

// 버블 정렬 O(n^2), 인접한 2개의 레코드의 키를 비교하여 순서대로 되어 있지 않으면 서로 교환
void bubble_sort(int list[], int n) {
    int i, j, temp = 0;
    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) // 앞뒤의 레코드를 비교한 후 교환
            if (list[j] > list[j + 1])
                SWAP(list[j], list[j + 1], temp);
    }
}

// 개선된 버블 정렬 O(n^2), 한 번도 swap이 되지 않았을 경우 결과 반환
// 최선의 경우 O(n)
// 배열의 뒷부분부터 인접한 원소를 비교하여 작은 원소를 앞으로 보내는 개선된 버블 정렬 알고리즘
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

// 개선된 버블 정렬 O(n^2), 한 번도 swap이 되지 않았을 경우 결과 반환
// 최선의 경우 O(n)
// 배열의 앞부분부터 인접한 원소를 비교하여 큰 원소를 뒤로 보내는 개선된 버블 정렬 알고리즘
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