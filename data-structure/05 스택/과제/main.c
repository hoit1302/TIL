#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strlen
#include <ctype.h>  // isdigit
#include <stdlib.h> // exit(1), malloc
#define MAX_STACK_SIZE 100

// �迭���� ���� ����
typedef char element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType* s) {
	s->top = -1;
}
int is_empty(StackType* s) {
	return (s->top == -1);
}
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}
element peak(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->stack[(s->top)];
}


// ���� ǥ����� ���� ǥ������� ��ȯ
int isp(char op) {
	switch (op) {
	case '(':
		return 0;
	case '+': case '-':
		return 12;
	case '*': case '/': case '%':
		return 13;
	case '^':
		return 14;
	case '#':
		return 0;
	}

}
int icp(char op) {
	switch (op) {
	case '(':
		return 20;
	case '+': case '-':
		return 12;
	case '*': case '/': case '%':
		return 13;
	case '^':
		return 15;
	}
}
char* infix_to_postfix(char* exp) {
	char result[100] = {0, }, element, token;
	char* return_result = (char*)malloc(sizeof(char) * 100);

	// ������ ���� ��� (�迭)
	StackType s;
	init(&s);
	push(&s, '#');

	for (int i = 0; i < (int)strlen(exp) - 1; i++) {
		token = exp[i];
		
		if (isdigit(token)) sprintf(result, "%s%c", result, token);
		else if (token == ')') {
			while (peak(&s) != '(') {
				element = pop(&s);
				sprintf(result, "%s%c", result, element);
			}
			pop(&s);
		}
		else {
			while (isp(peak(&s)) >= icp(token)) {
				element = pop(&s);
				sprintf(result, "%s%c", result, element);
			}
			push(&s, token);
		}
	}

	while ((element = pop(&s)) != '#') sprintf(result, "%s%c", result, element);
	strcat(result, ";");
	if (strlen(result))
		strcpy(return_result, result);
	return return_result;
}


// ���Ḯ��Ʈ���� ���� ����
typedef int _element;
typedef struct StackNode {
	_element data;
	struct StackNode* link;
}StackNode;
typedef struct {
	StackNode* top;
}LinkedStackType;
void _init (LinkedStackType* s) {
	s->top = NULL;
}
int _is_empty (LinkedStackType* s) {
	return (s->top == NULL);
}
void _push (LinkedStackType* s, _element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "�޸� �Ҵ翡��\n");
		return;
	}
	else {
		temp->data = item;
		temp->link = s->top;
		s->top = temp;
	}
}
_element _pop (LinkedStackType* s) {
	if (_is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top; // (1)
		int item = temp->data; // (2)
		s->top = s->top->link; // (3)
		free(temp); // (4)
		return item;
	}
}

// ���� ǥ����� ���
int calculate(char operand, int first, int second) {
	switch (operand) {
	case '+':
		return first + second;
	case '-':
		return first - second;
	case '*':
		return first * second;
	case '/':
		return first / second;
	case '%':
		return first % second;
	case '^':
		if (second == 0)
			return 1;
		int result = 1;
		for (int i = 0; i < second; i++)
			result *= first;
		return result;
	}
	return 0;
}
int calculate_postfix(const char* postfix) {
	int result = 0;

	// �ǿ����� ���� ��� (���� ����Ʈ)
	LinkedStackType* s;
	s = (LinkedStackType*)malloc(sizeof(LinkedStackType));
	_init(s);

	for (int i = 0; i < (int)strlen(postfix) - 1; i++) {
		if ((isdigit(postfix[i])))     
			_push(s, postfix[i] - '0');
		else {                         
			int second = _pop(s);      
			int first = _pop(s);
			result = calculate(postfix[i], first, second);
			_push(s, result);          
		}
	}

	return _pop(s);
}


void main() {

	FILE* file = fopen("infix.txt", "r");
	if (file == NULL) {
		printf("������ �� �� �����ϴ�. �����մϴ�.");
		return;
	}

	int n = 0;
	fscanf(file, "%d", &n);
	
	while (n--) {

		// ���� �Է�
		char infix[100] = {0, };
		fscanf(file, "%s", infix);
		printf("postfix notation = ");
		for (int i = 0; i < (int)strlen(infix); i++)
			printf("%c ", infix[i]);
		printf("\n");
		// ���� ǥ����� ���� ǥ������� ��ȯ
		char* postfix = infix_to_postfix(infix);
		printf("postfix notation = ");
		for (int i = 0; i < (int)strlen(postfix); i++)
			printf("%c ", postfix[i]);
		printf("\n");

		// ���� ǥ����� ���
		int result = calculate_postfix(postfix);
		printf("value = %d\n", result);

		free(postfix);
	}
	fclose(file);
	return;
}

