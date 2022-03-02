/*삽입정렬 - p383*/
#include <stdio.h>

void InsertSort1(int arr[], int n)
{
	int i, j;
	int insData;

	for (i = 1; i < n; i++)
	{
		insData = arr[i];		// 정렬대상을 insData에 저장

		for (j = i - 1; j >= 0; j--)	// j = i-1 때문에 i는 1부터 시작한다.
		{
			if (arr[j] > insData)		
			{
				arr[j + 1] = arr[j];	
			}
			else
			{
				break;
			}
		}
		arr[j + 1] = insData;
	}
}

void InsertSort2(int arr[], int n)
{
	int i, j;
	int insData;

	for (i = 1; i < n; i++)
	{
		insData = arr[i];		// 정렬대상을 insData에 저장

		for (j = i - 1; j >= 0; j--)	// j = i-1 때문에 i는 1부터 시작한다.
		{
			if (arr[j] > insData)
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j + 1] = insData;
	}
}


int main(void)
{
	int arr1[10] = { 3,2,10,9,4,1,8 ,5,7,6 };
	int arr2[10] = { 3,2,10,9,4,1,8 ,5,7,6 };
	int i;

	InsertSort1(arr1, sizeof(arr1) / sizeof(arr1[0]));
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");

	InsertSort2(arr2, sizeof(arr2) / sizeof(arr2[0]));
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");

	return 0;
}