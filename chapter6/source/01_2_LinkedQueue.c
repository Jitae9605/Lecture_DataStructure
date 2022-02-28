#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef char element;

typedef struct node{			// 큐 노드생성 구조체
	struct node* link;			
	element data;
}Node;

typedef struct {		// 큐위치 나타내는 구조체
	Node* rear;				// 큐 노드를 가리키는 멤버(입구)
	Node* front;			// 큐 노드를 가리키는 멤버(출구)
}LinkQ;

LinkQ* create()			// 링크 큐 생성 함수
{
	LinkQ* ql = (LinkQ*)malloc(sizeof(LinkQ));
	if (ql == NULL) return;
	ql->front = NULL;			// 초기화
	ql->rear = NULL;			// 초기화
	return ql;			// 만든 ql을 반환
}

bool isEnpty(LinkQ* aql)
{
	if (aql->front == NULL)
	{
		printf("\n\n !!! Queue is Underflow !!! \n\n");
		return true;
	}
	else return false;
}

void enQueue(LinkQ* aql, char adata)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;

	newNode->data = adata;
	newNode->link = NULL;
}

int mai(void)
{


	return 0;
}