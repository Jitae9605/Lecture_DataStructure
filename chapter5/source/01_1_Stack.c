#include <stdio.h>
#include <stdbool.h>

#define STACK_SZ	5

typedef int element;			// 자료구조의 형식을 좀더 쉽게 이해하기 위해 int -> element 로 이름을 바꾼것
								// 스택의 자료형이다.

bool inEmpty();					// 스택이 비어있는지 여부 확인
								// 헤더파일 stdbool.h를 포함해야 bool 자료형을 쓸수있다.

element stack[STACK_SZ];		// stack

int top = -1;					// -1이면 비워져있다.

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