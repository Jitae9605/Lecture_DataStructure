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
		// Fibonacci(i);					// �̷��� �� �����ϸ� ���� ��ȯ�ȴ��� ������� �ʰ� �״�� �������⸸�Ѵ�(���길�ϰ� ���� ������)
											// �� �Լ��� printf�� ������ ��͵ɶ����� ���� ��µǹǷ� X


	return 0;
}