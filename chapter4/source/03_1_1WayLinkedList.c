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

Node* searchNode_struct(Node* h, int data)				// 강사님의 검색방법
{
	Node* curr = h->next;
	while (curr != NULL)
	{
		if (curr->data == data)
		{
			printf("%d를 찾았습니다! \n", data);
			return curr;
		}
		curr = curr->next;
	}

	printf("%d 를 찾지 못했습니다.\n", data);
	return NULL;
}

void DeletNode(Node* h, int num)
{
	Node* curr = h->next; // curr이 1번째 노드를 가리킴
	Node* temp = h->next;

	for (int i = 0; i < num-1; i++)		// num-1인 이유는 지우고자하는 대상의 이전 노드에서 next를 대상노드를 뛰어넘어 다다음 노드를 가리키게 하기 위해
	{
		h = curr;
		curr = curr->next;
	}
	curr = h->next;
	h->next = h->next->next;			// 이러면 출력이나 값은 제대로 나오지만 실제로 삭제된게 아니라 건너뛰었기때문에 노드가 남아있다!
	free(curr);
}

void delNode(Node* h, Node* p)						// 강사님의 노드삭제함수
{
	Node* curr = h->next;
	if (curr == p) {								// 첫번째 노드인경우,
		h->next = p->next;							// 두번째 노드를 첫번째노드로 연결
	}
	else {											// 두번째이상인 경우,
		while (curr->next != p) {					
			curr = curr->next;						// 현노드의 next필드가 삭제노드인지 찾는다.
		}				
		curr->next = p->next;						// 삭제할 노드의 다음노드를 현 노드의 next멤버에 연결
	}
	free(p);										// 삭제할 노드 헤제
}

// 작성할 것
void InsertNode_SpecipicNum(Node* h, int data, int num)
{
	Node* curr = h->next;
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

	searchNode_struct(head, 20);														// 값의 존재여부를 탐색하는 함수

	DeletNode(head, searchNode(head, 10));												// 노드번호를 입력받아 해당 번호의 노드를 삭제

	printNode(head);				// 	DeletNode함수 때문에 해당 함수 출력시 튕김			

	FreeNode(head);					// 노드를 삭제하는 함수
	// printf("%d", head->next->data); // 삭제확인

	InsertNode_SpecipicNum(head, 90 ,6);	// 6번째 노드의 뒤에 노드를 삽입하는 함수



	return 0;

}