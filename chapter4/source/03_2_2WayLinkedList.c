// ����⿬�Ḯ��Ʈ

#include<stdio.h>
#include<stdlib.h>

typedef struct Double_node
{
	int data;
	struct Double_node* next;			// ���� ���� ������ ���
	struct Double_node* prev;			// ���� ���� ������ ���
}Dnode;

//�Լ�����
void insertNode(Dnode* head, int data, Dnode* num, char option); 
Dnode* searchNode(Dnode* head, int data);
void printNode(Dnode* head);
void allDelNode(Dnode* head);
void removeNode(Dnode* head, Dnode*);


int main(voide)
{
	Dnode* head = (Dnode*)malloc(sizeof(Dnode));		// head ����
	if (head == NULL) exit(1);							// �޸� ������ ��������

	head->next = NULL;									// head �ʱ�ȭ (next)
	head->prev = NULL;;									// head �ʱ�ȭ (prev)
	
	Dnode* pos = NULL;									// ���س�忪���� �ϰ�, �˻��Ͽ� ã�� ����� �ּҰ��� ����

	insertNode(head, 10, pos, 'n');
	insertNode(head, 20, pos, 'n');
	insertNode(head, 30, pos, 'n');
	insertNode(head, 40, head->next->next, 'p');		// 2��° ��� 20�� target���� prev��ġ(20�� 30 ����)�� ��带 ����
	insertNode(head, 50, pos, 'n');
	insertNode(head, 60, pos, 'p');
	insertNode(head, 100, pos, 'p');
	insertNode(head, 110, pos, 'p');
	insertNode(head, 120, pos, 'p');
	insertNode(head, 130, pos, 'p');
	insertNode(head, 140, pos, 'p');

	printNode(head);

	searchNode(head, 110);								// �����Ͱ��� �������� ��带 ��Ƽ� ����� ��ȣ�� ��� [ ��ȯ�� = ã�� ����� �ּҰ��� ���� ����Ʈ����ü( = Node*curr) ]
	
	insertNode(head, 110, searchNode(head, 130), 'p');
	
	printNode(head);
	
	// allDelNode(head);

	removeNode(head, searchNode(head, 60));
	printNode(head);

	return 0;
}

void insertNode(Dnode* head, int data, Dnode* target, char option)
{
	Dnode* newNode = (Dnode*)malloc(sizeof(Dnode));
	if (newNode == NULL) return;

	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (target == NULL)		// target�� �������� ������ ù��° ���� �ִ´�
	{
		if (head->next == NULL)			// ��尡 �ϳ��� ������ - ����� head�� ����
		{
			head->next = newNode;		// ���� ���� ��带 head�� ����Ŵ
		}

		else	// ��尡 ������ - ������忡 �����ϰ� head�� ����
		{
			newNode->next = head->next;		// ���θ��� ����� next�� ������ ù��° ��带 ����Ŵ (next�� ���� ù��° ���� ����)
			head->next->prev = newNode;		// head�� ������ ����Ű�� ���(���� ù��° ���)�� prev�� ���� ���� ��带 ����Ŵ
			head->next = newNode;			// head�� next�� ����Ű�� ����� ���θ��� ���� �ٲ�
		}
	}

	else					// target�� ����
	{
		Dnode* curr = head->next;	// Ž����� ����
		while (curr != target)		// ��ȸ�ϸ� target�� ���� ��尡 �ִ��� ã��
		{
			curr = curr->next;		
		}

		if (option == 'n')		// target��� ������ �߰� (n == next)
		{
			newNode->next = curr->next;									// ���ο� ����� next�� target����� �������(target->next)�� ����Ű����
			newNode->prev = curr;										// ���ο� ����� prev�� target�� ����Ű����
			if(newNode->next != NULL) curr->next->prev = newNode;		// ��������尡 �ƴѰ�� target����� ��������� prev�� newNode�� ����Ű����
			curr->next = newNode;										// target����� next�� ���ο� ��带 ����Ű����
		}

		else if (option == 'p') // target��� ������ �߰� (p == prev)
		{
			newNode->next = curr;
			newNode->prev = curr->prev;
			curr->prev->next = newNode;
			curr->prev = newNode;
		}
	}

	if (head->next == NULL)
	{
		head->next = newNode;
	}
}

Dnode* searchNode(Dnode* head, int data)
{
	int i = 1;
	Dnode* curr = head->next;
	while (curr != NULL)
	{
		if (curr->data == data)
		{
			printf("\n ã���ô� ���� ���� ����� ��ȣ�� %d�� �Դϴ�.\n", i);
			return curr;
		}
		curr = curr->next;
		i++;
	}
	printf(" �Է��Ͻ� ���� ã�����߽��ϴ�. \n");
}

void printNode(Dnode* head)
{
	printf("\n");
	Dnode* curr = head->next;
	while (curr != NULL)
	{
		printf(" %d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}


void allDelNode(Dnode* head)
{
	int i=1;
	Dnode* curr = head->next;
	while (curr != NULL)
	{
		printf(" %d �� ��� ����\n", i);
		head = curr;
		curr = curr->next;
		free(head);
		i++;
	}

}

void removeNode(Dnode* head, Dnode* target)
{
	Dnode* curr = head->next;
	while (curr != NULL)
	{
		curr = curr->next;
		
		if (curr == target)
		{
			printf(" ��� ��带 �����մϴ�.\n");
			free(curr);
			return;
		}
	}
	printf(" ����� ã�� ���߽��ϴ�.\n");
	
}