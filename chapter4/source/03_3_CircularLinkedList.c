// �������Ḯ��Ʈ

#include<stdio.h>
#include<stdlib.h>

typedef struct circular_node
{
	int data;
	struct circular_node* next;			// ���� ���� ������ ���
	
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

Node* InsertFirstNode(Node* tail, int data)			// ù��° ���� ����
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;

	newNode->next = NULL;
	newNode->data = data;

	if (tail == NULL)
	{
		tail = newNode;					
		newNode->next = newNode;		// �����̹Ƿ� ȥ�������� �ܼ� ��͸� �Ѵ�. (�ڱ��ڽ��� ����Ű�� �ȴ�)
	}

	else
	{
		newNode->next = tail->next;
		tail->next = newNode;
	}
	return tail;
}

Node* InsertLastNode(Node* tail, int data)			// ������ ���� ����
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
			printf("ã���ô� �� %d ��(��) %d�� ��忡 �ֽ��ϴ�.\n", data, i);
			return curr;
		}
		i++;
		curr = curr->next;
	}
	printf("ã���ô� ���� �����ϴ�\n");
}

void printNode(Node*tail)
{
	int i = 1;
	Node* curr = (Node*)malloc(sizeof(Node));
	if (curr == NULL) return;
	curr = tail->next;

	while (curr != NULL)
	{
		printf("%3d �� ���: %3d \n",i ,curr->data);
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
		printf("%3d �� ���(��: %3d ) ���� \n", i, curr->data);
		tail->next = curr->next;
		if (curr == tail->next) break;
		free(curr);
	}
}

void removeNode(Node*tail, int data)
{

}