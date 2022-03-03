/*
	Alphabet_sort.c
	creaated : 2022. 3. 3
	Author : ������
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NUM  10									// �ִ�� ���� ���ĺ��� ����

typedef struct _node {
	char data;
	struct _node* next;
}LNode;

void createNode(LNode* head, char adata);				// ������
void printNode(LNode* head);							// ������
void insertionSort(LNode* head);						// ����(��������)

int main(void)
{
	char data = '0';
	int num = 0;										// ������ ����� ���� ī��Ʈ
	LNode* head = (LNode*)malloc(sizeof(LNode));		// ������
	if (head == NULL) exit(1);
	head->next = NULL;									// �ʱ�ȭ

	while (1)
	{
		if (num >= MAX_NUM) break;
		printf("���ĺ��� �Է��ϼ��� : ");
		scanf("%c", &data);
		getchar();										// ���ۿ��� Enter ����
		if (data == '0') break;							// 10���� �ƴϾ �߰��� ������ ����
		else
		{
			createNode(head, data);						// ������
		}
		num++;											// ������ ����� ���� ī��Ʈ
	}

	printf("\n=== < ���� �� > ===\n\n");
	printNode(head);		

	insertionSort(head);

	printf("=== < ���� �� > ===\n\n");
	printNode(head);


	return 0;
}

void createNode(LNode*head, char adata)
{
	LNode* newNode = (LNode*)malloc(sizeof(LNode));
	if (newNode == NULL) return;

	newNode->data = adata;					// �ʱ�ȭ(�Է¹��� adata�� ������ ����� data�� �Է�)
	newNode->next = NULL;					// �ʱ�ȭ

	if (head->next == NULL)			// ��尡 �ϳ��� ������
	{
		head->next = newNode;
	}
	else							// ��尡 ������
	{
		newNode->next = head->next;
		head->next = newNode;
	}
}

void printNode(LNode*head)						// ���� ������ ���
{
	LNode* curr = head->next;
	char upper_ary[MAX_NUM] = { 0 };			// �빮�� ����
	char lower_ary[MAX_NUM] = { 0 };			// �ҹ��� ����
	char temp[MAX_NUM];							// �ӽ÷� ������ �޾ƿ� �迭
	int i = 0, a = 0, b = 0;					// �ӽú���(�ݺ��� �� �������� ���)

	
	while (curr != NULL)
	{
		temp[i] = curr->data;
		curr = curr->next;
		i++;
	}

	for (int j = 0; j < i; j++)
	{
		if (temp[j] >= 'a' && temp[j] <= 'z')			// �޾ƿ� �������� �ҹ��ڴ� lower�� ����
		{
			lower_ary[a] = temp[j];
			a++;
		}

		if (temp[j] >= 'A' && temp[j] <= 'Z')			// �޾ƿ� �������� �빮�ڴ� upper�� ����
		{
			upper_ary[b] = temp[j];
			b++;
		}
	}
		
	if (upper_ary[0] != 0)								// �빮�� ���
	{
		printf(" �빮�� : ");
		for (int c = 0; c < a; c++)
		{
			printf("%c ", upper_ary[c]);
		}
	}
	printf("\n\n");

	if (lower_ary[0] != 0)								// �ҹ��� ���
	{
		printf(" �ҹ��� : ");
		for (int d = 0; d < b; d++)
		{
			printf("%c ", lower_ary[d]);
		}
	}
	printf("\n\n");
}

void insertionSort(LNode* head)							// ���������Լ�
{
	char temp[MAX_NUM + 1] = { '0', };					// ���Ķ� ����� ���ڿ� �迭���� �� �ʱ�ȭ
	int k = 0;											// �ݺ��� ���� �ӽú���
	char t;												// ���Ķ� ����� �ӽð���
	int maxIdx = 0;
	LNode* curr = (LNode*)malloc(sizeof(LNode));
	if (curr == NULL) return;
	curr = head->next;

	while(curr != NULL)									// ��带 ��ȸ�ϸ鼭 �� ����� data���� temp�迭�� �Է�
	{
		temp[k] = curr->data;
		curr = curr->next;
		k++;
		
	}
	

	for (int i = 0; i < k-1; i++)						// temp�迭�� ������� ��������(�Ű������� ���� ����� ����(num)�� ����������)
	{
		maxIdx = i;
		for (int j = i + 1; j < k; j++)
		{
			if (temp[j] < temp[maxIdx])
				maxIdx = j;
		}
		t = temp[i];
		temp[i] = temp[maxIdx];
		temp[maxIdx] = t;
	}

	curr = head->next;									// ���ĵ� temp�� ���� ������� ����� data����� ����
	for (int i = 0; i < k; i++)
	{
		curr->data = temp[i];
		curr = curr->next;
	}


}
