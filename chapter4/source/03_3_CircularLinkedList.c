// 원형연결리스트

#include<stdio.h>
#include<stdlib.h>

typedef struct circular_node
{
	int data;
	struct circular_node* next;			// 뒤의 노드와 연결할 멤버
	
}Node;

Node* InsertFirstNode(Node*tail, int data);
Node* InsertLastNode(Node* tail, int data);
Node* searchNode(Node*tail, int data);
void printNode(Node* tail);
void allDelNode(Node* tail);
void removeNode(Node* tail, int data);

int main(void)
{
	Node* tail = NULL;

	tail = InsertFirstNode(tail, 10);
	tail = InsertLastNode(tail, 20);
	tail = InsertFirstNode(tail, 30);
	tail = InsertFirstNode(tail, 40);
	tail = InsertFirstNode(tail, 50);
	tail = InsertFirstNode(tail, 60);
	tail = InsertFirstNode(tail, 70);
	tail = InsertFirstNode(tail, 80);
	tail = InsertLastNode(tail, 90);
	tail = InsertLastNode(tail, 100);
	tail = InsertLastNode(tail, 110);
	tail = InsertLastNode(tail, 120);
	tail = InsertLastNode(tail, 130);
	tail = InsertLastNode(tail, 140);

	printNode(tail);

	searchNode(tail, 90);

	allDelNode(tail);

	return 0;
}

Node* InsertFirstNode(Node* tail, int data)			// 첫번째 노드로 삽입
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;

	newNode->next = NULL;
	newNode->data = data;

	if (tail == NULL)
	{
		tail = newNode;					
		newNode->next = newNode;		// 원형이므로 혼자있으면 단순 재귀만 한다. (자기자신을 가리키게 된다)
	}

	else
	{
		newNode->next = tail->next;
		tail->next = newNode;
	}
	return tail;
}

Node* InsertLastNode(Node* tail, int data)			// 마지막 노드로 삽입
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;

	newNode->next = NULL;
	newNode->data = data;

	if (tail == NULL)
	{
		tail = newNode;
		newNode->next = newNode;		
	}

	else
	{
		newNode->next = tail->next;
		tail->next = newNode;
		tail = newNode;
	}
	return tail;
}

Node* searchNode(Node* tail, int data)
{
	int i = 1;
	Node* curr = (Node*)malloc(sizeof(Node));
	if (curr == NULL) return;
	curr = tail->next;

	while (curr != NULL)
	{
		if (curr->data == data)
		{
			printf("찾으시는 값 %d 은(는) %d번 노드에 있습니다.\n", data, i);
			return curr;
		}
		i++;
		curr = curr->next;
	}
	printf("찾으시는 값이 없습니다\n");
}

void printNode(Node*tail)
{
	int i = 1;
	Node* curr = (Node*)malloc(sizeof(Node));
	if (curr == NULL) return;
	curr = tail->next;

	while (curr != NULL)
	{
		printf("%3d 번 노드: %3d \n",i ,curr->data);
		curr = curr->next;
		i++;
		if (curr == tail->next) break;
	}
}

void allDelNode(Node*tail)
{
	int i = 0;
	Node* curr = (Node*)malloc(sizeof(Node));
	if (curr == NULL) return;
	curr = tail->next;

	while (curr != NULL)
	{
		i++;
		curr = tail->next;
		printf("%3d 번 노드(값: %3d ) 삭제 \n", i, curr->data);
		tail->next = curr->next;
		if (curr == tail->next) break;
		free(curr);
	}
}

void removeNode(Node*tail, int data)
{

}