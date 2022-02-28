/* 순차자료구조의 큐 */
// - FIFIO
// - 입구1개, 출구1개
// !!! 원래는 이렇게 순차를 안쓴다(매우 불편하고 안좋음) 실제로 사용은 원형큐를 쓴다 !!!


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define SIZE	10

typedef char element;

typedef struct {
	element que[SIZE];			// 큐배열
	int front, rear;				// 위치멤버 - front(=출구), rear(=입구)
}Queue;

Queue* createQ()								// q배열 만들고 초기화하는 함수
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
	if (apq->rear >= SIZE - 1)				// rear가 -1부터 시작하므로 
	{
		printf("\nQueue is Full !!!\n\n");
		return true;
	}
	else return false;
}

void enQueue(Queue* apq, element adata)	// 큐에 값 추가
{
	if (isFull(apq)) return;
	apq->que[++(apq->rear)] = adata;			// rear값을 하나 증가시키고 그 번호의 큐배열요소에 값을 입력				(= -1 부터 시작했으므로)
}

element deQueue(Queue* apq)				// 큐에서 값 출력 및 삭제
{
	if (isEmpty(apq)) return '\0';
	return apq->que[++(apq->front)];			// fornt값을 하나 증가시키고 그 번호에 해당하는 배열요소의 값을 출력		(= -1 부터 시작했으므로)
}

element peek(Queue* apq)				// 맨앞의 원소 출력
{
	if (isEmpty(apq)) return '\0';
	return apq->que[(apq->front)];
}

void printQ(Queue* apq)					// 큐에서 값 출력
{
	int num = apq->front;				// 실제 front값은 건드리지 않고 값을 출력
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
	enQueue(Q, 'J');						// 여기까지 10개
	enQueue(Q, 'K');						// Queue is Full!!! 출력

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
	printf("%c ", deQueue(Q));				// 여기까지 10개
	printf("%c ", deQueue(Q));				// Queue is Empty!!! 출력
*/
	return 0;
}