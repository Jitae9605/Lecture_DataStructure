#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
} Node;

void AddNode(Node* h, int data)		// ���ο� ��带 ������� head�� ���ο� ��带 ����Ű��(ù ��° ���� �����) �����͸� �־��ش�.
{
	Node* newNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return;
	}

	if (h->next == NULL)				// ��尡 ���°��
	{
		
		newNode->data = data;	// �Է��� �����͸� ���λ����� ����� data�� �ִ´�.
		h->next = newNode;		// ����� next�� ���� ������ ��带 ����Ű����

	}

	else								// ��尡 �ִ°�� - ���� ����� ���� ���ʿ� ���ο� ù��° ��带 �����.
	{
		newNode->data = data;			// �Է��� �����͸� ���λ����� ����� data�� �ִ´�.
		newNode->next = h->next;		// ���θ��� ����� next�� ���� ��尡 ����Ű���ִ� ����� �ּҸ� �Է�
		h->next = newNode;				// ����� next�� ���� ������ ��带 ����Ű����
	}

}

void PrintNode(Node* h)
{
	Node* curr = h->next;		// curr = h->next = �ص尡 ����Ű�� �ִ� ����ü ��ü
	printf("%d %p %p\n\n", curr->data, curr, curr->next);		// curr->data = h->next->data ,
																// %p curr = h->next�� ����Ű�� ����� �ּҰ�,
																// %p curr->next = h->net�� ����Ű�� ����� next�� ����Ű�� ����� �ּҰ�
}

int main(void)
{
	Node* head = malloc(sizeof(Node));
	head->next = NULL;


	AddNode(head, 10);					// ��� �߰� (ù ���)
	PrintNode(head);

	AddNode(head, 20);				
	PrintNode(head);

	AddNode(head, 30);
	PrintNode(head);
}