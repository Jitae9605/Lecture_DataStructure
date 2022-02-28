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

LinkQ* createQ()			// 링크 큐 생성 함수
{
	LinkQ* ql = (LinkQ*)malloc(sizeof(LinkQ));
	if (ql == NULL) exit(1);
	ql->front = NULL;			// 초기화
	ql->rear = NULL;			// 초기화
	return ql;			// 만든 ql을 반환
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
		aql->rear->link = newNode;						// 기존 rear가 가리키고있는 노드의 link에 새로만든 newNode의 주소를 넣는다.  
		aql->rear = newNode;							// read를 새로운 노드로 바꾼다.
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

	printQ(Q);								// Q 데이터 출력

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
	printf("%c ", deQueue(Q));				// underflow 발생

	printf("\n%p %p", Q->front, Q->rear);		// 다 삭제했는데(즉, 요소가 없는데) front와 rear가 가리키는게 다름
												// 동작에는 문제가 없으나 이런게 쌓여서 오류가 발생하고 이러면 오류를 찾기가 불가능에 가까움
												// 미리 처리해줘야함
												// 조치사항 = deQueue에 [ if (aql->front == NULL) aql->rear = NULL; ] 를 삽입
												// 이제 같음
												// 이상했던걸 확인하려면 저 한줄을 주석처리후 확인

	return 0;
}