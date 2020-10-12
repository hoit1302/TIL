#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

// array-stack.c 파일의 내용 끌어쓰기
extern void init(StackType* s);
extern int is_empty(StackType* s);
extern int is_full(StackType* s);
extern void push(StackType* s, element item);
extern element pop(StackType* s);

int check_matching(const char* in) {
	StackType s;
	init(&s);
	for (int i = 0; i < (int)strlen(in); i++) {
		char ch = in[i];
		switch (ch) {
		case '(': case '[': case '{':
			push(&s, ch);
			break;
		case ')': case ']': case '}':
			if (is_empty(&s)) return 0;
			else {
				char open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}'))
					return 0;
			}
			break;
		} // switch
	} // for
	if (!is_empty(&s)) return 0;
	return 1;
}


void main() {
	if (check_matching("{A[(i+1)]=0;}") == 1)
		printf("괄호검사성공\n");
	else
		printf("괄호검사실패\n");
}