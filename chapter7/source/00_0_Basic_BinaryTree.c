/* 이진트리 */

#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
	char ch;
	struct tnode* left;
	struct tnode* right;
}TNode;

TNode* createNode(char ach)								// ach == 트리에 입력될 데이터
{
	TNode* newNode = (TNode*)malloc(sizeof(TNode));
	if (newNode == NULL) return;
	newNode->ch = ach;					// 초기화
	newNode->left = NULL;				// 초기화
	newNode->right = NULL;				// 초기화

	return newNode;										// 만든노드 반환
}

void makeTreeNode(TNode* aroot, TNode* al, TNode* ar)		// aroot = 부모노드(root방향) al = 왼쪽, ar = 오른쪽;
{
	aroot->left = al;
	aroot->right = ar;
}

int main(void)
{
	TNode* t1 = createNode('a');						
	TNode* t2 = createNode('b');
	TNode* t3 = createNode('c');
	TNode* t4 = createNode('d');
	TNode* t5 = createNode('e');
	TNode* t6 = createNode('f');
	TNode* t7 = createNode('g');
	TNode* t8 = createNode('h');
	TNode* t9 = createNode('i');
	TNode* t10 = createNode('j');
	TNode* t11 = createNode('k');
	TNode* t12 = createNode('l');
	TNode* t13 = createNode('m');
	TNode* t14 = createNode('n');
	TNode* t15 = createNode('o');

	printf("\n%c %c %c\n", t1->ch, t2->ch, t3->ch);

	makeTreeNode(t1, t2, t3);											// t1을 루트로 t2를 왼쪽가지, t3를 오른쪽 가지로 배치하여 트리구조를 만듬
	makeTreeNode(t2, t4, t5);
	makeTreeNode(t3, t6, t7);
	makeTreeNode(t4, t8, t9);
	makeTreeNode(t5, t10, t11);
	makeTreeNode(t6, t12, t13);
	makeTreeNode(t7, t14, t15);

	printf("\n%c %c %c\n", t1->ch, t1->left->ch, t1->right->ch);		// t1의 값, t1의 왼쪽 가지노드의 값,	t1의 오른쪽 가지노드의 값 을 각각 출력
	printf("\n%c %c %c\n", t2->ch, t2->left->ch, t2->right->ch);		// t2의 값, t2의 왼쪽 가지노드의 값,	t2의 오른쪽 가지노드의 값 을 각각 출력
	printf("\n%c %c %c\n", t3->ch, t3->left->ch, t3->right->ch);		// t3의 값, t3의 왼쪽 가지노드의 값,	t3의 오른쪽 가지노드의 값 을 각각 출력
	printf("\n%c %c %c\n", t4->ch, t4->left->ch, t4->right->ch);		// t4의 값, t4의 왼쪽 가지노드의 값,	t4의 오른쪽 가지노드의 값 을 각각 출력
	printf("\n%c %c %c\n", t5->ch, t5->left->ch, t5->right->ch);		// t5의 값, t5의 왼쪽 가지노드의 값,	t5의 오른쪽 가지노드의 값 을 각각 출력
	printf("\n%c %c %c\n", t6->ch, t6->left->ch, t6->right->ch);		// t6의 값, t6의 왼쪽 가지노드의 값,	t6의 오른쪽 가지노드의 값 을 각각 출력
	printf("\n%c %c %c\n", t7->ch, t7->left->ch, t7->right->ch);		// t7의 값, t7의 왼쪽 가지노드의 값,	t7의 오른쪽 가지노드의 값 을 각각 출력
	
	


	return 0;
}