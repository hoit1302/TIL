#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_DEGREE 101
#define MAX(a,b) ((a>b)?a:b)

typedef struct {
	int degree;
	int coef[MAX_DEGREE];
} polynomial;

// C = A+B, 여기서 A와 B는 다항식이다.
polynomial poly_add1(polynomial A, polynomial B) {
	polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0; // 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수
	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) { // A항 > B항
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) { // A항 == B항
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else { // B항 > A항
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}


void main() {
	polynomial a = { 5, {3, 6, 0, 0, 0, 10} };  // a(x) = 3x^5 + 6x^4 + 10
	polynomial b = { 4, {7, 0, 5, 0, 1} };      // b(x) = 7x^4 + 5x^2 + 1
	polynomial c;
	c = poly_add1(a, b);                        // c = {5, {3, 13, 0, 5, 0, 11} }
	return;
}
