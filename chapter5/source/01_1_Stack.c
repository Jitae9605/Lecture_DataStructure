#include <stdio.h>
#include <stdbool.h>

#define STACK_SZ	5

typedef int element;			// �ڷᱸ���� ������ ���� ���� �����ϱ� ���� int -> element �� �̸��� �ٲ۰�
								// ������ �ڷ����̴�.

bool inEmpty();					// ������ ����ִ��� ���� Ȯ��
								// ������� stdbool.h�� �����ؾ� bool �ڷ����� �����ִ�.

element stack[STACK_SZ];		// stack

int top = -1;					// -1�̸� ������ִ�.

int main(void)
{


	return 0;
}

bool isEmpty()
{
	if (top <= -1) return true;
	else return false;
}

bool isFull()
{
	if (top >= STACK_SZ - 1) return true;
	else return false;
}