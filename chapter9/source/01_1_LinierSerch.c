/* 순차탐색 */
#include<stdio.h>

int LSerch(int* arr, int len, int adata)
{

	for (int i = 0; i < len; i++)
	{
		if (arr[i] == adata)
		{
			printf("값을 찾았습니다. %d번째 배열에 저장되어 있습니다.\n\n", i + 1);
			return 0;
		}
	}
	printf("해당 값을 찾지 못했습니다.\n\n");
	return 0;

}

int main(void)
{
	int ary[] = { 1,5,9,3,8,7,4,2 };
	int len = sizeof(ary) / sizeof(ary[0]);

	LSerch(ary, len, 1);
	LSerch(ary, len, 5);
	LSerch(ary, len, 11);
	LSerch(ary, len, 3);
	LSerch(ary, len, 12);


	return 0;
}