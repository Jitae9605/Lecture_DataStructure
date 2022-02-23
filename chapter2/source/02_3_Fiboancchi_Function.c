#include<stdio.h>

int Fibonacci(int n)
{
	if (n == 1)
		return 0;

	else if (n == 2)
		return 1;

	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);

}

int Fibonacci_fail(int n)
{
	printf("func call param %d\n", n);
	if (n == 1)
		return 0;

	else if (n == 2)
		return 1;

	else
		return Fibonacci_fail(n - 1) + Fibonacci_fail(n - 2);

}


int main(void)
{
	printf(" \n=== < 틀린 방법 > ===\n\n");

	Fibonacci_fail(7);
	// 재귀함수 내부에 printf 같은 것을 사용하면 재귀되는 상황전부에서 내용을 출력한다.
	//	즉, 유지보수측면이든 무슨 측면이든 반환값을 변수로 받는것이 옳다.

	printf(" \n=== < 옳은 방법 > ===\n\n");
	int i;

	for (i = 1; i < 15; i++)
		printf(" %d ", Fibonacci(i));
		// Fibonacci(i);					// 이렇게 만 선언하면 값이 반환된다음 저장되지 않고 그대로 벼려지기만한다(연산만하고 전부 버려짐)
											// 이 함수에 printf를 넣으면 재귀될때마다 전부 출력되므로 X


	return 0;
}