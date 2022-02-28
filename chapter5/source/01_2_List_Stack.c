// ��������Ʈ �迭����

#include <stdio.h>
#include <stdbool.h>

#define STACK_SZ 10

typedef int element;			// stack�� ��Ҵ� element�� ��� ǥ�� - ���ص� �� �� �˾ƺ��� �����Ϸ���


typedef struct {
	int top;
	element stack[STACK_SZ];
}Stack;

void initStack(Stack* pstack);
bool isEmpty(Stack*pstack);
bool isFull(Stack* pstack);
void push(Stack* pstack, element value);
element pop(Stack* pstack);

int main()
{
	Stack stack;
	initStack(&stack);
	push(&stack, 5);
	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);
	push(&stack, 40);
	push(&stack, 50);
	push(&stack, 60);
	push(&stack, 70);

	printf("%d ", pop(&stack));
	printf("%d ", pop(&stack));
	printf("%d ", pop(&stack));
	printf("%d ", pop(&stack));
	printf("%d ", pop(&stack));
	printf("%d ", pop(&stack));
	printf("%d ", pop(&stack));
	printf("%d ", pop(&stack));
	printf("%d ", pop(&stack));


	return 0;
}
	
void initStack(Stack* pstack)								// stack�ʱ�ȭ �Լ�
{
	pstack->top = -1;
}

bool isEmpty(Stack* pstack)									// ����ִ��� üũ
{
	if (pstack->top <= -1) return true;
	else return false;
}

bool isFull(Stack* pstack)									// ��ġ���� üũ
{
	if (pstack->top >= STACK_SZ - 1) return true;
	else return false;
}

void push(Stack* pstack, element value)						// �����߰�
{		
	if (isFull(pstack))
	{
		printf("\nStack overflow!!!\n");
		return;
	}
	else pstack->stack[++(pstack->top)] = value;
}

element pop(Stack* pstack)									// ���û���
{
	if (isEmpty(pstack))
	{
		printf("\nStack Underflow!!!\n");
		return;
	}
	else return pstack->stack[(pstack->top)--];
}

