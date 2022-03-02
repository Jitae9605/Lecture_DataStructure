/*������ - p406 */
#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)			// arr�� idx1��ҿ� idx2��� �� ��ȯ
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];							// �ǹ��� ��ġ�� ���� �������� ��ġ
	int low = left + 1;
	int high = right;

	while (low <= high)								// ������������������ �ݺ�
	{
		while (pivot >= arr[low] && low <= right)		// �ǹ����� ū ���� ã�´�
			low++;										// low�� ���������� �̵�

		while (pivot <= arr[high] && high >= (left+1))	// �ǹ����� ���� ���� ã�´�
			high--;										// high�� �������� �̵�

		if (low <= high)								// �������� ���� ���¶�� Swap�Ѵ�
			Swap(arr, low, high);					
	}

	Swap(arr, left, high);								// �Ǹڰ� high�� ����Ű�� ����� ��ȯ�Ѵ�.
	return high;										// �Ű��� �ǹ��� ��ġ������ ��ȯ
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);		// �ѷ� ������
		QuickSort(arr, left, pivot - 1);				// ���ʿ����� ����
		QuickSort(arr, pivot + 1, right);				// ������ ������ ����
	}
}

void QuickSort2(int* parr, int left, int right)
{
	int left_idx = left, right_idx = right;
	int temp;
	int pivot = (left + right) / 2;						// �߾Ӻθ� �ǹ����� �غ���.

	while (left_idx <= right_idx)
	{
		while (parr[left_idx] < parr[pivot])			// �Ǻ� ���ʿ��� �Ǻ����� �������� �ְ� 
		{
			left_idx++;				
		}

		while (parr[right_idx] > parr[pivot])			// �Ǻ� �����ʿ��� �Ǻ����� ū���� �ְ�
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