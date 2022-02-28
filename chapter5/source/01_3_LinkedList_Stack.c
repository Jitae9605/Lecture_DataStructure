#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int element;			// stack의 요소는 element로 적어서 표시 - 안해도 됨 걍 알아보기 쉽게하려고

typedef struct node{				// 리스트구조체
	int data;
	struct node* link;
}Node;

typedef struct {					// 헤드구조체
	Node* head;
}HStack;

HStack* createHead();
bool isEmpty(HStack* h);
void push(HStack* h,element value);
element pop(HStack*);
element  peek(HStack*);


int  main(void)
{
	HStack* H = createHead();

	push(H, 10);
	push(H, 20);
	push(H, 30);
	push(H, 40);
	push(H, 50);
	push(H, 60);
	push(H, 70);
	push(H, 80);
	push(H, 90);
	push(H, 100);

	printf("%d ", pop(H));
	printf("%d ", pop(H));
	printf("%d ", pop(H));
	printf("%d ", pop(H));
	printf("%d ", pop(H));
	printf("%d ", pop(H));
	printf("%d ", pop(H));
	printf("%d ", pop(H));
	printf("%d ", pop(H));
	printf("%d ", pop(H));
	printf("%d ", pop(H));

	push(H, 10);
	push(H, 20);
	push(H, 30);
	push(H, 40);
	push(H, 50);
	push(H, 60);
	push(H, 70);
	push(H, 80);
	push(H, 90);
	push(H, 100);

	printf("%d ", pop(H));
	printf("%d ", pop(H));
	printf("%d ", pop(H));
	printf("%d ", pop(H));
	printf("%d ", pop(H));
	printf("%d ", pop(H));
	printf("%d ", pop(H));
	printf("%d ", pop(H));
	printf("%d ", pop(H));
	printf("%d ", pop(H));
	printf("%d ", pop(H));

	return 0;
}

HStack* createHead()								// 노드생성
{
	HStack* h = (HStack*)malloc(sizeof(HStack));
	if (h == NULL) exit(1);
	h->head = NULL;
	return h;
}

bool isEmpty(HStack* ahead)							// 빈거 체크
{
	if (ahead->head == NULL) return true;
	else return false;
}

void push(HStack* ahead, element value)				// 입력
{
	Node* newStack = (Node*)malloc(sizeof(Node));
	if (newStack == NULL) exit(1);
	if (ahead->head == NULL) printf("\n\n");			// 보기좋게 하기위해 언더플로우이후 값을 입력받을때 한줄넘기고 입력받음 -> 출력시 예쁨 

	newStack->data = value;
	newStack->link = ahead->head;
	ahead->head = newStack;
	

}

element pop(HStack* ahead)							// 삭제
{
	if (isEmpty(ahead))
	{
		printf("\nSTACK Underflow!!");
		return 1;
	}

	else
	{
		int data = ahead->head->data;
		ahead->head = ahead->head->link;
		return data;
	}



}
element  peek(HStack* ahead)
{

}

