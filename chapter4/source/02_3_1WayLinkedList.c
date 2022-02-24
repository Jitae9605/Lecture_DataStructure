#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
} Node;

void Pre_insertNode(Node* h, int data)			// ����� �Ǿտ� ���ο� ��带 �߰��ϴ� �Լ�
{
	Node* newNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL)						// �޸𸮾�����
	{
		return;
	}

	if (h->next == NULL)						// ��������
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

void Rear_insertNode(Node* h, int data)		// �� �ڿ� ���ο� ��带 �߰��ϴ� �Լ�
{
	Node* newNode = NULL;
	Node* tail = h->next;

	newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;
	
	newNode->data = data;
	newNode->next = NULL;

	

	if (tail == NULL)		// ��尪�� NULL = ��尡 ����;
	{
		h->next = newNode;
	}

	else						// ��尡 ������ ���ʿ� �߰� 
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

	Pre_insertNode(head, 10);		// ��带 ���ʿ� �߰��ϴ� �Լ�
	Pre_insertNode(head, 20);
	Pre_insertNode(head, 30);
	Pre_insertNode(head, 40);
	Pre_insertNode(head, 50);
	Pre_insertNode(head, 60);
	
	Rear_insertNode(head, 100);		// ��带 ���ʿ� �߰��ϴ� �Լ�
	

	printNode(head);				// ��带 ����ϴ� �Լ�
			
	FreeNode(head);					// ��带 �����ϴ� �Լ�
	printf("%d", head->next->data);



	return 0;

}