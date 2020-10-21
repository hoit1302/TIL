#include <stdio.h>
#include <stdlib.h>
void error(char* string) {
	printf(string);
}

typedef struct TreeNode {
	char key;
	struct TreeNode* left, * right;
}TreeNode;

typedef TreeNode* element;
typedef struct QueueNode {
	element item;
	struct QueueNode* link;
}QueueNode;
typedef struct {
	QueueNode* front,* rear;
}QueueType;

void init(QueueType* q) {
	q->front = q->rear = NULL;
}
int is_empty(QueueType* q) {
	if (q->front == NULL)
		return  1;
	return 0;
}
void enqueue(QueueType* q, TreeNode* item) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		error("메모리 할당 에러");
	else {
		temp->item = item;
		temp->link = NULL;

		if (is_empty(q))	q->front = q->rear = temp;
		else {
			q->rear->link = temp;
			q->rear = temp;
		}
	}
}
TreeNode* dequeue(QueueType* q) {
	QueueNode* temp = q->front;
	element item;

	if (is_empty(q))
		error("큐가 공백 상태임.");
	else {
		item = temp->item;
		q->front = q->front->link;
		if (q->front == NULL)	// 삭제했는데 다음 노드가 없을 때
			q->rear = NULL;
		free(temp);
		return item;
	}
}

void level_order(TreeNode* ptr) {
	QueueType q;
	init(&q);
	if (ptr == NULL) return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf("%c ", ptr->key);
		if (ptr->left) enqueue(&q, ptr->left);
		if (ptr->right) enqueue(&q, ptr->right);
	}
}

void main() {
	TreeNode n4 = { 'A', NULL, NULL };
	TreeNode n5 = { 'B', NULL, NULL };
	TreeNode n6 = { 'C', NULL, NULL };
	TreeNode n7 = { 'D', NULL, NULL };
	TreeNode n2 = { '*', &n4, &n5 };
	TreeNode n3 = { '/', &n6, &n7 };
	TreeNode n1 = {'+', &n2, &n3};
	TreeNode* root = &n1;

	printf("level order traversal: ");
	level_order(root);
	printf("\n");
}