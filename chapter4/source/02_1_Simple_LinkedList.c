// 단순연결 리스트
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
} Node;

int main(void)
{
	printf("\n\n---------------------------- < 단순열결 리스트 개념 > -------------------------------------\n\n");

	Node node1, node2 ;

	node1.data = 10;					
	node1.next = NULL;					

	printf("%d %p, %p\n\n", node1.data, &node1 ,node1.next);		// 10 100(node1의 시작주소)  NULL(새로운 노드를 만들경우 해당 노드의 시작주소를 가리킬 포인터 멤버)

	node2.data = 20;
	node2.next = NULL;
	node1.next = &node2;			// node1의 next가 node2의 시작주소를 가리킨다.


	printf("%d %p %p\n\n", node1.data, &node1, node1.next);		// 10 100(node1의 시작주소) 200(node2의 시작주소)
	printf("%d %p %p\n\n", node2.data, &node2, node2.next);		// 20 200(node2의 시작주소) NULL(새로운 노드를 만들경우 해당 노드의 시작주소를 가리킬 포인터 멤버)


	
	printf("\n\n-------------------------- < 동적할당을 이용한 단순열결 리스트 > ----------------------------------------\n\n");

	Node* head = (Node*)malloc(sizeof(Node));					// 노드헤드를 생성하고 동적할당을 부여
	head->next = NULL;											// 헤드는 항상 첫번째 노드를 가리킨다.
																// 노드가 없다면 헤드는 NULL로 초기화 상태
																


	Node* MalNode1 = NULL;										// 자동 노드 추가를 위한 포인터 구조체 
	MalNode1 = (Node*)malloc(sizeof(Node));						// 동적할당을 통해 자동 추가이므로 노드갯수 추가에 제한을 없앰!
	if (MalNode1 == NULL)
	{
		return;
	}

	Node* MalNode2 = NULL;										// 자동 노드 추가를 위한 포인터 구조체 
	MalNode2 = (Node*)malloc(sizeof(Node));						// 동적할당을 통해 자동 추가이므로 노드갯수 추가에 제한을 없앰!
	if (MalNode2 == NULL)
	{
		return;
	}

	Node* MalNode3 = NULL;										// 자동 노드 추가를 위한 포인터 구조체 
	MalNode3 = (Node*)malloc(sizeof(Node));						// 동적할당을 통해 자동 추가이므로 노드갯수 추가에 제한을 없앰!
	if (MalNode3 == NULL)
	{
		return;
	}

	MalNode1->data = 10;				// 포인터이므로 '->' 사용
	MalNode1->next = NULL;
	head->next = MalNode1;				// 헤드는 항상 첫번째 노드를 가리키는 역할을 해야한다.
	printf(" \n ===== \n\n헤드가리키는 곳이 첫번째 노드의 주소가 맞는지 확인.\n\n\t헤드 : %p\n첫 번째 노드 : %p\n\n ===== \n\n", head->next, MalNode1);

	MalNode2->data = 20;				
	MalNode2->next = NULL;
	MalNode1->next = MalNode2;

	MalNode3->data = 30;				
	MalNode3->next = NULL;
	MalNode2->next = MalNode3;


	printf("%d %p %p\n\n", MalNode1->data, MalNode1, MalNode1->next);			// 1번노드 데이터, 1번노드 시작주소, 1번노드의 next가 가리키는 다음 노드의 시작주소
	printf("%d %p %p\n\n", MalNode2->data, MalNode2, MalNode2->next);			// 2번노드 데이터, 2번노드 시작주소, 2번노드의 next가 가리키는 다음 노드의 시작주소
	printf("%d %p %p\n\n", MalNode3->data, MalNode3, MalNode3->next);			// 3번노드 데이터, 3번노드 시작주소, 3번노드의 next가 가리키는 다음 노드의 시작주소(다음이 없으므로 초기화값NULL)


	printf("\n\n---------------------- < 동적할당을 통한 노드의 추가 > -------------------------------------------\n\n");
	
	Node* NewNode1 = NULL;										// 자동 노드 추가를 위한 포인터 구조체 
	NewNode1 = (Node*)malloc(sizeof(Node));						// 동적할당을 통해 자동 추가이므로 노드갯수 추가에 제한을 없앰!
	if (NewNode1 == NULL)
	{
		return;
	}

	NewNode1->data = 10;				// 포인터이므로 '->' 사용
	NewNode1->next = NULL;						

	printf("%d %p\n", NewNode1->data, NewNode1->next);



	return 0;
}