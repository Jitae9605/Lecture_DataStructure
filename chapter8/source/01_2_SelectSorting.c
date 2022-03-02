/* 선택정렬 p379*/
#include<stdio.h>

void SelSort(int arr[], int n)
{
	int i, j;
	int maxIdx;
	int temp;

	for (i = 0; i < n-1; i++)
	{
		maxIdx = i;

		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[maxIdx])
				maxIdx = j;
		}

		// 교환
		temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}



int main(void)
{
	int arr[10] = { 3,2,10,9,4,1,8 ,5,7,6 };
	int i;
	SelSort(arr, sizeof(arr) / sizeof(arr[0]));

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");


	return 0;
}