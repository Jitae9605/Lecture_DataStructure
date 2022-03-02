/*버블정렬 - p367*/
#include <stdio.h>

void BubbleSort(int arr[], int n)
{
	int i, j;
	int temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < (n - i) - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// 데이터교환
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main(void)
{
	int arr[10] = { 3,2,10,9,4,1,8 ,5,7,6};
	int i;
	BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}