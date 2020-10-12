#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_LIST_SIZE 100

void error(const char* string) {
	printf(string);
}

// 배열로 구현된 리스트
typedef int element;
typedef struct {
	element list[MAX_LIST_SIZE]; // 배열 정의
	int length; // 현재 배열에 저장된 원소들의 개수, "끝 원소 위치 + 1"
} ArrayListType;

// 리스트 초기화
void init(ArrayListType* L) {
	L->length = 0;
}
int is_empty(ArrayListType* L) {
	return (L->length == 0);
}
int is_full(ArrayListType* L) {
	return (L->length == MAX_LIST_SIZE);
}
void add_last(ArrayListType* L, element item) {
	if (is_full(L))	error("리스트 L이 꽉 차 있으므로 삽입 불가능");
	 else 		L->list[L->length++] = item;
}
// 원하는 위치에 넣는다기보다 처음 중간에 삽입 or 마지막에 추가
void add(ArrayListType* L, int position, element item) {
	if (is_full(L))
		error("리스트 L이 꽉 차 있으므로 삽입 불가능");
	else if (position < 0 || L->length < position)
		error("접근 가능한 위치가 아니므로 삽입 불가능");
	else {
		for (int i = (L->length - 1); i >= position; i--)
			L->list[i + 1] = L->list[i];
		L->list[position] = item;
		L->length++;
	}
}
// 값을 직접 삭제하진 않음. 배열의 길이를 줄일 뿐.
// 반환값: 삭제되는 자료
element delete_last(ArrayListType* L) {
	element item;

	if (is_empty(L))
		error("리스트 L이 비어있으므로 제거 불가능");
	 else {
		item = L->list[L->length - 1];
		L->length--;
		return item;
	}
}

element delete(ArrayListType* L, int position) {
	element item;

	if (is_empty(L))
		error("리스트 L이 비어있으므로 제거 불가능");
	else if (position < 0 || L->length <= position)
		error("위치 오류");
	else {
		item = L->list[position];
		for (int i = position; i < (L->length - 1); i++)
			L->list[i] = L->list[i + 1];
		L->length--;
		return item;
	}
}

int main() {
	ArrayListType L;
	init(&L);
	add_last(&L, 1); // 1
	add_last(&L, 2); // 1 2
	add_last(&L, 6); // 1 2 6
	add(&L, 2, 3);   // 1 2 3 6
	add(&L, 3, 4);   // 1 2 3 4 6
	delete_last(&L); // 1 2 3 4
	add_last(&L, 5); // 1 2 3 4 5
	add(&L, 5, 6);   // 1 2 3 4 5 6
	delete(&L, 2);   // 1 2 3 4 5
	add(&L, 10, 6);   // error message

	return 0;
}
