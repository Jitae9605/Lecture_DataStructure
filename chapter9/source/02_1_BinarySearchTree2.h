#ifndef __BINARY_SEARCH_TREE2_H__
#define __BINARY_SEARCH_TREE2_H__

#include "02_1_BinaryTree3.h"

typedef BTData BSTData;

// ����Ʈ�� ������ �ʱ�ȭ
void BSTMakeAndInit(BTreeNode** pRoot);

// ��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode* bst);

//����Ž�� Ʈ���� ������� ���������� (����� �������� ����)
void BSTInsert(BTreeNode** pRoot, BSTData data);

// ����Ž��Ʈ���� ������� ������ Ž��
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);

// Ʈ������ ��带 �����ϰ� ���ŵ� ����� �ּҰ��� ��ȯ
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target);

// ����Ž��Ʈ���� ����� ��� ����� �����͸� ���
void BSTShowAll(BTreeNode* bst);


#endif