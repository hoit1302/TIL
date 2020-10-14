#include <stdio.h>
typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

// �ݺ��� ���
TreeNode* search_iter(TreeNode* node, int key)
{
	while (node != NULL) {
		if (key == node->key) return node;
		else if (key < node->key) node = node->left;
		else node = node->right;
	}
	return NULL; // Ž���� �������� ��� NULL ��ȯ
}

// ����� ���
TreeNode* search_rec(TreeNode* node, int key)
{
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search_rec(node->left, key);
	else
		return search_rec(node->right, key);
}

void insert_node(TreeNode** root, int key)
{
	TreeNode* p, * t; // p�� �θ���, t�� ������
	TreeNode* n; // n�� ������ ���ο� ���

	t = *root; p = NULL;
	while (t != NULL) { // Ž�� : ���� ��ġ ã��
		if (key == t->key) return; // key�� �̹� Ʈ�� �ȿ� ������ ���� �ȵ�
		p = t;
		if (key < t->key) t = t->left;
		else t = t->right;
	}
	n = (TreeNode*)malloc(sizeof(TreeNode)); if (n == NULL) return;
	n->key = key; // ������ ����
	n->left = n->right = NULL;
	if (p != NULL) // �θ���� ��ũ ����
		if (key < p->key) p->left = n;
		else p->right = n;
	else *root = n;	// ��Ʈ ��尡 ��
}

void delete_node(TreeNode** root, int key)
{
	TreeNode* p, * child, * succ, * succ_p, * t;
	p = NULL; t = *root; // �湮�� t, p�� t�� �θ���
	// child : t�� child
	// succ : successor, succ_p : parent of successor
	while (t != NULL && t->key != key) { // key�� ���� ��� t Ž��
		p = t;
		t = (key < t->key) ? t->left : t->right;
	}
	if (t == NULL) { // Ž��Ʈ���� Ű�� ����
		printf("key is not in the tree");
		return;
	}

	// ù��° ��� : ������ ��尡 �ܸ������ ���
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) { // �θ����� �ڽ��ʵ带 NULL�� �����.
			if (p->left == t) p->left = NULL;
			else p->right = NULL;
		}
		else // ���� �θ��尡 NULL�̸� �����Ǵ� ��尡 ��Ʈ
			*root = NULL;
	}
	// �ι�° ��� : �ϳ��� �ڽĸ� �ִ� ���
	else if ((t->left == NULL) || (t->right == NULL)) {
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) { // �θ� t�� �ڽİ� ����
			if (p->left == t) p->left = child;
			else p->right = child;
		}
		else // ���� �θ��尡 NULL�̸� �����Ǵ� ��尡 ��Ʈ
			*root = child;
	}

	// ����° ���: �� ���� �ڽ��� ������ ���(succ�� �ݵ�� �ִ�)
	else {
		succ_p = t; // ������ �κ�Ʈ������ ����ڸ� ã�´�.
		succ = t->right; // ����� : ������ �κ�Ʈ���� leftmost child
		while (succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		// ������� �θ�� ������� �ڽ��� ����
		if (succ_p->left == succ)
			succ_p->left = succ->right; //(1)
		else // t == succ_p
			succ_p->right = succ->right; //(2)
			// ������� Ű���� ���� ��忡 ����
		t->key = succ->key;
		// ������ ����� ����
		t = succ;
	}
	free(t);
}

void main() {

	TreeNode n1 = { 1, NULL, NULL };
	TreeNode n2 = { 4, &n1, NULL };
	TreeNode n3 = { 16, NULL, NULL };
	TreeNode n4 = { 25, NULL, NULL };
	TreeNode n5 = { 20, &n3, &n4 };
	TreeNode n6 = { 15, &n2, &n5 };
	TreeNode* root = &n6;

	TreeNode* temp = search_iter(root, 19);
	if (temp)	printf("%d\n", temp->key);
	else		printf("����\n");
	TreeNode* temp2 = search_rec(root, 20);
	if (temp2)	printf("%d\n", temp2->key);
	else		printf("����\n");

	
}

/*
		15
	  4	  20
	1	 16 25
*/