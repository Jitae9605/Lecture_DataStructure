#include <stdio.h>

int main(void)
{
	// 4 * 3 * 2 * 1
	// 1) for

	int sum_1 = 1;
	for (int i = 4; i >= 1; i--)
	{
		sum_1 *= i;
	}
	printf("%d", sum_1);


	return 0;
}