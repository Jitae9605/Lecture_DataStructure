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
		newNode->data = data;					// ��忡 ������ ����
		newNode->next = NULL;					// ó�� ������ �̹Ƿ� next���� NULL�� �ʱ�ȭ
		h->next = newNode;						// h->next�� ���ο� ��带 ����Ű�� ����
	}

	else
	{
		newNode->data = data;					// ��忡 ������ ����
		newNode->next = h->next;				// ���ο� ��带 ù��° ���� ���
		h->next = newNode;						// ù��° ���� ���������Ƿ� ����� ��ġ�� �Ű��ش�
	}

}

void Rear_insertNode(Node* h, int data)		// �� �ڿ� ���ο� ��带 �߰��ϴ� �Լ�
{
	Node* newNode = NULL;
	Node* tail = h->next;

	newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;
	
	newNode->data = data;			// ������ ����
	newNode->next = NULL;			// next�� ���� �̸� NULL�� �ʱ�ȭ

	

	if (tail == NULL)		// ��尪�� NULL = ��尡 ����;
	{
		h->next = newNode;	// ����� next�� ���θ��� ��带 ����Ű�� ����
	}

	else						// ��尡 ������ ���ʿ� �߰� 
	{
		
		while (tail->next != NULL)	// tail->next�� NULL�̶��� �� �ڿ� ���ٴ°� (�ʱ����)
		{
			tail = tail->next;		// tail�� ����Ű�� ����� next�� NULL�϶����� tail�� ��ĭ�� �̵�
		}
		tail->next = newNode;		// ������ �̵��ϰ� ������ NULL������ next�� ��� ���� ����� �ּҸ� ����
		
	}
}

void printNode(Node* h)
{
	Node* curr = NULL;
	curr = h->next;					// curr�� ù��° ��带 ����Ű����

	while (curr != NULL)			// curr�� ������������� �ݺ�
	{
		printf("%d ", curr->data);	// curr�� ����Ű�� ����� data����� ���
		curr = curr->next;			// curr�� ����Ű�� ����� next�� �ش��ϴ� ��带 curr�� ����Ŵ
	}
	
}

void FreeNode(Node * h)
{
	Node* curr = h->next;			// curr�� ù��° ��带 ����Ŵ

	while (curr != NULL)			// next�� NULL�� ��带 curr�� ����ų������ �ݺ� 
	{
		h = curr;					// 
		curr = curr->next;
		free(h);
	}
	
	
}

int searchNode(Node* h, int data)
{
	int i = 1;
	Node* curr = h->next;		// curr�� ù��° ��带 ����Ų��.
	while (curr != NULL)
	{
		if (curr->data == data)
			return i;
		curr = curr->next;
		i++;
	}
}

Node* searchNode_struct(Node* h, int data)				// ������� �˻����
{
	Node* curr = h->next;
	while (curr != NULL)
	{
		if (curr->data == data)
		{
			printf("%d�� ã�ҽ��ϴ�! \n", data);
			return curr;
		}
		curr = curr->next;
	}

	printf("%d �� ã�� ���߽��ϴ�.\n", data);
	return NULL;
}

void DeletNode(Node* h, int num)
{
	Node* curr = h->next; // curr�� 1��° ��带 ����Ŵ
	Node* temp = h->next;

	for (int i = 0; i < num-1; i++)		// num-1�� ������ ��������ϴ� ����� ���� ��忡�� next�� ����带 �پ�Ѿ� �ٴ��� ��带 ����Ű�� �ϱ� ����
	{
		h = curr;
		curr = curr->next;
	}
	curr = h->next;
	h->next = h->next->next;			// �̷��� ����̳� ���� ����� �������� ������ �����Ȱ� �ƴ϶� �ǳʶپ��⶧���� ��尡 �����ִ�!
	free(curr);
}

void delNode(Node* h, Node* p)						// ������� �������Լ�
{
	Node* curr = h->next;
	if (curr == p) {								// ù��° ����ΰ��,
		h->next = p->next;							// �ι�° ��带 ù��°���� ����
	}
	else {											// �ι�°�̻��� ���,
		while (curr->next != p) {					
			curr = curr->next;						// ������� next�ʵ尡 ����������� ã�´�.
		}				
		curr->next = p->next;						// ������ ����� ������带 �� ����� next����� ����
	}
	free(p);										// ������ ��� ����
}

// �ۼ��� ��
void InsertNode_SpecipicNum(Node* h, int data, int num)
{
	Node* curr = h->next;
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

	printf("ã���� �ϴ� ���� ���� ���� %d�� ��� �Դϴ�.\n\n",searchNode(head, 30));		// �����Ͱ��� ���� ��� ��ȣ �˻��Լ�

	searchNode_struct(head, 20);														// ���� ���翩�θ� Ž���ϴ� �Լ�

	DeletNode(head, searchNode(head, 10));												// ����ȣ�� �Է¹޾� �ش� ��ȣ�� ��带 ����

	printNode(head);				// 	DeletNode�Լ� ������ �ش� �Լ� ��½� ƨ��			

	FreeNode(head);					// ��带 �����ϴ� �Լ�
	// printf("%d", head->next->data); // ����Ȯ��

	InsertNode_SpecipicNum(head, 90 ,6);	// 6��° ����� �ڿ� ��带 �����ϴ� �Լ�



	return 0;

}