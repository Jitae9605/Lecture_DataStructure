// 양방향연결리스트

#include<stdio.h>
#include<stdlib.h>

typedef struct Double_node
{
	int data;
	struct Double_node* next;			// 뒤의 노드와 연결할 멤버
	struct Double_node* prev;			// 앞의 노드와 연결할 멤버
}Dnode;

//함수선언
void insertNode(Dnode* head, int data, Dnode* num, char option); 
Dnode* searchNode(Dnode* head, int data);
void printNode(Dnode* head);
void allDelNode(Dnode* head);
void removeNode(Dnode* head, Dnode*);


int main(voide)
{
	Dnode* head = (Dnode*)malloc(sizeof(Dnode));		// head 생성
	if (head == NULL) exit(1);							// 메모리 부족시 강제종료

	head->next = NULL;									// head 초기화 (next)
	head->prev = NULL;;									// head 초기화 (prev)
	
	Dnode* pos = NULL;									// 기준노드역할을 하고, 검색하여 찾은 노드의 주소값을 저장

	insertNode(head, 10, pos, 'n');
	insertNode(head, 20, pos, 'n');
	insertNode(head, 30, pos, 'n');
	insertNode(head, 40, head->next->next, 'p');		// 2번째 노드 20을 target으로 prev위치(20과 30 사이)에 노드를 삽입
	insertNode(head, 50, pos, 'n');
	insertNode(head, 60, pos, 'p');
	insertNode(head, 100, pos, 'p');
	insertNode(head, 110, pos, 'p');
	insertNode(head, 120, pos, 'p');
	insertNode(head, 130, pos, 'p');
	insertNode(head, 140, pos, 'p');

	printNode(head);

	searchNode(head, 110);								// 데이터값을 기준으로 노드를 장아서 노드의 번호를 출력 [ 반환값 = 찾은 노드의 주소값을 가진 포인트구조체( = Node*curr) ]
	
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

	if (target == NULL)		// target을 지정하지 않으면 첫번째 노드로 넣는다
	{
		if (head->next == NULL)			// 노드가 하나도 없을때 - 만들고 head만 연결
		{
			head->next = newNode;		// 새로 만든 노드를 head가 가리킴
		}

		else	// 노드가 있을때 - 기존노드에 연결하고 head를 연결
		{
			newNode->next = head->next;		// 새로만든 노드의 next가 기존의 첫번째 노드를 가리킴 (next를 기존 첫번째 노드와 연결)
			head->next->prev = newNode;		// head가 기존에 가리키던 노드(기존 첫번째 노드)의 prev가 새로 만든 노드를 가리킴
			head->next = newNode;			// head의 next가 가리키는 대상을 새로만든 노드로 바꿈
		}
	}

	else					// target이 지정
	{
		Dnode* curr = head->next;	// 탐색노드 생성
		while (curr != target)		// 순회하며 target과 같은 노드가 있는지 찾음
		{
			curr = curr->next;		
		}

		if (option == 'n')		// target노드 다음에 추가 (n == next)
		{
			newNode->next = curr->next;									// 새로운 노드의 next를 target노드의 다음노드(target->next)를 가리키게함
			newNode->prev = curr;										// 새로운 노드의 prev를 target을 가리키게함
			if(newNode->next != NULL) curr->next->prev = newNode;		// 마지막노드가 아닌경우 target노드의 다음노드의 prev가 newNode를 가리키게함
			curr->next = newNode;										// target노드의 next가 새로운 노드를 가리키게함
		}

		else if (option == 'p') // target노드 아전에 추가 (p == prev)
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
			printf("\n 찾으시는 값을 가진 노드의 번호는 %d번 입니다.\n", i);
			return curr;
		}
		curr = curr->next;
		i++;
	}
	printf(" 입력하신 값을 찾지못했습니다. \n");
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
		printf(" %d 번 노드 삭제\n", i);
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
			printf(" 대상 노드를 삭제합니다.\n");
			free(curr);
			return;
		}
	}
	printf(" 대상을 찾지 못했습니다.\n");
	
}