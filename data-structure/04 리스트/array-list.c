#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_LIST_SIZE 100

void error(const char* string) {
	printf(string);
}

// �迭�� ������ ����Ʈ
typedef int element;
typedef struct {
	element list[MAX_LIST_SIZE]; // �迭 ����
	int length; // ���� �迭�� ����� ���ҵ��� ����, "�� ���� ��ġ + 1"
} ArrayListType;

// ����Ʈ �ʱ�ȭ
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
	if (is_full(L))
		error("����Ʈ L�� �� �� �����Ƿ� ���� �Ұ���");
	 else {
		L->list[L->length] = item;
		L->length++;
	}
}
// ���ϴ� ��ġ�� �ִ´ٱ⺸�� ó�� �߰��� ���� or �������� �߰�
void add(ArrayListType* L, int position, element item) {
	if (is_full(L))
		error("����Ʈ L�� �� �� �����Ƿ� ���� �Ұ���");
	else if (position < 0 || L->length < position)
		error("���� ������ ��ġ�� �ƴϹǷ� ���� �Ұ���");
	else {
		for (int i = (L->length - 1); i >= position; i--)
			L->list[i + 1] = L->list[i];
		L->list[position] = item;
		L->length++;
	}
}
// ���� ���� �������� ����. ���� ����Ű�� �����͸� ��ȭ��ų ��.
// ��ȯ��: �����Ǵ� �ڷ�
element delete_last(ArrayListType* L) {
	element item;

	if (is_empty(L))
		error("����Ʈ L�� ��������Ƿ� ���� �Ұ���");
	 else {
		item = L->list[L->length - 1];
		L->length--;
		return item;
	}
}

element delete(ArrayListType* L, int position) {
	int i;
	element item;

	if (is_empty(L))
		error("����Ʈ L�� ��������Ƿ� ���� �Ұ���");
	else if (position < 0 || L->length <= position)
		error("��ġ ����");
	else {
		item = L->list[position];
		for (i = position; i < (L->length - 1); i++)
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
