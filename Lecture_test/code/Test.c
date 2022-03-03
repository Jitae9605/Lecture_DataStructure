#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NUM  10

typedef struct _node {
	char data;
	struct _node* next;
}LNode;

void createNode(LNode* head, char adata);
void printNode(LNode* head);
void insertionSort(LNode* head, int num);

int main(void)
{
	char data = '0';
	int num = 0;
	LNode* head = (LNode*)malloc(sizeof(LNode));
	if (head == NULL) exit(1);
	head->next = NULL;

	while (1)
	{
		if (num >= MAX_NUM) break;
		printf("알파벳을 입력하세요 : ");
		scanf("%c", &data);
		getchar();
		if (data == '0') break;
		else
		{
			createNode(head, data);
		}
		num++;
	}

	printNode(head);

	insertionSort(head,num);

	printNode(head);


	return 0;
}

void createNode(LNode*head, char adata)
{
	LNode* newNode = (LNode*)malloc(sizeof(LNode));
	if (newNode == NULL) return;

	newNode->data = adata;
	newNode->next = NULL;

	if (head->next == NULL)
	{
		head->next = newNode;
	}
	else
	{
		newNode->next = head->next;
		head->next = newNode;
	}
}

void printNode(LNode*head)
{
	LNode* curr = head->next;
	
	while (curr != NULL)
	{
		printf("%c ", curr->data);
		curr = curr->next;
	}
	printf("\n\n");
	
}

void insertionSort(LNode* head,int num)
{
	char temp[MAX_NUM + 1] = { '0', };
	int k = 0;
	char t;
	int maxIdx = 0;
	LNode* curr = (LNode*)malloc(sizeof(LNode));
	if (curr == NULL) return;
	curr = head->next;

	while(curr != NULL)
	{
		temp[k] = curr->data;
		curr = curr->next;
		k++;
		
	}
	

	for (int i = 0; i < num-1; i++)
	{
		maxIdx = i;
		for (int j = i + 1; j < num; j++)
		{
			if (temp[j] < temp[maxIdx])
				maxIdx = j;
		}
		t = temp[i];
		temp[i] = temp[maxIdx];
		temp[maxIdx] = t;
	}

	curr = head->next;
	for (int i = 0; i < num; i++)
	{
		curr->data = temp[i];
		curr = curr->next;
	}


}

