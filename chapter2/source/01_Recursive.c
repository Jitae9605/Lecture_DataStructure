#include <stdio.h>

void Recursive(int num)
{
	if (num <= 0)		// 이거없으면 무한루프
		return;

	printf("Recursive call! %d \n", num);
	Recursive(num - 1);
}

int main(void)
{
	Recursive(3);

	return 0;
}