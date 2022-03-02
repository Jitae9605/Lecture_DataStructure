#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
	char ch;
	struct tnode* left;
	struct tnode* right;
}TNode;

TNode* createNode(char ach)
{
	TNode* newNode = (TNode*)malloc(sizeof(TNode));
	if (newNode == NULL) return;
	
	newNode->ch = ach;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void makeTree(TNode* RootNode, TNode* LeftNode, TNode* RightNode)
{
	RootNode->left = LeftNode;
	RootNode->right = RightNode;
}

void preorderTree(TNode* RootNode)				// 전위순회 = root - left - right
{
	if (RootNode == NULL) return;				// 재귀호출로 순회하다가 탈출할 조건

	printf("%c ", RootNode->ch);		// root
	preorderTree(RootNode->left);	// left
	preorderTree(RootNode->right);	// right
	
}

void inorderTree(TNode* RootNode)				// 중위순회 = left - root - right
{
	if (RootNode == NULL) return;				// 재귀호출로 순회하다가 탈출할 조건

	inorderTree(RootNode->left);	// left
	printf("%c ", RootNode->ch);		// root
	inorderTree(RootNode->right);	// right
	


}

void postorderTree(TNode* RootNode)				// 후위순회 =  left - right - root
{
	if (RootNode == NULL) return;				// 재귀호출로 순회하다가 탈출할 조건

	postorderTree(RootNode->left);	// left
	postorderTree(RootNode->right);	// right
	printf("%c ", RootNode->ch);		// root
	
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

	makeTree(t1, t2, t3);
	makeTree(t2, t4, t5);
	makeTree(t3, t6, t7);
	makeTree(t4, t8, t9);
	makeTree(t5, t10, t11);

	// printf("%c %c %c", t1->ch, t1->left->ch, t1->right->ch);

	preorderTree(t1);
	printf("\n");

	inorderTree(t1);
	printf("\n");

	postorderTree(t1);
	printf("\n");

	return 0;
}