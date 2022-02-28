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

LinkQ* createQ()			// ��ũ ť ���� �Լ�
{
	LinkQ* ql = (LinkQ*)malloc(sizeof(LinkQ));
	if (ql == NULL) exit(1);
	ql->front = NULL;			// �ʱ�ȭ
	ql->rear = NULL;			// �ʱ�ȭ
	return ql;			// ���� ql�� ��ȯ
}

bool isEmpty(LinkQ* aql)
{
	if (aql->front == NULL)
	{
		printf("\n\n !!! Queue is Underflow !!! \n\n");
		return true;
	}
	else return false;
}

void enQueue(LinkQ* aql, element adata)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;

	newNode->data = adata;
	newNode->link = NULL;

	if (isEmpty(aql))
	{
		aql->front = newNode;
		aql->rear = newNode;
	}
	else
	{
		aql->rear->link = newNode;						// ���� rear�� ����Ű���ִ� ����� link�� ���θ��� newNode�� �ּҸ� �ִ´�.  
		aql->rear = newNode;							// read�� ���ο� ���� �ٲ۴�.
	}
}

void printQ(LinkQ* aql)
{
	Node* curr = aql->front;
	while (curr != NULL)
	{
		printf("%c ", curr->data);
		curr = curr->link;
	}
	printf("\n");
}

element deQueue(LinkQ* aql)
{
	Node* curr = aql->front;
	element data; 
	if (isEmpty(aql)) return '\0';

	else
	{
		data = curr->data;
		aql->front = aql->front->link;
		if (aql->front == NULL) aql->rear = NULL;
		free(curr);
		return data;
	}
}

int main(void)
{
	LinkQ* Q = createQ();

	enQueue(Q, 'A');
	enQueue(Q, 'B');
	enQueue(Q, 'C');
	enQueue(Q, 'D');
	enQueue(Q, 'G');
	enQueue(Q, 'F');
	enQueue(Q, 'G');
	enQueue(Q, 'H');
	enQueue(Q, 'I');
	enQueue(Q, 'J');						
	enQueue(Q, 'K');						

	printQ(Q);								// Q ������ ���

	printf("%c ", deQueue(Q));
	printf("%c ", deQueue(Q));
	printf("%c ", deQueue(Q));
	printf("%c ", deQueue(Q));
	printf("%c ", deQueue(Q));	
	printf("%c ", deQueue(Q));
	printf("%c ", deQueue(Q));
	printf("%c ", deQueue(Q));
	printf("%c ", deQueue(Q));
	printf("%c ", deQueue(Q));
	printf("%c ", deQueue(Q));				// underflow �߻�

	printf("\n%p %p", Q->front, Q->rear);		// �� �����ߴµ�(��, ��Ұ� ���µ�) front�� rear�� ����Ű�°� �ٸ�
												// ���ۿ��� ������ ������ �̷��� �׿��� ������ �߻��ϰ� �̷��� ������ ã�Ⱑ �Ұ��ɿ� �����
												// �̸� ó���������
												// ��ġ���� = deQueue�� [ if (aql->front == NULL) aql->rear = NULL; ] �� ����
												// ���� ����
												// �̻��ߴ��� Ȯ���Ϸ��� �� ������ �ּ�ó���� Ȯ��

	return 0;
}