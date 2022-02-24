#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
} Node;

void AddNode(Node* h, int data)		// 새로운 노드를 만든다음 head가 새로운 노드를 가리키고(첫 번째 노드로 만든다) 데이터를 넣어준다.
{
	Node* newNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return;
	}

	if (h->next == NULL)				// 노드가 없는경우
	{
		
		newNode->data = data;	// 입력한 데이터를 새로생성한 노드의 data에 넣는다.
		h->next = newNode;		// 헤드의 next가 새로 생성한 노드를 가리키게함

	}

	else								// 노드가 있는경우 - 현재 노드중 가장 앞쪽에 새로운 첫번째 노드를 만든다.
	{
		newNode->data = data;			// 입력한 데이터를 새로생성한 노드의 data에 넣는다.
		newNode->next = h->next;		// 새로만든 노드의 next에 현재 헤드가 가리키고있는 노드의 주소를 입력
		h->next = newNode;				// 헤드의 next가 새로 생성한 노드를 가리키게함
	}

}

void PrintNode(Node* h)
{
	Node* curr = h->next;		// curr = h->next = 해드가 가리키고 있는 구조체 자체
	printf("%d %p %p\n\n", curr->data, curr, curr->next);		// curr->data = h->next->data ,
																// %p curr = h->next가 가리키는 대상의 주소값,
																// %p curr->next = h->net가 가리키는 대상의 next가 가리키는 대상의 주소값
}

int main(void)
{
	Node* head = malloc(sizeof(Node));
	head->next = NULL;


	AddNode(head, 10);					// 노드 추가 (첫 노드)
	PrintNode(head);

	AddNode(head, 20);				
	PrintNode(head);

	AddNode(head, 30);
	PrintNode(head);
}