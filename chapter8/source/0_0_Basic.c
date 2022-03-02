#include<stdio.h>

int main(void)
{
	int num=0;
	/*
	// 직각삼각형 만들기 1

	printf("정수입력 : ");
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = i+1; j > 0; j--)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n");

	// 직각삼각형 만들기 2

	printf("정수입력 : ");
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	*/

	printf("정수입력 : ");
	scanf("%d", &num);
	
	for (int i = 0; i < (num / 2) + 1; i++)						// 출력되는 총 줄의 수는 ((입력받은 홀수 / 2) + 1)
	{

		for (int a = 0; a < (num / 2) - i; a++)					// 공백출력	= 첫줄에는 (num/2)개의 공백 이루 다음줄마다 1개씩 공백을 줄인다
		{
			printf(" ");
		}

		for (int b = 0; b < 1 + (2 * i); b++)					// "*"출력	= 첫줄에는 1개 다음 줄부터 2개씩 늘린다
		{ 
			printf("*");
		}		

		printf("\n");											
		
	}
	return 0;
}