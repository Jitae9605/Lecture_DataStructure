#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int data;							// 데이터를 저장할 멤버 변수
	struct _node* next;					// 다음 노드의 주소를 저장할 멤버 포인터 변수
} Node;

int main(void)
{
	Node* head = NULL;					// 첫 노드의 주소를 가리키는 포인터 구조체
	Node* tail = NULL;					// 마지막 노드의 주소를 가리키는 포인터 구조체
	Node* cur = NULL;					// 현재 가리키고있는 노드의 주소를 가리키는 포인터 구조체

	Node* newNode = NULL;				// 새로운 노드를 추가하는 노드
	int readData;						// 읽어온 데이터를 임시 저장할 변수

	// 데이터를 입력받는 과정
	while (1)
	{
		printf(" 자연수 입력: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		// 노드의 추가과정
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;

		tail = newNode;
	}
	printf("\n");

	// 입력받은 데이터의 출력과정
	printf(" 입력받은 데이터의 전체출력! \n");
	if (head == NULL)
	{
		printf(" 저장된 자연수가 존재하지 않습니다.\n");
	}
	else
	{
		cur = head;
		printf(" %d ", cur->data);	// 첫번쨰 데이터 출력
		while (cur->next != NULL)
		{
			cur = cur->next;
			printf(" %d ", cur->data);
		}
	}
	printf("\n\n");


	// 메모리의 헤제과정
	if (head == NULL)
	{
		return 0;	// 헤제할 노드가 존재하지 않는다.
	}
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf(" %d 을(를) 삭제합니다. \n", head->data);
		free(delNode);							// 첫번째 노드 삭제

		while (delNextNode != NULL)				// 두번째 이후 노드 삭제
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf(" %d 를 삭제합니다. \n", delNode->data);
			free(delNode);
		}
	}
	
	return 0;
}