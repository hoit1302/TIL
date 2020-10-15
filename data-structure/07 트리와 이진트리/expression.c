#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;



int evaluate(TreeNode* root) {
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL)
		return root->key;
	else {
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		switch (root->key) { // operator
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		}
	}
}


int main() {

	TreeNode n1 = { 1, NULL, NULL };
	TreeNode n2 = { 4, NULL, NULL };
	TreeNode n3 = { '*', &n1, &n2 };
	TreeNode n4 = { 16, NULL, NULL };
	TreeNode n5 = { 25, NULL, NULL };
	TreeNode n6 = { '+', &n4, &n5 };
	TreeNode n7 = { '+', &n3, &n6 };
	TreeNode* exp = &n7;	// TreeNode를 가리키는 포인터

	printf("%d", evaluate(exp));
	return 0;
}