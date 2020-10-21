#include <stdio.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;

int get_node_count(TreeNode* node){
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	return count;
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

	printf("%d", get_node_count(exp));
}