/* ����Ʈ�� */

#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
	char ch;
	struct tnode* left;
	struct tnode* right;
}TNode;

createNode(char ach)								// ach == Ʈ���� �Էµ� ������
{
	TNode* newNode = (TNode*)malloc(sizeof(TNode));
	if (newNode == NULL) return;
	newNode->ch = ach;					// �ʱ�ȭ
	newNode->left = NULL;				// �ʱ�ȭ
	newNode->right = NULL;				// �ʱ�ȭ
}

makeTreeNode()
{

}

int main(void)
{

	return 0;
}