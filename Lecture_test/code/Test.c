#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NUM  10									// 최대로 받을 알파벳의 숫자

typedef struct _node {
	char data;
	struct _node* next;
}LNode;

void createNode(LNode* head, char adata);			// 노드생성
void printNode(LNode* head);						// 노드출력
void insertionSort(LNode* head, int num);			// 정렬(삽입정렬)

int main(void)
{
	char data = '0';
	int num = 0;										// 생성된 노드의 갯수 카운트
	LNode* head = (LNode*)malloc(sizeof(LNode));		// 헤드생성
	if (head == NULL) exit(1);
	head->next = NULL;									// 초기화

	while (1)
	{
		if (num >= MAX_NUM) break;
		printf("알파벳을 입력하세요 : ");
		scanf("%c", &data);
		getchar();										// 버퍼에서 Enter 삭제
		if (data == '0') break;							// 10개가 아니어도 중간에 나가기 가능
		else
		{
			createNode(head, data);						// 노드생성
		}
		num++;											// 생성된 노드의 숫자 카운트
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

	newNode->data = adata;		// 초기화(입력받은 adata를 생성한 노드의 data에 입력)
	newNode->next = NULL;		// 초기화

	if (head->next == NULL)		// 노드가 하나도 없을때
	{
		head->next = newNode;
	}
	else						// 노드가 있을때
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
	char temp[MAX_NUM + 1] = { '0', };					// 정렬때 사용할 문자열 배열생성 및 초기화
	int k = 0;											// 반복을 위한 임시
	char t;												// 정렬때 사용할 임시공산
	int maxIdx = 0;
	LNode* curr = (LNode*)malloc(sizeof(LNode));
	if (curr == NULL) return;
	curr = head->next;

	while(curr != NULL)									// 노드를 순회하면서 각 노드의 data값을 temp배열에 입력
	{
		temp[k] = curr->data;
		curr = curr->next;
		k++;
		
	}
	

	for (int i = 0; i < num-1; i++)						// temp배열을 대상으로 삽입정렬(매개변수로 받은 노드의 갯수(num)를 기준으로함)
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

	curr = head->next;									// 정렬된 temp의 값을 순서대로 노드의 data멤버에 삽입
	for (int i = 0; i < num; i++)
	{
		curr->data = temp[i];
		curr = curr->next;
	}


}

