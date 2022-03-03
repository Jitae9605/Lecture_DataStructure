#ifndef __BINARY_SEARCH_TREE2_H__
#define __BINARY_SEARCH_TREE2_H__

#include "02_1_BinaryTree3.h"

typedef BTData BSTData;

// 이진트리 생성및 초기화
void BSTMakeAndInit(BTreeNode** pRoot);

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode* bst);

//이진탐색 트리를 대상으로 데이터저장 (노드의 생성과정 포함)
void BSTInsert(BTreeNode** pRoot, BSTData data);

// 이진탐색트리를 대상으로 데이터 탐색
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);

// 트리에서 노드를 제거하고 제거된 노드의 주소값을 반환
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target);

// 이진탐색트리에 저장된 모든 노드의 데이터를 출력
void BSTShowAll(BTreeNode* bst);


#endif