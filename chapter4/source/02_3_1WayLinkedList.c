#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
} Node;

void Pre_insertNode(Node* h, int data)			// 노드의 맨앞에 새로운 노드를 추가하는 함수
{
	Node* newNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL)						// 메모리없을때
	{
		return;
	}

	if (h->next == NULL)						// 노드없을때
	{
		newNode->data = data;					// 노드에 데이터 삽임
		newNode->next = NULL;					// 처음 만든노드 이므로 next값을 NULL로 초기화
		h->next = newNode;						// h->next가 새로운 노드를 가리키게 설정
	}

	else
	{
		newNode->data = data;					// 노드에 데이터 삽입
		newNode->next = h->next;				// 새로운 노드를 첫번째 노드로 사용
		h->next = newNode;						// 첫번째 노드로 설정했으므로 헤드의 위치도 옮겨준다
	}

}

void Rear_insertNode(Node* h, int data)		// 맨 뒤에 새로운 노드를 추가하는 함수
{
	Node* newNode = NULL;
	Node* tail = h->next;

	newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return;
	
	newNode->data = data;			// 데이터 삽입
	newNode->next = NULL;			// next의 정보 미리 NULL로 초기화

	

	if (tail == NULL)		// 헤드값이 NULL = 노드가 없음;
	{
		h->next = newNode;	// 헤드의 next를 새로만든 노드를 가리키거 설정
	}

	else						// 노드가 있으면 뒤쪽에 추가 
	{
		
		while (tail->next != NULL)	// tail->next가 NULL이란건 그 뒤에 없다는것 (초기상태)
		{
			tail = tail->next;		// tail이 가리키는 노드의 next가 NULL일때까지 tail을 한칸씩 이동
		}
		tail->next = newNode;		// 끝까지 이동하고 난다음 NULL상태인 next에 방금 만든 노드의 주소를 연결
		
	}
}

void printNode(Node* h)
{
	Node* curr = NULL;
	curr = h->next;					// curr이 첫번째 노드를 가리키게함

	while (curr != NULL)			// curr이 비어있을때까지 반복
	{
		printf("%d ", curr->data);	// curr이 가리키는 노드의 data멤버를 출력
		curr = curr->next;			// curr이 가리키는 노드의 next에 해당하는 노드를 curr이 가리킴
	}
	
}

void FreeNode(Node * h)
{
	Node* curr = h->next;			// curr이 첫번째 노드를 가리킴

	while (curr != NULL)			// next가 NULL인 노드를 curr이 가리킬때까지 반복 
	{
		h = curr;					// 
		curr = curr->next;
		free(h);
	}
	
	
}

int searchNode(Node* h, int data)
{
	int i = 1;
	Node* curr = h->next;		// curr이 첫번째 노드를 가리킨다.
	while (curr != NULL)
	{
		if (curr->data == data)
			return i;
		curr = curr->next;
		i++;
	}

}

void DeletNode(Node* h, int num)
{
	Node* curr = h->next; // curr이 1번째 노드를 가리킴

	for (int i = 0; i < num; i++)
	{
		h = curr;
		curr = curr->next;
	}
	free(h);


}


int main(void)
{
	Node* head = (Node*)malloc(sizeof(Node));
	if (head != NULL) head->next = NULL;

	Pre_insertNode(head, 10);		// 노드를 앞쪽에 추가하는 함수
	Pre_insertNode(head, 20);
	Pre_insertNode(head, 30);
	Pre_insertNode(head, 40);
	Pre_insertNode(head, 50);
	Pre_insertNode(head, 60);
	
	Rear_insertNode(head, 100);		// 노드를 뒷쪽에 추가하는 함수

	printNode(head);				// 노드를 출력하는 함수

	printf("찾고자 하는 값을 가진 노드는 %d번 노드 입니다.\n\n",searchNode(head, 30));		// 데이터값을 통한 노드 번호 검색함수

	DeletNode(head, searchNode(head, 40));
	printNode(head);
	FreeNode(head);					// 노드를 삭제하는 함수
	// printf("%d", head->next->data); // 삭제확인



	return 0;

}