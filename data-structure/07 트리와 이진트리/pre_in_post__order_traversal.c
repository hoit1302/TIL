#include <stdio.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;

// 중순위 운행
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left); // L
		printf("%d ", root->key); // v
		inorder(root->right); // R
	}
}
// 전순위 운행
void preorder(TreeNode* root) {
	if (root) {
		printf("%d ", root->key); // v
		preorder(root->left); // L
		preorder(root->right); // R
	}
}
// 후순위 운행
void postorder(TreeNode* root) {
	if (root) {
		postorder(root->left); // L
		postorder(root->right); // R
		printf("%d ", root->key); // v
	}
}

// 퀴즈
void d_order(TreeNode* bt) {
	if (bt) {
		printf("%c ", bt->key);   // v
		d_order(bt->left);		 // L
		printf("%c ", bt->key);   // v
		d_order(bt->right);		 // R
	}
}

void main() {

	TreeNode n1 = { 1, NULL, NULL };
	TreeNode n2 = { 4, &n1, NULL };
	TreeNode n3 = { 16, NULL, NULL };
	TreeNode n4 = { 25, NULL, NULL };
	TreeNode n5 = { 20, &n3, &n4 };
	TreeNode n6 = { 15, &n2, &n5 };
	TreeNode* root = &n6;

	printf("inorder: ");
	inorder(root);
	printf("\n");
	printf("preorder: ");
	preorder(root);
	printf("\n");
	printf("postorder: ");
	d_order(root);
	printf("\n");

	printf("1012\'s quiz: ");
	postorder(root);
	printf("\n");
}