// 스택자료구조기본
// 쓰임새 = 대표적으로 ctrl + z(실행취소), 뒤로가기 등의 동작에서 사용된다.

#include <stdio.h>
#include <stdbool.h>			// 헤더파일 stdbool.h를 포함해야 bool 자료형을 쓸수있다.

#define STACK_SZ	5

typedef int element;			// 자료구조의 형식을 좀더 쉽게 이해하기 위해 int -> element 로 이름을 바꾼것
								// 스택의 자료형이다.

bool isEmpty();					// 스택이 비어있는지 여부 확인
bool isFull();					// 스택이 꽉차있는지 여부 확인
void push(element);				// 스택 값 추가
element pop();					// 스택 값 삭제
element peek();					// 스택 값 조회
								

element stack[STACK_SZ];		// stack 선언

int top = -1;					// -1이면 비워져있다.

int main(void)
{


	return 0;
}

bool isEmpty()					// 비워져있는지 확인
{
	if (top <= -1) return true;
	else return false;
}

bool isFull()					// 스택의 포화상태 확인
{
	if (top >= STACK_SZ - 1) return true;
	else return false;
}

void push(element value)				// stack 추가
{
	if (isFull())
	{
		printf("STACK overflow!!!\n");
		return;
	}
	else stack[++top] = value;			// top의 초기값이 -1이므로 stack[++top] 이다
}

element pop()							// stack 삭제
{
	if (isEmpty())
	{
		printf("STACK underflow!!!\n");
		return 0;
	}
	else return stack[top--];			// 삭제했으니 최상단을 의미하는 top의 값을 1감소 (top--)		
}

element peek()
{
	if (isEmpty())
	{
		printf("STACK underflow!!\n");		// 값이 없는데 읽어오려하므로 오류
		exit(1);
	}
	else return stack[top];

}