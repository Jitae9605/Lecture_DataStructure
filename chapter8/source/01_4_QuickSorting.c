/*퀵정렬 - p406 */
#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)			// arr의 idx1요소와 idx2요소 값 교환
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];							// 피벗의 위치를 가장 왼쪽으로 배치
	int low = left + 1;
	int high = right;

	while (low <= high)								// 교차되지않을때까지 반복
	{
		while (pivot >= arr[low] && low <= right)		// 피벗보다 큰 값을 찾는다
			low++;										// low를 오른쪽으로 이동

		while (pivot <= arr[high] && high >= (left+1))	// 피벗보다 작은 값을 찾는다
			high--;										// high룰 왼쪽으로 이동

		if (low <= high)								// 교차되지 않은 상태라면 Swap한다
			Swap(arr, low, high);					
	}

	Swap(arr, left, high);								// 피멋과 high가 가리키는 대상을 교환한다.
	return high;										// 옮겨진 피벗의 위치정보를 반환
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);		// 둘로 나눠서
		QuickSort(arr, left, pivot - 1);				// 왼쪽영역을 정렬
		QuickSort(arr, pivot + 1, right);				// 오른쪽 영역을 정렬
	}
}

void QuickSort2(int* parr, int left, int right)
{
	int left_idx = left, right_idx = right;
	int temp;
	int pivot = (left + right) / 2;						// 중앙부를 피벗으로 해본다.

	while (left_idx <= right_idx)
	{
		while (parr[left_idx] < parr[pivot])			// 피봇 왼쪽에는 피봇보다 작은값만 있게 
		{
			left_idx++;				
		}

		while (parr[right_idx] > parr[pivot])			// 피봇 오른쪽에는 피봇보다 큰값만 있게
		{
			right_idx--;
		}

		if (left_idx < right_idx)						
		{
			temp = parr[left_idx];
			parr[left_idx] = parr[right_idx];
			parr[right_idx] = temp;
		}

		left_idx++;
		right_idx--;
	}

	if (left < right_idx) QuickSort2(parr, left, right_idx);
	if (left_idx < right) QuickSort2(parr, left_idx, right);
}

int main(void)
{
	 int arr[7] = { 3,2,4,1,7,6,5 };
	// int arr[3] = { 3,3,3 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	//QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	QuickSort2(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}