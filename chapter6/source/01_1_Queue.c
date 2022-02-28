/* �����ڷᱸ���� ť */
// - FIFIO
// - �Ա�1��, �ⱸ1��
// !!! ������ �̷��� ������ �Ⱦ���(�ſ� �����ϰ� ������) ������ ����� ����ť�� ���� !!!


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define SIZE	10

typedef char element;

typedef struct {
	element que[SIZE];			// ť�迭
	int front, rear;				// ��ġ��� - front(=�ⱸ), rear(=�Ա�)
}Queue;

Queue* createQ()								// q�迭 ����� �ʱ�ȭ�ϴ� �Լ�
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if (q == NULL) exit(1);
	q->front = -1;
	q->rear = -1;
	return q;
}

bool isEmpty(Queue* apq)
{
	if (apq->front == apq->rear)
	{
		printf("\nQueue is Empty !!!\n\n");
		return true;
	}
	else return false;
}

bool isFull(Queue* apq)
{
	if (apq->rear >= SIZE - 1)				// rear�� -1���� �����ϹǷ� 
	{
		printf("\nQueue is Full !!!\n\n");
		return true;
	}
	else return false;
}

void enQueue(Queue* apq, element adata)	// ť�� �� �߰�
{
	if (isFull(apq)) return;
	apq->que[++(apq->rear)] = adata;			// rear���� �ϳ� ������Ű�� �� ��ȣ�� ť�迭��ҿ� ���� �Է�				(= -1 ���� ���������Ƿ�)
}

element deQueue(Queue* apq)				// ť���� �� ��� �� ����
{
	if (isEmpty(apq)) return '\0';
	return apq->que[++(apq->front)];			// fornt���� �ϳ� ������Ű�� �� ��ȣ�� �ش��ϴ� �迭����� ���� ���		(= -1 ���� ���������Ƿ�)
}

element peek(Queue* apq)				// �Ǿ��� ���� ���
{
	if (isEmpty(apq)) return '\0';
	return apq->que[(apq->front)];
}

void printQ(Queue* apq)					// ť���� �� ���
{
	int num = apq->front;				// ���� front���� �ǵ帮�� �ʰ� ���� ���
	while (num < apq->rear)
	{
		printf("%c ", apq->que[num+1]);
		num++;
	}
}

int main(void) 
{
	Queue* Q = createQ();
	enQueue(Q, 'A');
	enQueue(Q, 'B');
	enQueue(Q, 'C');
	enQueue(Q, 'D');
	enQueue(Q, 'E');
	enQueue(Q, 'F');
	enQueue(Q, 'G');	
	enQueue(Q, 'H');
	enQueue(Q, 'I');
	enQueue(Q, 'J');						// ������� 10��
	enQueue(Q, 'K');						// Queue is Full!!! ���

	printQ(Q);

/*
	printf("%c ", deQueue(Q));
	printf("%c ", deQueue(Q));
	printf("%c ", deQueue(Q));
	printf("%c ", deQueue(Q));
	printf("%c ", deQueue(Q));
	printf("%c ", deQueue(Q));
	printf("%c ", deQueue(Q));
	printf("%c ", deQueue(Q));
	printf("%c ", deQueue(Q));
	printf("%c ", deQueue(Q));				// ������� 10��
	printf("%c ", deQueue(Q));				// Queue is Empty!!! ���
*/
	return 0;
}