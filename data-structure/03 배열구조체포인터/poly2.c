#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_TERMS 101
struct {
	float coef;
	int exp;
} terms[MAX_TERMS] = { {8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0} };

int avail = 6;

// �� ���� ������ ��
char compare(int a, int b)
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

// ���ο� ���� ���׽Ŀ� �߰�
void attach(float coef, int exp)
{
	if (avail > MAX_TERMS) {
		fprintf(stderr, "���� ������ �ʹ� ����\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail++].exp = exp;
}

// C = A + B
poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
	float tempcoef;
	*Cs = avail;
	while (As <= Ae && Bs <= Be)
		switch (compare(terms[As].exp, terms[Bs].exp)) {
		case '>': // A�� ���� > B�� ����
			attach(terms[As].coef, terms[As].exp);
			As++; break;
		case '=': // A�� ���� == B�� ����
			tempcoef = terms[As].coef + terms[Bs].coef;
			if (tempcoef)
				attach(tempcoef, terms[As].exp);
			As++; Bs++; break;
		case '<': // A�� ���� < B�� ����
			attach(terms[Bs].coef, terms[Bs].exp);
			Bs++; break;
		}
	// A�� ������ �׵��� �̵���
	for (; As <= Ae; As++)
		attach(terms[As].coef, terms[As].exp);
	// B�� ������ �׵��� �̵���
	for (; Bs <= Be; Bs++)
		attach(terms[Bs].coef, terms[Bs].exp);
	*Ce = avail - 1;
}

void main() {
	int Cs, Ce;
	poly_add2(0, 2, 3, 5, &Cs, &Ce);
	return;
}