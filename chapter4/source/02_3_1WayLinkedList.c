#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
} Node;

void Pre_insertNode(Node* h, int data)			// 노드의 맨앞에 새로운 노드를 추가하는 함수
{
	Node* newNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL)						// 메모리없을때
	{
		return;
	}

	if (h->next == NULL)						// 노드없을때
	{
		newNode->data = data;				
		newNode->next = NULL;
		h->next = newNode;
	}

	else
	{
		newNode->data = data;
		newNode->next = h->next;
		h->next = newNode;
	}

}

void Rear_insertNode(Node* h, int data)		// 맨 뒤에 새로운 노드를 추가하는 함수
{
	Node* newNode = NULL;
	Node* tail = h->next;

	newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;
	
	newNode->data = data;
	newNode->next = NULL;

	

	if (tail == NULL)		// 헤드값이 NULL = 노드가 없음;
	{
		h->next = newNode;
	}

	else						// 노드가 있으면 뒤쪽에 추가 
	{
		
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
		
	}
}

void printNode(Node* h)
{
	Node* curr = NULL;
	curr = h->next;

	while (curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
	
}

void FreeNode(Node * h)
{
	Node* curr = h->next;

	while (curr->next != NULL)
	{
		h = curr;
		curr = curr->next;
		free(h);
	}
	
	
}


int main(void)
{
	Node* head = (Node*)malloc(sizeof(Node));
	if (head != NULL) head->next = NULL;

	Pre_insertNode(head, 10);		// 노드를 앞쪽에 추가하는 함수
	Pre_insertNode(head, 20);
	Pre_insertNode(head, 30);
	Pre_insertNode(head, 40);
	Pre_insertNode(head, 50);
	Pre_insertNode(head, 60);
	
	Rear_insertNode(head, 100);		// 노드를 뒷쪽에 추가하는 함수
	

	printNode(head);				// 노드를 출력하는 함수
			
	FreeNode(head);					// 노드를 삭제하는 함수
	printf("%d", head->next->data);



	return 0;

}