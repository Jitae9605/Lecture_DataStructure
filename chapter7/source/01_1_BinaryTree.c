/* 이진트리 */

#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
	char ch;
	struct tnode* left;
	struct tnode* right;
}TNode;

createNode(char ach)								// ach == 트리에 입력될 데이터
{
	TNode* newNode = (TNode*)malloc(sizeof(TNode));
	if (newNode == NULL) return;
	newNode->ch = ach;					// 초기화
	newNode->left = NULL;				// 초기화
	newNode->right = NULL;				// 초기화
}

makeTreeNode()
{

}

int main(void)
{

	return 0;
}