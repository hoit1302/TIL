#include <stdio.h>
int max(int a, int b) { return (a > b) ? a : b; }
typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;

// 1부터 시작
int get_height(TreeNode* node) {
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

void main() {
	TreeNode n1 = { 1, NULL, NULL };
	TreeNode n2 = { 4, NULL, NULL };
	TreeNode n3 = { '*', &n1, &n2 };
	TreeNode n4 = { 16, NULL, NULL };
	TreeNode n5 = { 25, NULL, NULL };
	TreeNode n6 = { '+', &n4, &n5 };
	TreeNode n7 = { '+', &n3, &n6 };
	TreeNode* exp = &n7;

	printf("%d", get_height(exp));
}