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

	else								// ��尡 �ִ°��
	{
		newNode->data = data;			// �Է��� �����͸� ���λ����� ����� data�� �ִ´�.
		newNode->next = h->next;		// ���θ��� ����� next�� ���� ��尡 ����Ű���ִ� ����� �ּҸ� �Է�
		h->next = newNode;				// ����� next�� ���� ������ ��带 ����Ű����
	}

}

void PrintNode(Node* p)
{
	printf("%d %p %p\n\n", p->next->data, p, p->next);		// p->next->data = newNode->data    ,     %p p = �Է¹��� �������� �ּ�,   %p  p->next  = �Է¹��� ������p�� next�� ����Ű�� ����� �ּ�
}

int main(void)
{
	Node* head = malloc(sizeof(Node));
	head->next = NULL;


	AddNode(head, 10);
	PrintNode(head);
	AddNode(head, 20);
	PrintNode(head);
	AddNode(head, 30);
	PrintNode(head);
}