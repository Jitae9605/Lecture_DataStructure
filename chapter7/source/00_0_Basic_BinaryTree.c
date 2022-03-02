/* ����Ʈ�� */

#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
	char ch;
	struct tnode* left;
	struct tnode* right;
}TNode;

TNode* createNode(char ach)								// ach == Ʈ���� �Էµ� ������
{
	TNode* newNode = (TNode*)malloc(sizeof(TNode));
	if (newNode == NULL) return;
	newNode->ch = ach;					// �ʱ�ȭ
	newNode->left = NULL;				// �ʱ�ȭ
	newNode->right = NULL;				// �ʱ�ȭ

	return newNode;										// ������ ��ȯ
}

void makeTreeNode(TNode* aroot, TNode* al, TNode* ar)		// aroot = �θ���(root����) al = ����, ar = ������;
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

	makeTreeNode(t1, t2, t3);											// t1�� ��Ʈ�� t2�� ���ʰ���, t3�� ������ ������ ��ġ�Ͽ� Ʈ�������� ����
	makeTreeNode(t2, t4, t5);
	makeTreeNode(t3, t6, t7);
	makeTreeNode(t4, t8, t9);
	makeTreeNode(t5, t10, t11);
	makeTreeNode(t6, t12, t13);
	makeTreeNode(t7, t14, t15);

	printf("\n%c %c %c\n", t1->ch, t1->left->ch, t1->right->ch);		// t1�� ��, t1�� ���� ��������� ��,	t1�� ������ ��������� �� �� ���� ���
	printf("\n%c %c %c\n", t2->ch, t2->left->ch, t2->right->ch);		// t2�� ��, t2�� ���� ��������� ��,	t2�� ������ ��������� �� �� ���� ���
	printf("\n%c %c %c\n", t3->ch, t3->left->ch, t3->right->ch);		// t3�� ��, t3�� ���� ��������� ��,	t3�� ������ ��������� �� �� ���� ���
	printf("\n%c %c %c\n", t4->ch, t4->left->ch, t4->right->ch);		// t4�� ��, t4�� ���� ��������� ��,	t4�� ������ ��������� �� �� ���� ���
	printf("\n%c %c %c\n", t5->ch, t5->left->ch, t5->right->ch);		// t5�� ��, t5�� ���� ��������� ��,	t5�� ������ ��������� �� �� ���� ���
	printf("\n%c %c %c\n", t6->ch, t6->left->ch, t6->right->ch);		// t6�� ��, t6�� ���� ��������� ��,	t6�� ������ ��������� �� �� ���� ���
	printf("\n%c %c %c\n", t7->ch, t7->left->ch, t7->right->ch);		// t7�� ��, t7�� ���� ��������� ��,	t7�� ������ ��������� �� �� ���� ���
	
	


	return 0;
}