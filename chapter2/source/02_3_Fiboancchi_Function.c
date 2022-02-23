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

int main(void)
{
	int i;

	for (i = 1; i < 15; i++)
		printf(" %d ", Fibonacci(i));
		// Fibonacci(i);					// 이렇게 만 선언하면 값이 반환된다음 저장되지 않고 그대로 벼려지기만한다(연산만하고 전부 버려짐)
											// 이 함수에 printf를 넣으면 재귀될때마다 전부 출력되므로 X


	return 0;
}