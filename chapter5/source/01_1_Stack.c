// �����ڷᱸ���⺻
// ���ӻ� = ��ǥ������ ctrl + z(�������), �ڷΰ��� ���� ���ۿ��� ���ȴ�.

#include <stdio.h>
#include <stdbool.h>			// ������� stdbool.h�� �����ؾ� bool �ڷ����� �����ִ�.

#define STACK_SZ	5

typedef int element;			// �ڷᱸ���� ������ ���� ���� �����ϱ� ���� int -> element �� �̸��� �ٲ۰�
								// ������ �ڷ����̴�.

bool isEmpty();					// ������ ����ִ��� ���� Ȯ��
bool isFull();					// ������ �����ִ��� ���� Ȯ��
void push(element);				// ���� �� �߰�
element pop();					// ���� �� ����
element peek();					// ���� �� ��ȸ
								

element stack[STACK_SZ];		// stack ����

int top = -1;					// -1�̸� ������ִ�.

int main(void)
{


	return 0;
}

bool isEmpty()					// ������ִ��� Ȯ��
{
	if (top <= -1) return true;
	else return false;
}

bool isFull()					// ������ ��ȭ���� Ȯ��
{
	if (top >= STACK_SZ - 1) return true;
	else return false;
}

void push(element value)				// stack �߰�
{
	if (isFull())
	{
		printf("STACK overflow!!!\n");
		return;
	}
	else stack[++top] = value;			// top�� �ʱⰪ�� -1�̹Ƿ� stack[++top] �̴�
}

element pop()							// stack ����
{
	if (isEmpty())
	{
		printf("STACK underflow!!!\n");
		return 0;
	}
	else return stack[top--];			// ���������� �ֻ���� �ǹ��ϴ� top�� ���� 1���� (top--)		
}

element peek()
{
	if (isEmpty())
	{
		printf("STACK underflow!!\n");		// ���� ���µ� �о�����ϹǷ� ����
		exit(1);
	}
	else return stack[top];

}