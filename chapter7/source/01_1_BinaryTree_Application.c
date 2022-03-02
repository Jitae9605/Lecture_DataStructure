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

}


int main(void)
{
	TNode* t1 = createNode('a');
	TNode* t2 = createNode('b');
	TNode* t3 = createNode('c');

	makeTree(t1, t2, t3);

	printf("%c %c %c", t1->ch, t1->left->ch, t1->right->ch);

	return 0;
}