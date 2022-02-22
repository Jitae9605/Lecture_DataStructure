#include <stdio.h>

int Factorial(int num);

int main(void)
{
	// 4 * 3 * 2 * 1
	printf("\n------------------------- < 1) for문을 이용한 팩토리알 > ---------------------------------------------\n\n");
	// 
	// 1) for

	int sum_1 = 1;
	for (int i = 4; i >= 1; i--)
	{
		sum_1 *= i;
	}
	printf("%d\n", sum_1);

	printf("\n\n------------------------- < 2) 함수를 이용한 팩토리알 > ---------------------------------------------\n\n");

	// 2) function
	printf("%d\n",Factorial(4));


	return 0;
}

int Factorial(int num)
{
	if (num == 0)
		return 1;
	else
		return num * Factorial(num - 1);

}