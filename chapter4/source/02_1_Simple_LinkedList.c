// �ܼ����� ����Ʈ
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
} Node;

int main(void)
{
	printf("\n\n---------------------------- < �ܼ����� ����Ʈ ���� > -------------------------------------\n\n");

	Node node1, node2 ;

	node1.data = 10;					
	node1.next = NULL;					

	printf("%d %p, %p\n\n", node1.data, &node1 ,node1.next);		// 10 100(node1�� �����ּ�)  NULL(���ο� ��带 ������ �ش� ����� �����ּҸ� ����ų ������ ���)

	node2.data = 20;
	node2.next = NULL;
	node1.next = &node2;			// node1�� next�� node2�� �����ּҸ� ����Ų��.


	printf("%d %p %p\n\n", node1.data, &node1, node1.next);		// 10 100(node1�� �����ּ�) 200(node2�� �����ּ�)
	printf("%d %p %p\n\n", node2.data, &node2, node2.next);		// 20 200(node2�� �����ּ�) NULL(���ο� ��带 ������ �ش� ����� �����ּҸ� ����ų ������ ���)


	
	printf("\n\n-------------------------- < �����Ҵ��� �̿��� �ܼ����� ����Ʈ > ----------------------------------------\n\n");

	Node* head = (Node*)malloc(sizeof(Node));					// �����带 �����ϰ� �����Ҵ��� �ο�
	head->next = NULL;											// ���� �׻� ù��° ��带 ����Ų��.
																// ��尡 ���ٸ� ���� NULL�� �ʱ�ȭ ����
																


	Node* MalNode1 = NULL;										// �ڵ� ��� �߰��� ���� ������ ����ü 
	MalNode1 = (Node*)malloc(sizeof(Node));						// �����Ҵ��� ���� �ڵ� �߰��̹Ƿ� ��尹�� �߰��� ������ ����!
	if (MalNode1 == NULL)
	{
		return;
	}

	Node* MalNode2 = NULL;										// �ڵ� ��� �߰��� ���� ������ ����ü 
	MalNode2 = (Node*)malloc(sizeof(Node));						// �����Ҵ��� ���� �ڵ� �߰��̹Ƿ� ��尹�� �߰��� ������ ����!
	if (MalNode2 == NULL)
	{
		return;
	}

	Node* MalNode3 = NULL;										// �ڵ� ��� �߰��� ���� ������ ����ü 
	MalNode3 = (Node*)malloc(sizeof(Node));						// �����Ҵ��� ���� �ڵ� �߰��̹Ƿ� ��尹�� �߰��� ������ ����!
	if (MalNode3 == NULL)
	{
		return;
	}

	MalNode1->data = 10;				// �������̹Ƿ� '->' ���
	MalNode1->next = NULL;
	head->next = MalNode1;				// ���� �׻� ù��° ��带 ����Ű�� ������ �ؾ��Ѵ�.
	printf(" \n ===== \n\n��尡��Ű�� ���� ù��° ����� �ּҰ� �´��� Ȯ��.\n\n\t��� : %p\nù ��° ��� : %p\n\n ===== \n\n", head->next, MalNode1);

	MalNode2->data = 20;				
	MalNode2->next = NULL;
	MalNode1->next = MalNode2;

	MalNode3->data = 30;				
	MalNode3->next = NULL;
	MalNode2->next = MalNode3;


	printf("%d %p %p\n\n", MalNode1->data, MalNode1, MalNode1->next);			// 1����� ������, 1����� �����ּ�, 1������� next�� ����Ű�� ���� ����� �����ּ�
	printf("%d %p %p\n\n", MalNode2->data, MalNode2, MalNode2->next);			// 2����� ������, 2����� �����ּ�, 2������� next�� ����Ű�� ���� ����� �����ּ�
	printf("%d %p %p\n\n", MalNode3->data, MalNode3, MalNode3->next);			// 3����� ������, 3����� �����ּ�, 3������� next�� ����Ű�� ���� ����� �����ּ�(������ �����Ƿ� �ʱ�ȭ��NULL)


	printf("\n\n---------------------- < �����Ҵ��� ���� ����� �߰� > -------------------------------------------\n\n");
	
	Node* NewNode1 = NULL;										// �ڵ� ��� �߰��� ���� ������ ����ü 
	NewNode1 = (Node*)malloc(sizeof(Node));						// �����Ҵ��� ���� �ڵ� �߰��̹Ƿ� ��尹�� �߰��� ������ ����!
	if (NewNode1 == NULL)
	{
		return;
	}

	NewNode1->data = 10;				// �������̹Ƿ� '->' ���
	NewNode1->next = NULL;						

	printf("%d %p\n", NewNode1->data, NewNode1->next);



	return 0;
}