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
	printf(" \n=== < Ʋ�� ��� > ===\n\n");

	Fibonacci_fail(7);
	// ����Լ� ���ο� printf ���� ���� ����ϸ� ��͵Ǵ� ��Ȳ���ο��� ������ ����Ѵ�.
	//	��, �������������̵� ���� �����̵� ��ȯ���� ������ �޴°��� �Ǵ�.

	printf(" \n=== < ���� ��� > ===\n\n");
	int i;

	for (i = 1; i < 15; i++)
		printf(" %d ", Fibonacci(i));
		// Fibonacci(i);					// �̷��� �� �����ϸ� ���� ��ȯ�ȴ��� ������� �ʰ� �״�� �������⸸�Ѵ�(���길�ϰ� ���� ������)
											// �� �Լ��� printf�� ������ ��͵ɶ����� ���� ��µǹǷ� X


	return 0;
}