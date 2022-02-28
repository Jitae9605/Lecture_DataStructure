#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int element;			// stack�� ��Ҵ� element�� ��� ǥ�� - ���ص� �� �� �˾ƺ��� �����Ϸ���

typedef struct node{				// ����Ʈ����ü
	int data;
	struct node* link;
}Node;

typedef struct {					// ��屸��ü
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

HStack* createHead()								// ������
{
	HStack* h = (HStack*)malloc(sizeof(HStack));
	if (h == NULL) exit(1);
	h->head = NULL;
	return h;
}

bool isEmpty(HStack* ahead)							// ��� üũ
{
	if (ahead->head == NULL) return true;
	else return false;
}

void push(HStack* ahead, element value)				// �Է�
{
	Node* newStack = (Node*)malloc(sizeof(Node));
	if (newStack == NULL) exit(1);
	if (ahead->head == NULL) printf("\n\n");			// �������� �ϱ����� ����÷ο����� ���� �Է¹����� ���ٳѱ�� �Է¹��� -> ��½� ���� 

	newStack->data = value;
	newStack->link = ahead->head;
	ahead->head = newStack;
	

}

element pop(HStack* ahead)							// ����
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

