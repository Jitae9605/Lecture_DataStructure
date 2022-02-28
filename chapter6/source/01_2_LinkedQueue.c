#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef char element;

typedef struct node{			// ť ������ ����ü
	struct node* link;			
	element data;
}Node;

typedef struct {		// ť��ġ ��Ÿ���� ����ü
	Node* rear;				// ť ��带 ����Ű�� ���(�Ա�)
	Node* front;			// ť ��带 ����Ű�� ���(�ⱸ)
}LinkQ;

LinkQ* create()			// ��ũ ť ���� �Լ�
{
	LinkQ* ql = (LinkQ*)malloc(sizeof(LinkQ));
	if (ql == NULL) return;
	ql->front = NULL;			// �ʱ�ȭ
	ql->rear = NULL;			// �ʱ�ȭ
	return ql;			// ���� ql�� ��ȯ
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