#include <stdio.h>
typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

// 반복적 방법
TreeNode* search_iter(TreeNode* node, int key)
{
	while (node != NULL) {
		if (key == node->key) return node;
		else if (key < node->key) node = node->left;
		else node = node->right;
	}
	return NULL; // 탐색에 실패했을 경우 NULL 반환
}

// 재귀적 방법
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
	TreeNode* p, * t; // p는 부모노드, t는 현재노드
	TreeNode* n; // n은 삽입할 새로운 노드

	t = *root; p = NULL;
	while (t != NULL) { // 탐색 : 삽입 위치 찾기
		if (key == t->key) return; // key가 이미 트리 안에 있으면 삽입 안됨
		p = t;
		if (key < t->key) t = t->left;
		else t = t->right;
	}
	n = (TreeNode*)malloc(sizeof(TreeNode)); if (n == NULL) return;
	n->key = key; // 데이터 복사
	n->left = n->right = NULL;
	if (p != NULL) // 부모노드와 링크 연결
		if (key < p->key) p->left = n;
		else p->right = n;
	else *root = n;	// 루트 노드가 됨
}

void delete_node(TreeNode** root, int key)
{
	TreeNode* p, * child, * succ, * succ_p, * t;
	p = NULL; t = *root; // 방문용 t, p는 t의 부모노드
	// child : t의 child
	// succ : successor, succ_p : parent of successor
	while (t != NULL && t->key != key) { // key를 갖는 노드 t 탐색
		p = t;
		t = (key < t->key) ? t->left : t->right;
	}
	if (t == NULL) { // 탐색트리에 키가 없음
		printf("key is not in the tree");
		return;
	}

	// 첫번째 경우 : 삭제할 노드가 단말노드인 경우
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) { // 부모노드의 자식필드를 NULL로 만든다.
			if (p->left == t) p->left = NULL;
			else p->right = NULL;
		}
		else // 만약 부모노드가 NULL이면 삭제되는 노드가 루트
			*root = NULL;
	}
	// 두번째 경우 : 하나의 자식만 있는 경우
	else if ((t->left == NULL) || (t->right == NULL)) {
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) { // 부모를 t의 자식과 연결
			if (p->left == t) p->left = child;
			else p->right = child;
		}
		else // 만약 부모노드가 NULL이면 삭제되는 노드가 루트
			*root = child;
	}

	// 세번째 경우: 두 개의 자식을 가지는 경우(succ가 반드시 있다)
	else {
		succ_p = t; // 오른쪽 부분트리에서 계승자를 찾는다.
		succ = t->right; // 계승자 : 오른쪽 부분트리의 leftmost child
		while (succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		// 계승자의 부모와 계승자의 자식을 연결
		if (succ_p->left == succ)
			succ_p->left = succ->right; //(1)
		else // t == succ_p
			succ_p->right = succ->right; //(2)
			// 계승자의 키값을 현재 노드에 복사
		t->key = succ->key;
		// 원래의 계승자 삭제
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
	else		printf("없음\n");
	TreeNode* temp2 = search_rec(root, 20);
	if (temp2)	printf("%d\n", temp2->key);
	else		printf("없음\n");

	
}

/*
		15
	  4	  20
	1	 16 25
*/